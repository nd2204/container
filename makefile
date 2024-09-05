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
LIB_DIR := lib

# Source files and object files
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.c.o, $(SRCS))

# Executable target
TARGET := $(LIB_DIR)/libcontainer.a

# Test executable target
 
TEST_TARGETS := $(patsubst $(TEST_DIR)/%.c, %, $(wildcard $(TEST_DIR)/*.c))

#-------------------------------------------------------------
# rules
#-------------------------------------------------------------

# Default rules
all: $(TARGET) $(TEST_TARGETS)
	@echo "[v] all completed"

# Run tests
run: $(TEST_TARGETS)
	@echo "[*] Running $(target)..."
	@$(BIN_DIR)/$(target) $(ARGS)

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
$(TEST_TARGETS): $(OBJS) $(wildcard $(TEST_DIR)/*.c) | $(BIN_DIR)
	@echo "[*] Linking object files to create $@"
	$(CC) -g $(CFLAGS) $(OBJS) $(TEST_DIR)/$@.c -o $(BIN_DIR)/$@ $(LDFLAGS)

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
