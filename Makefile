CFLAGS=-Wall -Wextra -Werror -pedantic
CC=clang $(CFLAGS)

tower	:	tower.o stack.o
	$(CC) -o tower tower.o stack.o -lm
tower.o	:	tower.c stack.h
	$(CC) -c tower.c
stack.o :	stack.c stack.h
	$(CC) -c stack.c
all	:	tower	
clean	:
	rm -f tower tower.o stack.o
infer	:
	make clean; infer-capture -- make; infer-analyze -- make
