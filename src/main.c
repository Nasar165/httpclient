#include <stdio.h>
#include "common/dns.h"
#include "common/error.h"

int main(int argc, char *argv[])
{

    if (argc <= 1)
        return error("Error: enter a domain : main.out <domain>\n");

    printf("Resolving %s\n", argv[1]);
    char ip[100];
    resolve(argv[1], ip);

    if (ip != NULL)
        printf("%s\n", ip);
    return 0;
}