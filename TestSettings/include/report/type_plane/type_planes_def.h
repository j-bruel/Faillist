//!
//! @file type_planes_def.h
//! @author jbruel
//! @date 14/02/19
//!

#ifndef FAILLIST_TYPE_PLANES_DEF_H
# define FAILLIST_TYPE_PLANES_DEF_H

# include "report/type_plane/write_type_plane.h"
# include "report/type_plane/type_plane.h"

//!
//! @static
//! @def static const struct type_plane  type_planes[TYPE_PLANE_MAX]
//! @brief All type planes.
//!
static const struct type_plane  type_planes[TYPE_PLANE_MAX] = {
        {320, "Airbus A320"},
        {330, "Airbus A330"},
        {350, "Airbus A350"},
        {380, "Airbus A380"},
        {400, "Airbus A400M"},
        {295, "Airbus CASA C-295"},
        {737, "Boeing 737"},
        {747, "Boeing 747"},
        {767, "Boeing 767"},
        {777, "Boeing 777"},
        {387, "Boeing 787"}
};

#endif //FAILLIST_TYPE_PLANES_DEF_H
