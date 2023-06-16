#just one step
all: hello world

hello: hello.c mymath.o
	cc hello.c mymath.o -o hello
world:	world.c
	cc world.c -o world

mymath.o: myMath.c myMath.h
	cc -c myMath.c  
clean:
	rm *.o hello world

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
