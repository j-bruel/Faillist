//!
//! @file failure_id.h
//! @author jbruel
//! @date 20/02/19
//!

#ifndef FAILLIST_FAILURE_ID_H
# define FAILLIST_FAILURE_ID_H

//!
//! @def TYPE_PLANE_DESC_MAX_SIZE
//! @brief Type plane description max size.
//!
# define ID_FAILURE_TYPE_DESC_MAX_SIZE   30

//!
//! @struct failure_id
//! @brief ID failure information.
//!
struct  failure_id
{
    unsigned int    value; //!< Id failure value.
    char            failure_type[ID_FAILURE_TYPE_DESC_MAX_SIZE]; //!< Type failure description.
};

#endif //FAILLIST_FAILURE_ID_H
