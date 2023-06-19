
all: client server


client: client.c
	cc -Wall $< -o $@

server: server.c
	cc -Wall $< -o $@

usingSelect: usingSelect.c
	cc -Wall  $< -o $@

clean: 
	-rm  client server usingSelect
