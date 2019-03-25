//!
//! @file write_id_plane.h
//! @author jbruel
//! @date 16/02/19
//!

#ifndef FAILLIST_WRITE_ID_PLANE_H
# define FAILLIST_WRITE_ID_PLANE_H

# include "report/id_plane/id_plane_max_size.h"

//!
//! @def PLANE_NATIONALITY_TEXT
//! @brief Plane nationality text.
//!
# define PLANE_NATIONALITY_TEXT "PLANE_NATIONALITY: "

//!
//! @brief Write id plane.
//! @param fd File directory (output file)
//! @param id_plane Id plane prefix.
//!
void    write_id_plane(int fd, unsigned char *raised_id_plane);

#endif //FAILLIST_WRITE_ID_PLANE_H
