CC = gcc
CFLAGS = -Wall -Wextra -g
MY_FLAGS = -lm
SRC = main.c
OBJ = $(SRC:.c=.o)
TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(MY_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(MY_FLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
