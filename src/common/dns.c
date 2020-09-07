#include <stdio.h>     // NULL
#include <netdb.h>     // hostent
#include <string.h>    // strcpy
#include <arpa/inet.h> // inet_ntoa
#include "error.h"     // error
#include <errno.h>
int resolve(char *domain, char *ip)
{
    struct hostent *he;
    struct in_addr **addr_list;
    int i;

    if ((he = gethostbyname(domain)) == NULL)
    {
        printf("%s", errno);
        return error("Could not resolve the hostname");
    }

    addr_list = (struct in_addr **)he->h_addr_list;

    for (i = 0; addr_list[i] != NULL; i++)
    {
        //Return the first one;
        strcpy(ip, inet_ntoa(*addr_list[i]));
        return 0;
    }

    return 1;
}