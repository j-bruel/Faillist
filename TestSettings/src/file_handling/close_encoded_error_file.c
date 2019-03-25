//!
//! @file close_encoded_error_file.c
//! @author jbruel
//! @date 11/02/19
//!

#include <unistd.h>
#include <stdio.h>
#include "file_handling/close_encoded_error_file.h"

void close_encoded_error_file(int fd, const char *file_path)
{
    close(fd);
    remove(file_path);
    remove(".TestSettings");
}