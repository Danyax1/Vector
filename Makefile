CC = gcc
CFLAGC = -O2 -Wall -Wextra
TARGET = main

all: 
	@$(CC) $(CFLAGC) main.c Vector.c pprint.c -o $(TARGET)

clean:
	rm -rf *.o main