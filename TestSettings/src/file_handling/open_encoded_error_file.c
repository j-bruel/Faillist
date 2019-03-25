//!
//! @file open_encoded_error_file.c
//! @author jbruel
//! @date 11/02/19
//!

#include "file_handling/open_encoded_error_file.h"
#include "report/faillure/failure_info_max_allow.h"
#include <sys/stat.h>
#include <memory.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int open_encoded_error_file(char *filename)
{
    struct stat sb;
    char        tmp_file_path[24];

    if (stat(".TestSettings", &sb) == 0 && S_ISDIR(sb.st_mode));
    else
        mkdir(".TestSettings", 0700);
    memset(tmp_file_path, '\0', 24);
    for (int i = 0; i < FAILURE_INFO_MAX_ALLOW; ++i)
    {
        sprintf(tmp_file_path, ".TestSettings/%d.json", i);
        if (access(tmp_file_path, F_OK) == -1)
        {
            strcpy(filename, tmp_file_path);
            return (open(filename, O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
        }
    }
    return (-1);
}