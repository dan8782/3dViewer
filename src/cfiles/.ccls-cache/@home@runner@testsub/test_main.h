#ifndef SRC_TESTS_TEST_MAIN_H_
#define SRC_TESTS_TEST_MAIN_H_
#define MINUS_SIGN 2147483648
#include "s21_decimal.h"
Suite *suite_s21_sub(void);
void do_suite(Suite *suite, int *res);
#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))
#endif  //  SRC_TESTS_TEST_MAIN_H_
