//!
//! @file failure.h
//! @author jbruel
//! @date 11/02/19
//!

#ifndef FAILLIST_FAILURE_FAILURE_H
# define FAILLIST_FAILURE_FAILURE_H

# include "report/max_comment_size.h"

//!
//! @struct failure
//! @brief Failure information.
//!
struct  failure
{
    unsigned int    id_failure; //!< Field ID_FAILURE_X must be one of the values described in file “Embedded_World-Request_for_proposal-Annex1.xlsx”, sheet “ID_FAILURE_X”.
    unsigned int    date; //!< The date and time format of the DATETIME_FAILURE_X field is the number of second since 00:00 January the 1rst 1970 UTC.
    unsigned int    id_component; //!< Field ID_COMPONENT_FAILURE_X must be one of the values described in file “Embedded_World-Request_for_proposal-Annex1.xlsx”, sheet “ID_COMPONENT_FAILURE_X”.
    unsigned int    level_criticity; //!< Field LEVEL_CRITICITY_FAILURE_X range must be [0;10], with 0 the minimum level of criticity, 10 the maximum.
    unsigned int    comment_failure_size; //!< Field COMMENT_FAILURE_X_SIZE range is [0;MAX_COMMENT_SIZE].
    unsigned char   comment_failure[MAX_COMMENT_SIZE]; //!< Describe the failure X cause.
};

#endif //FAILLIST_FAILURE_FAILURE_H
