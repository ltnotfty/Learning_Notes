CFLAGS= -Wall -g


test: test.o ipUtils.o
	cc ${CFLAGS} $^ -o $@

test.o: test.c  
	cc ${CFLAGS} -c $<
ipUtils.o: ipUtils.c ipUtils.h
	cc ${CFLAGS} -c ipUtils.c 

clean: 
	-rm test.o ipUtils.o test
