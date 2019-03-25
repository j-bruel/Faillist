//!
//! @file report.h
//! @author jbruel
//! @date 11/02/19
//!

#ifndef FAILLIST_REPORT_H
# define FAILLIST_REPORT_H

# include "report/faillure/failure_info_max_allow.h"
# include "report/id_plane/id_plane_max_size.h"
# include "report/faillure/failure.h"

//!
//! @struct report
//! @brief Failure report information.
//!
struct  report
{
    unsigned char       id_plane[ID_PLANE_MAX_SIZE]; //!< The description of possible values of the field ID_PLANE is described in file “Embedded_World-Request_for_proposal-Annex1.xlsx”, sheet “ID_PLANE”.
    unsigned int        type_plane; //!< Field TYPE_PLANE must be one of the values described in file “Embedded_World-Request_for_proposal-Annex1.xlsx”, sheet “TYPE_PLANE”.
    unsigned int        nb_failures; //!< Field NB_FAILURES range is [0;999].
    struct failure      faillures[FAILURE_INFO_MAX_ALLOW]; //!< Faillures list.
};

#endif //FAILLIST_REPORT_H
