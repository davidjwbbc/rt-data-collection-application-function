/**********************************************************************************************************************************
 * RelativeVelocityWithUncertainty - C interface to the RelativeVelocityWithUncertainty object
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

/*#include "RelativeVelocityWithUncertainty.h" already included by data-collection-sp/data-collection.h */
#include "RelativeVelocityWithUncertainty-internal.h"
#include "openapi/model/RelativeVelocityWithUncertainty.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_create(


)
{
    return reinterpret_cast<data_collection_model_relative_velocity_with_uncertainty_t*>(new std::shared_ptr<RelativeVelocityWithUncertainty>(new RelativeVelocityWithUncertainty(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_create_ref(const data_collection_model_relative_velocity_with_uncertainty_t *other)
{
    return reinterpret_cast<data_collection_model_relative_velocity_with_uncertainty_t*>(new std::shared_ptr<RelativeVelocityWithUncertainty>(*reinterpret_cast<const std::shared_ptr<RelativeVelocityWithUncertainty >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_create_copy(const data_collection_model_relative_velocity_with_uncertainty_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<RelativeVelocityWithUncertainty >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_relative_velocity_with_uncertainty_t*>(new std::shared_ptr<RelativeVelocityWithUncertainty >(new RelativeVelocityWithUncertainty(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_create_move(data_collection_model_relative_velocity_with_uncertainty_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<RelativeVelocityWithUncertainty > *obj = reinterpret_cast<std::shared_ptr<RelativeVelocityWithUncertainty >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_copy(data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty, const data_collection_model_relative_velocity_with_uncertainty_t *other)
{
    if (relative_velocity_with_uncertainty) {
        std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<RelativeVelocityWithUncertainty >*>(relative_velocity_with_uncertainty);
        if (obj) {
            if (other) {
                const std::shared_ptr<RelativeVelocityWithUncertainty > &other_obj = *reinterpret_cast<const std::shared_ptr<RelativeVelocityWithUncertainty >*>(other);
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
                const std::shared_ptr<RelativeVelocityWithUncertainty > &other_obj = *reinterpret_cast<const std::shared_ptr<RelativeVelocityWithUncertainty >*>(other);
                if (other_obj) {
                    obj.reset(new RelativeVelocityWithUncertainty(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        relative_velocity_with_uncertainty = data_collection_model_relative_velocity_with_uncertainty_create_copy(other);
    }
    return relative_velocity_with_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_move(data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty, data_collection_model_relative_velocity_with_uncertainty_t *other)
{
    std::shared_ptr<RelativeVelocityWithUncertainty > *other_ptr = reinterpret_cast<std::shared_ptr<RelativeVelocityWithUncertainty >*>(other);

    if (relative_velocity_with_uncertainty) {
        std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<RelativeVelocityWithUncertainty >*>(relative_velocity_with_uncertainty);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                relative_velocity_with_uncertainty = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return relative_velocity_with_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_relative_velocity_with_uncertainty_free(data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty)
{
    if (!relative_velocity_with_uncertainty) return;
    delete reinterpret_cast<std::shared_ptr<RelativeVelocityWithUncertainty >*>(relative_velocity_with_uncertainty);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_relative_velocity_with_uncertainty_toJSON(const data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty, bool as_request)
{
    if (!relative_velocity_with_uncertainty) return NULL;
    const std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<RelativeVelocityWithUncertainty >*>(relative_velocity_with_uncertainty);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_relative_velocity_with_uncertainty_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_relative_velocity_with_uncertainty_t*>(new std::shared_ptr<RelativeVelocityWithUncertainty >(new RelativeVelocityWithUncertainty(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_velocity_with_uncertainty_is_equal_to(const data_collection_model_relative_velocity_with_uncertainty_t *first, const data_collection_model_relative_velocity_with_uncertainty_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<RelativeVelocityWithUncertainty > &obj2 = *reinterpret_cast<const std::shared_ptr<RelativeVelocityWithUncertainty >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<RelativeVelocityWithUncertainty > &obj1 = *reinterpret_cast<const std::shared_ptr<RelativeVelocityWithUncertainty >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_velocity_with_uncertainty_has_r_velocity(const data_collection_model_relative_velocity_with_uncertainty_t *obj_relative_velocity_with_uncertainty)
{
    if (!obj_relative_velocity_with_uncertainty) return false;

    const std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<RelativeVelocityWithUncertainty >*>(obj_relative_velocity_with_uncertainty);
    if (!obj) return false;

    return obj->getRVelocity().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_radial_velocity_t* data_collection_model_relative_velocity_with_uncertainty_get_r_velocity(const data_collection_model_relative_velocity_with_uncertainty_t *obj_relative_velocity_with_uncertainty)
{
    if (!obj_relative_velocity_with_uncertainty) {
        const data_collection_model_radial_velocity_t *result = NULL;
        return result;
    }

    const std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<RelativeVelocityWithUncertainty >*>(obj_relative_velocity_with_uncertainty);
    if (!obj) {
        const data_collection_model_radial_velocity_t *result = NULL;
        return result;
    }

    typedef typename RelativeVelocityWithUncertainty::RVelocityType ResultFromType;
    const ResultFromType &result_from = obj->getRVelocity();
    const data_collection_model_radial_velocity_t *result = reinterpret_cast<const data_collection_model_radial_velocity_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_set_r_velocity(data_collection_model_relative_velocity_with_uncertainty_t *obj_relative_velocity_with_uncertainty, const data_collection_model_radial_velocity_t* p_r_velocity)
{
    if (!obj_relative_velocity_with_uncertainty) return NULL;

    std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<RelativeVelocityWithUncertainty >*>(obj_relative_velocity_with_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_r_velocity;
    typedef typename RelativeVelocityWithUncertainty::RVelocityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRVelocity(value)) return NULL;

    return obj_relative_velocity_with_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_set_r_velocity_move(data_collection_model_relative_velocity_with_uncertainty_t *obj_relative_velocity_with_uncertainty, data_collection_model_radial_velocity_t* p_r_velocity)
{
    if (!obj_relative_velocity_with_uncertainty) return NULL;

    std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<RelativeVelocityWithUncertainty >*>(obj_relative_velocity_with_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_r_velocity;
    typedef typename RelativeVelocityWithUncertainty::RVelocityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRVelocity(std::move(value))) return NULL;
    data_collection_model_radial_velocity_free
(p_r_velocity);

    return obj_relative_velocity_with_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_velocity_with_uncertainty_has_a_transverse_velocity(const data_collection_model_relative_velocity_with_uncertainty_t *obj_relative_velocity_with_uncertainty)
{
    if (!obj_relative_velocity_with_uncertainty) return false;

    const std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<RelativeVelocityWithUncertainty >*>(obj_relative_velocity_with_uncertainty);
    if (!obj) return false;

    return obj->getATransverseVelocity().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_angular_velocity_t* data_collection_model_relative_velocity_with_uncertainty_get_a_transverse_velocity(const data_collection_model_relative_velocity_with_uncertainty_t *obj_relative_velocity_with_uncertainty)
{
    if (!obj_relative_velocity_with_uncertainty) {
        const data_collection_model_angular_velocity_t *result = NULL;
        return result;
    }

    const std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<RelativeVelocityWithUncertainty >*>(obj_relative_velocity_with_uncertainty);
    if (!obj) {
        const data_collection_model_angular_velocity_t *result = NULL;
        return result;
    }

    typedef typename RelativeVelocityWithUncertainty::ATransverseVelocityType ResultFromType;
    const ResultFromType &result_from = obj->getATransverseVelocity();
    const data_collection_model_angular_velocity_t *result = reinterpret_cast<const data_collection_model_angular_velocity_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_set_a_transverse_velocity(data_collection_model_relative_velocity_with_uncertainty_t *obj_relative_velocity_with_uncertainty, const data_collection_model_angular_velocity_t* p_a_transverse_velocity)
{
    if (!obj_relative_velocity_with_uncertainty) return NULL;

    std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<RelativeVelocityWithUncertainty >*>(obj_relative_velocity_with_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_a_transverse_velocity;
    typedef typename RelativeVelocityWithUncertainty::ATransverseVelocityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setATransverseVelocity(value)) return NULL;

    return obj_relative_velocity_with_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_set_a_transverse_velocity_move(data_collection_model_relative_velocity_with_uncertainty_t *obj_relative_velocity_with_uncertainty, data_collection_model_angular_velocity_t* p_a_transverse_velocity)
{
    if (!obj_relative_velocity_with_uncertainty) return NULL;

    std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<RelativeVelocityWithUncertainty >*>(obj_relative_velocity_with_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_a_transverse_velocity;
    typedef typename RelativeVelocityWithUncertainty::ATransverseVelocityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setATransverseVelocity(std::move(value))) return NULL;
    data_collection_model_angular_velocity_free
(p_a_transverse_velocity);

    return obj_relative_velocity_with_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_velocity_with_uncertainty_has_e_transverse_velocity(const data_collection_model_relative_velocity_with_uncertainty_t *obj_relative_velocity_with_uncertainty)
{
    if (!obj_relative_velocity_with_uncertainty) return false;

    const std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<RelativeVelocityWithUncertainty >*>(obj_relative_velocity_with_uncertainty);
    if (!obj) return false;

    return obj->getETransverseVelocity().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_angular_velocity_t* data_collection_model_relative_velocity_with_uncertainty_get_e_transverse_velocity(const data_collection_model_relative_velocity_with_uncertainty_t *obj_relative_velocity_with_uncertainty)
{
    if (!obj_relative_velocity_with_uncertainty) {
        const data_collection_model_angular_velocity_t *result = NULL;
        return result;
    }

    const std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<RelativeVelocityWithUncertainty >*>(obj_relative_velocity_with_uncertainty);
    if (!obj) {
        const data_collection_model_angular_velocity_t *result = NULL;
        return result;
    }

    typedef typename RelativeVelocityWithUncertainty::ETransverseVelocityType ResultFromType;
    const ResultFromType &result_from = obj->getETransverseVelocity();
    const data_collection_model_angular_velocity_t *result = reinterpret_cast<const data_collection_model_angular_velocity_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_set_e_transverse_velocity(data_collection_model_relative_velocity_with_uncertainty_t *obj_relative_velocity_with_uncertainty, const data_collection_model_angular_velocity_t* p_e_transverse_velocity)
{
    if (!obj_relative_velocity_with_uncertainty) return NULL;

    std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<RelativeVelocityWithUncertainty >*>(obj_relative_velocity_with_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_e_transverse_velocity;
    typedef typename RelativeVelocityWithUncertainty::ETransverseVelocityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setETransverseVelocity(value)) return NULL;

    return obj_relative_velocity_with_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_set_e_transverse_velocity_move(data_collection_model_relative_velocity_with_uncertainty_t *obj_relative_velocity_with_uncertainty, data_collection_model_angular_velocity_t* p_e_transverse_velocity)
{
    if (!obj_relative_velocity_with_uncertainty) return NULL;

    std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<RelativeVelocityWithUncertainty >*>(obj_relative_velocity_with_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_e_transverse_velocity;
    typedef typename RelativeVelocityWithUncertainty::ETransverseVelocityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setETransverseVelocity(std::move(value))) return NULL;
    data_collection_model_angular_velocity_free
(p_e_transverse_velocity);

    return obj_relative_velocity_with_uncertainty;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_relative_velocity_with_uncertainty_make_lnode(data_collection_model_relative_velocity_with_uncertainty_t *p_relative_velocity_with_uncertainty)
{
    return data_collection_lnode_create(p_relative_velocity_with_uncertainty, reinterpret_cast<void(*)(void*)>(data_collection_model_relative_velocity_with_uncertainty_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_relative_velocity_with_uncertainty_refcount(data_collection_model_relative_velocity_with_uncertainty_t *obj_relative_velocity_with_uncertainty)
{
    if (!obj_relative_velocity_with_uncertainty) return 0l;
    std::shared_ptr<RelativeVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<RelativeVelocityWithUncertainty >*>(obj_relative_velocity_with_uncertainty);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

