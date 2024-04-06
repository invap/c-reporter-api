.PHONY : clean bin lib

clean :
	rm -rf bin/*.o lib/*.a

bin : clean
	gcc -c src/c-reporter-api.c -o bin/c-reporter-api.o

lib : clean bin
	ar -rcs lib/libc-reporter-api.a bin/c-reporter-api.o
