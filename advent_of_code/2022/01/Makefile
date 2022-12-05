CC=	cc
CFLAGS=	-std=c89 -Wall -Wextra -Wpedantic -Wshadow -Werror
.PHONY:	clean
01: 01.o
	$(CC) $(CFLAGS) 01.o -o 01.out
01.o: 01.c
	$(CC) $(CFLAGS) -c 01.c
clean:
	rm -f 01.o 01.out
