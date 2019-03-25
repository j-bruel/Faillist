//!
//! @file write_type_plane.h
//! @author jbruel
//! @date 14/02/19
//!

#ifndef FAILLIST_WRITE_TYPE_PLANE_H
# define FAILLIST_WRITE_TYPE_PLANE_H

//!
//! @def TYPE_PLANE_MAX
//! @brief Type plane max size.
//!
# define TYPE_PLANE_MAX 11

//!
//! @brief Write type plane information into the log file.
//! @param fd File director of the output file.
//! @param raised_type_plane Raised type plane.
//!
void write_type_plane(int fd, unsigned int raised_type_plane);

#endif //FAILLIST_WRITE_TYPE_PLANE_H
