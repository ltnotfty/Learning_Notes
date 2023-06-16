all: client server

client: udpEchoClient.c
	cc $< -o $@
server: udpEchoServer.c
	cc $< -o $@



clean:
	rm client server
