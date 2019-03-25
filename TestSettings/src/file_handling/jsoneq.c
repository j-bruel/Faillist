//!
//! @file jsoneq.c
//! @author jbruel
//! @date 11/02/19
//!

#include "file_handling/jsoneq.h"
#include <memory.h>

/**
 * Check if a element is find into the current json.
 */
bool    jsoneq(const char *json, jsmntok_t *tok, const char *s)
{
    return (tok->type == JSMN_PRIMITIVE && (int)strlen(s) == tok->end - tok->start && strncmp(json + tok->start, s,
                                                                                              (size_t) (tok->end - tok->start)) == 0);
}
