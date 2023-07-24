#include "../test_main.h"

START_TEST(s21_result_from_polish_1) {
  char *input_string = "365";
  int result = get_elem_type(input_string);
  ck_assert_int_eq(result, 1);
}




Suite *suite_s21_get_elem_type(void) {
  Suite *s22;
  TCase *tc22;
  s22 = suite_create("s21_result_from_polish");
  tc22 = tcase_create("case_s21_result_from_polish");
  tcase_add_test(tc22, s21_result_from_polish_1);
  suite_add_tcase(s22, tc22);
  return s22;
}