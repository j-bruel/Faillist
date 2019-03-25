//!
//! @file jsoneq.h
//! @author jbruel
//! @date 11/02/19
//!

#ifndef FAILLIST_JSONEQ_H
# define FAILLIST_JSONEQ_H

# include <stdbool.h>
# include <jsmn.h>

//!
//! @brief Check if a element is find.
//! @def bool    jsoneq(const char *json, jsmntok_t *tok, const char *s);
//! @note REQ_FUNC_010
//! @param json All input file.
//! @param tok Token indicator.
//! @param s input searching string.
//! @return State
//!
bool    jsoneq(const char *json, jsmntok_t *tok, const char *s);

#endif //FAILLIST_JSONEQ_H
