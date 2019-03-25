//!
//! @file test_file_reader.c
//! @author jbruel
//! @date 11/02/19
//!

#include <np.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include "file_handling/file_reader.h"
#include "test_file_reader.h"

static ssize_t mock_read(__attribute__((unused)) int fd,
                         __attribute__((unused)) void *buf,
                         __attribute__((unused)) size_t count)
{
    return (-1);
}

// ------------------------- STARTING TESTS -------------------------

static void test_file_reader_BR1_CS1( void )
{
    // Test case 1 : INS_001 with inflexion value NULL.

    // Parameters
    char    in[FILE_MAX_SIZE]; // File content.
    bool    ret = false; // Return status

    printf( "**** Run test case 1 on branch 1 => Check INS_001 with inflexion value NULL.\n");

    // -----
    // Run function
    ret = file_reader(NULL, in);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_file_reader_BR2_CS2( void )
{
    // Test case 2 : INS_002 with inflexion value NULL.

    // Parameters
    char    *filename = "./test"; // File name to open and read.
    bool    ret = false; // Return status

    printf( "**** Run test case 2 on branch 2 => Check INS_002 with inflexion value NULL.\n");

    // -----
    // Run function
    ret = file_reader(filename, NULL);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}


static void test_file_reader_BR3_CS3( void )
{
    // Test case 3 : INS_010 with inflexion value -1.

    // Parameters
    char    *filename = "./no_existing_file.test"; // File name to open and read.
    char    in[FILE_MAX_SIZE]; // File content.
    bool    ret = false; // Return status

    printf( "**** Run test case 3 on branch 3 => Check INS_010 with inflexion value -1.\n");

    // -----
    // Run function
    ret = file_reader(filename, in);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_file_reader_BR4_CS4( void )
{
    // Test case 4 : INS_017 with inflexion value -1.

    // Parameters
    char    *filename = "./error_read"; // File name to open and read.
    char    in[FILE_MAX_SIZE]; // File content.
    bool    ret = false; // Return status
    int     fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644); // File director for opened file.

    printf( "**** Run test case 4 on branch 4 => Check INS_017 with inflexion value -1.\n");

    // -----
    // Mocks
    // Link mock mock_read with -1 value for INS_017
    np_mock(read, mock_read);

    write(fd, "same random content...", strlen("same random content..."));
    close(fd);

    // -----
    // Run function
    ret = file_reader(filename, in);

    remove(filename);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_file_reader_BR5_CS5( void )
{
    // Test case 5 : full branch, normal case.

    // Parameters
    char    *filename = "./file_read_normal"; // File name to open and read.
    char    in[FILE_MAX_SIZE]; // File content.
    bool    ret = false; // Return status
    int     fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644); // File director for opened file.

    printf( "**** Run test case 5 on branch 5 => Check full branch, normal case.\n");
    write(fd, "same random content...", strlen("same random content..."));
    close(fd);

    // -----
    // Run function
    ret = file_reader(filename, in);

    remove(filename);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}
