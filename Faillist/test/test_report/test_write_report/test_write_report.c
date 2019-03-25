//!
//! @file test_write_report.c
//! @author jbruel
//! @date 04/03/19
//!

#include <np.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "report/write_report.h"
#include "report/open_report.h"
#include "report/init_report.h"
#include "report/faillure/write_failure.h"
#include "test_write_report.h"

bool    mock_write_failure_return_false(__attribute__((unused)) int fd,
                                        __attribute__((unused)) size_t idx,
                                        __attribute__((unused)) struct failure *failure)
{
    if (failure->level_criticity == 2)
        return (false);
    return (true);
}

// ------------------------- STARTING TESTS -------------------------

static void test_write_report_BR1_CS1( void )
{
    // Test case 1 : INS_005 with inflexion value NULL.

    // Parameters
    struct report   *raised_error = NULL; // Raised errors.
    int             fd = 3;

    printf( "**** Run test case 1 on branch 1 => Check INS_005 with inflexion value NULL.\n");

    // -----
    // Run function
    write_report(fd, raised_error);
}

static void test_write_report_BR2_CS2( void )
{
    // Test case 2 : INS_006 with inflexion value -1.

    // Parameters
    struct report   raised_error; // Raised errors.
    int             fd = -1;

    printf( "**** Run test case 2 on branch 2 => Check INS_006 with inflexion value -1.\n");

    // -----
    // Run function
    write_report(fd, &raised_error);
}

static void test_write_report_BR3_CS3( void )
{
    // Test case 3 : Full branch 3 test.

    // Parameters
    struct report   raised_error; // Raised errors.

    init_report(&raised_error);

    int             fd = open_report(&raised_error); // file director.

    printf( "**** Run test case 3 on branch 3 => Check full branch.\n");

    // -----
    // Run function
    write_report(fd, &raised_error);
    close(fd);
}

static void test_write_report_BR4_CS4( void )
{
    // Test case 4 : Full branch 4 test with empty file.

    // Parameters
    struct report   raised_error; // Raised errors.

    init_report(&raised_error);

    int             fd = open("./ut-write_report", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH); // file director

    printf( "**** Run test case 4 on branch 4 => Check full branch with empty file.\n");

    // -----
    // Run function
    write_report(fd, &raised_error);
    close(fd);
    remove("./ut-write_report");
}

static void test_write_report_BR4_CS5( void )
{
    // Test case 5 : Full branch 4 test.

    // Parameters
    struct report   raised_error; // Raised errors.

    init_report(&raised_error);
    raised_error.nb_failures = 1;
    raised_error.faillures[0].id_failure = 0;
    raised_error.faillures[0].date = 0;
    raised_error.faillures[0].id_component = 0;
    raised_error.faillures[0].level_criticity = 1;
    raised_error.faillures[0].comment_failure_size = 1;
    memset(raised_error.faillures[0].comment_failure, '\0', MAX_COMMENT_SIZE);
    memset(raised_error.faillures[0].comment_failure, 'a', MAX_COMMENT_SIZE - 1);

    int             fd = open_report(&raised_error); // file director.

    printf( "**** Run test case 5 on branch 4 => Check full branch.\n");

    // -----
    // Run function
    write_report(fd, &raised_error);
    close(fd);
}

static void test_write_report_BR5_CS5( void )
{
    // Test case 6 : Check INS_014 with true inflexion value.

    // Parameters
    struct report   raised_error; // Raised errors.

    init_report(&raised_error);
    raised_error.nb_failures = 2;
    raised_error.faillures[0].id_failure = 0;
    raised_error.faillures[0].date = 0;
    raised_error.faillures[0].id_component = 0;
    raised_error.faillures[0].level_criticity = 1;
    raised_error.faillures[0].comment_failure_size = 1;
    memset(raised_error.faillures[0].comment_failure, '\0', MAX_COMMENT_SIZE);
    memset(raised_error.faillures[0].comment_failure, 'a', MAX_COMMENT_SIZE - 1);
    raised_error.faillures[1].id_failure = 0;
    raised_error.faillures[1].date = 0;
    raised_error.faillures[1].id_component = 0;
    raised_error.faillures[1].level_criticity = 2;
    raised_error.faillures[1].comment_failure_size = 1;
    memset(raised_error.faillures[1].comment_failure, '\0', MAX_COMMENT_SIZE);
    memset(raised_error.faillures[1].comment_failure, 'a', MAX_COMMENT_SIZE - 1);

    int             fd = open_report(&raised_error); // file director.

    printf( "**** Run test case 6 on branch 5 => Check INS_014 with inflexion value true\n");

    // -----
    // Mocks
    // Link mock mock_write_failure_id_true with true value for INS_008
    np_mock(write_failure, mock_write_failure_return_false);
    // -----
    // Run function
    write_report(fd, &raised_error);
    close(fd);
}