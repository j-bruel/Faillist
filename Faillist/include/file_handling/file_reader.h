//!
//! @file filereader.hpp
//! @author jbruel
//! @date 11/02/19
//!

#ifndef FAILLIST_FILEREADER_HPP
# define FAILLIST_FILEREADER_HPP

# include "report/file_max_size.h"
# include <stdbool.h>

//!
//! @brief Read a file and insert into a string.
//! @def void file_reader(const char *filename, char in[FILE_MAX_SIZE]);
//! @note REQ_FUNC_010
//! @param filename Filename to read.
//! @param in file input.
//! @return State.
//!
bool file_reader(const char *filename, char *in);

#endif //FAILLIST_FILEREADER_HPP
