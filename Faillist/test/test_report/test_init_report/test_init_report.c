//!
//! @file test_init_report.c
//! @author jbruel
//! @date 04/03/19
//!

#include <np.h>
#include <stdio.h>
#include "report/init_report.h"
#include "test_init_report.h"

// ------------------------- STARTING TESTS -------------------------

static void test_init_report_BR1_CS1( void )
{
    // Test case 1 : INS_001 with inflexion value NULL.

    // Parameters
    struct report   *raised_error = NULL; // Raised errors.

    printf( "**** Run test case 1 on branch 1 => Check INS_001 with inflexion value NULL.\n");

    // -----
    // Run function
    init_report(raised_error);
}

static void test_init_report_BR2_CS2( void )
{
    // Test case 2 : Full branch 2.

    // Parameters
    struct report   raised_error;// = malloc((sizeof(struct report))); // Raised errors.

    printf( "**** Run test case 2 on branch 2 => Check Full branch test.\n");

    // -----
    // Run function
    init_report(&raised_error);
}