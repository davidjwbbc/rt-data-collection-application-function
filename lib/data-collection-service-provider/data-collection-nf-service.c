/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include <inttypes.h>
#include "context.h"
#include "utilities.h"
#include "data-collection-nf-service.h"
#include "openapi/api/TS26532_Ndcaf_DataReportingProvisioningApi-info.h"
#include "openapi/api/TS26532_Ndcaf_DataReportingApi-info.h"
#include "openapi/api/ApplicationEventSubscriptionCollectionApi-info.h"
#include "openapi/api/IndividualApplicationEventSubscriptionDocumentApi-info.h"

typedef struct {
    uint64_t flag;
    int server_ifc;
} __server_flags_t;

static ogs_sbi_nf_service_t *__data_collection_nf_service(const char *name, const __server_flags_t * const server_ifcs, const char *api_version, const char *supported_features);
static void __add_addresses_to_nf_service(ogs_sbi_nf_service_t *nf_service, ogs_sockaddr_t *addrs);

int _data_collection_set_nf_services(void)
{
    ogs_sbi_nf_service_t *nf_service = NULL;
    size_t i;

    static const struct {
        uint64_t flag;
        const char *name;
        const __server_flags_t server_ifcs[4];
        const char *full_version;
        bool event_feature_flags;
    } services[] = {
      {DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_PROVISIONING, "3gpp-ndcaf_data-reporting-provisioning",
       {
        {DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_PROVISIONING_R1, DATA_COLLECTION_SVR_PROVISIONING},
        {0, -1}
       }, NDCAF_DATAREPORTINGPROVISIONING_API_VERSION, false},
      {DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING, "3gpp-ndcaf_data-reporting",
       {
        {DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R2, DATA_COLLECTION_SVR_DIRECT_DATA_REPORTING},
        {DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R3, DATA_COLLECTION_SVR_INDIRECT_DATA_REPORTING},
        {DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R4, DATA_COLLECTION_SVR_AS_DATA_REPORTING},
        {0, -1}
       }, NDCAF_DATAREPORTING_API_VERSION, false},
      {DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE, "naf-eventexposure",
       {
        {DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE_R5, DATA_COLLECTION_SVR_AF_EVENT_EXPOSURE},
        {DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE_R6, DATA_COLLECTION_SVR_NWDAF_EVENT_EXPOSURE},
        {0, -1}
       }, NAF_EVENTEXPOSURE_API_VERSION, true}
    };

    for (i=0; i<sizeof(services)/sizeof(services[0]); i++) {
        uint64_t enabled_services =
                    services[i].flag & ~data_collection_self()->config.data_collection_configuration->disable_features;
        if (enabled_services == 0) {
            ogs_info("Data Collection Service [%s] disabled by controlling app", services[i].name);
        } else {
            char *supported_features = NULL;

            ogs_info("Registering Data Collection Service [%s]", services[i].name);
            if (services[i].event_feature_flags) {
                supported_features = ogs_msprintf("%" PRIx64, data_collection_self()->config.data_collection_configuration->event_exposure_supported_features);
            }
            nf_service = __data_collection_nf_service(services[i].name, services[i].server_ifcs, services[i].full_version, supported_features);
            ogs_free(supported_features);
            if (!nf_service) return OGS_ERROR;
        }
    }

    return OGS_OK;
}

/***** Private functions *****/

static ogs_sbi_nf_service_t *__data_collection_nf_service(const char *name, const __server_flags_t* const server_ifcs, const char *api_version, const char *supported_features)
{
    ogs_sbi_nf_service_t *nf_service = NULL;
    ogs_uuid_t uuid;
    char id[OGS_UUID_FORMATTED_LENGTH + 1];
    size_t j;

    ogs_assert(name);

    ogs_uuid_get(&uuid);
    ogs_uuid_format(id, &uuid);

    nf_service = ogs_sbi_nf_service_add(ogs_sbi_self()->nf_instance, id, name,
                                        ogs_app()->sbi.server.no_tls == false ? OpenAPI_uri_scheme_https : OpenAPI_uri_scheme_http);
    ogs_assert(nf_service);

    for (j=0; server_ifcs[j].server_ifc != -1; j++) {
        if (server_ifcs[j].flag & ~data_collection_self()->config.data_collection_configuration->disable_features) {
            size_t i;
            data_collection_configuration_server_hdr_t *svr_hdr =
                        data_collection_self()->config.servers + server_ifcs[j].server_ifc;
            for (i=0; i<svr_hdr->num_v4_server_instances; i++) {
                __add_addresses_to_nf_service(nf_service, svr_hdr->ogs_server[i].ipv4);
            }
            for (i=0; i<svr_hdr->num_v6_server_instances; i++) {
                __add_addresses_to_nf_service(nf_service, svr_hdr->ogs_server[i].ipv6);
            }
        } else {
            ogs_debug("Data Collection Service [%s] is partially disabled by the controlling app", name);
        }
    }

    ogs_sbi_nf_service_add_version(nf_service, OGS_SBI_API_V1, api_version, NULL);

    nf_service->supported_features = data_collection_strdup(supported_features);

    ogs_debug("Data Collection Service [%s]", nf_service->name);

    return nf_service;
}

static void __add_addresses_to_nf_service(ogs_sbi_nf_service_t *nf_service, ogs_sockaddr_t *addrs)
{
    ogs_sockaddr_t *addr = NULL;

    for (ogs_copyaddrinfo(&addr, addrs); addr && nf_service->num_of_addr < OGS_SBI_MAX_NUM_OF_IP_ADDRESS;
         addr = addr->next) {
        bool is_port = true;
        int port = 0;

        if (addr->ogs_sa_family == AF_INET) {
            nf_service->addr[nf_service->num_of_addr].ipv4 = addr;
        } else if (addr->ogs_sa_family == AF_INET6) {
            nf_service->addr[nf_service->num_of_addr].ipv6 = addr;
        } else {
            continue;
        }

        port = OGS_PORT(addr);
        if (nf_service->scheme == OpenAPI_uri_scheme_https) {
            if (port == OGS_SBI_HTTPS_PORT) is_port = false;
        } else if (nf_service->scheme == OpenAPI_uri_scheme_http) {
            if (port == OGS_SBI_HTTP_PORT) is_port = false;
        }

        nf_service->addr[nf_service->num_of_addr].is_port = is_port;
        nf_service->addr[nf_service->num_of_addr].port = port;

        nf_service->num_of_addr++;
    }
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
