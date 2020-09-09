#include <stdio.h>        // printf
#include "core/dns.h"     // Resolve
#include "core/http.h"    // Get
#include "common/error.h" // errror

// Test DNS Only
/*int main(int argc, char *argv[])
{
    if (argc <= 1)
        return error("Error: enter a domain : main.out <domain>\n");

    printf("Resolving %s\n", argv[1]);
    int err;
    char ip[256];
    err = resolve(argv[1], ip);

    if (ip != NULL && err == 0)
        printf("%s\n", ip);
    return 0;
}*/

// TEST DNS AND HTTP GET
int main(int argc, char *argv[])
{
    if (argc <= 1)
        return error("Error: enter a domain : main.out <domain>\n");

    return 0;
}