CC   = gcc
OPTS = -Wall

all: server client library
#TODO: build shared lib

# this generates the target executables
server: server.o udp.o
	$(CC) -o server server.o udp.o 

client: client.o udp.o
	$(CC) -o client client.o udp.o 
library:client_library.c mfs.h
	$(CC) -c -fpic client_library.c -Wall -Werror
	$(CC) -shared -o libmfs.so client_library.o
# this is a generic rule for .o files 
%.o: %.c 
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -f server.o udp.o client.o server client
	rm -rf client_library.o libmfs.so	

