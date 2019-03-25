//!
//! @file is_number.c
//! @author jbruel
//! @date 05/03/19
//!

#include "tool/is_number.h"
#include <stddef.h>
#include <ctype.h>
#include <string.h>

/**
 * Check if a string is a number.
 */
bool    is_number(const char *str)
{
    if (str == NULL)
        return (false);

    size_t  size = strlen(str); // String size.

    for (size_t i = 0; i < size; ++i)
        if (isdigit(str[i]) == false)
            return (false);
    return (true);
}