//!
//! @file show_help.c
//! @author jbruel
//! @date 11/02/19
//!

#include <unistd.h>
#include <memory.h>

/**
 * Display the application help to standard output.
 */
void    show_help(int argc, const char * const *argv)
{
    if (argc >= 1 && argv != NULL && argv[0] != NULL)
    {
       write(1, "Usage: ", strlen("Usage: "));
       write(1, argv[0], strlen(argv[0]));
       write(1, " [OPTION]\n\n", strlen(" [OPTION]\n\n"));
    }
    write(1, "Test application. Give the ability to the user to launch manually or automatically errors handle by the faillist application.\n",
             strlen("Test application. Give the ability to the user to launch manually or automatically errors handle by the faillist application.\n"));
    write(1, "Raise error application. Warning, this application does not handle invalid raised error, errors are handle by the faillist application.\n\n",
             strlen("Raise error application. Warning, this application does not handle invalid raised error, errors are handle by the faillist application.\n\n"));
    write(1, "  -h [--help]              Display this help and quit.\n",
          strlen("  -h [--help]              Display this help and quit.\n"));
    write(1, "  --faillist [APP_PATH]    Call the faillist application and raised error to the faillist.\n",
          strlen("  --faillist [APP_PATH]    Call the faillist application and raised error to the faillist.\n"));
    write(1, "  --automatic [NB_FAILURE] Create randomly errors, user give the number of error needed to be generate.\n",
          strlen("  --automatic [NB_FAILURE] Create randomly errors, user give the number of error needed to be generate.\n"));
    write(1, "  --manual [ERR_FILE_PATH] Generate user error code, user give all errors information with full path files.\n\n",
          strlen("  --manual [ERR_FILE_PATH] Generate user error code, user give all errors information with full path files.\n\n"));
    write(1, "APP_PATH: Path to the faillist application.\n",
          strlen("APP_PATH: Path to the faillist application.\n"));
    write(1, "NB_FAILURE: The number of failure that the application will generate randomly. Maximum 999, if upper than 999, 999 errors will be generated.\n",
          strlen("NB_FAILURE: The number of failure that the application will generate randomly. Maximum 999, if upper than 999, 999 errors will be generated.\n"));
    write(1, "ERR_FILE_PATH: The full file path to the user manually error.\n",
          strlen("ERR_FILE_PATH: The full file path to the user manually error.\n"));
    write(1, "               The information must follow the faillist raised error format.\n",
          strlen("               The information must follow the faillist raised error format.\n"));
    write(1, "               WARNING: The file must contain one error code with 1, 2 or 3 maximum failures.\n",
          strlen("               WARNING: The file must contain one error code with 1, 2 or 3 maximum failures.\n"));
}