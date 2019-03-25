//!
//! @file failure_id_def.h
//! @author jbruel
//! @date 20/02/19
//!

#ifndef FAILLIST_FAILURE_ID_DEF_H
# define FAILLIST_FAILURE_ID_DEF_H

# include "report/faillure/failure_id/failure_id.h"

//!
//! @def FAILURE_ID_MAX
//! @brief Id failure max.
//!
# define FAILURE_ID_MAX 17

//!
//! @static
//! @def static const struct failure_id  id_failures[FAILURE_ID_MAX]
//! @brief Define all id failures available.
//!
static const struct failure_id  id_failures[FAILURE_ID_MAX] = {
        {4096, "Null pointer error"},
        {4097, "Buffer overflow error"},
        {4098, "Resource leak error"},
        {4099, "Short circuiting error"},
        {4100, "Too_High voltage error"},
        {4101, "Mechanical failure error"},
        {4102, "Too_Hot temperature error"},
        {4103, "Too_Cold temperature error"},
        {4104, "Corrosion corrosion error"},
        {4105, "Engine fire error"},
        {4106, "Fuel fire error"},
        {4107, "Fuel leak error"},
        {4108, "Explosion explosion error"},
        {4109, "Hijacking hijacking error"},
        {4110, "Weather storm error"},
        {4111, "Sabotage sabotage error"},
        {4112, "Pilot error error"}
};


#endif //FAILLIST_FAILURE_ID_DEF_H
