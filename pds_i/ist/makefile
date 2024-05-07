CC = gcc
CFLAGS = -Wall -Wextra -g
MY_FLAGS = -lm
SRC = main.c string_inaue.c
OBJ = $(SRC:.c=.o)
HEADER = string_inaue.h
TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(MY_FLAGS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $< $(MY_FLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
