CC = clang++
CFLAGS = -Wextra -Wall -std=c++20
ROOT = src
BIN = bin
OBJS=$(BIN)/main.o

main: main.o lexer.o utils.o
	$(CC) $(CFLAGS) -o main main.o lexer.o utils.o

main.o: $(ROOT)/main.cpp 
	$(CC) $(CFLAGS) -c $(ROOT)/main.cpp

lexer.o: $(ROOT)/lexer.cpp utils.o
	$(CC) $(CFLAGS) -c $(ROOT)/lexer.cpp

utils.o: $(ROOT)/utils.cpp
	$(CC) $(CFLAGS) -c $(ROOT)/utils.cpp

clean:
	rm -rf *.o
	rm main	