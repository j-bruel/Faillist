//!
//! @file exec_faillist_app.c
//! @author jbruel
//! @date 11/02/19
//!

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include "generation/exec_faillist_app.h"

void exec_faillist_app(const char *app_path, const char *output_file_path)
{
    const unsigned int  cmd_size = (const unsigned int) (strlen(output_file_path) + strlen(app_path) + 1);
    char                cmd[cmd_size];

    memset(cmd, '\0', cmd_size);
    sprintf(cmd, "%s %s", app_path, output_file_path);
    system(cmd);

}