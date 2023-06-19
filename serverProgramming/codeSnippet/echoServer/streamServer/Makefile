all: client server
server: server.c
	cc -Wall -g $< -o $@


client: client.c
	cc -Wall -g $< -o $@


clean: 
	-rm client server 
