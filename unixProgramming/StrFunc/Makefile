
TARGET=



TARGET += useStrdup
TARGET += useGetOpt
TARGET += useGetOptLong

useStrdup: useStrdup.c
	cc -Wall $< -o $@
useGetOpt: useGetOpt.c
	cc -Wall $< -o $@
useGetOptLong: useGetOptLong.c
	cc -Wall $< -o $@


all: ${TARGET}

clean: 
	-rm ${TARGET}

