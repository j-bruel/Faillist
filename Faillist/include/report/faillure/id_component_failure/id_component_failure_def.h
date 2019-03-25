//!
//! @file id_component_failure_def.h
//! @author jbruel
//! @date 20/02/19
//!

#ifndef FAILLIST_ID_COMPONENT_FAILURE_DEF_H
# define FAILLIST_ID_COMPONENT_FAILURE_DEF_H

# include "report/faillure/id_component_failure/id_component_failure.h"

//!
//! @def COMPONENT_ID_MAX
//! @brief ID component failure max.
//!
# define COMPONENT_ID_MAX 14

//!
//! @def static const struct id_component_failure  id_components_failure[COMPONENT_ID_MAX]
//! @brief List of all if components failures.
//!
static const struct id_component_failure  id_components_failure[COMPONENT_ID_MAX] = {
        {8192, "Cockpit"},
        {8193, "Fuselage"},
        {8194, "Turbine engine"},
        {8195, "Wing"},
        {8196, "Winglet"},
        {8197, "Horizontal Stabilizer"},
        {8198, "Vertical Stabilizer"},
        {8199, "Rudder Winglet"},
        {8200, "Rudder"},
        {8201, "Elevator"},
        {8202, "Flaps"},
        {8203, "Aileron"},
        {8204, "Spoiler"},
        {8205, "Slats"}
};

#endif //FAILLIST_ID_COMPONENT_FAILURE_DEF_H
