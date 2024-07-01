CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = main.c
OBJ = $(SRC:.c=.o)
TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
