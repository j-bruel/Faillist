//!
//! @file filereader.c
//! @author jbruel
//! @date 11/02/19
//!

#include "file_handling/file_reader.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <memory.h>

/**
 * File reader.
 */
bool    file_reader(const char *filename, char *in)
{
    if (filename == NULL ||
        in == NULL)
        return (false);

    int fd = open(filename, O_RDONLY); // file directory, needed to open the file.
    int read_size = 0; // Read size.

    write(1, "Faillist: Open the file: ", strlen("Faillist: Open the file: "));
    write(1, filename, strlen(filename));
    write(1, ".\n", 2);
    if (fd == -1)
    {
        write(1, "Faillist: Impossible to open the next input file: ", strlen("Faillist: Impossible to open the next input file: "));
        write(1, filename, strlen(filename));
        write(1, ".\n", 2);
        return (false);
    }
    if ((read_size = (int)read(fd, in, FILE_MAX_SIZE)) == -1)
    {
        write(1, "Faillist: Impossible to read the next input file: ", strlen("Faillist: Impossible to read the next input file: "));
        write(1, filename, strlen(filename));
        write(1, ".\n", 2);
        close(fd);
        return (false);
    }
    in[read_size] = '\0';
    close(fd);
    return (true);
}