//!
//! @file pars_faillure.cpp
//! @author jbruel
//! @date 13/02/19
//!

#include "file_handling/jsoneq.h"
#include "file_handling/pars_faillure.h"
#include "tool/is_number.h"
#include <memory.h>
#include <stdlib.h>

/**
 * Faillure parser.
 */
bool    pars_faillure(char *in, size_t in_size, struct failure *faillure)
{
    jsmn_parser     parer; // parser json instance.
    jsmntok_t       tok[in_size]; // We expect no more than the input size tokens.

    jsmn_init(&parer);

    if (in == NULL)
        return (false);

    int     ret = jsmn_parse(&parer, in, in_size, tok, sizeof(tok) / sizeof(tok[0])); // parser return value.

    if (faillure == NULL ||
        ret < 1 ||
        tok[0].type != JSMN_OBJECT)
        return (false);
    for (int i = 1; i < ret; i++)
    {
        if (jsoneq(in, &tok[i], "Id_failure") == true)
        {
            char    id_failure[7]; // Failure id.

            memset(id_failure, '\0', 7);
            strncpy(id_failure, in + tok[i + 1].start,
                    (size_t) ((tok[i + 1].end - tok[i + 1].start) > 6 ? 6 : (tok[i + 1].end - tok[i + 1].start)));
            faillure->id_failure = (unsigned int) strtol(id_failure, NULL, 0);
            ++i;
        }
        else if (jsoneq(in, &tok[i], "Date") == true)
        {
            char    date[11]; // Date.

            memset(date, '\0', 11);
            strncpy(date, in + tok[i + 1].start,
                    (size_t) ((tok[i + 1].end - tok[i + 1].start) > 10 ? 10 : (tok[i + 1].end - tok[i + 1].start)));
            if (is_number(date))
                faillure->date = (unsigned int) atoi(date);
            ++i;
        }
        else if (jsoneq(in, &tok[i], "Id_component") == true)
        {
            char    id_component[7]; // Id component.

            memset(id_component, '\0', 7);
            strncpy(id_component, in + tok[i + 1].start,
                    (size_t) ((tok[i + 1].end - tok[i + 1].start) > 6 ? 6 : (tok[i + 1].end - tok[i + 1].start)));
            faillure->id_component = (unsigned int) strtol(id_component, NULL, 0);
            ++i;
        }
        else if (jsoneq(in, &tok[i], "Level_criticity") == true)
        {
            char    level_criticity[3]; // Level criticity.

            memset(level_criticity, '\0', 3);
            strncpy(level_criticity, in + tok[i + 1].start,
                    (size_t) ((tok[i + 1].end - tok[i + 1].start) > 2 ? 2 : (tok[i + 1].end - tok[i + 1].start)));
            if (is_number(level_criticity))
                faillure->level_criticity = (unsigned int) atoi(level_criticity);
            ++i;
        }
        else if (jsoneq(in, &tok[i], "Comment_failure_size") == true)
        {
            char    comment_failure_size[4]; // comment failure max size allow.

            memset(comment_failure_size, '\0', 4);
            strncpy(comment_failure_size, in + tok[i + 1].start,
                    (size_t) ((tok[i + 1].end - tok[i + 1].start) > 3 ? 3 : (tok[i + 1].end - tok[i + 1].start)));
            faillure->comment_failure_size = 0;
            if (is_number(comment_failure_size))
                faillure->comment_failure_size = (unsigned int) atoi(comment_failure_size);
            ++i;
        }
        else if (jsoneq(in, &tok[i], "Comment_failure") == true)
        {
            if (faillure->comment_failure_size > 0) {
                strncpy((char *) faillure->comment_failure, in + tok[i + 1].start,((unsigned int) (tok[i + 1].end - tok[i + 1].start) > faillure->comment_failure_size ? faillure->comment_failure_size : (unsigned int) (tok[i + 1].end - tok[i + 1].start)));
                faillure->comment_failure[((unsigned int) (tok[i + 1].end - tok[i + 1].start) > faillure->comment_failure_size ? faillure->comment_failure_size : (unsigned int) (tok[i + 1].end - tok[i + 1].start))] = '\0';
            }
            ++i;
        }
    }
    return (true);
}