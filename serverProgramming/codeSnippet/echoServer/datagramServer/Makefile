all: server client

client: client.c
	cc -Wall -g $< -o $@

server: server.c
	cc -Wall -g $< -o $@


clean:
	-rm server client
