/**********************************************************************************************************************************
 * PerformanceDataRecord - C interface to the PerformanceDataRecord object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

#include <memory>
#include <type_traits>

#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "PerformanceDataRecord.h" already included by data-collection-sp/data-collection.h */
#include "PerformanceDataRecord-internal.h"
#include "openapi/model/PerformanceDataRecord.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_create(








)
{
    return reinterpret_cast<data_collection_model_performance_data_record_t*>(new std::shared_ptr<PerformanceDataRecord>(new PerformanceDataRecord(








)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_create_ref(const data_collection_model_performance_data_record_t *other)
{
    return reinterpret_cast<data_collection_model_performance_data_record_t*>(new std::shared_ptr<PerformanceDataRecord>(*reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_create_copy(const data_collection_model_performance_data_record_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_performance_data_record_t*>(new std::shared_ptr<PerformanceDataRecord >(new PerformanceDataRecord(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_create_move(data_collection_model_performance_data_record_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PerformanceDataRecord > *obj = reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_copy(data_collection_model_performance_data_record_t *performance_data_record, const data_collection_model_performance_data_record_t *other)
{
    if (performance_data_record) {
        std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(performance_data_record);
        if (obj) {
            if (other) {
                const std::shared_ptr<PerformanceDataRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(other);
                if (other_obj) {
                    *obj = *other_obj;
                } else {
                    obj.reset();
                }
            } else {
                obj.reset();
            }
        } else {
            if (other) {
                const std::shared_ptr<PerformanceDataRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(other);
                if (other_obj) {
                    obj.reset(new PerformanceDataRecord(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        performance_data_record = data_collection_model_performance_data_record_create_copy(other);
    }
    return performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_move(data_collection_model_performance_data_record_t *performance_data_record, data_collection_model_performance_data_record_t *other)
{
    std::shared_ptr<PerformanceDataRecord > *other_ptr = reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(other);

    if (performance_data_record) {
        std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(performance_data_record);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                performance_data_record = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_performance_data_record_free(data_collection_model_performance_data_record_t *performance_data_record)
{
    if (!performance_data_record) return;
    delete reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(performance_data_record);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_performance_data_record_toJSON(const data_collection_model_performance_data_record_t *performance_data_record, bool as_request)
{
    if (!performance_data_record) return NULL;
    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(performance_data_record);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_performance_data_record_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_performance_data_record_t*>(new std::shared_ptr<PerformanceDataRecord >(new PerformanceDataRecord(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_is_equal_to(const data_collection_model_performance_data_record_t *first, const data_collection_model_performance_data_record_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PerformanceDataRecord > &obj2 = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PerformanceDataRecord > &obj1 = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(first);
    if (!second) {
        if (!obj1) return true;
        return false;
    }
    
    /* check what std::shared_ptr objects are pointing to */
    if (obj1 == obj2) return true;
    if (!obj1) return false;
    if (!obj2) return false;

    /* different shared_ptr objects pointing to different instances, so compare instances */
    return (*obj1 == *obj2);
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_get_timestamp(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerformanceDataRecord::TimestampType ResultFromType;
    const ResultFromType &result_from = obj->getTimestamp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_timestamp(data_collection_model_performance_data_record_t *obj_performance_data_record, const char* p_timestamp)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_timestamp;
    typedef typename PerformanceDataRecord::TimestampType ValueType;

    ValueType value(value_from);

    if (!obj->setTimestamp(value)) return NULL;

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_timestamp_move(data_collection_model_performance_data_record_t *obj_performance_data_record, char* p_timestamp)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_timestamp;
    typedef typename PerformanceDataRecord::TimestampType ValueType;

    ValueType value(value_from);

    if (!obj->setTimestamp(std::move(value))) return NULL;
    ogs_free
(p_timestamp);

    return obj_performance_data_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_performance_data_record_get_context_ids(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename PerformanceDataRecord::ContextIdsType ResultFromType;
    const ResultFromType &result_from = obj->getContextIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_context_ids(data_collection_model_performance_data_record_t *obj_performance_data_record, const ogs_list_t* p_context_ids)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename PerformanceDataRecord::ContextIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setContextIds(value)) return NULL;

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_context_ids_move(data_collection_model_performance_data_record_t *obj_performance_data_record, ogs_list_t* p_context_ids)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename PerformanceDataRecord::ContextIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setContextIds(std::move(value))) return NULL;
    data_collection_list_free
(p_context_ids);

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_add_context_ids(data_collection_model_performance_data_record_t *obj_performance_data_record, char* p_context_ids)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    typedef typename PerformanceDataRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);

    ogs_free
(p_context_ids);
    obj->addContextIds(value);
    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_remove_context_ids(data_collection_model_performance_data_record_t *obj_performance_data_record, const char* p_context_ids)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    typedef typename PerformanceDataRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);

    obj->removeContextIds(value);
    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_get_entry_context_ids(const data_collection_model_performance_data_record_t *obj_performance_data_record, size_t idx)
{
    if (!obj_performance_data_record) {
        const char *result = NULL;

        return result;
    }

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) {
        const char *result = NULL;

        return result;
    }

    const PerformanceDataRecord::ContextIdsType &container = obj->getContextIds();
    

    auto itr = container.cbegin();
    while (idx > 0 && itr != container.cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.cend()) {
        const char *result = NULL;

        return result;
    }
    typedef typename PerformanceDataRecord::ContextIdsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_clear_context_ids(data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    obj->clearContextIds();
    return obj_performance_data_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_performance_data_record_get_time_interval(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) {
        const data_collection_model_time_window_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) {
        const data_collection_model_time_window_t *result = NULL;
        return result;
    }

    typedef typename PerformanceDataRecord::TimeIntervalType ResultFromType;
    const ResultFromType &result_from = obj->getTimeInterval();
    const data_collection_model_time_window_t *result = reinterpret_cast<const data_collection_model_time_window_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_time_interval(data_collection_model_performance_data_record_t *obj_performance_data_record, const data_collection_model_time_window_t* p_time_interval)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_time_interval;
    typedef typename PerformanceDataRecord::TimeIntervalType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setTimeInterval(value)) return NULL;

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_time_interval_move(data_collection_model_performance_data_record_t *obj_performance_data_record, data_collection_model_time_window_t* p_time_interval)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_time_interval;
    typedef typename PerformanceDataRecord::TimeIntervalType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setTimeInterval(std::move(value))) return NULL;
    data_collection_model_time_window_free
(p_time_interval);

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_location(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) return false;

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return false;

    return obj->getLocation().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_performance_data_record_get_location(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) {
        const data_collection_model_location_area5_g_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) {
        const data_collection_model_location_area5_g_t *result = NULL;
        return result;
    }

    typedef typename PerformanceDataRecord::LocationType ResultFromType;
    const ResultFromType &result_from = obj->getLocation();
    const data_collection_model_location_area5_g_t *result = reinterpret_cast<const data_collection_model_location_area5_g_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_location(data_collection_model_performance_data_record_t *obj_performance_data_record, const data_collection_model_location_area5_g_t* p_location)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_location;
    typedef typename PerformanceDataRecord::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setLocation(value)) return NULL;

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_location_move(data_collection_model_performance_data_record_t *obj_performance_data_record, data_collection_model_location_area5_g_t* p_location)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_location;
    typedef typename PerformanceDataRecord::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setLocation(std::move(value))) return NULL;
    data_collection_model_location_area5_g_free
(p_location);

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_remote_endpoint(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) return false;

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return false;

    return obj->getRemoteEndpoint().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_performance_data_record_get_remote_endpoint(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) {
        const data_collection_model_addr_fqdn_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) {
        const data_collection_model_addr_fqdn_t *result = NULL;
        return result;
    }

    typedef typename PerformanceDataRecord::RemoteEndpointType ResultFromType;
    const ResultFromType &result_from = obj->getRemoteEndpoint();
    const data_collection_model_addr_fqdn_t *result = reinterpret_cast<const data_collection_model_addr_fqdn_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_remote_endpoint(data_collection_model_performance_data_record_t *obj_performance_data_record, const data_collection_model_addr_fqdn_t* p_remote_endpoint)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_remote_endpoint;
    typedef typename PerformanceDataRecord::RemoteEndpointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRemoteEndpoint(value)) return NULL;

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_remote_endpoint_move(data_collection_model_performance_data_record_t *obj_performance_data_record, data_collection_model_addr_fqdn_t* p_remote_endpoint)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_remote_endpoint;
    typedef typename PerformanceDataRecord::RemoteEndpointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRemoteEndpoint(std::move(value))) return NULL;
    data_collection_model_addr_fqdn_free
(p_remote_endpoint);

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_packet_delay_budget(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) return false;

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return false;

    return obj->getPacketDelayBudget().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_record_get_packet_delay_budget(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PerformanceDataRecord::PacketDelayBudgetType ResultFromType;
    const ResultFromType &result_from = obj->getPacketDelayBudget();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_delay_budget(data_collection_model_performance_data_record_t *obj_performance_data_record, const int32_t p_packet_delay_budget)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_packet_delay_budget;
    typedef typename PerformanceDataRecord::PacketDelayBudgetType ValueType;

    ValueType value(value_from);

    if (!obj->setPacketDelayBudget(value)) return NULL;

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_delay_budget_move(data_collection_model_performance_data_record_t *obj_performance_data_record, int32_t p_packet_delay_budget)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_packet_delay_budget;
    typedef typename PerformanceDataRecord::PacketDelayBudgetType ValueType;

    ValueType value(value_from);

    if (!obj->setPacketDelayBudget(std::move(value))) return NULL;

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_packet_loss_rate(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) return false;

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return false;

    return obj->getPacketLossRate().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_record_get_packet_loss_rate(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PerformanceDataRecord::PacketLossRateType ResultFromType;
    const ResultFromType &result_from = obj->getPacketLossRate();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_loss_rate(data_collection_model_performance_data_record_t *obj_performance_data_record, const int32_t p_packet_loss_rate)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_packet_loss_rate;
    typedef typename PerformanceDataRecord::PacketLossRateType ValueType;

    ValueType value(value_from);

    if (!obj->setPacketLossRate(value)) return NULL;

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_loss_rate_move(data_collection_model_performance_data_record_t *obj_performance_data_record, int32_t p_packet_loss_rate)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_packet_loss_rate;
    typedef typename PerformanceDataRecord::PacketLossRateType ValueType;

    ValueType value(value_from);

    if (!obj->setPacketLossRate(std::move(value))) return NULL;

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_uplink_throughput(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) return false;

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return false;

    return obj->getUplinkThroughput().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_get_uplink_throughput(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerformanceDataRecord::UplinkThroughputType ResultFromType;
    const ResultFromType &result_from = obj->getUplinkThroughput();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_uplink_throughput(data_collection_model_performance_data_record_t *obj_performance_data_record, const char* p_uplink_throughput)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_uplink_throughput;
    typedef typename PerformanceDataRecord::UplinkThroughputType ValueType;

    ValueType value(value_from);

    if (!obj->setUplinkThroughput(value)) return NULL;

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_uplink_throughput_move(data_collection_model_performance_data_record_t *obj_performance_data_record, char* p_uplink_throughput)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_uplink_throughput;
    typedef typename PerformanceDataRecord::UplinkThroughputType ValueType;

    ValueType value(value_from);

    if (!obj->setUplinkThroughput(std::move(value))) return NULL;
    ogs_free
(p_uplink_throughput);

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_downlink_througput(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) return false;

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return false;

    return obj->getDownlinkThrougput().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_get_downlink_througput(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerformanceDataRecord::DownlinkThrougputType ResultFromType;
    const ResultFromType &result_from = obj->getDownlinkThrougput();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_downlink_througput(data_collection_model_performance_data_record_t *obj_performance_data_record, const char* p_downlink_througput)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_downlink_througput;
    typedef typename PerformanceDataRecord::DownlinkThrougputType ValueType;

    ValueType value(value_from);

    if (!obj->setDownlinkThrougput(value)) return NULL;

    return obj_performance_data_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_downlink_througput_move(data_collection_model_performance_data_record_t *obj_performance_data_record, char* p_downlink_througput)
{
    if (!obj_performance_data_record) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    if (!obj) return NULL;

    const auto &value_from = p_downlink_througput;
    typedef typename PerformanceDataRecord::DownlinkThrougputType ValueType;

    ValueType value(value_from);

    if (!obj->setDownlinkThrougput(std::move(value))) return NULL;
    ogs_free
(p_downlink_througput);

    return obj_performance_data_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_performance_data_record_make_lnode(data_collection_model_performance_data_record_t *p_performance_data_record)
{
    return data_collection_lnode_create(p_performance_data_record, reinterpret_cast<void(*)(void*)>(data_collection_model_performance_data_record_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_performance_data_record_refcount(data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    if (!obj_performance_data_record) return 0l;
    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

