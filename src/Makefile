CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
ifeq ($(shell uname), Linux)
	TST_LIBS += -lpthread -lrt -lsubunit -lm
endif
LIB_NAME = s21_parser
LIBS := -lcheck -lm
SRCS=$(wildcard parser/*.c data_containers/*.c)

OBJS=$(SRCS:.c=.o)

TESTS := cfiles/test_main.h cfiles/tests/parser_suits.c cfiles/tests/test_main.c

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIB_NAME).a: $(OBJS)
	ar rc $(LIB_NAME).a $^
	ranlib $(LIB_NAME).a
	rm -rf parser/*.o
	rm -rf data_containers/*.o

all: uninstall install dvi dist

install: delete_temp_build recreate_build_dir
	@mkdir .temp_build
	@cd .temp_build/ && qmake ../3dviewer/3dviewer.pro && make && mv 3dviewer.app ../build/3dviewer.app
	rm -rf .temp_build
uninstall: 
	@rm -rf build

tests: $(TESTS)
	@$(CC) $(CFLAGS)  $(LIBS) cfiles/c_libs/*.c $(TESTS) -o test.a
	@./test.a

add_coverage_flag:
	$(eval FLAGS += --coverage)

gcov_report:
	@$(CC) --coverage cfiles/tests/*.c cfiles/test_main.h  -o s21_test -lcheck cfiles/c_libs/*.c
	@./s21_test
	@lcov -t "s21_test" -o s21_test.info -c -d .
	@genhtml -o report s21_test.info
	@open ./report/index.html

dvi:
	@doxygen conf && mv html documentation
	@open documentation/index.html

dist:
	@rm -rf dist.tar.gz
	@tar -cvzf dist.tar.gz build/3dviewer.app

delete_temp_build:
	rm -rf .temp_build

recreate_build_dir:
	@rm -rf build
	@mkdir build

clean:
	rm -rf reports/* *.o test *.a *.gcno *.gcda *.gcov *.html *.css
	rm -rf data_containers/*.gcda data_containers/*.gcno
	rm -rf parser/*.gcda parser/*.gcno
	@rm -rf *.o *.a
	@rm -rf *.gcda *.gcno *.info
	@rm -rf s21_test report
	@rm -rf s21_calc s21_test
	@rm -rf ./build*


all: clean tests
