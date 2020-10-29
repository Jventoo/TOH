CFLAGS=-Wall -Wextra -Werror -pedantic
CC=clang $(CFLAGS)

tower	:	tower.o
	$(CC) -o tower tower.o -lm
tower.o	:	tower.c
	$(CC) -c tower.c
all		:	tower	
clean	:
	rm -f tower tower.o
infer	:
	make clean; infer-capture -- make; infer-analyze -- make