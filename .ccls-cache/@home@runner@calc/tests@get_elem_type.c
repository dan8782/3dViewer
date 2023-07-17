#include "../test_main.h"

START_TEST(s21_get_elem_type_1) {
  char *input_string = "(x+2)";

  int result = is_brakets_valid(input_string);
  ck_assert_int_eq(result, 1);
}


Suite *suite_s21_get_elem_type(void) {
  Suite *s22;
  TCase *tc22;
  s22 = suite_create("s21_get_elem_type");
  tc22 = tcase_create("case_get_elem_type");
  tcase_add_test(tc22, s21_get_elem_type_1);

  suite_add_tcase(s22, tc22);
  return s22;
}