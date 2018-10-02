#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>


int main (int argc, char * argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Enter a valid URL as argv[1]\n");
        return 0;
    }

    struct hostent * res = gethostbyname(argv[1]); 
    if (res == NULL) {
        fprintf(stderr, "Whoops, no host by that name!\n");
        return 1;
    }

    /*
       struct hostent {
       char  *h_name;            
       char **h_aliases;         
       int    h_addrtype;        
       int    h_length;          
       char **h_addr_list;       
       }
       */

    // Now extract the address
    
    /*
     struct in_addr {
         unsigned long s_addr;  // load with inet_aton()
     };
     */

    struct in_addr * ip = (struct in_addr *) res->h_addr_list[0];
    char * addr = inet_ntoa(*ip);

    printf("Host: %s\n"
           "Has aliases: %s\n"
           "And an IP address of: %s\n", res->h_name, res->h_aliases[0], addr);


    return 0;
}
