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
    struct Http request, response;
    int err = 0;

    if (argc <= 2)
        return error("Error: enter a domain and port: main.out <domain> <port>\n");
    request.domain = argv[1];

    for (int i = 0; i < strlen(argv[2]); i++)
        if (isalpha(argv[2][i]))
            return error("Error: you have entered a alpabetic value as port");

    request.port = atoi(argv[2]);

    separateUrlFromDomain(request.domain, request.url);

    strcpy(request.protocol, "HTTP/1.1");
    strcpy(request.method, "GET");

    request.header[0] = addHeader("keep-alive:", "close");
    request.header[1] = addHeader("Authorization:", "Bearer adqdada87dasd7165e81hdnl");
    request.header[2] = addHeader("Content-Type:", "Application/json");

    if ((err = fetch(&request, &response)) != 0)
        return error("Http request failed\n");

    printf("\nProtocol : %s\n", response.protocol);
    printf("Method \t : %s\n", response.method);
    printf("Domain \t : %s\n", response.domain);
    printf("URL \t : %s\n", response.url);
    printf("Port \t : %d\n", response.port);
    printf("IP \t : %s\n", response.ip);

    printf("\nHeaders :\n");
    for (int i = 0; i < 30; i++)
        if (response.header[i].name != NULL)
            printf("%d. : %s %s\n", i, response.header[i].name, response.header[i].value);
        else
            break;

    printf("\nBody\n");
    printf("Body \t : %s\n", response.body);

    return 0;
}