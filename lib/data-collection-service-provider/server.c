/*
License: 5G-MAG Public License (v1.0)
Author: Dev Audsin
Copyright: (C) 2022 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "ogs-sbi.h"
#include "server.h"
#include "utilities.h"
#include "data-collection-sp/data-collection-version.h"

static bool nf_server_send_problem(ogs_sbi_stream_t *stream, OpenAPI_problem_details_t *problem,
        const nf_server_interface_metadata_t *interface, const nf_server_app_metadata_t *app);

static ogs_sbi_response_t *nf_build_response(ogs_sbi_message_t *message, int status,
        const nf_server_interface_metadata_t *interface, const nf_server_app_metadata_t *app);

static bool nf_build_content(ogs_sbi_http_message_t *http, ogs_sbi_message_t *message);

static char *nf_build_json(ogs_sbi_message_t *message);

ogs_sbi_response_t *nf_server_new_response(const char *location, const char *content_type, ogs_time_t last_modified,
                                           const char *etag, int cache_control, const char *allow_methods,
                                           const nf_server_interface_metadata_t *interface,
                                           const nf_server_app_metadata_t *app)
{
    ogs_sbi_response_t *response = NULL;

    response = ogs_sbi_response_new();
    ogs_expect(response);

    if (content_type) {
        ogs_sbi_header_set(response->http.headers, "Content-Type", content_type);
    }

    if (location) {
        ogs_sbi_header_set(response->http.headers, "Location", location);
    }

    if (last_modified) {
        char *modified = ogs_time_to_string(last_modified, "%a, %d %b %Y %H:%M:%S %Z");
	//char *modified = ogs_time_to_string(last_modified);
        ogs_sbi_header_set(response->http.headers, "Last-Modified", modified);
	ogs_free(modified);
    }

    if (etag) {
        ogs_sbi_header_set(response->http.headers, "ETag", etag);
    }

    if (cache_control) {
        char *response_cache_control;
        response_cache_control = ogs_msprintf("max-age=%d", cache_control);
        ogs_sbi_header_set(response->http.headers, "Cache-Control", response_cache_control);
        ogs_free(response_cache_control);
    }

    if (allow_methods) {
        ogs_sbi_header_set(response->http.headers, "Allow", allow_methods);
    }

    {
        char *server;
        const char *server_api_info = "";
        char *server_api_gen = NULL;
        if (interface) {
            server_api_gen = ogs_msprintf(" (info.title=%s; info.version=%s)", interface->api_title, interface->api_version);
            server_api_info = server_api_gen;
        }
        server = ogs_msprintf("%s/%s%s %s %s/%s",app->server_name, FIVEG_API_RELEASE, server_api_info, app->nf_info, app->app_name,
                              app->app_version);
        if (server_api_gen) ogs_free(server_api_gen);
        ogs_sbi_header_set(response->http.headers, "Server", server);
	ogs_free(server);
    }

    return response;
}

ogs_sbi_response_t *nf_server_populate_response(ogs_sbi_response_t *response, int content_length, char *content, int status)
{
    response->http.content_length = content_length;
    response->http.content = content;
    response->status = status;
    return response;

}

OpenAPI_list_t *nf_server_make_invalid_params(const char *param, const char *reason) {

    OpenAPI_invalid_param_t *invalid_param;
    OpenAPI_list_t *invalid_params;

    invalid_params = OpenAPI_list_create();
    invalid_param = OpenAPI_invalid_param_create(data_collection_strdup(param), data_collection_strdup(reason));
    OpenAPI_list_add(invalid_params, invalid_param);
    return invalid_params;
}


static bool nf_server_send_problem(
        ogs_sbi_stream_t *stream, OpenAPI_problem_details_t *problem, const nf_server_interface_metadata_t *interface, const nf_server_app_metadata_t *app)
{
    ogs_sbi_message_t message;
    ogs_sbi_response_t *response = NULL;

    ogs_assert(stream);
    ogs_assert(problem);

    memset(&message, 0, sizeof(message));

    message.http.content_type = "application/problem+json";
    message.ProblemDetails = problem;

    response = nf_build_response(&message, problem->status, interface, app);
    ogs_assert(response);

    ogs_sbi_server_send_response(stream, response);

    return true;
}


bool nf_server_send_error(ogs_sbi_stream_t *stream,
        int status, int number_of_components, ogs_sbi_message_t *message,
        const char *title, const char *detail, cJSON * problem_detail, OpenAPI_list_t *invalid_params, const char *problem_type, const nf_server_interface_metadata_t *interface, const nf_server_app_metadata_t *app)
{
    OpenAPI_problem_details_t problem;
    OpenAPI_problem_details_t *problem_details = NULL;

    ogs_assert(stream);

    memset(&problem, 0, sizeof(problem));

    if(problem_detail) {
        problem_details = OpenAPI_problem_details_parseFromJSON(problem_detail);
        problem.invalid_params = problem_details->invalid_params;
	problem_details->invalid_params = NULL;
	OpenAPI_problem_details_free(problem_details);

    }

    if (message) {
        int i;
	/*
        problem.type = ogs_msprintf("/%s/%s",
                message->h.service.name, message->h.api.version);
        ogs_expect(problem.type);

        problem.instance = ogs_msprintf("/%s", message->h.resource.component[0]);
	*/

	if (problem_type) {
            problem.type = data_collection_strdup(problem_type);
            ogs_expect(problem.type);
        }

        if(invalid_params) problem.invalid_params = invalid_params;

        problem.instance = ogs_msprintf("/%s/%s/%s", message->h.service.name, message->h.api.version, message->h.resource.component[0]);

        for (i = 1; i <= number_of_components; i++)
        {
            problem.instance = ogs_mstrcatf(problem.instance, "/%s", message->h.resource.component[i]);
            ogs_expect(problem.instance);
        }
    }
    if (status) {
        problem.is_status = true;
        problem.status = status;
    }
    if (title) problem.title = data_collection_strdup(title);
    if (detail) problem.detail = data_collection_strdup(detail);

    nf_server_send_problem(stream, &problem, interface, app);

    if (problem.type)
        ogs_free(problem.type);
    if (problem.instance)
        ogs_free(problem.instance);
    if (problem.title)
        ogs_free(problem.title);
    if (problem.detail)
        ogs_free(problem.detail);
    if (problem.invalid_params) {
	OpenAPI_lnode_t *node = NULL;    
        OpenAPI_list_for_each(problem.invalid_params, node) {
            OpenAPI_invalid_param_free(node->data);
        }
        OpenAPI_list_free(problem.invalid_params);
        problem.invalid_params = NULL;
    }

    return true;
}

