//!
//! @file id_plane.h
//! @author jbruel
//! @date 16/02/19
//!

#ifndef FAILLIST_ID_PLANE_H
# define FAILLIST_ID_PLANE_H

# include "report/id_plane/id_plane_max_size.h"

//!
//! @def ID_PLANE_COUNTRY_MAX_SIZE
//! @brief ID plane country max size.
//!
# define ID_PLANE_COUNTRY_MAX_SIZE   40

//!
//! @struct id_plane
//! @brief ID plane information.
//!
struct id_plane
{
    unsigned char   country[ID_PLANE_COUNTRY_MAX_SIZE]; //!< ID plane country.
    unsigned char   prefix[ID_PLANE_MAX_SIZE]; //!< ID plane prefix.
};

#endif //FAILLIST_ID_PLANE_H
