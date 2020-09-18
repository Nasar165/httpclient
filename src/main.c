#include <stdio.h>        // printf
#include <string.h>       // strlen
#include <stdlib.h>       // atoi
#include <ctype.h>        // isdigt
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
    uint16_t port;
    int err = 0;
    char resp[4096];
    if (argc <= 2)
        return error("Error: enter a domain and port: main.out <domain> <port>\n");

    for (int i = 0; i < strlen(argv[2]); i++)
        if (isalpha(argv[2][i]))
            return error("Error: you have entered a alpabetic value as port");

    port = atoi(argv[2]);
    if ((err = Get(argv[1], &port, resp)) != 0)
        return error("Http request failed\n");

    printf("%s\n", resp);

    return 0;
}