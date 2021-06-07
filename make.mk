a.out: main.o fun.o
	gcc main.o fun.o
fun.o: fun.c server.h
	gcc -c fun.c
main.o: main.c server.h
	gcc -c main.c
