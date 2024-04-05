debug:
	gcc -g -c src/timer.c -o timer.o
	gcc -g -c src/c-reporter-api.c -o c-reporter-api.o

main:
	gcc -c src/timer.c -o timer.o
	gcc -c src/c-reporter-api.c -o c-reporter-api.o

