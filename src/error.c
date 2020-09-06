#include <stdio.h>  // vfprintf, fprintf, fflush
#include <string.h> // strerror
#include <errno.h>  // errno
#include <stdarg.h> // va_list, va_start, va_end
#include <unistd.h> // _exit

void error(short int exit, const char *fmt, ...)
{
    int errno_save;

    errno_save = errno;

    printf("Error message: %s\n", fmt);
    fflush(stdout);

    if (errno_save != 0)
        printf("(errno = %d) : %s\n", errno_save, strerror(errno_save));

    if (exit)
        _exit(1);
}