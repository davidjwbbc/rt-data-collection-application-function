#ifndef _DATA_COLLECTION_POSITIONING_METHOD_ANY_OF_H_
#define _DATA_COLLECTION_POSITIONING_METHOD_ANY_OF_H_

/**********************************************************************************************************************************
 * PositioningMethod_anyOf - Public C interface to the PositioningMethod_anyOf object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_positioning_method_any_of_s data_collection_model_positioning_method_any_of_t;

typedef enum {
    DCM_POSITIONING_METHOD_ANY_OF_NO_VAL,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_CELLID,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_ECID,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_OTDOA,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_BAROMETRIC_PRESSURE,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_WLAN,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_BLUETOOTH,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_MBS,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_MOTION_SENSOR,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_DL_TDOA,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_DL_AOD,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_MULTI_RTT,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_NR_ECID,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_UL_TDOA,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_UL_AOA,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_NETWORK_SPECIFIC,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_TDOA,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_TOA,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_AO_A,
    DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_RT
} data_collection_model_positioning_method_any_of_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_create_copy(const data_collection_model_positioning_method_any_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_create_move(data_collection_model_positioning_method_any_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_copy(data_collection_model_positioning_method_any_of_t *positioning_method_any_of, const data_collection_model_positioning_method_any_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_move(data_collection_model_positioning_method_any_of_t *positioning_method_any_of, data_collection_model_positioning_method_any_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_positioning_method_any_of_free(data_collection_model_positioning_method_any_of_t *positioning_method_any_of);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_positioning_method_any_of_toJSON(const data_collection_model_positioning_method_any_of_t *positioning_method_any_of, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_any_of_is_equal_to(const data_collection_model_positioning_method_any_of_t *positioning_method_any_of, const data_collection_model_positioning_method_any_of_t *other_positioning_method_any_of);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_any_of_is_not_set(const data_collection_model_positioning_method_any_of_t *positioning_method_any_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_e data_collection_model_positioning_method_any_of_get_enum(const data_collection_model_positioning_method_any_of_t *positioning_method_any_of);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_positioning_method_any_of_get_string(const data_collection_model_positioning_method_any_of_t *positioning_method_any_of);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_any_of_set_enum(data_collection_model_positioning_method_any_of_t *positioning_method_any_of, data_collection_model_positioning_method_any_of_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_any_of_set_string(data_collection_model_positioning_method_any_of_t *positioning_method_any_of, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type PositioningMethod_anyOf */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_positioning_method_any_of_make_lnode(data_collection_model_positioning_method_any_of_t *positioning_method_any_of);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_POSITIONING_METHOD_ANY_OF_H_ */

