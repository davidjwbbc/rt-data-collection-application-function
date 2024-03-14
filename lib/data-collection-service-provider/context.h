/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DATA_COLLECTION_CONTEXT_H
#define DATA_COLLECTION_CONTEXT_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <features.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include "ogs-sbi.h"
#include "ogs-app.h"
//#include "event.h"
//#include "data-collection-sm.h"
#include "response-cache-control.h"
#include "data-collection-sp/data-collection.h"


#ifdef __cplusplus
extern "C" {
#endif

extern int __data_collection_log_domain;

#undef OGS_LOG_DOMAIN
#define OGS_LOG_DOMAIN __data_collection_log_domain

typedef struct data_collection_configuration_server_s {
    ogs_sockaddr_t *ipv4;
    ogs_sockaddr_t *ipv6;
    ogs_sbi_server_t *server_v4;
    ogs_sbi_server_t *server_v6;
} data_collection_configuration_server_t;

typedef enum data_collection_configuration_server_ifc_e {
    DATA_COLLECTION_SVR_SBI = 0,
    DATA_COLLECTION_SVR_PROVISIONING,
    DATA_COLLECTION_SVR_DATA_REPORTING,
    DATA_COLLECTION_SVR_EVENT,

    DATA_COLLECTION_SVR_NUM_IFCS
} data_collection_configuration_server_ifc_t;

#define DATA_COLLECTION_SVR_MAX_SERVERS_PER_IFC 8

typedef struct data_collection_lib_configuration_s {
    const data_collection_configuration_t *data_collection_configuration;
    struct {
        size_t num_v4_server_instances;
        size_t num_v6_server_instances;
        data_collection_configuration_server_t ogs_server[DATA_COLLECTION_SVR_MAX_SERVERS_PER_IFC];
    } servers[DATA_COLLECTION_SVR_NUM_IFCS];
    data_collection_server_response_cache_control_t *server_response_cache_control;

    char *data_collection_dir;
} data_collection_lib_configuration_t;

typedef struct data_collection_context_s {
    data_collection_lib_configuration_t config;
    ogs_hash_t  *data_reporting_provisioning_sessions; // id => data_reporting_provisioning_session_t*
    ogs_hash_t  *data_reporting_sessions; // id => data_collection_reporting_session_t*
    char server_name[NI_MAXHOST];
} data_collection_context_t;

typedef struct data_collection_server_addr_s {
    ogs_lnode_t node;
    const char *server_addr;
} data_collection_context_server_addr_t;

extern int _data_collection_initialise(const data_collection_configuration_t* const configuration);
extern void data_collection_context_init(void);
extern void data_collection_context_final(void);
extern data_collection_context_t *data_collection_self(void);
extern int data_collection_parse_config(const data_collection_configuration_t* const configuration);

extern int data_collection_context_server_name_set(void);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_CONTEXT_H */
