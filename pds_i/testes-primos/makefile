CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = main.c primalidade.c
OBJ = $(SRC:.c=.o)
HEADER = primalidade.h
TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
