//!
//! @file write_id_component_failure.h
//! @author jbruel
//! @date 20/02/19
//!

#ifndef FAILLIST_WRITE_ID_COMPONENT_FAILURE_H
# define FAILLIST_WRITE_ID_COMPONENT_FAILURE_H

# include <stdbool.h>

//!
//! @def ID_COMPONENT_FAILURE_TEXT_MAX_SIZE
//! @brief ID Component failure text max size.
//!
# define ID_COMPONENT_FAILURE_TEXT_MAX_SIZE 45

//!
//! @brief Write id component failure.
//! @def bool    write_id_component_failure(int fd, unsigned int id_component);
//! @note REQ_FUNC_120
//! @param fd File director.
//! @param id_component Id component.
//! @return State.
//!
bool    write_id_component_failure(int fd, unsigned int id_component);

#endif //FAILLIST_WRITE_ID_COMPONENT_FAILURE_H
