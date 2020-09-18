#include <stdio.h>           // sprintf
#include <string.h>          // memset strncpy
#include <sys/socket.h>      // socket connect
#include <netinet/in.h>      // all socket funtions
#include <arpa/inet.h>       // inet_pton htons
#include <netinet/in.h>      // all socket funtions
#include <unistd.h>          // write
#include "dns.h"             // Resolve
#include "../common/error.h" // Error

#define BUFFER 4096
#define SA struct sockaddr

int Get(char *domain, uint16_t *port, char *resp)
{
    int err, n, sock, sendBytes;
    char ip[15];
    struct sockaddr_in server;
    char request[BUFFER];
    char response[BUFFER];

    if ((err = resolve(domain, ip)) != 0)
        return error("An error has occurred fetching the ip of the domain");

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) // Init TCP socket
        return error("Failed to create Socket");

    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(*port);

    if ((inet_pton(AF_INET, ip, &server.sin_addr)) <= 0)
        return error("Unable to convert ip address to binary form");

    if ((err = connect(sock, (SA *)&server, sizeof(server))) < 0)
        return error("Failed to connect to the server");

    // slash after get represents a url
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", domain);
    sendBytes = strlen(request);

    if (write(sock, request, sendBytes) != sendBytes)
        return error("Failed to write to response");

    memset(&response, 0, sizeof(response));

    while ((n = read(sock, response, BUFFER - 1)) > 0)
        strncpy(resp, response, sizeof(response));

    if (n < 0)
        return error("Failed to read from response");

    return 0;
}