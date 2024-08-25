CC := gcc

# Compiler and flags
CC := gcc
CFLAGS := -Wall -O2 -Iinclude
# LDFLAGS := -Llib -lm

# Directories
SRC_DIR := src
OBJ_DIR := build/obj
BIN_DIR := build/bin
INC_DIR := include
TEST_DIR := tests

# Source files and object files
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.c.o, $(SRCS))

# Executable target
TARGET := $(LIB_DIR)/libcontainer.a

# Test executable target
TEST_TARGET := $(BIN_DIR)/test_list.c

#-------------------------------------------------------------
# rules
#-------------------------------------------------------------

# Default rules
all: $(TARGET)

# Run tests
test: $(TEST_TARGET)
	@echo "[*] Running $^..."
	@$^ $(ARGS)

# Clean up build artifacts
clean:
	@echo "Cleaning up..."
	rm -rf $(OBJ_DIR) $(BIN_DIR)

#-------------------------------------------------------------
# Rules for linking
#-------------------------------------------------------------

# Link object files to create the executable
$(TARGET): $(OBJS) | $(LIB_DIR)
	@echo "[*] building library"
	ar rcs $@ $^

#-------------------------------------------------------------
# Rules for compiling to object
#-------------------------------------------------------------

# Compile and link test source files to src object
$(TEST_TARGET): $(OBJS) $(wildcard $(TEST_DIR)/*.c) | $(BIN_DIR)
	@echo "[*] Linking object files to create $@"
	$(CC) $(CFLAGS) $(OBJS) $(wildcard $(TEST_DIR)/*.c) -o $(TEST_TARGET) $(LDFLAGS)

# Compile source files to object files
$(OBJ_DIR)/%.c.o: $(SRC_DIR)/%.c compiling_echo | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#-------------------------------------------------------------
# Auxiliary Rules
#-------------------------------------------------------------

compiling_echo:
	@echo "[*] Compiling source files"

# Ensure build directories exist
$(OBJ_DIR):
	@mkdir -p $@

$(LIB_DIR):
	@mkdir -p $@

$(BIN_DIR):
	@mkdir -p $@

# Phony targets
.PHONY: all clean test
