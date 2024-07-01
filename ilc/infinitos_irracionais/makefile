CC      = gcc
CFLAGS  = -Wall -Wextra -g
MYFLAGS = -lm
SRC     = main.c
OBJ     = $(SRC:.c=.o)
TARGET  = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(MYFLAGS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $< $(MYFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
