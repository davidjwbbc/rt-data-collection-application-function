/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "ogs-core.h"

#include "data-collection-sp/data-collection.h"
#include "hash.h"
#include "utilities.h"

#include "data-reporting.h"
#include "data-reporting-session-cache.h"

#ifdef __cplusplus
extern "C" {
#endif

static void _debug_key(const char *key, const char *prefix);
static data_reporting_session_cache_entry_t *_data_reporting_session_cache_find(ogs_hash_t *cache, const char *key);

ogs_hash_t *data_reporting_session_cache_new(void)
{
    ogs_hash_t *ret;

    ret = ogs_hash_make();

    ogs_debug("data_reporting_session_cache_new() = %p", ret);

    return (ogs_hash_t *)ret;
   
}

void data_reporting_session_cache_free(ogs_hash_t *cache)
{
    if (!cache) return;
    ogs_debug("data_reporting_session_cache_free(%p)", cache);
    data_reporting_session_cache_clear(cache);
    ogs_hash_destroy(cache);
}

bool data_reporting_session_cache_add(ogs_hash_t *cache, const data_collection_reporting_session_t *data_collection_reporting_session)
{
    data_reporting_session_cache_entry_t *entry = NULL;

    ogs_assert(cache);

    ogs_debug("data_reporting_session_cache_add(%p, %p, %p)", cache, data_collection_reporting_session, data_collection_reporting_session->data_reporting_session);

    const char *data_reporting_session_id = data_collection_model_data_reporting_session_get_session_id(data_collection_reporting_session->data_reporting_session);
    entry = _data_reporting_session_cache_find(cache, data_reporting_session_id);
    if (entry) {
        /* replacing existing entry, free old one */
        data_reporting_session_cache_entry_free(entry);
    } 
    if(!entry) {

	entry = data_reporting_session_cache_entry_new(data_collection_reporting_session->data_reporting_session);    
    }
    ogs_assert(entry);

    entry->reporting_session_received = data_collection_reporting_session->received;

    ogs_hash_set(cache, data_reporting_session_id, OGS_HASH_KEY_STRING, entry);
    return true;
}

bool data_reporting_session_cache_del(ogs_hash_t *cache, const char *session_id)
{
    data_reporting_session_cache_entry_t *entry;

    if (!cache) return false;

    ogs_debug("data_reporting_session_cache_del(%p, %s)", cache, session_id);

    entry = _data_reporting_session_cache_find(cache, session_id);

    if (entry) {
        ogs_hash_set(cache, session_id, OGS_HASH_KEY_STRING, NULL);
        data_reporting_session_cache_entry_free(entry);
        return true;
    }

    return false;
}

data_reporting_session_cache_entry_t *data_reporting_session_cache_find(ogs_hash_t *cache, const char *session_id)
{
    ogs_debug("data_reporting_session_cache_find(cache=%p, Session=%s)", cache, session_id);
    if (!cache) return NULL;
    if (!session_id) return NULL;
    return _data_reporting_session_cache_find(cache, session_id);
}

bool data_reporting_session_cache_clear(ogs_hash_t *cache)
{
    ogs_hash_index_t *it;

    if (!cache) return false;

    ogs_debug("data_reporting_session_cache_clear(%p) [%i entries]", cache, ogs_hash_count(cache));
    for (it = ogs_hash_first(cache); it; it = ogs_hash_next(it)) {
        const char *key;
        int key_len;
        data_reporting_session_cache_entry_t *entry;

        ogs_hash_this(it, (const void **)&key, &key_len, (void**)(&entry));
        _debug_key(key, "=");
        ogs_debug("clear %p[%i]: %p", key, key_len, entry);
        ogs_hash_set(cache, key, key_len, NULL);
        data_reporting_session_cache_entry_free(entry);
    }
    ogs_debug("Entries after clear = %i", ogs_hash_count(cache));

    return true;
}

bool data_reporting_session_cache_prune(ogs_hash_t *cache)
{
    ogs_hash_index_t *it;

    if (!cache) return false;

    ogs_debug("data_reporting_session_cache_prune(%p) [%i entries]", cache, ogs_hash_count(cache));
    for (it = ogs_hash_first(cache); it; it = ogs_hash_next(it)) {
        const char *key;
        int key_len;
        data_reporting_session_cache_entry_t *entry;
	//data_collection_reporting_session_t *data_reporting_session = NULL;
	const ogs_time_t current_time = ogs_time_now();

        ogs_hash_this(it, (const void **)&key, &key_len, (void**)(&entry));
        _debug_key(key, "=");
	if (current_time >= entry->generated +  ( 3 * ogs_time_from_sec(data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age))) {
            ogs_debug("clear %p[%i]: %p", key, key_len, entry);
	    //data_reporting_session = data_collection_reporting_session_find(key);
            ogs_hash_set(cache, key, key_len, NULL);
            //if (data_reporting_session) data_collection_reporting_session_destroy_active_session(data_reporting_session);
            data_reporting_session_cache_entry_free(entry);
	}
    }
    ogs_debug("Entries after pruning = %i", ogs_hash_count(cache));

    return true;
}


data_reporting_session_cache_entry_t *data_reporting_session_cache_entry_new(const data_collection_model_data_reporting_session_t *data_reporting_session)
{
    data_reporting_session_cache_entry_t *entry;
    cJSON *reporting_session;

    entry = ogs_calloc(1, sizeof(*entry));
    ogs_assert(entry);

    if(entry->session_id) ogs_free(entry->session_id);

    entry->session_id = data_collection_strdup(data_collection_model_data_reporting_session_get_session_id(data_reporting_session));

    reporting_session = data_collection_model_data_reporting_session_toJSON(data_reporting_session, false);
    ogs_assert(reporting_session);

    entry->reporting_session = cJSON_Print(reporting_session);
    cJSON_Delete(reporting_session);

    entry->hash = calculate_hash(entry->reporting_session);

    entry->generated = ogs_time_now();

    return entry;
}

void data_reporting_session_cache_entry_free(data_reporting_session_cache_entry_t *entry)
{
    if (!entry) return;

    if (entry->session_id) {
        ogs_free(entry->session_id);
        entry->session_id = NULL;
    }

    if (entry->reporting_session) {
	cJSON_free(entry->reporting_session);
	entry->reporting_session = NULL;
    }

    if (entry->hash) {
	ogs_free(entry->hash);
	entry->hash = NULL;
    }

    ogs_free(entry);
}

void data_collection_reporting_session_cache_destroy(data_reporting_session_cache_entry_t *entry)
{
    if (!entry) return;

    ogs_hash_set(data_collection_self()->data_reporting_sessions_cache, entry->session_id, OGS_HASH_KEY_STRING, NULL);
    data_reporting_session_cache_entry_free(entry);
}

void data_reporting_session_cache_accessed(data_reporting_session_cache_entry_t *entry)
{
    if (entry) {
        entry->access_time = ogs_time_now();
    }
}

/**** Static functions ****/

static void _debug_key(const char *key, const char *prefix)
{
    ogs_debug("%s session = %s", prefix, key);
}

static data_reporting_session_cache_entry_t *_data_reporting_session_cache_find(ogs_hash_t *cache, const char *key)
{
    return (data_reporting_session_cache_entry_t *)ogs_hash_get(cache, key, OGS_HASH_KEY_STRING);
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
