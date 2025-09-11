/**********************************************************************************************************************************
 * RadialVelocity - C interface to the RadialVelocity object
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

/*#include "RadialVelocity.h" already included by data-collection-sp/data-collection.h */
#include "RadialVelocity-internal.h"
#include "openapi/model/RadialVelocity.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_radial_velocity_t *data_collection_model_radial_velocity_create(


)
{
    return reinterpret_cast<data_collection_model_radial_velocity_t*>(new std::shared_ptr<RadialVelocity>(new RadialVelocity(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_radial_velocity_t *data_collection_model_radial_velocity_create_ref(const data_collection_model_radial_velocity_t *other)
{
    return reinterpret_cast<data_collection_model_radial_velocity_t*>(new std::shared_ptr<RadialVelocity>(*reinterpret_cast<const std::shared_ptr<RadialVelocity >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_radial_velocity_t *data_collection_model_radial_velocity_create_copy(const data_collection_model_radial_velocity_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<RadialVelocity > &obj = *reinterpret_cast<const std::shared_ptr<RadialVelocity >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_radial_velocity_t*>(new std::shared_ptr<RadialVelocity >(new RadialVelocity(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_radial_velocity_t *data_collection_model_radial_velocity_create_move(data_collection_model_radial_velocity_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<RadialVelocity > *obj = reinterpret_cast<std::shared_ptr<RadialVelocity >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_radial_velocity_t *data_collection_model_radial_velocity_copy(data_collection_model_radial_velocity_t *radial_velocity, const data_collection_model_radial_velocity_t *other)
{
    if (radial_velocity) {
        std::shared_ptr<RadialVelocity > &obj = *reinterpret_cast<std::shared_ptr<RadialVelocity >*>(radial_velocity);
        if (obj) {
            if (other) {
                const std::shared_ptr<RadialVelocity > &other_obj = *reinterpret_cast<const std::shared_ptr<RadialVelocity >*>(other);
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
                const std::shared_ptr<RadialVelocity > &other_obj = *reinterpret_cast<const std::shared_ptr<RadialVelocity >*>(other);
                if (other_obj) {
                    obj.reset(new RadialVelocity(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        radial_velocity = data_collection_model_radial_velocity_create_copy(other);
    }
    return radial_velocity;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_radial_velocity_t *data_collection_model_radial_velocity_move(data_collection_model_radial_velocity_t *radial_velocity, data_collection_model_radial_velocity_t *other)
{
    std::shared_ptr<RadialVelocity > *other_ptr = reinterpret_cast<std::shared_ptr<RadialVelocity >*>(other);

    if (radial_velocity) {
        std::shared_ptr<RadialVelocity > &obj = *reinterpret_cast<std::shared_ptr<RadialVelocity >*>(radial_velocity);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                radial_velocity = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return radial_velocity;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_radial_velocity_free(data_collection_model_radial_velocity_t *radial_velocity)
{
    if (!radial_velocity) return;
    delete reinterpret_cast<std::shared_ptr<RadialVelocity >*>(radial_velocity);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_radial_velocity_toJSON(const data_collection_model_radial_velocity_t *radial_velocity, bool as_request)
{
    if (!radial_velocity) return NULL;
    const std::shared_ptr<RadialVelocity > &obj = *reinterpret_cast<const std::shared_ptr<RadialVelocity >*>(radial_velocity);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_radial_velocity_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_radial_velocity_t *data_collection_model_radial_velocity_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_radial_velocity_t*>(new std::shared_ptr<RadialVelocity >(new RadialVelocity(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_radial_velocity_is_equal_to(const data_collection_model_radial_velocity_t *first, const data_collection_model_radial_velocity_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<RadialVelocity > &obj2 = *reinterpret_cast<const std::shared_ptr<RadialVelocity >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<RadialVelocity > &obj1 = *reinterpret_cast<const std::shared_ptr<RadialVelocity >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_units_linear_velocity_t* data_collection_model_radial_velocity_get_units_radial_velocity(const data_collection_model_radial_velocity_t *obj_radial_velocity)
{
    if (!obj_radial_velocity) {
        const data_collection_model_units_linear_velocity_t *result = NULL;
        return result;
    }

    const std::shared_ptr<RadialVelocity > &obj = *reinterpret_cast<const std::shared_ptr<RadialVelocity >*>(obj_radial_velocity);
    if (!obj) {
        const data_collection_model_units_linear_velocity_t *result = NULL;
        return result;
    }

    typedef typename RadialVelocity::UnitsRadialVelocityType ResultFromType;
    const ResultFromType &result_from = obj->getUnitsRadialVelocity();
    const data_collection_model_units_linear_velocity_t *result = reinterpret_cast<const data_collection_model_units_linear_velocity_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_radial_velocity_t *data_collection_model_radial_velocity_set_units_radial_velocity(data_collection_model_radial_velocity_t *obj_radial_velocity, const data_collection_model_units_linear_velocity_t* p_units_radial_velocity)
{
    if (!obj_radial_velocity) return NULL;

    std::shared_ptr<RadialVelocity > &obj = *reinterpret_cast<std::shared_ptr<RadialVelocity >*>(obj_radial_velocity);
    if (!obj) return NULL;

    const auto &value_from = p_units_radial_velocity;
    typedef typename RadialVelocity::UnitsRadialVelocityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setUnitsRadialVelocity(value)) return NULL;

    return obj_radial_velocity;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_radial_velocity_t *data_collection_model_radial_velocity_set_units_radial_velocity_move(data_collection_model_radial_velocity_t *obj_radial_velocity, data_collection_model_units_linear_velocity_t* p_units_radial_velocity)
{
    if (!obj_radial_velocity) return NULL;

    std::shared_ptr<RadialVelocity > &obj = *reinterpret_cast<std::shared_ptr<RadialVelocity >*>(obj_radial_velocity);
    if (!obj) return NULL;

    const auto &value_from = p_units_radial_velocity;
    typedef typename RadialVelocity::UnitsRadialVelocityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setUnitsRadialVelocity(std::move(value))) return NULL;
    data_collection_model_units_linear_velocity_free
(p_units_radial_velocity);

    return obj_radial_velocity;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_radial_velocity_get_radial_velocity(const data_collection_model_radial_velocity_t *obj_radial_velocity)
{
    if (!obj_radial_velocity) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<RadialVelocity > &obj = *reinterpret_cast<const std::shared_ptr<RadialVelocity >*>(obj_radial_velocity);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename RadialVelocity::RadialVelocityType ResultFromType;
    const ResultFromType &result_from = obj->getRadialVelocity();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_radial_velocity_t *data_collection_model_radial_velocity_set_radial_velocity(data_collection_model_radial_velocity_t *obj_radial_velocity, const int32_t p_radial_velocity)
{
    if (!obj_radial_velocity) return NULL;

    std::shared_ptr<RadialVelocity > &obj = *reinterpret_cast<std::shared_ptr<RadialVelocity >*>(obj_radial_velocity);
    if (!obj) return NULL;

    const auto &value_from = p_radial_velocity;
    typedef typename RadialVelocity::RadialVelocityType ValueType;

    ValueType value(value_from);

    if (!obj->setRadialVelocity(value)) return NULL;

    return obj_radial_velocity;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_radial_velocity_t *data_collection_model_radial_velocity_set_radial_velocity_move(data_collection_model_radial_velocity_t *obj_radial_velocity, int32_t p_radial_velocity)
{
    if (!obj_radial_velocity) return NULL;

    std::shared_ptr<RadialVelocity > &obj = *reinterpret_cast<std::shared_ptr<RadialVelocity >*>(obj_radial_velocity);
    if (!obj) return NULL;

    const auto &value_from = p_radial_velocity;
    typedef typename RadialVelocity::RadialVelocityType ValueType;

    ValueType value(value_from);

    if (!obj->setRadialVelocity(std::move(value))) return NULL;

    return obj_radial_velocity;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_radial_velocity_get_r_velocity_uncertainty(const data_collection_model_radial_velocity_t *obj_radial_velocity)
{
    if (!obj_radial_velocity) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<RadialVelocity > &obj = *reinterpret_cast<const std::shared_ptr<RadialVelocity >*>(obj_radial_velocity);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename RadialVelocity::RVelocityUncertaintyType ResultFromType;
    const ResultFromType &result_from = obj->getRVelocityUncertainty();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_radial_velocity_t *data_collection_model_radial_velocity_set_r_velocity_uncertainty(data_collection_model_radial_velocity_t *obj_radial_velocity, const int32_t p_r_velocity_uncertainty)
{
    if (!obj_radial_velocity) return NULL;

    std::shared_ptr<RadialVelocity > &obj = *reinterpret_cast<std::shared_ptr<RadialVelocity >*>(obj_radial_velocity);
    if (!obj) return NULL;

    const auto &value_from = p_r_velocity_uncertainty;
    typedef typename RadialVelocity::RVelocityUncertaintyType ValueType;

    ValueType value(value_from);

    if (!obj->setRVelocityUncertainty(value)) return NULL;

    return obj_radial_velocity;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_radial_velocity_t *data_collection_model_radial_velocity_set_r_velocity_uncertainty_move(data_collection_model_radial_velocity_t *obj_radial_velocity, int32_t p_r_velocity_uncertainty)
{
    if (!obj_radial_velocity) return NULL;

    std::shared_ptr<RadialVelocity > &obj = *reinterpret_cast<std::shared_ptr<RadialVelocity >*>(obj_radial_velocity);
    if (!obj) return NULL;

    const auto &value_from = p_r_velocity_uncertainty;
    typedef typename RadialVelocity::RVelocityUncertaintyType ValueType;

    ValueType value(value_from);

    if (!obj->setRVelocityUncertainty(std::move(value))) return NULL;

    return obj_radial_velocity;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_radial_velocity_make_lnode(data_collection_model_radial_velocity_t *p_radial_velocity)
{
    return data_collection_lnode_create(p_radial_velocity, reinterpret_cast<void(*)(void*)>(data_collection_model_radial_velocity_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_radial_velocity_refcount(data_collection_model_radial_velocity_t *obj_radial_velocity)
{
    if (!obj_radial_velocity) return 0l;
    std::shared_ptr<RadialVelocity > &obj = *reinterpret_cast<std::shared_ptr<RadialVelocity >*>(obj_radial_velocity);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

