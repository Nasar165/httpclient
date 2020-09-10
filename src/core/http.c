#include <stdio.h>
#include <string.h>          //memset
#include <sys/socket.h>      // socket connect
#include <netinet/in.h>      // all socket funtions
#include <arpa/inet.h>       // inet_pton htons
#include <netinet/in.h>      // all socket funtions
#include <unistd.h>          // write
#include "../common/error.h" // Error
#include "dns.h"             // Resolve

#define BUFFER 4096
#define SA struct sockaddr

int Get(char *domain, uint16_t *port)
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
    printf("%d", err);

    // slash after get represents a url
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", domain);
    sendBytes = strlen(request);

    if (write(sock, request, sendBytes) != sendBytes)
        return error("Failed to write to response");

    memset(&response, 0, sizeof(response));

    while ((n = read(sock, response, BUFFER - 1)) > 0)
        printf("%s\n", response);

    if (n < 0)
        return error("Failed to read from response");

    return 0;
}