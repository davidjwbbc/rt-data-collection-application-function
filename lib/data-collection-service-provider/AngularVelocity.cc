/**********************************************************************************************************************************
 * AngularVelocity - C interface to the AngularVelocity object
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

/*#include "AngularVelocity.h" already included by data-collection-sp/data-collection.h */
#include "AngularVelocity-internal.h"
#include "openapi/model/AngularVelocity.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_create(


)
{
    return reinterpret_cast<data_collection_model_angular_velocity_t*>(new std::shared_ptr<AngularVelocity>(new AngularVelocity(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_create_ref(const data_collection_model_angular_velocity_t *other)
{
    return reinterpret_cast<data_collection_model_angular_velocity_t*>(new std::shared_ptr<AngularVelocity>(*reinterpret_cast<const std::shared_ptr<AngularVelocity >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_create_copy(const data_collection_model_angular_velocity_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<AngularVelocity > &obj = *reinterpret_cast<const std::shared_ptr<AngularVelocity >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_angular_velocity_t*>(new std::shared_ptr<AngularVelocity >(new AngularVelocity(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_create_move(data_collection_model_angular_velocity_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<AngularVelocity > *obj = reinterpret_cast<std::shared_ptr<AngularVelocity >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_copy(data_collection_model_angular_velocity_t *angular_velocity, const data_collection_model_angular_velocity_t *other)
{
    if (angular_velocity) {
        std::shared_ptr<AngularVelocity > &obj = *reinterpret_cast<std::shared_ptr<AngularVelocity >*>(angular_velocity);
        if (obj) {
            if (other) {
                const std::shared_ptr<AngularVelocity > &other_obj = *reinterpret_cast<const std::shared_ptr<AngularVelocity >*>(other);
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
                const std::shared_ptr<AngularVelocity > &other_obj = *reinterpret_cast<const std::shared_ptr<AngularVelocity >*>(other);
                if (other_obj) {
                    obj.reset(new AngularVelocity(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        angular_velocity = data_collection_model_angular_velocity_create_copy(other);
    }
    return angular_velocity;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_move(data_collection_model_angular_velocity_t *angular_velocity, data_collection_model_angular_velocity_t *other)
{
    std::shared_ptr<AngularVelocity > *other_ptr = reinterpret_cast<std::shared_ptr<AngularVelocity >*>(other);

    if (angular_velocity) {
        std::shared_ptr<AngularVelocity > &obj = *reinterpret_cast<std::shared_ptr<AngularVelocity >*>(angular_velocity);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                angular_velocity = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return angular_velocity;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_angular_velocity_free(data_collection_model_angular_velocity_t *angular_velocity)
{
    if (!angular_velocity) return;
    delete reinterpret_cast<std::shared_ptr<AngularVelocity >*>(angular_velocity);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_angular_velocity_toJSON(const data_collection_model_angular_velocity_t *angular_velocity, bool as_request)
{
    if (!angular_velocity) return NULL;
    const std::shared_ptr<AngularVelocity > &obj = *reinterpret_cast<const std::shared_ptr<AngularVelocity >*>(angular_velocity);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_angular_velocity_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_angular_velocity_t*>(new std::shared_ptr<AngularVelocity >(new AngularVelocity(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_angular_velocity_is_equal_to(const data_collection_model_angular_velocity_t *first, const data_collection_model_angular_velocity_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<AngularVelocity > &obj2 = *reinterpret_cast<const std::shared_ptr<AngularVelocity >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<AngularVelocity > &obj1 = *reinterpret_cast<const std::shared_ptr<AngularVelocity >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_units_angular_velocity_t* data_collection_model_angular_velocity_get_units_angular_velocity(const data_collection_model_angular_velocity_t *obj_angular_velocity)
{
    if (!obj_angular_velocity) {
        const data_collection_model_units_angular_velocity_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AngularVelocity > &obj = *reinterpret_cast<const std::shared_ptr<AngularVelocity >*>(obj_angular_velocity);
    if (!obj) {
        const data_collection_model_units_angular_velocity_t *result = NULL;
        return result;
    }

    typedef typename AngularVelocity::UnitsAngularVelocityType ResultFromType;
    const ResultFromType &result_from = obj->getUnitsAngularVelocity();
    const data_collection_model_units_angular_velocity_t *result = reinterpret_cast<const data_collection_model_units_angular_velocity_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_set_units_angular_velocity(data_collection_model_angular_velocity_t *obj_angular_velocity, const data_collection_model_units_angular_velocity_t* p_units_angular_velocity)
{
    if (!obj_angular_velocity) return NULL;

    std::shared_ptr<AngularVelocity > &obj = *reinterpret_cast<std::shared_ptr<AngularVelocity >*>(obj_angular_velocity);
    if (!obj) return NULL;

    const auto &value_from = p_units_angular_velocity;
    typedef typename AngularVelocity::UnitsAngularVelocityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setUnitsAngularVelocity(value)) return NULL;

    return obj_angular_velocity;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_set_units_angular_velocity_move(data_collection_model_angular_velocity_t *obj_angular_velocity, data_collection_model_units_angular_velocity_t* p_units_angular_velocity)
{
    if (!obj_angular_velocity) return NULL;

    std::shared_ptr<AngularVelocity > &obj = *reinterpret_cast<std::shared_ptr<AngularVelocity >*>(obj_angular_velocity);
    if (!obj) return NULL;

    const auto &value_from = p_units_angular_velocity;
    typedef typename AngularVelocity::UnitsAngularVelocityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setUnitsAngularVelocity(std::move(value))) return NULL;
    data_collection_model_units_angular_velocity_free
(p_units_angular_velocity);

    return obj_angular_velocity;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_angular_velocity_get_angular_velocity(const data_collection_model_angular_velocity_t *obj_angular_velocity)
{
    if (!obj_angular_velocity) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<AngularVelocity > &obj = *reinterpret_cast<const std::shared_ptr<AngularVelocity >*>(obj_angular_velocity);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename AngularVelocity::AngularVelocityType ResultFromType;
    const ResultFromType &result_from = obj->getAngularVelocity();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_set_angular_velocity(data_collection_model_angular_velocity_t *obj_angular_velocity, const int32_t p_angular_velocity)
{
    if (!obj_angular_velocity) return NULL;

    std::shared_ptr<AngularVelocity > &obj = *reinterpret_cast<std::shared_ptr<AngularVelocity >*>(obj_angular_velocity);
    if (!obj) return NULL;

    const auto &value_from = p_angular_velocity;
    typedef typename AngularVelocity::AngularVelocityType ValueType;

    ValueType value(value_from);

    if (!obj->setAngularVelocity(value)) return NULL;

    return obj_angular_velocity;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_set_angular_velocity_move(data_collection_model_angular_velocity_t *obj_angular_velocity, int32_t p_angular_velocity)
{
    if (!obj_angular_velocity) return NULL;

    std::shared_ptr<AngularVelocity > &obj = *reinterpret_cast<std::shared_ptr<AngularVelocity >*>(obj_angular_velocity);
    if (!obj) return NULL;

    const auto &value_from = p_angular_velocity;
    typedef typename AngularVelocity::AngularVelocityType ValueType;

    ValueType value(value_from);

    if (!obj->setAngularVelocity(std::move(value))) return NULL;

    return obj_angular_velocity;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_angular_velocity_get_a_velocity_uncertainty(const data_collection_model_angular_velocity_t *obj_angular_velocity)
{
    if (!obj_angular_velocity) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<AngularVelocity > &obj = *reinterpret_cast<const std::shared_ptr<AngularVelocity >*>(obj_angular_velocity);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename AngularVelocity::AVelocityUncertaintyType ResultFromType;
    const ResultFromType &result_from = obj->getAVelocityUncertainty();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_set_a_velocity_uncertainty(data_collection_model_angular_velocity_t *obj_angular_velocity, const int32_t p_a_velocity_uncertainty)
{
    if (!obj_angular_velocity) return NULL;

    std::shared_ptr<AngularVelocity > &obj = *reinterpret_cast<std::shared_ptr<AngularVelocity >*>(obj_angular_velocity);
    if (!obj) return NULL;

    const auto &value_from = p_a_velocity_uncertainty;
    typedef typename AngularVelocity::AVelocityUncertaintyType ValueType;

    ValueType value(value_from);

    if (!obj->setAVelocityUncertainty(value)) return NULL;

    return obj_angular_velocity;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_set_a_velocity_uncertainty_move(data_collection_model_angular_velocity_t *obj_angular_velocity, int32_t p_a_velocity_uncertainty)
{
    if (!obj_angular_velocity) return NULL;

    std::shared_ptr<AngularVelocity > &obj = *reinterpret_cast<std::shared_ptr<AngularVelocity >*>(obj_angular_velocity);
    if (!obj) return NULL;

    const auto &value_from = p_a_velocity_uncertainty;
    typedef typename AngularVelocity::AVelocityUncertaintyType ValueType;

    ValueType value(value_from);

    if (!obj->setAVelocityUncertainty(std::move(value))) return NULL;

    return obj_angular_velocity;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_angular_velocity_make_lnode(data_collection_model_angular_velocity_t *p_angular_velocity)
{
    return data_collection_lnode_create(p_angular_velocity, reinterpret_cast<void(*)(void*)>(data_collection_model_angular_velocity_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_angular_velocity_refcount(data_collection_model_angular_velocity_t *obj_angular_velocity)
{
    if (!obj_angular_velocity) return 0l;
    std::shared_ptr<AngularVelocity > &obj = *reinterpret_cast<std::shared_ptr<AngularVelocity >*>(obj_angular_velocity);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

