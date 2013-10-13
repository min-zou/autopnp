/*
 * Copyright (c) 2011-2013, fortiss GmbH.
 * Licensed under the Apache License, Version 2.0.
 *
 * Use, modification and distribution are subject to the terms specified
 * in the accompanying license file LICENSE.txt located at the root directory
 * of this software distribution. A copy is available at
 * http://chromosome.fortiss.org/.
 *
 * This file is part of CHROMOSOME.
 *
 * $Id: demarshaler.h 4834 2013-08-28 09:36:55Z wiesmueller $
 */

/**
 * \file
 *
 * \brief  Waypoint that demarshals topic data.
 */

#ifndef XME_WP_MARSHAL_DEMARSHALER_H
#define XME_WP_MARSHAL_DEMARSHALER_H

/**
 * \defgroup wp_marshal (De-)marshaling related waypoints.
 * @{
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "xme/core/component.h"
#include "xme/core/dataManagerTypes.h"

#include "xme/wp/waypoint.h"

#include <stdbool.h>
#include <stdint.h>

/******************************************************************************/
/***   Prototypes                                                           ***/
/******************************************************************************/
XME_EXTERN_C_BEGIN

/**
 * \brief  Initialize this waypoint.
 *
 * \retval XME_STATUS_SUCCESS if the waypoint has been initialized successfully.
 * \retval XME_STATUS_INTERNAL_ERROR if an error occurred.
 */
xme_status_t
xme_wp_marshal_demarshaler_init(void);

/**
 * \brief  Get data from configuration entry.
 *         This function will search for the first configuration that matches
 *         all given non-invalid paramters.
 *         All parameters with invalid values will then be filled with the
 *         data from the found configuration.
 *
 * \param  instanceId InstanceId of searched configuration, or XME_WP_WAYPOINT_INSTANCEID_INVALID
 *         when this should be an output parameter. May not be null.
 * \param  topic Topic of searched configuration, or XME_CORE_TOPIC_INVALID_TOPIC
 *         when this should be an output parameter. May not be null.
 * \param  inputPort InstanceId of searched configuration, or XME_CORE_DATAMANAGER_DATAPACKETID_INVALID
 *         when this should be an output parameter. May not be null.
 * \param  outputPort InstanceId of searched configuration, or XME_CORE_DATAMANAGER_DATAPACKETID_INVALID
 *         when this should be an output parameter. May not be null.
 *
 * \retval XME_STATUS_SUCCESS if a matching configuration has been found.
 * \retval XME_STATUS_NOT_FOUND if no matching configuration exists.
 */
xme_status_t
xme_wp_marshal_demarshaler_getConfig
(
    xme_wp_waypoint_instanceId_t* instanceId,
    xme_core_topic_t* topic,
    xme_core_dataManager_dataPacketId_t* inputPort,
    xme_core_dataManager_dataPacketId_t* outputPort
);

/**
 * \brief  Add a new configuration for this waypoint.
 *
 * \param  instanceId Pointer where id for the newly added configuration is written to.
 *                    Only valid when XME_STATUS_SUCCESS has been returned, else undefined.
 * \param  topic      Topic of the data that is stored at inputPort.
 * \param  inputPort  Port identifier for the input port.
 *                    Denotes where the marshaled topic data is located at.
 *                    No check is performed whether the port is valid.
 * \param  outputPort Port identifier for the output port.
 *                    Denotes the port where the demarshaled data will be written to.
 *                    No check is performed whether the port is valid.
 *
 * \retval XME_STATUS_SUCCESS if the configuration has been added successfully.
 * \retval XME_STATUS_OUT_OF_RESOURCES if the configuration could not be added due
 *         to resource constraints (e.g. not enough memory to store entry).
 * \retval XME_STATUS_INVALID_PARAMETER if the given topic is not supported by this marshaler.
 */
xme_status_t
xme_wp_marshal_demarshaler_addConfig
(
    xme_wp_waypoint_instanceId_t* instanceId,
    xme_core_topic_t topic,
    xme_core_dataManager_dataPacketId_t inputPort,
    xme_core_dataManager_dataPacketId_t outputPort
);

/**
 * \brief  Finalize this waypoint.
 *
 * \retval XME_STATUS_SUCCESS if the waypoint has been finalized successfully.
 * \retval XME_STATUS_INTERNAL_ERROR if an error occurred.
 */
xme_status_t
xme_wp_marshal_demarshaler_fini(void);

XME_EXTERN_C_END

/**@}*/

#endif // #ifndef XME_WP_MARSHAL_DEMARSHALER_H
