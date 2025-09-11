#ifndef _DATA_COLLECTION_RELATIVE_VELOCITY_WITH_UNCERTAINTY_H_
#define _DATA_COLLECTION_RELATIVE_VELOCITY_WITH_UNCERTAINTY_H_

/**********************************************************************************************************************************
 * RelativeVelocityWithUncertainty - Public C interface to the RelativeVelocityWithUncertainty object
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

#include "RadialVelocity.h"
#include "AngularVelocity.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP RelativeVelocityWithUncertainty object reference
 */
typedef struct data_collection_model_relative_velocity_with_uncertainty_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_relative_velocity_with_uncertainty_t;



/** Create a new RelativeVelocityWithUncertainty.
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 * @return a new RelativeVelocityWithUncertainty object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_create();

/** Create a new RelativeVelocityWithUncertainty reference.
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The RelativeVelocityWithUncertainty to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_create_ref(const data_collection_model_relative_velocity_with_uncertainty_t *other);

/** Create a new copy of a RelativeVelocityWithUncertainty object.
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 * Creates a new copy of the given @a other object
 * @param other The RelativeVelocityWithUncertainty to copy.
 * @return a new RelativeVelocityWithUncertainty object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_create_copy(const data_collection_model_relative_velocity_with_uncertainty_t *other);

/** Create a new reference of a RelativeVelocityWithUncertainty object
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 * Creates a reference to the same underlying @a other object.
 * @param other The RelativeVelocityWithUncertainty to create a new reference to.
 * @return a new RelativeVelocityWithUncertainty object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_create_move(data_collection_model_relative_velocity_with_uncertainty_t *other);

/** Copy the value of another RelativeVelocityWithUncertainty into this object
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 * Copies the value of @a other {{classname} object into @a relative_velocity_with_uncertainty.
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to copy @a other into.
 * @param other The RelativeVelocityWithUncertainty to copy the value from.
 * @return @a relative_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_copy(data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty, const data_collection_model_relative_velocity_with_uncertainty_t *other);

/** Move the value of another RelativeVelocityWithUncertainty into this object
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 * Discards the current value of @a relative_velocity_with_uncertainty and moves the value of @a other
 * into @a relative_velocity_with_uncertainty. This will leave @a other as an empty reference.
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to move @a other into.
 * @param other The RelativeVelocityWithUncertainty to move the value from.
 *
 * @return @a relative_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_move(data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty, data_collection_model_relative_velocity_with_uncertainty_t *other);

/** Delete a RelativeVelocityWithUncertainty object
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 * Destroys the reference to the RelativeVelocityWithUncertainty object and frees the value of RelativeVelocityWithUncertainty if this is the last reference.
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_relative_velocity_with_uncertainty_free(data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty);

/** Get a cJSON tree representation of a RelativeVelocityWithUncertainty
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * Create a cJSON tree representation of the RelativeVelocityWithUncertainty object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_relative_velocity_with_uncertainty_toJSON(const data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty, bool as_request);

/** Parse a cJSON tree into a RelativeVelocityWithUncertainty object
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * Attempts to interpret a cJSON tree as a RelativeVelocityWithUncertainty API request or response (dependent on @a as_request value). If successful
 * will return a new referenced RelativeVelocityWithUncertainty object containing the value represented by the cJSON tree. On failure will return
 * `NULL` and will set @a error_reason, @a error_class and @a error_parameter output parameters to indicate the reason for the
 * failure. The @a error_reason, @a error_class and @a error_parameter strings must be freed using ogs_free().
 *
 * @param json The cJSON tree object to interpret.
 * @param as_request `true` to interpret the @a json as an API request or `false` for interpretation as an API response.
 * @param[out] error_reason On failure will be set to a new nul terminated string indicating the reason for the failure.
 * @param[out] error_class On failure will be set to the class name of the object where the failure happened if available or `NULL`.
 * @param[out] error_parameter On failure will be set to the JSON path of the field where the failure happened if available or
                               `NULL`.
 *
 * @return a new RelativeVelocityWithUncertainty object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two RelativeVelocityWithUncertainty objects to see if they are equivalent
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param relative_velocity_with_uncertainty The first RelativeVelocityWithUncertainty object to compare.
 * @param other_relative_velocity_with_uncertainty The second RelativeVelocityWithUncertainty object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_velocity_with_uncertainty_is_equal_to(const data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty, const data_collection_model_relative_velocity_with_uncertainty_t *other_relative_velocity_with_uncertainty);


/** Check if the rVelocity field of a RelativeVelocityWithUncertainty object is set
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to examine.
 *
 * @return `true` if the optional rVelocity field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_velocity_with_uncertainty_has_r_velocity(const data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty);


/** Get the value of the rVelocity field of a RelativeVelocityWithUncertainty object
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to examine.
 *
 * @return the value current set for the rVelocity field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_radial_velocity_t* data_collection_model_relative_velocity_with_uncertainty_get_r_velocity(const data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty);

/** Set the value of the rVelocity field in a RelativeVelocityWithUncertainty object
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to set the field in.
 * @param p_r_velocity The value to copy into the RelativeVelocityWithUncertainty object.
 *
 * @return @a relative_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_set_r_velocity(data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty, const data_collection_model_radial_velocity_t* p_r_velocity);

/** Move a value to the rVelocity field in a RelativeVelocityWithUncertainty object
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to set the field in.
 * @param p_r_velocity The value to move into the RelativeVelocityWithUncertainty object.
 *
 * @return @a relative_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_set_r_velocity_move(data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty, data_collection_model_radial_velocity_t* p_r_velocity);

/** Check if the aTransverseVelocity field of a RelativeVelocityWithUncertainty object is set
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to examine.
 *
 * @return `true` if the optional aTransverseVelocity field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_velocity_with_uncertainty_has_a_transverse_velocity(const data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty);


/** Get the value of the aTransverseVelocity field of a RelativeVelocityWithUncertainty object
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to examine.
 *
 * @return the value current set for the aTransverseVelocity field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_angular_velocity_t* data_collection_model_relative_velocity_with_uncertainty_get_a_transverse_velocity(const data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty);

/** Set the value of the aTransverseVelocity field in a RelativeVelocityWithUncertainty object
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to set the field in.
 * @param p_a_transverse_velocity The value to copy into the RelativeVelocityWithUncertainty object.
 *
 * @return @a relative_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_set_a_transverse_velocity(data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty, const data_collection_model_angular_velocity_t* p_a_transverse_velocity);

/** Move a value to the aTransverseVelocity field in a RelativeVelocityWithUncertainty object
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to set the field in.
 * @param p_a_transverse_velocity The value to move into the RelativeVelocityWithUncertainty object.
 *
 * @return @a relative_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_set_a_transverse_velocity_move(data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty, data_collection_model_angular_velocity_t* p_a_transverse_velocity);

/** Check if the eTransverseVelocity field of a RelativeVelocityWithUncertainty object is set
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to examine.
 *
 * @return `true` if the optional eTransverseVelocity field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_velocity_with_uncertainty_has_e_transverse_velocity(const data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty);


/** Get the value of the eTransverseVelocity field of a RelativeVelocityWithUncertainty object
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to examine.
 *
 * @return the value current set for the eTransverseVelocity field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_angular_velocity_t* data_collection_model_relative_velocity_with_uncertainty_get_e_transverse_velocity(const data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty);

/** Set the value of the eTransverseVelocity field in a RelativeVelocityWithUncertainty object
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to set the field in.
 * @param p_e_transverse_velocity The value to copy into the RelativeVelocityWithUncertainty object.
 *
 * @return @a relative_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_set_e_transverse_velocity(data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty, const data_collection_model_angular_velocity_t* p_e_transverse_velocity);

/** Move a value to the eTransverseVelocity field in a RelativeVelocityWithUncertainty object
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to set the field in.
 * @param p_e_transverse_velocity The value to move into the RelativeVelocityWithUncertainty object.
 *
 * @return @a relative_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_velocity_with_uncertainty_t *data_collection_model_relative_velocity_with_uncertainty_set_e_transverse_velocity_move(data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty, data_collection_model_angular_velocity_t* p_e_transverse_velocity);

/** lnode helper for generating ogs_list_t nodes's of type RelativeVelocityWithUncertainty
 * \public \memberof data_collection_model_relative_velocity_with_uncertainty_t
 *
 * Creates a new data_collection_lnode_t object containing the @a relative_velocity_with_uncertainty object.
 * The @a relative_velocity_with_uncertainty will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param relative_velocity_with_uncertainty The RelativeVelocityWithUncertainty object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a relative_velocity_with_uncertainty
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_relative_velocity_with_uncertainty_make_lnode(data_collection_model_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_RELATIVE_VELOCITY_WITH_UNCERTAINTY_H_ */

