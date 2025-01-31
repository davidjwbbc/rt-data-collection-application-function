/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 * Author(s): David Waring <david.waring2@bbc.co.uk>
 * 
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "event.h"

ogs_event_t *_local_event_create(dc_local_event_e event_type, void *data)
{
    dc_local_event_t *event = (dc_local_event_t*)ogs_event_size(DC_EVENT_LOCAL, sizeof(dc_local_event_t));
    event->ogs_event.sbi.data = (void*)DC_LOCAL_EVENT_MARKER;
    event->local_id = event_type;
    event->data = data;
    
    return &(event->ogs_event);
}

const char *_dc_event_name(ogs_event_t *e)
{
    if (e->id < OGS_MAX_NUM_OF_PROTO_EVENT)
        return ogs_event_get_name(e);
    switch (e->id) {
    case DC_EVENT_BASE:
        return "DC_EVENT_BASE";
    case DC_EVENT_LOCAL:
        if (e->sbi.data == (void*)DC_LOCAL_EVENT_MARKER) {
            dc_local_event_t *dc_evt = (dc_local_event_t*)e;
            switch (dc_evt->local_id) {
            case DC_LOCAL_EVENT_EXPOSURE_NOTIFICATION:
                return "DC_EVENT_LOCAL::DC_LOCAL_EVENT_EXPOSURE_NOTIFICATION";
            case DC_LOCAL_EVENT_REPORTING_SESSION_EXPIRY:
                return "DC_EVENT_LOCAL::DC_LOCAL_EVENT_REPORTING_SESSION_EXPIRY";
            default:
                return "DC_EVENT_LOCAL::<Unknown-local-event>";
            }
        }
        break;
    case DC_EVENT_REPORTING_SESSION_CACHE:
        return "DC_EVENT_REPORTING_SESSION_CACHE";
    case DC_EVENT_DATA_REPORTS_EXPIRY:
        return "DC_EVENT_DATA_REPORTS_EXPIRY";
    case DC_EVENT_DATA_REPORTS_CLEAR:
        return "DC_EVENT_DATA_REPORTS_CLEAR";
    default:
    }
    return "Unknown Event Type";
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
