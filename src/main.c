#include <stdio.h>
#include "common/error.h"

int main()
{
    FILE *file = fopen("/home/asd", "r");
    if (file == NULL)
        error_n_die("Could not find the file\n");

    printf("hello world");
    return 0;
}