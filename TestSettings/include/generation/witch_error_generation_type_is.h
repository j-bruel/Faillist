//!
//! @file witch_error_generation_type_is.h
//! @author jbruel
//! @date 11/02/19
//!

#ifndef T_800_EMB_FAILLIST_2018_WITCH_ERROR_GENERATION_TYPE_IS_H
# define T_800_EMB_FAILLIST_2018_WITCH_ERROR_GENERATION_TYPE_IS_H

# include "error_generation_type.h"

//!
//! @brief Tell with error generation type was asked by the user.
//! @def enum error_generation_type  witch_error_generation_type_is(int argc, const char * const *argv);
//! @note REQ_TEST_040
//! @param argc Number of arguments.
//! @param argv Application arguments.
//! @param generation_arg_idx Generation argument argv index.
//! @param faillist_app_path_arg_idx Faillist application path.
//! @return Error generation type.
//!
enum error_generation_type  witch_error_generation_type_is(int argc, const char * const *argv, int *generation_arg_idx, int *faillist_app_path_arg_idx);

#endif //T_800_EMB_FAILLIST_2018_WITCH_ERROR_GENERATION_TYPE_IS_H
