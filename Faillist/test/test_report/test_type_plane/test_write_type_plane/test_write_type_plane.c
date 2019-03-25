//!
//! @file test_write_type_plane.c
//! @author jbruel
//! @date 04/03/19
//!

#include <np.h>
#include <stdio.h>
#include "report/type_plane/write_type_plane.h"
#include "test_write_type_plane.h"

// ------------------------- STARTING TESTS -------------------------

static void test_write_type_plane_BR1_CS1( void )
{
    // Test case 1 : INS_002 with inflexion value false.

    // Parameters
    int             fd = 1; // File directory.
    unsigned int    raised_type_plane = 0; // Type plane value.

    printf( "**** Run test case 1 on branch 1 => Check INS_002 with inflexion value false.\n");

    // -----
    // Run function
    write_type_plane(fd, raised_type_plane);
}

static void test_write_type_plane_BR2_CS2( void )
{
    // Test case 2 : INS_002 with inflexion value true.

    // Parameters
    int             fd = 1; // File directory.
    unsigned int    raised_type_plane = 380; // Type plane value.

    printf( "**** Run test case 2 on branch 2 => Check INS_002 with inflexion value true.\n");

    // -----
    // Run function
    write_type_plane(fd, raised_type_plane);
}