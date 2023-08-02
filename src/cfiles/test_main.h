#ifndef SRC_TESTS_TEST_MAIN_H_
#define SRC_TESTS_TEST_MAIN_H_
#include "s21_c_libs.h"
#include <check.h>

void do_suite(Suite *suite, int *res);

Suite *suite_parser(void);
#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))
#endif //  SRC_TESTS_TEST_MAIN_H_
