clean:
	rm -rf bin/*.o main.dSYM

debug:
	gcc -g -c src/c-reporter-api.c -o bin/c-reporter-api.o

main:
	gcc -c src/c-reporter-api.c -o bin/c-reporter-api.o

