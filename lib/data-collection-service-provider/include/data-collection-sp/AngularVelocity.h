#ifndef _DATA_COLLECTION_ANGULAR_VELOCITY_H_
#define _DATA_COLLECTION_ANGULAR_VELOCITY_H_

/**********************************************************************************************************************************
 * AngularVelocity - Public C interface to the AngularVelocity object
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

#include "UnitsAngularVelocity.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP AngularVelocity object reference
 */
typedef struct data_collection_model_angular_velocity_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_angular_velocity_t;



/** Create a new AngularVelocity.
 * \public \memberof data_collection_model_angular_velocity_t
 * @return a new AngularVelocity object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_create();

/** Create a new AngularVelocity reference.
 * \public \memberof data_collection_model_angular_velocity_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The AngularVelocity to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_create_ref(const data_collection_model_angular_velocity_t *other);

/** Create a new copy of a AngularVelocity object.
 * \public \memberof data_collection_model_angular_velocity_t
 * Creates a new copy of the given @a other object
 * @param other The AngularVelocity to copy.
 * @return a new AngularVelocity object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_create_copy(const data_collection_model_angular_velocity_t *other);

/** Create a new reference of a AngularVelocity object
 * \public \memberof data_collection_model_angular_velocity_t
 * Creates a reference to the same underlying @a other object.
 * @param other The AngularVelocity to create a new reference to.
 * @return a new AngularVelocity object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_create_move(data_collection_model_angular_velocity_t *other);

/** Copy the value of another AngularVelocity into this object
 * \public \memberof data_collection_model_angular_velocity_t
 * Copies the value of @a other {{classname} object into @a angular_velocity.
 * @param angular_velocity The AngularVelocity object to copy @a other into.
 * @param other The AngularVelocity to copy the value from.
 * @return @a angular_velocity.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_copy(data_collection_model_angular_velocity_t *angular_velocity, const data_collection_model_angular_velocity_t *other);

/** Move the value of another AngularVelocity into this object
 * \public \memberof data_collection_model_angular_velocity_t
 * Discards the current value of @a angular_velocity and moves the value of @a other
 * into @a angular_velocity. This will leave @a other as an empty reference.
 *
 * @param angular_velocity The AngularVelocity object to move @a other into.
 * @param other The AngularVelocity to move the value from.
 *
 * @return @a angular_velocity.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_move(data_collection_model_angular_velocity_t *angular_velocity, data_collection_model_angular_velocity_t *other);

/** Delete a AngularVelocity object
 * \public \memberof data_collection_model_angular_velocity_t
 * Destroys the reference to the AngularVelocity object and frees the value of AngularVelocity if this is the last reference.
 *
 * @param angular_velocity The AngularVelocity to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_angular_velocity_free(data_collection_model_angular_velocity_t *angular_velocity);

/** Get a cJSON tree representation of a AngularVelocity
 * \public \memberof data_collection_model_angular_velocity_t
 *
 * Create a cJSON tree representation of the AngularVelocity object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param angular_velocity The AngularVelocity to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_angular_velocity_toJSON(const data_collection_model_angular_velocity_t *angular_velocity, bool as_request);

/** Parse a cJSON tree into a AngularVelocity object
 * \public \memberof data_collection_model_angular_velocity_t
 *
 * Attempts to interpret a cJSON tree as a AngularVelocity API request or response (dependent on @a as_request value). If successful
 * will return a new referenced AngularVelocity object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new AngularVelocity object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two AngularVelocity objects to see if they are equivalent
 * \public \memberof data_collection_model_angular_velocity_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param angular_velocity The first AngularVelocity object to compare.
 * @param other_angular_velocity The second AngularVelocity object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_angular_velocity_is_equal_to(const data_collection_model_angular_velocity_t *angular_velocity, const data_collection_model_angular_velocity_t *other_angular_velocity);



/** Get the value of the unitsAngularVelocity field of a AngularVelocity object
 * \public \memberof data_collection_model_angular_velocity_t
 *
 * @param angular_velocity The AngularVelocity object to examine.
 *
 * @return the value current set for the unitsAngularVelocity field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_units_angular_velocity_t* data_collection_model_angular_velocity_get_units_angular_velocity(const data_collection_model_angular_velocity_t *angular_velocity);

/** Set the value of the unitsAngularVelocity field in a AngularVelocity object
 * \public \memberof data_collection_model_angular_velocity_t
 *
 * @param angular_velocity The AngularVelocity object to set the field in.
 * @param p_units_angular_velocity The value to copy into the AngularVelocity object.
 *
 * @return @a angular_velocity.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_set_units_angular_velocity(data_collection_model_angular_velocity_t *angular_velocity, const data_collection_model_units_angular_velocity_t* p_units_angular_velocity);

/** Move a value to the unitsAngularVelocity field in a AngularVelocity object
 * \public \memberof data_collection_model_angular_velocity_t
 *
 * @param angular_velocity The AngularVelocity object to set the field in.
 * @param p_units_angular_velocity The value to move into the AngularVelocity object.
 *
 * @return @a angular_velocity.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_set_units_angular_velocity_move(data_collection_model_angular_velocity_t *angular_velocity, data_collection_model_units_angular_velocity_t* p_units_angular_velocity);


/** Get the value of the angularVelocity field of a AngularVelocity object
 * \public \memberof data_collection_model_angular_velocity_t
 *
 * @param angular_velocity The AngularVelocity object to examine.
 *
 * @return the value current set for the angularVelocity field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_angular_velocity_get_angular_velocity(const data_collection_model_angular_velocity_t *angular_velocity);

/** Set the value of the angularVelocity field in a AngularVelocity object
 * \public \memberof data_collection_model_angular_velocity_t
 *
 * @param angular_velocity The AngularVelocity object to set the field in.
 * @param p_angular_velocity The value to copy into the AngularVelocity object.
 *
 * @return @a angular_velocity.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_set_angular_velocity(data_collection_model_angular_velocity_t *angular_velocity, const int32_t p_angular_velocity);

/** Move a value to the angularVelocity field in a AngularVelocity object
 * \public \memberof data_collection_model_angular_velocity_t
 *
 * @param angular_velocity The AngularVelocity object to set the field in.
 * @param p_angular_velocity The value to move into the AngularVelocity object.
 *
 * @return @a angular_velocity.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_set_angular_velocity_move(data_collection_model_angular_velocity_t *angular_velocity, int32_t p_angular_velocity);


/** Get the value of the aVelocityUncertainty field of a AngularVelocity object
 * \public \memberof data_collection_model_angular_velocity_t
 *
 * @param angular_velocity The AngularVelocity object to examine.
 *
 * @return the value current set for the aVelocityUncertainty field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_angular_velocity_get_a_velocity_uncertainty(const data_collection_model_angular_velocity_t *angular_velocity);

/** Set the value of the aVelocityUncertainty field in a AngularVelocity object
 * \public \memberof data_collection_model_angular_velocity_t
 *
 * @param angular_velocity The AngularVelocity object to set the field in.
 * @param p_a_velocity_uncertainty The value to copy into the AngularVelocity object.
 *
 * @return @a angular_velocity.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_set_a_velocity_uncertainty(data_collection_model_angular_velocity_t *angular_velocity, const int32_t p_a_velocity_uncertainty);

/** Move a value to the aVelocityUncertainty field in a AngularVelocity object
 * \public \memberof data_collection_model_angular_velocity_t
 *
 * @param angular_velocity The AngularVelocity object to set the field in.
 * @param p_a_velocity_uncertainty The value to move into the AngularVelocity object.
 *
 * @return @a angular_velocity.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_angular_velocity_t *data_collection_model_angular_velocity_set_a_velocity_uncertainty_move(data_collection_model_angular_velocity_t *angular_velocity, int32_t p_a_velocity_uncertainty);

/** lnode helper for generating ogs_list_t nodes's of type AngularVelocity
 * \public \memberof data_collection_model_angular_velocity_t
 *
 * Creates a new data_collection_lnode_t object containing the @a angular_velocity object.
 * The @a angular_velocity will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param angular_velocity The AngularVelocity object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a angular_velocity
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_angular_velocity_make_lnode(data_collection_model_angular_velocity_t *angular_velocity);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ANGULAR_VELOCITY_H_ */

