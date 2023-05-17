CC=gcc
CFLAGS=-Werror -Wpedantic -Wextra
DEPSS= Liste.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: main.o Liste.o
	$(CC) -o main.exe main.o Liste.o $(CFLAGS)

clean: 
	rm *.o
