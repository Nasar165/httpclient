#include <stdio.h>  // printf
#include <string.h> // strerror
#include <errno.h>  // errno
#include <stdarg.h> // va_list, va_start, va_end
#include <unistd.h> // _exit

void error(char *msg, ...)
{
    int error = errno;
    printf("%s", msg);
    if (errno != 0)
    {
        printf("(errno = %d) : %s\n", error, strerror(error));
        printf("\n");
    }
}

void error_n_die(char *msg)
{
    error(msg);
    _exit(1);
}