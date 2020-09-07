#include <stdio.h>  // vfprintf, fprintf, fflush
#include <string.h> // strerror
#include <errno.h>  // errno
#include <stdarg.h> // va_list, va_start, va_end
#include <unistd.h> // _exit

void error(char *msg, ...)
{
    int error = errno;
    va_list ap;

    va_start(ap, msg);
    //prints error message to stderr and not stdout
    vfprintf(stderr, msg, ap);
    fprintf(stderr, "\n");
    fflush(stderr);

    if (errno != 0)
    {
        fprintf(stdout, "(errno = %d) : %s\n", error, strerror(error));
        fprintf(stdout, "\n");
        fflush(stdout);
    }
    va_end(ap);
}

void error_n_die(char *msg)
{
    error(msg);
    _exit(1);
}
