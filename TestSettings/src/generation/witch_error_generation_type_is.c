//!
//! @file witch_error_generation_type_is.c
//! @author jbruel
//! @date 1102/19
//!

#include "generation/witch_error_generation_type_is.h"
#include <stdlib.h>
#include <memory.h>

/**
 * Tell with error generation type was asked by the user.
 */
enum error_generation_type  witch_error_generation_type_is(int argc, const char * const *argv, int *generation_arg_idx, int *faillist_app_path_arg_idx)
{
    enum error_generation_type  type = NONE;

    if (argc < 3 || argv == NULL || generation_arg_idx == NULL || faillist_app_path_arg_idx == NULL)
        return (NONE);
    for (int i = 0; i < argc; ++i)
    {
        if (strcmp(argv[i], "--faillist") == 0 && argc > i + 1)
            *faillist_app_path_arg_idx = i + 1;
        else if (strcmp(argv[i], "--automatic") == 0 && argc > i + 1)
        {
            *generation_arg_idx = i + 1;
            type = AUTOMATICALLY;
        }
        else if (strcmp(argv[i], "--manual") == 0  && argc > i + 1)
        {
            *generation_arg_idx = i + 1;
            type = MANUALLY;
        }
    }
    if (*faillist_app_path_arg_idx == 0)
        return (NONE);
    return (type);
}