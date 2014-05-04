#include <stdio.h>
 #include <stdlib.h>
#include "udp.h"
#include "mfs.h"

#define BUFFER_SIZE (4096)


int port;
char *image;

void getargs(int *port, char *image, int argc, char *argv[]) {

    if (argc != 3) {
	fprintf(stderr, "Usage0: %s [port] [disk-image] \n", argv[0]);
	exit(1);
    }
    *port = atoi(argv[1]);
    strcpy(image, argv[2]);

}








int
main(int argc, char *argv[])
{
   
     image = malloc(8096);
    getargs(&port,image,argc,argv);
    int sd = UDP_Open(port);
    assert(sd > -1);

    printf("                                SERVER:: waiting in loop\n");

    while (1) {
	    struct sockaddr_in s;
	    //char buffer[BUFFER_SIZE];
	    
	    MFS_package_t *package;
	    package = malloc(sizeof(struct __MFS_package_t));
	    
	    int rc = UDP_Read(sd, &s, package, sizeof(struct __MFS_package_t));
	    if (rc > 0) {
	        //printf("                                SERVER:: read %d bytes (message: '%s')\n", rc, package);
	        
	        printf("current package num: %d\n", package->function);
	        package->function = 2;
	        
	        //char reply[BUFFER_SIZE];
	        //sprintf(reply, "reply");
	        rc = UDP_Write(sd, &s, package, sizeof(struct __MFS_package_t));
	    }
    }

    return 0;
}


