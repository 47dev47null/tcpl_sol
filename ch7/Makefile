SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c, %, $(SRCS))

BIN = bin

all: $(PROGS)

CC = gcc

CFLAGS = -Wall

%: %.c
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

clean:
	rm -f $(BIN)/*
