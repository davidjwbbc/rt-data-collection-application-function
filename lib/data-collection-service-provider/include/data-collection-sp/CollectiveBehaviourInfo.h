#ifndef _DATA_COLLECTION_COLLECTIVE_BEHAVIOUR_INFO_H_
#define _DATA_COLLECTION_COLLECTIVE_BEHAVIOUR_INFO_H_

/**********************************************************************************************************************************
 * CollectiveBehaviourInfo - Public C interface to the CollectiveBehaviourInfo object
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

#include "Direction.h"
#include "PerUeAttribute.h"
#include "RelativeDirection.h"
#include "UeTrajectoryCollection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_collective_behaviour_info_s data_collection_model_collective_behaviour_info_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_create_copy(const data_collection_model_collective_behaviour_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_create_move(data_collection_model_collective_behaviour_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_copy(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const data_collection_model_collective_behaviour_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, data_collection_model_collective_behaviour_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_collective_behaviour_info_free(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_collective_behaviour_info_toJSON(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_is_equal_to(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const data_collection_model_collective_behaviour_info_t *other_collective_behaviour_info);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_col_attrib(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_col_attrib(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_col_attrib(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const ogs_list_t* p_col_attrib);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_col_attrib_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, ogs_list_t* p_col_attrib);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_col_attrib(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, data_collection_model_per_ue_attribute_t* col_attrib);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_col_attrib(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const data_collection_model_per_ue_attribute_t* col_attrib);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_per_ue_attribute_t* data_collection_model_collective_behaviour_info_get_entry_col_attrib(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_col_attrib(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_no_of_ues(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_collective_behaviour_info_get_no_of_ues(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_no_of_ues(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const int32_t p_no_of_ues);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_no_of_ues_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, int32_t p_no_of_ues);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_app_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_app_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_app_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const ogs_list_t* p_app_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_app_ids_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, ogs_list_t* p_app_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_app_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, char* app_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_app_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const char* app_ids);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_collective_behaviour_info_get_entry_app_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_app_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_ext_ue_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_ext_ue_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ext_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const ogs_list_t* p_ext_ue_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ext_ue_ids_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, ogs_list_t* p_ext_ue_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_ext_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, char* ext_ue_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_ext_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const char* ext_ue_ids);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_collective_behaviour_info_get_entry_ext_ue_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_ext_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_ue_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_ue_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const ogs_list_t* p_ue_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_ids_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, ogs_list_t* p_ue_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, char* ue_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const char* ue_ids);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_collective_behaviour_info_get_entry_ue_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_collision_dist(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_collective_behaviour_info_get_collision_dist(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_collision_dist(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const int32_t p_collision_dist);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_collision_dist_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, int32_t p_collision_dist);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_abs_dirs(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_abs_dirs(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_abs_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const ogs_list_t* p_abs_dirs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_abs_dirs_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, ogs_list_t* p_abs_dirs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_abs_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, data_collection_model_direction_t* abs_dirs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_abs_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const data_collection_model_direction_t* abs_dirs);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_direction_t* data_collection_model_collective_behaviour_info_get_entry_abs_dirs(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_abs_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_rel_dirs(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_rel_dirs(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_rel_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const ogs_list_t* p_rel_dirs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_rel_dirs_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, ogs_list_t* p_rel_dirs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_rel_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, data_collection_model_relative_direction_t* rel_dirs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_rel_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const data_collection_model_relative_direction_t* rel_dirs);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_relative_direction_t* data_collection_model_collective_behaviour_info_get_entry_rel_dirs(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_rel_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_ue_trajectory(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ue_trajectory_collection_t* data_collection_model_collective_behaviour_info_get_ue_trajectory(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_trajectory(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const data_collection_model_ue_trajectory_collection_t* p_ue_trajectory);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_trajectory_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, data_collection_model_ue_trajectory_collection_t* p_ue_trajectory);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_confidence(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_collective_behaviour_info_get_confidence(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_confidence(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const int32_t p_confidence);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_confidence_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, int32_t p_confidence);

/* lnode helper for generating ogs_list_t nodes's of type CollectiveBehaviourInfo */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_collective_behaviour_info_make_lnode(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_COLLECTIVE_BEHAVIOUR_INFO_H_ */

