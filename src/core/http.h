#ifndef FUNCTIONS_HTTP
#define FUNCTIONS_HTTP

#include <stdint.h>

#define BUFFER 4096    // Max content length of the Http Response
#define MAXLENGTH 2048 // Max length for the url

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
    char url[MAXLENGTH];
    uint16_t port;
    char ip[15];
    struct Header header[30];
    char body[BUFFER];
};

struct Header addHeader(char *name, char *value);

int fetch(struct Http *request, struct Http *response);

#endif