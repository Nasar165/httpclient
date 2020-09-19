#include <stdio.h>           // sprintf
#include <string.h>          // memset strncpy
#include <sys/socket.h>      // socket connect
#include <netinet/in.h>      // all socket funtions
#include <arpa/inet.h>       // inet_pton htons
#include <netinet/in.h>      // all socket funtions
#include <unistd.h>          // write
#include "dns.h"             // Resolve
#include "../common/error.h" // Error
#include "http.h"            // Http

#define SA struct sockaddr

int fetch(struct Http *request, struct Http *response)
{
    int err, n, sock, sendBytes;
    struct sockaddr_in server;
    char req[BUFFER];
    char resp[BUFFER];

    if ((err = resolve(request->domain, request->ip)) != 0)
        return error("An error has occurred fetching the ip of the domain");

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) // Init TCP socket
        return error("Failed to create Socket");

    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(request->port);

    if ((inet_pton(AF_INET, request->ip, &server.sin_addr)) <= 0)
        return error("Unable to convert ip address to binary form");

    if ((err = connect(sock, (SA *)&server, sizeof(server))) < 0)
        return error("Failed to connect to the server");

    // slash after get represents a url
    sprintf(req, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: keep-alive\r\n\r\n", request->domain);
    sendBytes = strlen(req);

    if (write(sock, req, sendBytes) != sendBytes)
        return error("Failed to write to response");

    memset(&resp, 0, sizeof(resp));

    while ((n = read(sock, resp, BUFFER - 1)) > 0)
        strncpy(response->body, resp, sizeof(resp));

    if (n < 0)
        return error("Failed to read from response");

    return 0;
}

struct Header addHeader(char *name, char *value)
{
    struct Header header;
    header.name = name;
    header.value = value;
    return header;
}
