#ifndef FUNCTIONS_HTTP
#define FUNCTIONS_HTTP

#include <stdint.h>

#define BUFFER 4096

struct Header
{
    char *name;
    char *value;
};

struct Http
{
    char protocol[10];
    char method[6];
    char *domain;
    char *url;
    uint16_t port;
    char ip[15];
    struct Header header[30];
    char body[BUFFER];
};

int Get(char *domain, struct Http *http);

#endif