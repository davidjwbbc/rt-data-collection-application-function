/**********************************************************************************************************************************
 * UnitsLinearVelocity - C interface to the UnitsLinearVelocity object
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

/*#include "UnitsLinearVelocity.h" already included by data-collection-sp/data-collection.h */
#include "UnitsLinearVelocity-internal.h"
#include "openapi/model/UnitsLinearVelocity.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_units_linear_velocity_t *data_collection_model_units_linear_velocity_create()
{
    return reinterpret_cast<data_collection_model_units_linear_velocity_t*>(new std::shared_ptr<UnitsLinearVelocity>(new UnitsLinearVelocity()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_units_linear_velocity_t *data_collection_model_units_linear_velocity_create_ref(const data_collection_model_units_linear_velocity_t *other)
{
    return reinterpret_cast<data_collection_model_units_linear_velocity_t*>(new std::shared_ptr<UnitsLinearVelocity>(*reinterpret_cast<const std::shared_ptr<UnitsLinearVelocity >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_units_linear_velocity_t *data_collection_model_units_linear_velocity_create_copy(const data_collection_model_units_linear_velocity_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<UnitsLinearVelocity > &obj = *reinterpret_cast<const std::shared_ptr<UnitsLinearVelocity >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_units_linear_velocity_t*>(new std::shared_ptr<UnitsLinearVelocity >(new UnitsLinearVelocity(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_units_linear_velocity_t *data_collection_model_units_linear_velocity_create_move(data_collection_model_units_linear_velocity_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<UnitsLinearVelocity > *obj = reinterpret_cast<std::shared_ptr<UnitsLinearVelocity >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_units_linear_velocity_t *data_collection_model_units_linear_velocity_copy(data_collection_model_units_linear_velocity_t *units_linear_velocity, const data_collection_model_units_linear_velocity_t *other)
{
    if (units_linear_velocity) {
        std::shared_ptr<UnitsLinearVelocity > &obj = *reinterpret_cast<std::shared_ptr<UnitsLinearVelocity >*>(units_linear_velocity);
        if (obj) {
            if (other) {
                const std::shared_ptr<UnitsLinearVelocity > &other_obj = *reinterpret_cast<const std::shared_ptr<UnitsLinearVelocity >*>(other);
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
                const std::shared_ptr<UnitsLinearVelocity > &other_obj = *reinterpret_cast<const std::shared_ptr<UnitsLinearVelocity >*>(other);
                if (other_obj) {
                    obj.reset(new UnitsLinearVelocity(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        units_linear_velocity = data_collection_model_units_linear_velocity_create_copy(other);
    }
    return units_linear_velocity;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_units_linear_velocity_t *data_collection_model_units_linear_velocity_move(data_collection_model_units_linear_velocity_t *units_linear_velocity, data_collection_model_units_linear_velocity_t *other)
{
    std::shared_ptr<UnitsLinearVelocity > *other_ptr = reinterpret_cast<std::shared_ptr<UnitsLinearVelocity >*>(other);

    if (units_linear_velocity) {
        std::shared_ptr<UnitsLinearVelocity > &obj = *reinterpret_cast<std::shared_ptr<UnitsLinearVelocity >*>(units_linear_velocity);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                units_linear_velocity = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return units_linear_velocity;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_units_linear_velocity_free(data_collection_model_units_linear_velocity_t *units_linear_velocity)
{
    if (!units_linear_velocity) return;
    delete reinterpret_cast<std::shared_ptr<UnitsLinearVelocity >*>(units_linear_velocity);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_units_linear_velocity_toJSON(const data_collection_model_units_linear_velocity_t *units_linear_velocity, bool as_request)
{
    if (!units_linear_velocity) return NULL;
    const std::shared_ptr<UnitsLinearVelocity > &obj = *reinterpret_cast<const std::shared_ptr<UnitsLinearVelocity >*>(units_linear_velocity);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_units_linear_velocity_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_units_linear_velocity_t *data_collection_model_units_linear_velocity_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_units_linear_velocity_t*>(new std::shared_ptr<UnitsLinearVelocity >(new UnitsLinearVelocity(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_units_linear_velocity_is_equal_to(const data_collection_model_units_linear_velocity_t *first, const data_collection_model_units_linear_velocity_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<UnitsLinearVelocity > &obj2 = *reinterpret_cast<const std::shared_ptr<UnitsLinearVelocity >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<UnitsLinearVelocity > &obj1 = *reinterpret_cast<const std::shared_ptr<UnitsLinearVelocity >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_units_linear_velocity_is_not_set(const data_collection_model_units_linear_velocity_t *obj_units_linear_velocity)
{
    if (!obj_units_linear_velocity) return true;
    const std::shared_ptr<UnitsLinearVelocity > &obj = *reinterpret_cast<const std::shared_ptr<UnitsLinearVelocity >*>(obj_units_linear_velocity);
    if (!obj) return true;
    return obj->getValue() == UnitsLinearVelocity::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_units_linear_velocity_is_non_standard(const data_collection_model_units_linear_velocity_t *obj_units_linear_velocity)
{
    if (!obj_units_linear_velocity) return false;
    const std::shared_ptr<UnitsLinearVelocity > &obj = *reinterpret_cast<const std::shared_ptr<UnitsLinearVelocity >*>(obj_units_linear_velocity);
    if (!obj) return false;
    return obj->getValue() == UnitsLinearVelocity::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_units_linear_velocity_e data_collection_model_units_linear_velocity_get_enum(const data_collection_model_units_linear_velocity_t *obj_units_linear_velocity)
{
    if (!obj_units_linear_velocity)
        return DCM_UNITS_LINEAR_VELOCITY_NO_VAL;
    const std::shared_ptr<UnitsLinearVelocity > &obj = *reinterpret_cast<const std::shared_ptr<UnitsLinearVelocity >*>(obj_units_linear_velocity);
    if (!obj) return DCM_UNITS_LINEAR_VELOCITY_NO_VAL;
    switch (obj->getValue()) {
    case UnitsLinearVelocity::Enum::NO_VAL:
        return DCM_UNITS_LINEAR_VELOCITY_NO_VAL;
    case UnitsLinearVelocity::Enum::VAL_MPERS:
        return DCM_UNITS_LINEAR_VELOCITY_VAL_MPERS;
    case UnitsLinearVelocity::Enum::VAL_CMPERS:
        return DCM_UNITS_LINEAR_VELOCITY_VAL_CMPERS;
    default:
        break;
    }
    return DCM_UNITS_LINEAR_VELOCITY_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_units_linear_velocity_get_string(const data_collection_model_units_linear_velocity_t *obj_units_linear_velocity)
{
    if (!obj_units_linear_velocity) return NULL;
    const std::shared_ptr<UnitsLinearVelocity > &obj = *reinterpret_cast<const std::shared_ptr<UnitsLinearVelocity >*>(obj_units_linear_velocity);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_units_linear_velocity_set_enum(data_collection_model_units_linear_velocity_t *obj_units_linear_velocity, data_collection_model_units_linear_velocity_e p_value)
{
    if (!obj_units_linear_velocity) return false;
    std::shared_ptr<UnitsLinearVelocity > &obj = *reinterpret_cast<std::shared_ptr<UnitsLinearVelocity >*>(obj_units_linear_velocity);
    if (!obj) return false;
    switch (p_value) {
    case DCM_UNITS_LINEAR_VELOCITY_NO_VAL:
        *obj = UnitsLinearVelocity::Enum::NO_VAL;
        return true;
    case DCM_UNITS_LINEAR_VELOCITY_VAL_MPERS:
        *obj = UnitsLinearVelocity::Enum::VAL_MPERS;
        return true;
    case DCM_UNITS_LINEAR_VELOCITY_VAL_CMPERS:
        *obj = UnitsLinearVelocity::Enum::VAL_CMPERS;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_units_linear_velocity_set_string(data_collection_model_units_linear_velocity_t *obj_units_linear_velocity, const char *p_value)
{
    if (!obj_units_linear_velocity) return false;
    std::shared_ptr<UnitsLinearVelocity > &obj = *reinterpret_cast<std::shared_ptr<UnitsLinearVelocity >*>(obj_units_linear_velocity);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = UnitsLinearVelocity::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_units_linear_velocity_make_lnode(data_collection_model_units_linear_velocity_t *p_units_linear_velocity)
{
    return data_collection_lnode_create(p_units_linear_velocity, reinterpret_cast<void(*)(void*)>(data_collection_model_units_linear_velocity_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_units_linear_velocity_refcount(data_collection_model_units_linear_velocity_t *obj_units_linear_velocity)
{
    if (!obj_units_linear_velocity) return 0l;
    std::shared_ptr<UnitsLinearVelocity > &obj = *reinterpret_cast<std::shared_ptr<UnitsLinearVelocity >*>(obj_units_linear_velocity);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

