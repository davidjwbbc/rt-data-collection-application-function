/**********************************************************************************************************************************
 * DataReportingConfiguration - C interface to the DataReportingConfiguration object
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

/*#include "DataReportingConfiguration.h" already included by data-collection-sp/data-collection.h */
#include "DataReportingConfiguration-internal.h"
#include "openapi/model/DataReportingConfiguration.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_create(






)
{
    return reinterpret_cast<data_collection_model_data_reporting_configuration_t*>(new std::shared_ptr<DataReportingConfiguration>(new DataReportingConfiguration(






)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_create_ref(const data_collection_model_data_reporting_configuration_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_configuration_t*>(new std::shared_ptr<DataReportingConfiguration>(*reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_create_copy(const data_collection_model_data_reporting_configuration_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_data_reporting_configuration_t*>(new std::shared_ptr<DataReportingConfiguration >(new DataReportingConfiguration(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_create_move(data_collection_model_data_reporting_configuration_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<DataReportingConfiguration > *obj = reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_copy(data_collection_model_data_reporting_configuration_t *data_reporting_configuration, const data_collection_model_data_reporting_configuration_t *other)
{
    if (data_reporting_configuration) {
        std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(data_reporting_configuration);
        if (obj) {
            if (other) {
                const std::shared_ptr<DataReportingConfiguration > &other_obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(other);
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
                const std::shared_ptr<DataReportingConfiguration > &other_obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(other);
                if (other_obj) {
                    obj.reset(new DataReportingConfiguration(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        data_reporting_configuration = data_collection_model_data_reporting_configuration_create_copy(other);
    }
    return data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_move(data_collection_model_data_reporting_configuration_t *data_reporting_configuration, data_collection_model_data_reporting_configuration_t *other)
{
    std::shared_ptr<DataReportingConfiguration > *other_ptr = reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(other);

    if (data_reporting_configuration) {
        std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(data_reporting_configuration);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                data_reporting_configuration = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_configuration_free(data_collection_model_data_reporting_configuration_t *data_reporting_configuration)
{
    if (!data_reporting_configuration) return;
    delete reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(data_reporting_configuration);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_configuration_toJSON(const data_collection_model_data_reporting_configuration_t *data_reporting_configuration, bool as_request)
{
    if (!data_reporting_configuration) return NULL;
    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(data_reporting_configuration);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_data_reporting_configuration_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_reporting_configuration_t*>(new std::shared_ptr<DataReportingConfiguration >(new DataReportingConfiguration(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_is_equal_to(const data_collection_model_data_reporting_configuration_t *first, const data_collection_model_data_reporting_configuration_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DataReportingConfiguration > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DataReportingConfiguration > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_has_data_reporting_configuration_id(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) return false;

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return false;

    return obj->getDataReportingConfigurationId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_configuration_get_data_reporting_configuration_id(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) {
        const char *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) {
        const char *result = NULL;

        return result;
    }

    typedef typename DataReportingConfiguration::DataReportingConfigurationIdType ResultFromType;
    const ResultFromType &result_from = obj->getDataReportingConfigurationId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_set_data_reporting_configuration_id(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, const char* p_data_reporting_configuration_id)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    const auto &value_from = p_data_reporting_configuration_id;
    typedef typename DataReportingConfiguration::DataReportingConfigurationIdType ValueType;

    ValueType value(value_from);


    if (!obj->setDataReportingConfigurationId(value)) return NULL;

    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_set_data_reporting_configuration_id_move(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, char* p_data_reporting_configuration_id)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    const auto &value_from = p_data_reporting_configuration_id;
    typedef typename DataReportingConfiguration::DataReportingConfigurationIdType ValueType;

    ValueType value(value_from);


    if (!obj->setDataReportingConfigurationId(std::move(value))) return NULL;
    ogs_free

(p_data_reporting_configuration_id);

    return obj_data_reporting_configuration;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_collection_client_type_t* data_collection_model_data_reporting_configuration_get_data_collection_client_type(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) {
        const data_collection_model_data_collection_client_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) {
        const data_collection_model_data_collection_client_type_t *result = NULL;
        return result;
    }

    typedef typename DataReportingConfiguration::DataCollectionClientTypeType ResultFromType;
    const ResultFromType &result_from = obj->getDataCollectionClientType();
    const data_collection_model_data_collection_client_type_t *result = reinterpret_cast<const data_collection_model_data_collection_client_type_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_set_data_collection_client_type(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, const data_collection_model_data_collection_client_type_t* p_data_collection_client_type)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    const auto &value_from = p_data_collection_client_type;
    typedef typename DataReportingConfiguration::DataCollectionClientTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setDataCollectionClientType(value)) return NULL;

    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_set_data_collection_client_type_move(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, data_collection_model_data_collection_client_type_t* p_data_collection_client_type)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    const auto &value_from = p_data_collection_client_type;
    typedef typename DataReportingConfiguration::DataCollectionClientTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setDataCollectionClientType(std::move(value))) return NULL;
    data_collection_model_data_collection_client_type_free
(p_data_collection_client_type);

    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_has_authorization_url(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) return false;

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return false;

    return obj->getAuthorizationURL().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_configuration_get_authorization_url(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DataReportingConfiguration::AuthorizationURLType ResultFromType;
    const ResultFromType &result_from = obj->getAuthorizationURL();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_set_authorization_url(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, const char* p_authorization_url)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    const auto &value_from = p_authorization_url;
    typedef typename DataReportingConfiguration::AuthorizationURLType ValueType;

    ValueType value(value_from);

    if (!obj->setAuthorizationURL(value)) return NULL;

    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_set_authorization_url_move(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, char* p_authorization_url)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    const auto &value_from = p_authorization_url;
    typedef typename DataReportingConfiguration::AuthorizationURLType ValueType;

    ValueType value(value_from);

    if (!obj->setAuthorizationURL(std::move(value))) return NULL;
    ogs_free
(p_authorization_url);

    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_has_data_sampling_rules(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) return false;

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return false;

    return obj->getDataSamplingRules().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_configuration_get_data_sampling_rules(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReportingConfiguration::DataSamplingRulesType ResultFromType;
    const ResultFromType &result_from = obj->getDataSamplingRules();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_data_sampling_rule_t *item_obj = reinterpret_cast<data_collection_model_data_sampling_rule_t*>(item.has_value()?new std::shared_ptr<DataSamplingRule >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_data_sampling_rule_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_set_data_sampling_rules(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, const ogs_list_t* p_data_sampling_rules)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    const auto &value_from = p_data_sampling_rules;
    typedef typename DataReportingConfiguration::DataSamplingRulesType ValueType;

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

    if (!obj->setDataSamplingRules(value)) return NULL;

    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_set_data_sampling_rules_move(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, ogs_list_t* p_data_sampling_rules)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    const auto &value_from = p_data_sampling_rules;
    typedef typename DataReportingConfiguration::DataSamplingRulesType ValueType;

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

    if (!obj->setDataSamplingRules(std::move(value))) return NULL;
    data_collection_list_free
(p_data_sampling_rules);

    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_add_data_sampling_rules(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, data_collection_model_data_sampling_rule_t* p_data_sampling_rules)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    typedef typename DataReportingConfiguration::DataSamplingRulesType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_data_sampling_rules;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_data_sampling_rule_free
(p_data_sampling_rules);
    if (value) obj->addDataSamplingRules(value.value());
    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_remove_data_sampling_rules(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, const data_collection_model_data_sampling_rule_t* p_data_sampling_rules)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    typedef typename DataReportingConfiguration::DataSamplingRulesType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_data_sampling_rules;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeDataSamplingRules(value);
    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_sampling_rule_t* data_collection_model_data_reporting_configuration_get_entry_data_sampling_rules(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, size_t idx)
{
    if (!obj_data_reporting_configuration) {
        const data_collection_model_data_sampling_rule_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) {
        const data_collection_model_data_sampling_rule_t *result = NULL;

        return result;
    }

    const DataReportingConfiguration::DataSamplingRulesType &container = obj->getDataSamplingRules();
    if (!container.has_value()) {
        const data_collection_model_data_sampling_rule_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_data_sampling_rule_t *result = NULL;

        return result;
    }
    typedef typename DataReportingConfiguration::DataSamplingRulesItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_data_sampling_rule_t *result = reinterpret_cast<const data_collection_model_data_sampling_rule_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_clear_data_sampling_rules(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    obj->clearDataSamplingRules();
    return obj_data_reporting_configuration;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_configuration_get_data_reporting_conditions(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReportingConfiguration::DataReportingConditionsType ResultFromType;
    const ResultFromType &result_from = obj->getDataReportingConditions();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_data_reporting_condition_t *item_obj = reinterpret_cast<data_collection_model_data_reporting_condition_t*>(item.has_value()?new std::shared_ptr<DataReportingCondition >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_data_reporting_condition_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_set_data_reporting_conditions(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, const ogs_list_t* p_data_reporting_conditions)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    const auto &value_from = p_data_reporting_conditions;
    typedef typename DataReportingConfiguration::DataReportingConditionsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setDataReportingConditions(value)) return NULL;

    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_set_data_reporting_conditions_move(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, ogs_list_t* p_data_reporting_conditions)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    const auto &value_from = p_data_reporting_conditions;
    typedef typename DataReportingConfiguration::DataReportingConditionsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setDataReportingConditions(std::move(value))) return NULL;
    data_collection_list_free
(p_data_reporting_conditions);

    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_add_data_reporting_conditions(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, data_collection_model_data_reporting_condition_t* p_data_reporting_conditions)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    typedef typename DataReportingConfiguration::DataReportingConditionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_data_reporting_conditions;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_data_reporting_condition_free
(p_data_reporting_conditions);
    obj->addDataReportingConditions(value);
    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_remove_data_reporting_conditions(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, const data_collection_model_data_reporting_condition_t* p_data_reporting_conditions)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    typedef typename DataReportingConfiguration::DataReportingConditionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_data_reporting_conditions;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeDataReportingConditions(value);
    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_condition_t* data_collection_model_data_reporting_configuration_get_entry_data_reporting_conditions(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, size_t idx)
{
    if (!obj_data_reporting_configuration) {
        const data_collection_model_data_reporting_condition_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) {
        const data_collection_model_data_reporting_condition_t *result = NULL;

        return result;
    }

    const DataReportingConfiguration::DataReportingConditionsType &container = obj->getDataReportingConditions();
    

    auto itr = container.cbegin();
    while (idx > 0 && itr != container.cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.cend()) {
        const data_collection_model_data_reporting_condition_t *result = NULL;

        return result;
    }
    typedef typename DataReportingConfiguration::DataReportingConditionsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_data_reporting_condition_t *result = reinterpret_cast<const data_collection_model_data_reporting_condition_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_clear_data_reporting_conditions(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    obj->clearDataReportingConditions();
    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_has_data_reporting_rules(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) return false;

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return false;

    return obj->getDataReportingRules().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_configuration_get_data_reporting_rules(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReportingConfiguration::DataReportingRulesType ResultFromType;
    const ResultFromType &result_from = obj->getDataReportingRules();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_data_reporting_rule_t *item_obj = reinterpret_cast<data_collection_model_data_reporting_rule_t*>(item.has_value()?new std::shared_ptr<DataReportingRule >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_data_reporting_rule_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_set_data_reporting_rules(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, const ogs_list_t* p_data_reporting_rules)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    const auto &value_from = p_data_reporting_rules;
    typedef typename DataReportingConfiguration::DataReportingRulesType ValueType;

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

    if (!obj->setDataReportingRules(value)) return NULL;

    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_set_data_reporting_rules_move(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, ogs_list_t* p_data_reporting_rules)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    const auto &value_from = p_data_reporting_rules;
    typedef typename DataReportingConfiguration::DataReportingRulesType ValueType;

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

    if (!obj->setDataReportingRules(std::move(value))) return NULL;
    data_collection_list_free
(p_data_reporting_rules);

    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_add_data_reporting_rules(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, data_collection_model_data_reporting_rule_t* p_data_reporting_rules)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    typedef typename DataReportingConfiguration::DataReportingRulesType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_data_reporting_rules;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_data_reporting_rule_free
(p_data_reporting_rules);
    if (value) obj->addDataReportingRules(value.value());
    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_remove_data_reporting_rules(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, const data_collection_model_data_reporting_rule_t* p_data_reporting_rules)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    typedef typename DataReportingConfiguration::DataReportingRulesType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_data_reporting_rules;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeDataReportingRules(value);
    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_rule_t* data_collection_model_data_reporting_configuration_get_entry_data_reporting_rules(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, size_t idx)
{
    if (!obj_data_reporting_configuration) {
        const data_collection_model_data_reporting_rule_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) {
        const data_collection_model_data_reporting_rule_t *result = NULL;

        return result;
    }

    const DataReportingConfiguration::DataReportingRulesType &container = obj->getDataReportingRules();
    if (!container.has_value()) {
        const data_collection_model_data_reporting_rule_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_data_reporting_rule_t *result = NULL;

        return result;
    }
    typedef typename DataReportingConfiguration::DataReportingRulesItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_data_reporting_rule_t *result = reinterpret_cast<const data_collection_model_data_reporting_rule_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_clear_data_reporting_rules(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    obj->clearDataReportingRules();
    return obj_data_reporting_configuration;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_configuration_get_data_access_profiles(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReportingConfiguration::DataAccessProfilesType ResultFromType;
    const ResultFromType &result_from = obj->getDataAccessProfiles();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_data_access_profile_t *item_obj = reinterpret_cast<data_collection_model_data_access_profile_t*>(item.has_value()?new std::shared_ptr<DataAccessProfile >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_data_access_profile_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_set_data_access_profiles(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, const ogs_list_t* p_data_access_profiles)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    const auto &value_from = p_data_access_profiles;
    typedef typename DataReportingConfiguration::DataAccessProfilesType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setDataAccessProfiles(value)) return NULL;

    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_set_data_access_profiles_move(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, ogs_list_t* p_data_access_profiles)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    const auto &value_from = p_data_access_profiles;
    typedef typename DataReportingConfiguration::DataAccessProfilesType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setDataAccessProfiles(std::move(value))) return NULL;
    data_collection_list_free
(p_data_access_profiles);

    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_add_data_access_profiles(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, data_collection_model_data_access_profile_t* p_data_access_profiles)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    typedef typename DataReportingConfiguration::DataAccessProfilesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_data_access_profiles;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_data_access_profile_free
(p_data_access_profiles);
    obj->addDataAccessProfiles(value);
    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_remove_data_access_profiles(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, const data_collection_model_data_access_profile_t* p_data_access_profiles)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    typedef typename DataReportingConfiguration::DataAccessProfilesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_data_access_profiles;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeDataAccessProfiles(value);
    return obj_data_reporting_configuration;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_access_profile_t* data_collection_model_data_reporting_configuration_get_entry_data_access_profiles(const data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration, size_t idx)
{
    if (!obj_data_reporting_configuration) {
        const data_collection_model_data_access_profile_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) {
        const data_collection_model_data_access_profile_t *result = NULL;

        return result;
    }

    const DataReportingConfiguration::DataAccessProfilesType &container = obj->getDataAccessProfiles();
    

    auto itr = container.cbegin();
    while (idx > 0 && itr != container.cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.cend()) {
        const data_collection_model_data_access_profile_t *result = NULL;

        return result;
    }
    typedef typename DataReportingConfiguration::DataAccessProfilesItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_data_access_profile_t *result = reinterpret_cast<const data_collection_model_data_access_profile_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_t *data_collection_model_data_reporting_configuration_clear_data_access_profiles(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) return NULL;

    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    if (!obj) return NULL;

    obj->clearDataAccessProfiles();
    return obj_data_reporting_configuration;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_configuration_make_lnode(data_collection_model_data_reporting_configuration_t *p_data_reporting_configuration)
{
    return data_collection_lnode_create(p_data_reporting_configuration, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_configuration_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_reporting_configuration_refcount(data_collection_model_data_reporting_configuration_t *obj_data_reporting_configuration)
{
    if (!obj_data_reporting_configuration) return 0l;
    std::shared_ptr<DataReportingConfiguration > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfiguration >*>(obj_data_reporting_configuration);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

