CC=gcc
CFLAGS=-O3 -march=native -g -flto
DEPS=strl.h
OBJ=strl.o tst1.o tst2.o

all: tst1 tst2

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tst1: tst1.o strl.o
	$(CC) -flto -o tst1 tst1.o strl.o

tst2: tst2.o strl.o
	$(CC) -flto -o tst2 tst2.o strl.o

clean:
	rm tst1 tst2 $(OBJ)
