#include <stdio.h>           // NULL
#include <netdb.h>           // hostent addrinfo
#include <string.h>          // strcpy
#include <arpa/inet.h>       // inet_ntoa
#include <sys/socket.h>      // socket sendto perror
#include <unistd.h>          // close
#include "../common/error.h" // error

#define PORT "53"
#define MAXLENGTH 256

int resolve(char *domain, char *ip)
{
    if (strlen(domain) == 0 || domain == NULL)
        return error("Error: A domain name is required");

    int err, sock;
    char data_sent[MAXLENGTH];
    struct addrinfo hints, *result;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;    // change to AF_INET for ipv4 only
    hints.ai_socktype = SOCK_DGRAM; // Use TCP socket to connect to the DNS

    err = getaddrinfo(domain, PORT, &hints, &result);
    if (err != 0)
        return error("An error has occurred while getting address. %s.", gai_strerror(err));

    sock = socket(result->ai_family, result->ai_socktype, 0);
    if (sock < 0)
        return error("A socket error has occurred");

    err = sendto(sock, data_sent, sizeof(data_sent), 0, result->ai_addr, result->ai_addrlen);
    if (err < 0)
        return error("failed to send request to server");

    struct sockaddr_in *addr;
    addr = (struct sockaddr_in *)result->ai_addr;
    strcpy(ip, inet_ntoa((struct in_addr)addr->sin_addr));

    close(sock);
    freeaddrinfo(result);

    return 0;
}