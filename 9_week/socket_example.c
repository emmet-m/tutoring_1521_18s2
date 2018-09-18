#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
 
// Burns and dies :(
void fatal(const char *msg)
{
    perror(msg);
    exit(0);
}

/*
 * A very commented version of the week 9 tut!
 *
 * All this information can be obtained by using man.
 *
 * There are two parts - Part (1), which attempts to connect to a server
 * on port 8080, and;
 *
 * Part (2), which sends a request to a provided route (e.g. "/index.html")
 *  on that server, using HTTP.
 */
 
int main(int argc, char *argv[])
{
    // Example usage:
    //
    //  ./socket_example "google.com" "/" "80"
    //
    //  Make sure there's a server running on localhost:8080 (or change the URL/port)
    //

    /*
     *
     * Part (1)
     *
     */

    // Sockets are managed by file descriptors, like files!
    // This is where we'll store our socket descriptor.
    int sockfd;
    // The Port Number uniquely identifies a process on the other end
    //  for us to connect to. The default for HTTP (almost all websites)
    //  is 80. SSH uses 22, for example
    int portno = atoi(argv[2]);
    // used as a counter
    int n;

    // Will store the address of the server we're connecting to!
    struct sockaddr_in serv_addr;
    // We'll use this to look a host server up by it's URL!
    struct hostent *server;
 
    // Provide a URL to look up
    if (argc < 4) {
        fprintf(stderr, "Usage: %s HOST PORT ROUTE\n", argv[0]);
        exit(1);
    }

    char buffer[BUFSIZ];
    // 'open' our socket for reading and writing. 
    // AF_INENT    = use ipv4
    // SOCK_STREAM = consistent stream of uninterrupted bytes
    // 0           = There's only one type of protocol for the AF_INET
    //               protocol family, so just use the default.
    //          See "man 2 socket"
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) fatal("ERROR socket");

    // Look up the server that goes by the provided hostname
    //      See 'man 3 gethostbyname'
    server = gethostbyname(argv[1]);
    if (server == NULL) fatal("ERROR gethost");

    // Clear the serv_addr struct
    bzero((char *)&serv_addr, sizeof(serv_addr));

    // Set it's connection type to ipv4
    serv_addr.sin_family = AF_INET;

    // Copy the host address to our serv_addr struct
    bcopy((char *)server->h_addr, 
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);

    // Set the port to provided port number, in the byte order (endianness) used by the network.
    //      See 'man 3 htons'
    serv_addr.sin_port = htons(portno);

    // Let's actually attempt to contact the server!
    // Connect our opened (but idle) socket to the address provided in 
    //   serv_addr.
    //      See 'man 2 connect'
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        fatal("ERROR connecting");

    /*
     *
     * Part (2) - Send a request to server
     *
     */

    // A HTTP format header. Google the protocol for more info!
    char *reqFmt = "GET %s HTTP/1.1\r\nHost: %s/\r\n\r\n";
    // Write the route in argv[1] to our format string
    sprintf(buffer, reqFmt, argv[3], argv[1]);

    puts(buffer);

    // Write to our socket descriptor, i.e. send information. Like a file!
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) fatal("ERROR writing to socket");

    // Wait for a response with read.. 
    printf("Response:\n");
    while ((n = read(sockfd,buffer,BUFSIZ)) > 0)
        // Probe with 1 byte until we actually read something
        write(1, buffer, n);

    // We never got a response
    if (n < 0) fatal("ERROR reading from socket");

    // Close our socket
    close(sockfd);
    return 0;
}
 
