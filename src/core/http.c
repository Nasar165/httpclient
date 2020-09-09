#include <stdio.h>
#include <sys/socket.h>
#include "../common/error.h"
#include "dns.h"

void Get(char *domain)
{
    int err;
    char ip[15];
    err = resolve(domain, ip);
}