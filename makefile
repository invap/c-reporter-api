clean:
	rm -rf bin/*.o *.dSYM

debug:
	gcc -g -c src/c-reporter-api.c -o bin/c-reporter-api.o

main:
	gcc -c src/c-reporter-api.c -o bin/c-reporter-api.o

