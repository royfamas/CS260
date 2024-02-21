CC=g++
CFLAGS=-Wall

all: main

main: linked_list.o array_list.o main.o
	$(CC) $(CFLAGS) linked_list.o array_list.o main.o -o main

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main
