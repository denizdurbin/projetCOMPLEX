# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Files
SRCS = main.c arbrecartesien.c
OBJS = $(SRCS:.c=.o)
DEPS = arbrecartesien.h

# Output executable
EXEC = main

# Default target
all: $(EXEC)

# Linking
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Compile source files into object files
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and the executable
clean:
	rm -f $(OBJS) $(EXEC)

# Run the program with Valgrind
valgrind: $(EXEC)
	valgrind --leak-check=full --track-origins=yes ./$(EXEC)

# Phony targets
.PHONY: all clean valgrind