static ogs_sbi_response_t *nf_build_response(ogs_sbi_message_t *message, int status,
        const nf_server_interface_metadata_t *interface, const nf_server_app_metadata_t *app)
{
    ogs_sbi_response_t *response = NULL;

    ogs_assert(message);

    response = nf_server_new_response(NULL, NULL, 0, NULL, 0, NULL, interface, app);

    ogs_expect(response);

    response->status = status;

    if (response->status != OGS_SBI_HTTP_STATUS_NO_CONTENT) {
        ogs_expect(true ==
                nf_build_content(&response->http, message));
    }

    if (message->http.location) {
        ogs_sbi_header_set(response->http.headers, "Location",
                message->http.location);
    }
    if (message->http.cache_control)
        ogs_sbi_header_set(response->http.headers, "Cache-Control",
                message->http.cache_control);

    return response;
}

static bool nf_build_content(
        ogs_sbi_http_message_t *http, ogs_sbi_message_t *message)
{
    ogs_assert(message);
    ogs_assert(http);

    http->content = nf_build_json(message);
    if (http->content) {
        http->content_length = strlen(http->content);
        if (message->http.content_type) {
            ogs_sbi_header_set(http->headers,
                    OGS_SBI_CONTENT_TYPE, message->http.content_type);
        } else {
            ogs_sbi_header_set(http->headers,
                    OGS_SBI_CONTENT_TYPE, OGS_SBI_CONTENT_JSON_TYPE);
        }
    }

    return true;
}

static char *nf_build_json(ogs_sbi_message_t *message)
{
    char *content = NULL;
    cJSON *item = NULL;

    ogs_assert(message);

    if (message->ProblemDetails) {
        item = OpenAPI_problem_details_convertToJSON(message->ProblemDetails);
        ogs_assert(item);
    }
    if (item) {
        content = cJSON_Print(item);
        ogs_assert(content);
        ogs_log_print(OGS_LOG_TRACE, "%s", content);
        cJSON_Delete(item);
    }

    return content;
}

/* vim:ts=8:sts=4:sw=4:expandtab:
*/
