.PHONY : clean bin lib debug

clean :
	rm -rf bin/*.o lib/*.a

debug : clean
	gcc -g -c src/c-reporter-api.c -o bin/c-reporter-api.o
	gcc -g -c src/timer.c -o bin/timer.o

bin : clean
	gcc -c src/c-reporter-api.c -o bin/c-reporter-api.o
	gcc -c src/timer.c -o bin/timer.o

lib : clean bin
	ar -rcs lib/libc-reporter-api.a bin/c-reporter-api.o
	ar -rcs lib/libtimer.a bin/timer.o
