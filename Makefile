# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Directories
INCLUDE_DIR = include
SRC_DIR = src

# Source files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/keyboard.c $(SRC_DIR)/screen.c $(SRC_DIR)/timer.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable
TARGET = jogoAED

# Include directories
INC_DIRS = -I$(INCLUDE_DIR)

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) $(INC_DIRS) -c -o $@ $<

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean ups
clean:
	rm -f $(OBJS) $(TARGET)

