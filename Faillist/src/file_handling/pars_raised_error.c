//!
//! @file pars_raised_error.c
//! @author jbruel
//! @date 11/02/19
//!

#include "file_handling/pars_faillure.h"
#include "file_handling/pars_raised_error.h"
#include "file_handling/jsoneq.h"
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <unistd.h>

/**
 * Pars raised error with json parser.
 */
bool    pars_raised_error(char *in, size_t in_size, struct report *raised_error)
{
    jsmn_parser     parer; // parser json instance.
    jsmntok_t       tok[in_size]; // We expect no more than the input size tokens.

    jsmn_init(&parer);

    if (in == NULL)
        return (false);

    int     ret = jsmn_parse(&parer, in, in_size, tok, sizeof(tok) / sizeof(tok[0])); // parser return value.

    write(1, "Faillist: Parsing the loaded file.\n", strlen("Faillist: Parsing the loaded file.\n"));
    if (raised_error == NULL ||
        ret < 1 ||
        tok[0].type != JSMN_OBJECT)
    {
        write(1, "Faillist: Impossible to pars the loaded file.\n", strlen("Faillist: Impossible to pars the loaded file.\n"));
        return (false);
    }
    for (int i = 1; i < ret; i++)
    {
        if (jsoneq(in, &tok[i], "Id_plane") == true)
        {
            strncpy((char *) raised_error->id_plane, in + tok[i + 1].start,
                    (size_t) ((tok[i + 1].end - tok[i + 1].start) > 11 ? 11 : (tok[i + 1].end - tok[i + 1].start)));
            ++i;
        }
        else if (jsoneq(in, &tok[i], "Type_plane") == true)
        {
            char    type_plane[7]; // type plane.

            memset(type_plane, '\0', 7);
            strncpy(type_plane, in + tok[i + 1].start,
                    (size_t) ((tok[i + 1].end - tok[i + 1].start) > 6 ? 6 : (tok[i + 1].end - tok[i + 1].start)));
            raised_error->type_plane = (unsigned int) strtol(type_plane, NULL, 0);
            ++i;
        }
        else if (jsoneq(in, &tok[i], "Nb_failures") == true)
        {
            char    nb_failures[4]; // nb failures.

            memset(nb_failures, '\0', 4);
            strncpy(nb_failures, in + tok[i + 1].start,
                    (size_t) ((tok[i + 1].end - tok[i + 1].start) > 3 ? 3 : (tok[i + 1].end - tok[i + 1].start)));
            raised_error->nb_failures = (unsigned int) atoi(nb_failures);
            ++i;
        }
        else if (jsoneq(in, &tok[i], "failures") == true)
        {
            int j; // json parsing index.

            if (tok[i+1].type != JSMN_ARRAY) {
                continue;
            }

            int n = 0; // Number of element from the failures list index.

            for (j = 0; j < tok[i + 1].size; j++)
            {
                jsmntok_t   *g = &tok[i + j + 2 + n];

                pars_faillure(in + g->start, (size_t)(g->end - g->start), &(raised_error->faillures[j]));
                n += tok[i + j + n + 2].size * 2;
            }
            i += tok[i+1].size + 1;
        }
    }
    return (true);
}