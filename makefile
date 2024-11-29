.PHONY : clean bin lib debug

clean :
	rm -rf bin/*.o lib/*.a

debug : clean
	gcc -g -c src/c-reporter-api.c -o bin/c-reporter-api.o
	gcc -g -c src/stopwatch.c -o bin/stopwatch.o

bin : clean
	gcc -c src/c-reporter-api.c -o bin/c-reporter-api.o
	gcc -c src/stopwatch.c -o bin/stopwatch.o

lib : clean bin
	ar -rcs lib/libc-reporter-api.a bin/c-reporter-api.o
	ar -rcs lib/libstopwatch.a bin/stopwatch.o

test : clean
	gcc -c src/stopwatch.c -o bin/stopwatch.o
	g++ -std=gnu++2b tests/stopwatch/test_zero_basetime.cpp bin/stopwatch.o -lcriterion -o tests/test_zero_basetime
	g++ -std=gnu++2b tests/stopwatch/test_pause_resume.cpp bin/stopwatch.o -lcriterion -o tests/test_pause_resume
	./tests/test_pause_resume
	./tests/test_zero_basetime