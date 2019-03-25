//!
//! @file test_write_id_plane.c
//! @author jbruel
//! @date 04/03/19
//!

#include <np.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "report/id_plane/write_id_plane.h"
#include "test_write_id_plane.h"

// ------------------------- STARTING TESTS -------------------------

static void test_write_id_plane_BR1_CS1( void )
{
    // Test case 1 : INS_002 with inflexion value false.

    // Parameters
    int             fd = 1; // File directory.
    unsigned char   *raised_id_plane = malloc(sizeof(unsigned char) * 6); // Id plane prefix.

    strcpy((char *)raised_id_plane, "abcde");
    raised_id_plane[5] = '\0';
    printf( "**** Run test case 1 on branch 1 => Check INS_002 with inflexion value false.\n");

    // -----
    // Run function
    write_id_plane(fd, raised_id_plane);
    free(raised_id_plane);
}

static void test_write_id_plane_BR2_CS2( void )
{
    // Test case 2 : INS_002 with inflexion value true.

    // Parameters
    int             fd = 1; // File directory.
    unsigned char   *raised_id_plane = malloc(sizeof(unsigned char) * 3); // Id plane prefix.

    strcpy((char *)raised_id_plane, "D2");
    raised_id_plane[2] = '\0';
    printf( "**** Run test case 2 on branch 2 => Check INS_002 with inflexion value true.\n");

    // -----
    // Run function
    write_id_plane(fd, raised_id_plane);
    free(raised_id_plane);
}