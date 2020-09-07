#include <stdio.h>  // vfprintf, fprintf, fflush
#include <string.h> // strerror
#include <errno.h>  // errno
#include <stdarg.h> // va_list, va_start, va_end
#include <unistd.h> // _exit

void error(char *msg, ...)
{
    printf("%s", msg);
}

void error_n_die(char *msg)
{
    error(msg);
    _exit(1);
}
