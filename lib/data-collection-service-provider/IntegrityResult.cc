/**********************************************************************************************************************************
 * IntegrityResult - C interface to the IntegrityResult object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "IntegrityResult.h" already included by data-collection-sp/data-collection.h */
#include "IntegrityResult-internal.h"
#include "openapi/model/IntegrityResult.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_result_t *data_collection_model_integrity_result_create(



)
{
    return reinterpret_cast<data_collection_model_integrity_result_t*>(new std::shared_ptr<IntegrityResult>(new IntegrityResult(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_result_t *data_collection_model_integrity_result_create_copy(const data_collection_model_integrity_result_t *other)
{
    return reinterpret_cast<data_collection_model_integrity_result_t*>(new std::shared_ptr<IntegrityResult >(new IntegrityResult(**reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_result_t *data_collection_model_integrity_result_create_move(data_collection_model_integrity_result_t *other)
{
    return reinterpret_cast<data_collection_model_integrity_result_t*>(new std::shared_ptr<IntegrityResult >(std::move(*reinterpret_cast<std::shared_ptr<IntegrityResult >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_result_t *data_collection_model_integrity_result_copy(data_collection_model_integrity_result_t *integrity_result, const data_collection_model_integrity_result_t *other)
{
    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(integrity_result);
    *obj = **reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(other);
    return integrity_result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_result_t *data_collection_model_integrity_result_move(data_collection_model_integrity_result_t *integrity_result, data_collection_model_integrity_result_t *other)
{
    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(integrity_result);
    obj = std::move(*reinterpret_cast<std::shared_ptr<IntegrityResult >*>(other));
    return integrity_result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_integrity_result_free(data_collection_model_integrity_result_t *integrity_result)
{
    delete reinterpret_cast<std::shared_ptr<IntegrityResult >*>(integrity_result);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_integrity_result_toJSON(const data_collection_model_integrity_result_t *integrity_result, bool as_request)
{
    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(integrity_result);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_result_t *data_collection_model_integrity_result_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_integrity_result_t*>(new std::shared_ptr<IntegrityResult >(new IntegrityResult(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_integrity_result_is_equal_to(const data_collection_model_integrity_result_t *first, const data_collection_model_integrity_result_t *second)
{
    const std::shared_ptr<IntegrityResult > &obj1 = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(first);
    const std::shared_ptr<IntegrityResult > &obj2 = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_integrity_computing_entity_t* data_collection_model_integrity_result_get_computing_entity(const data_collection_model_integrity_result_t *obj_integrity_result)
{
    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    typedef typename IntegrityResult::ComputingEntityType ResultFromType;
    const ResultFromType result_from = obj->getComputingEntity();
    const data_collection_model_integrity_computing_entity_t *result = reinterpret_cast<const data_collection_model_integrity_computing_entity_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_computing_entity(data_collection_model_integrity_result_t *obj_integrity_result, const data_collection_model_integrity_computing_entity_t* p_computing_entity)
{
    if (obj_integrity_result == NULL) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    const auto &value_from = p_computing_entity;
    typedef typename IntegrityResult::ComputingEntityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setComputingEntity(value)) return NULL;
    return obj_integrity_result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_computing_entity_move(data_collection_model_integrity_result_t *obj_integrity_result, data_collection_model_integrity_computing_entity_t* p_computing_entity)
{
    if (obj_integrity_result == NULL) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    const auto &value_from = p_computing_entity;
    typedef typename IntegrityResult::ComputingEntityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setComputingEntity(std::move(value))) return NULL;
    return obj_integrity_result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_integrity_protection_level_t* data_collection_model_integrity_result_get_protection_level(const data_collection_model_integrity_result_t *obj_integrity_result)
{
    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    typedef typename IntegrityResult::ProtectionLevelType ResultFromType;
    const ResultFromType result_from = obj->getProtectionLevel();
    const data_collection_model_integrity_protection_level_t *result = reinterpret_cast<const data_collection_model_integrity_protection_level_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_protection_level(data_collection_model_integrity_result_t *obj_integrity_result, const data_collection_model_integrity_protection_level_t* p_protection_level)
{
    if (obj_integrity_result == NULL) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    const auto &value_from = p_protection_level;
    typedef typename IntegrityResult::ProtectionLevelType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setProtectionLevel(value)) return NULL;
    return obj_integrity_result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_protection_level_move(data_collection_model_integrity_result_t *obj_integrity_result, data_collection_model_integrity_protection_level_t* p_protection_level)
{
    if (obj_integrity_result == NULL) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    const auto &value_from = p_protection_level;
    typedef typename IntegrityResult::ProtectionLevelType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setProtectionLevel(std::move(value))) return NULL;
    return obj_integrity_result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const bool data_collection_model_integrity_result_is_integrity_req_met_ind(const data_collection_model_integrity_result_t *obj_integrity_result)
{
    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    typedef typename IntegrityResult::IntegrityReqMetIndType ResultFromType;
    const ResultFromType result_from = obj->isIntegrityReqMetInd();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_integrity_req_met_ind(data_collection_model_integrity_result_t *obj_integrity_result, const bool p_integrity_req_met_ind)
{
    if (obj_integrity_result == NULL) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    const auto &value_from = p_integrity_req_met_ind;
    typedef typename IntegrityResult::IntegrityReqMetIndType ValueType;

    ValueType value = value_from;
    if (!obj->setIntegrityReqMetInd(value)) return NULL;
    return obj_integrity_result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_integrity_req_met_ind_move(data_collection_model_integrity_result_t *obj_integrity_result, bool p_integrity_req_met_ind)
{
    if (obj_integrity_result == NULL) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    const auto &value_from = p_integrity_req_met_ind;
    typedef typename IntegrityResult::IntegrityReqMetIndType ValueType;

    ValueType value = value_from;
    
    if (!obj->setIntegrityReqMetInd(std::move(value))) return NULL;
    return obj_integrity_result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_integrity_result_get_achieved_tir(const data_collection_model_integrity_result_t *obj_integrity_result)
{
    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    typedef typename IntegrityResult::AchievedTirType ResultFromType;
    const ResultFromType result_from = obj->getAchievedTir();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_achieved_tir(data_collection_model_integrity_result_t *obj_integrity_result, const int32_t p_achieved_tir)
{
    if (obj_integrity_result == NULL) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    const auto &value_from = p_achieved_tir;
    typedef typename IntegrityResult::AchievedTirType ValueType;

    ValueType value = value_from;
    if (!obj->setAchievedTir(value)) return NULL;
    return obj_integrity_result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_achieved_tir_move(data_collection_model_integrity_result_t *obj_integrity_result, int32_t p_achieved_tir)
{
    if (obj_integrity_result == NULL) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    const auto &value_from = p_achieved_tir;
    typedef typename IntegrityResult::AchievedTirType ValueType;

    ValueType value = value_from;
    
    if (!obj->setAchievedTir(std::move(value))) return NULL;
    return obj_integrity_result;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_integrity_result_make_lnode(data_collection_model_integrity_result_t *p_integrity_result)
{
    return data_collection_lnode_create(p_integrity_result, reinterpret_cast<void(*)(void*)>(data_collection_model_integrity_result_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_integrity_result_refcount(data_collection_model_integrity_result_t *obj_integrity_result)
{
    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

