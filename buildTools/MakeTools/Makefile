#just one step
all: hello world

hello: hello.c
	cc hello.c -o hello


world:	world.c
	cc world.c -o world

clean:
	rm hello.o hello world world.o

# two steps
# hello: hello.o
# 	cc hello.o -o hello
# hello.o: hello.c
# 	cc -c hello.c 	

#using automatic variables
#hello: hello.o
#	cc $< -o $@
#hello.o: hello.c
#	cc -c $<	
