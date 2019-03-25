//!
//! @file id_component_failure.h
//! @author jbruel
//! @date 20/02/19
//!

#ifndef FAILLIST_ID_COMPONENT_FAILURE_H
# define FAILLIST_ID_COMPONENT_FAILURE_H

//!
//! @def ID_COMPONENT_FAILURE_DESC_MAX_SIZE
//! @brief ID Component failure description max size.
//!
# define ID_COMPONENT_FAILURE_DESC_MAX_SIZE   24

//!
//! @struct id_component_failure
//! @brief ID component failure information.
//!
struct  id_component_failure
{
    unsigned int    value; //!< Id component value.
    char            component_desc[ID_COMPONENT_FAILURE_DESC_MAX_SIZE]; //!< Component description.
};

#endif //FAILLIST_ID_COMPONENT_FAILURE_H
