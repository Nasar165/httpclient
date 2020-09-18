#ifndef FUNCTIONS_HTTP
#define FUNCTIONS_HTTP

#include <stdint.h>

#define BUFFER 4096

struct Http
{
    char protocol[10];
    char method[6];
    char *domain;
    char *url;
    uint16_t port;
    char ip[15];
    char header[30][150];
    char body[BUFFER];
};

int Get(char *domain, struct Http *http);

#endif