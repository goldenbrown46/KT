all: test

test: peri.o area.o test_func.o
	gcc peri.o area.o test_func.o -o test

peri.o: peri.c
	gcc -c peri.c -I./include

area.o: area.c
	gcc -c area.c -I./include

test_func.o: test_func.c
	gcc -c test_func.c -I./include
