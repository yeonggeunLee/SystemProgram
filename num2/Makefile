CC = gcc
CFLAGS = -Wall

SRC_DIR = src
LIB_DIR = lib
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

EXECUTABLE = main

LIBRARY_STATIC = _Arithmetic
LIBRARY_SHARED = _Arithmetic_shared
LIBRARY_DYNAMIC = _Arithmetic_dynamic

all: $(EXECUTABLE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIB_DIR) -l$(LIBRARY_STATIC)

static: $(EXECUTABLE)

shared: $(EXECUTABLE)
	$(CC) -o $@ $(OBJS) -L$(LIB_DIR) -l$(LIBRARY_SHARED)

dynamic: $(EXECUTABLE)
	$(CC) -o $@ $(OBJS) -L$(LIB_DIR) -l$(LIBRARY_DYNAMIC)

clean:
	rm -f $(OBJS) $(EXECUTABLE) static shared dynamic

