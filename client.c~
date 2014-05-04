#include <stdio.h>
 #include <stdlib.h>
#include "udp.h"
#include "mfs.h"
#include "client_library.h"

#define BUFFER_SIZE (4096)
char buffer[BUFFER_SIZE];

int
main(int argc, char *argv[])
{
    //-1 give open port
    int sd = UDP_Open(0);
    assert(sd > -1);

    struct sockaddr_in saddr;
    //TODO: must change computer name it's on when on different machines
    int rc = UDP_FillSockAddr(&saddr, "mumble-02.cs.wisc.edu", 10000);
    assert(rc == 0);

    printf("CLIENT:: about to send message (%d)\n", rc);
    //char message[BUFFER_SIZE];
    //sprintf(message, "hello world");
    
    MFS_package_t *p;
    p = malloc(sizeof(struct __MFS_package_t));
    
    //TODO: remove for testing p->function = 1;
    
    //getting user input
    char buffer[4096];
    char *text;
    
    if (fgets(buffer, sizeof(buffer), stdin) != NULL ) {
      char *newline = strchr(buffer, '\n'); /* search for newline character */
      if ( newline != NULL ){
         *newline = '\0'; /* overwrite trailing newline */
      }
      text = buffer;
    }
    
    
    
    
    rc = UDP_Write(sd, &saddr, p, sizeof(struct __MFS_package_t));
    printf("CLIENT:: sent message (%d)\n", rc);
    if (rc > 0) {
	    struct sockaddr_in raddr;
	    int rc = UDP_Read(sd, &raddr, p, sizeof(struct __MFS_package_t));
	    //printf("CLIENT:: read %d bytes (message: '%s')\n", rc, buffer);
	    printf("I see: %d\n", p->function);
    }

    return 0;
}


