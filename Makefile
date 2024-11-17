# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source and header files
SRCS = arbrecartesien.c
DEPS = arbrecartesien.h

# Executable names
EXECS = main ex1e ex3d ex4d

# Default target
all: $(EXECS)

# Linking
main: main.o arbrecartesien.o
	$(CC) $(CFLAGS) -o $@ $^

ex1e: ex1e.o arbrecartesien.o
	$(CC) $(CFLAGS) -o $@ $^

ex3d: ex3d.o arbrecartesien.o
	$(CC) $(CFLAGS) -o $@ $^

ex4d: ex4d.o arbrecartesien.o
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and the executables
clean:
	rm -f *.o $(EXECS)

# Run the main program with Valgrind
valgrind: main
	valgrind --leak-check=full --track-origins=yes ./main

# Phony targets
.PHONY: all clean valgrind
