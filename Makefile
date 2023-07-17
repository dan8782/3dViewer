GCC :=  gcc
FLAGS :=  -std=c11 -Wall -Werror -Wextra -g -O
LIBS := -lcheck -lm
 
TEST_DIR := ./tests
LIB_DIR := ./c_libs

LIB_OBJ := $(LIB_DIR)/*.c
TESTS := $(TEST_DIR)/*.c

all: clean test
main:
	clean test


main-debug: $(GCC) $(CFLAGS) -O0 $(LIBS) $(LIB_OBJ) $(TESTS) -o test.a

test: $(TESTS)
	$(GCC) $(CFLAGS)  $(LIBS) $(LIB_OBJ) $(TESTS) -o test.a

clean:
	rm -f test.a