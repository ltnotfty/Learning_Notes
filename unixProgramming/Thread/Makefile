TARGET=


pthread_create: pthread_create.c
	cc -Wall $< -o $@

TARGET+= pthread_create

pthread_simple: pthread_simple.c
	cc -Wall $< -o $@

TARGET+= pthread_simple


all: ${TARGET}

clean:
	-rm ${TARGET}
