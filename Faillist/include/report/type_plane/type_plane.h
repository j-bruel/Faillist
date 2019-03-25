//!
//! @file type_plane_def.h
//! @author jbruel
//! @date 14/02/19
//!

#ifndef FAILLIST_TYPE_PLANE_DEF_H
# define FAILLIST_TYPE_PLANE_DEF_H

//!
//! @def TYPE_PLANE_DESC_MAX_SIZE
//! @brief Type plane description max size.
//!
# define TYPE_PLANE_DESC_MAX_SIZE   18

//!
//! @struct type_plane
//! @brief Type plane information.
//!
struct type_plane
{
    unsigned int    value; //!< Type plane value.
    char            type_plane_desc[TYPE_PLANE_DESC_MAX_SIZE]; //!< Type plane description.
};

#endif //FAILLIST_TYPE_PLANE_DEF_H
