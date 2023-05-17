CC=gcc
CFLAGS=-Werror -Wpedantic -Wextra
DEPSS= Liste.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: main.o liste.o
	$(CC) -o main.exe main.o liste.o $(CFLAGS)

clean: 
	rm *.o