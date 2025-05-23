/**********************************************************************************************************************************
 * BaseEventRecord - C interface to the BaseEventRecord object
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

/*#include "BaseEventRecord.h" already included by data-collection-sp/data-collection.h */
#include "BaseEventRecord-internal.h"
#include "openapi/model/BaseEventRecord.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_create(








)
{
    return reinterpret_cast<data_collection_model_base_event_record_t*>(new std::shared_ptr<BaseEventRecord>(new BaseEventRecord(








)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_create_ref(const data_collection_model_base_event_record_t *other)
{
    return reinterpret_cast<data_collection_model_base_event_record_t*>(new std::shared_ptr<BaseEventRecord>(*reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_create_copy(const data_collection_model_base_event_record_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_base_event_record_t*>(new std::shared_ptr<BaseEventRecord >(new BaseEventRecord(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_create_move(data_collection_model_base_event_record_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<BaseEventRecord > *obj = reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_copy(data_collection_model_base_event_record_t *base_event_record, const data_collection_model_base_event_record_t *other)
{
    if (base_event_record) {
        std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(base_event_record);
        if (obj) {
            if (other) {
                const std::shared_ptr<BaseEventRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(other);
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
                const std::shared_ptr<BaseEventRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(other);
                if (other_obj) {
                    obj.reset(new BaseEventRecord(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        base_event_record = data_collection_model_base_event_record_create_copy(other);
    }
    return base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_move(data_collection_model_base_event_record_t *base_event_record, data_collection_model_base_event_record_t *other)
{
    std::shared_ptr<BaseEventRecord > *other_ptr = reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(other);

    if (base_event_record) {
        std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(base_event_record);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                base_event_record = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_base_event_record_free(data_collection_model_base_event_record_t *base_event_record)
{
    if (!base_event_record) return;
    delete reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(base_event_record);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_base_event_record_toJSON(const data_collection_model_base_event_record_t *base_event_record, bool as_request)
{
    if (!base_event_record) return NULL;
    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(base_event_record);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_base_event_record_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_base_event_record_t*>(new std::shared_ptr<BaseEventRecord >(new BaseEventRecord(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_record_is_equal_to(const data_collection_model_base_event_record_t *first, const data_collection_model_base_event_record_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<BaseEventRecord > &obj2 = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<BaseEventRecord > &obj1 = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_event_record_type_t* data_collection_model_base_event_record_get_record_type(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) {
        const data_collection_model_event_record_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) {
        const data_collection_model_event_record_type_t *result = NULL;
        return result;
    }

    typedef typename BaseEventRecord::RecordTypeType ResultFromType;
    const ResultFromType &result_from = obj->getRecordType();
    const data_collection_model_event_record_type_t *result = reinterpret_cast<const data_collection_model_event_record_type_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_record_type(data_collection_model_base_event_record_t *obj_base_event_record, const data_collection_model_event_record_type_t* p_record_type)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_record_type;
    typedef typename BaseEventRecord::RecordTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setRecordType(value)) return NULL;

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_record_type_move(data_collection_model_base_event_record_t *obj_base_event_record, data_collection_model_event_record_type_t* p_record_type)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_record_type;
    typedef typename BaseEventRecord::RecordTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setRecordType(std::move(value))) return NULL;
    data_collection_model_event_record_type_free
(p_record_type);

    return obj_base_event_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_record_get_record_timestamp(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename BaseEventRecord::RecordTimestampType ResultFromType;
    const ResultFromType &result_from = obj->getRecordTimestamp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_record_timestamp(data_collection_model_base_event_record_t *obj_base_event_record, const char* p_record_timestamp)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_record_timestamp;
    typedef typename BaseEventRecord::RecordTimestampType ValueType;

    ValueType value(value_from);

    if (!obj->setRecordTimestamp(value)) return NULL;

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_record_timestamp_move(data_collection_model_base_event_record_t *obj_base_event_record, char* p_record_timestamp)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_record_timestamp;
    typedef typename BaseEventRecord::RecordTimestampType ValueType;

    ValueType value(value_from);

    if (!obj->setRecordTimestamp(std::move(value))) return NULL;
    ogs_free
(p_record_timestamp);

    return obj_base_event_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_record_get_app_id(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename BaseEventRecord::AppIdType ResultFromType;
    const ResultFromType &result_from = obj->getAppId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_app_id(data_collection_model_base_event_record_t *obj_base_event_record, const char* p_app_id)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename BaseEventRecord::AppIdType ValueType;

    ValueType value(value_from);

    if (!obj->setAppId(value)) return NULL;

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_app_id_move(data_collection_model_base_event_record_t *obj_base_event_record, char* p_app_id)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename BaseEventRecord::AppIdType ValueType;

    ValueType value(value_from);

    if (!obj->setAppId(std::move(value))) return NULL;
    ogs_free
(p_app_id);

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_record_has_provisioning_session_id(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) return false;

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return false;

    return obj->getProvisioningSessionId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_record_get_provisioning_session_id(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename BaseEventRecord::ProvisioningSessionIdType ResultFromType;
    const ResultFromType &result_from = obj->getProvisioningSessionId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_provisioning_session_id(data_collection_model_base_event_record_t *obj_base_event_record, const char* p_provisioning_session_id)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_provisioning_session_id;
    typedef typename BaseEventRecord::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);

    if (!obj->setProvisioningSessionId(value)) return NULL;

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_provisioning_session_id_move(data_collection_model_base_event_record_t *obj_base_event_record, char* p_provisioning_session_id)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_provisioning_session_id;
    typedef typename BaseEventRecord::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);

    if (!obj->setProvisioningSessionId(std::move(value))) return NULL;
    ogs_free
(p_provisioning_session_id);

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_record_has_session_id(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) return false;

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return false;

    return obj->getSessionId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_record_get_session_id(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename BaseEventRecord::SessionIdType ResultFromType;
    const ResultFromType &result_from = obj->getSessionId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_session_id(data_collection_model_base_event_record_t *obj_base_event_record, const char* p_session_id)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename BaseEventRecord::SessionIdType ValueType;

    ValueType value(value_from);

    if (!obj->setSessionId(value)) return NULL;

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_session_id_move(data_collection_model_base_event_record_t *obj_base_event_record, char* p_session_id)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename BaseEventRecord::SessionIdType ValueType;

    ValueType value(value_from);

    if (!obj->setSessionId(std::move(value))) return NULL;
    ogs_free
(p_session_id);

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_record_has_ue_identification(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) return false;

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return false;

    return obj->getUeIdentification().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_record_get_ue_identification(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename BaseEventRecord::UeIdentificationType ResultFromType;
    const ResultFromType &result_from = obj->getUeIdentification();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_ue_identification(data_collection_model_base_event_record_t *obj_base_event_record, const char* p_ue_identification)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_ue_identification;
    typedef typename BaseEventRecord::UeIdentificationType ValueType;

    ValueType value(value_from);

    if (!obj->setUeIdentification(value)) return NULL;

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_ue_identification_move(data_collection_model_base_event_record_t *obj_base_event_record, char* p_ue_identification)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_ue_identification;
    typedef typename BaseEventRecord::UeIdentificationType ValueType;

    ValueType value(value_from);

    if (!obj->setUeIdentification(std::move(value))) return NULL;
    ogs_free
(p_ue_identification);

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_record_has_data_network_name(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) return false;

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return false;

    return obj->getDataNetworkName().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_record_get_data_network_name(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename BaseEventRecord::DataNetworkNameType ResultFromType;
    const ResultFromType &result_from = obj->getDataNetworkName();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_data_network_name(data_collection_model_base_event_record_t *obj_base_event_record, const char* p_data_network_name)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename BaseEventRecord::DataNetworkNameType ValueType;

    ValueType value(value_from);

    if (!obj->setDataNetworkName(value)) return NULL;

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_data_network_name_move(data_collection_model_base_event_record_t *obj_base_event_record, char* p_data_network_name)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename BaseEventRecord::DataNetworkNameType ValueType;

    ValueType value(value_from);

    if (!obj->setDataNetworkName(std::move(value))) return NULL;
    ogs_free
(p_data_network_name);

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_record_has_slice_id(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) return false;

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return false;

    return obj->getSliceId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_base_event_record_get_slice_id(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    typedef typename BaseEventRecord::SliceIdType ResultFromType;
    const ResultFromType &result_from = obj->getSliceId();
    const data_collection_model_snssai_t *result = reinterpret_cast<const data_collection_model_snssai_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_slice_id(data_collection_model_base_event_record_t *obj_base_event_record, const data_collection_model_snssai_t* p_slice_id)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_slice_id;
    typedef typename BaseEventRecord::SliceIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setSliceId(value)) return NULL;

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_slice_id_move(data_collection_model_base_event_record_t *obj_base_event_record, data_collection_model_snssai_t* p_slice_id)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_slice_id;
    typedef typename BaseEventRecord::SliceIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setSliceId(std::move(value))) return NULL;
    data_collection_model_snssai_free
(p_slice_id);

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_record_has_ue_locations(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) return false;

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return false;

    return obj->getUeLocations().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_base_event_record_get_ue_locations(const data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename BaseEventRecord::UeLocationsType ResultFromType;
    const ResultFromType &result_from = obj->getUeLocations();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_location_area5_g_t *item_obj = reinterpret_cast<data_collection_model_location_area5_g_t*>(item.has_value()?new std::shared_ptr<LocationArea5G >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_location_area5_g_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_ue_locations(data_collection_model_base_event_record_t *obj_base_event_record, const ogs_list_t* p_ue_locations)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_ue_locations;
    typedef typename BaseEventRecord::UeLocationsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setUeLocations(value)) return NULL;

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_ue_locations_move(data_collection_model_base_event_record_t *obj_base_event_record, ogs_list_t* p_ue_locations)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    const auto &value_from = p_ue_locations;
    typedef typename BaseEventRecord::UeLocationsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setUeLocations(std::move(value))) return NULL;
    data_collection_list_free
(p_ue_locations);

    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_add_ue_locations(data_collection_model_base_event_record_t *obj_base_event_record, data_collection_model_location_area5_g_t* p_ue_locations)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    typedef typename BaseEventRecord::UeLocationsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ue_locations;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_location_area5_g_free
(p_ue_locations);
    if (value) obj->addUeLocations(value.value());
    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_remove_ue_locations(data_collection_model_base_event_record_t *obj_base_event_record, const data_collection_model_location_area5_g_t* p_ue_locations)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    typedef typename BaseEventRecord::UeLocationsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ue_locations;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeUeLocations(value);
    return obj_base_event_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_base_event_record_get_entry_ue_locations(const data_collection_model_base_event_record_t *obj_base_event_record, size_t idx)
{
    if (!obj_base_event_record) {
        const data_collection_model_location_area5_g_t *result = NULL;

        return result;
    }

    const std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) {
        const data_collection_model_location_area5_g_t *result = NULL;

        return result;
    }

    const BaseEventRecord::UeLocationsType &container = obj->getUeLocations();
    if (!container.has_value()) {
        const data_collection_model_location_area5_g_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_location_area5_g_t *result = NULL;

        return result;
    }
    typedef typename BaseEventRecord::UeLocationsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_location_area5_g_t *result = reinterpret_cast<const data_collection_model_location_area5_g_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_clear_ue_locations(data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) return NULL;

    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    if (!obj) return NULL;

    obj->clearUeLocations();
    return obj_base_event_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_base_event_record_make_lnode(data_collection_model_base_event_record_t *p_base_event_record)
{
    return data_collection_lnode_create(p_base_event_record, reinterpret_cast<void(*)(void*)>(data_collection_model_base_event_record_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_base_event_record_refcount(data_collection_model_base_event_record_t *obj_base_event_record)
{
    if (!obj_base_event_record) return 0l;
    std::shared_ptr<BaseEventRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseEventRecord >*>(obj_base_event_record);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

