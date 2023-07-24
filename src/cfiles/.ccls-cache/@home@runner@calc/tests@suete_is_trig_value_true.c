#include "../test_main.h"

START_TEST(is_trig_value_true_1) {
  char *input_string = "(x+2)*sin(2x)";

  int result = is_trig_value_true(input_string);
  ck_assert_int_eq(result, 1);
}

START_TEST(is_trig_value_true_2) {
  char *input_string = "(x+2)*sn(2x)";

  int result = is_trig_value_true(input_string);
  ck_assert_int_eq(result, 1);
}

START_TEST(is_trig_value_true_3) {
  char *input_string = "(x+2)*sin(  )";

  int result = is_trig_value_true(input_string);
  ck_assert_int_eq(result, 0);
}

START_TEST(is_trig_value_true_4) {
  char *input_string = "(x+2)*sin(2+(3)+342)";

  int result = is_trig_value_true(input_string);
  ck_assert_int_eq(result, 1);
}

START_TEST(is_trig_value_true_5) {
  char *input_string = "(x+2)";

  int result = is_trig_value_true(input_string);
  ck_assert_int_eq(result, 1);
}

START_TEST(is_trig_value_true_6) {
  char *input_string = "(x+2)*sin)23(";

  int result = is_trig_value_true(input_string);
  ck_assert_int_eq(result, 0);
}

Suite *suite_s21_is_trig_value_true(void) {
  Suite *s22;
  TCase *tc22;
  s22 = suite_create("s21_is_trig_value_true_1");
  tc22 = tcase_create("case_is_trig_value_true_1");
  tcase_add_test(tc22, is_trig_value_true_1);
  tcase_add_test(tc22, is_trig_value_true_2);
  tcase_add_test(tc22, is_trig_value_true_3);
  tcase_add_test(tc22, is_trig_value_true_4);
  tcase_add_test(tc22, is_trig_value_true_5);
  tcase_add_test(tc22, is_trig_value_true_6);
  suite_add_tcase(s22, tc22);
  return s22;
}