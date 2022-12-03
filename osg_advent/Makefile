CC=	cc
CFLAGS=	-std=c89 -Wall -Wextra -Werror -pedantic
01: 01.o
	$(CC) $(CFLAGS) 01.o -o 01
01.o: 01.c
	$(CC) $(CFLAGS) -c 01.c
clean:
	rm -f 01 01.o
