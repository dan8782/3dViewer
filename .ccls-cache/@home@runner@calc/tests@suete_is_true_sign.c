#include "../test_main.h"

START_TEST(s21_is_true_sign_1) {
  char *input_string = "(x+2)";

  int result = is_true_sign(input_string);
  ck_assert_int_eq(result, 1);
}

START_TEST(s21_is_true_sign_2) {
  char *input_string = "( x + 2 )";

  int result = is_true_sign(input_string);
  ck_assert_int_eq(result, 1);
}

START_TEST(s21_is_true_sign_3) {
  char *input_string = "( r23 + 2 )";

  int result = is_true_sign(input_string);
  ck_assert_int_eq(result, 0);
}

START_TEST(s21_is_true_sign_4) {
  char *input_string = "( x23 + 2 )";

  int result = is_true_sign(input_string);
  ck_assert_int_eq(result, 0);
}

START_TEST(s21_is_true_sign_5) {
  char *input_string = "( sin(23) + 2 )";

  int result = is_true_sign(input_string);
  ck_assert_int_eq(result, 1);
}

START_TEST(s21_is_true_sign_6) {
  char *input_string = "( sni(23) + 2 )";

  int result = is_true_sign(input_string);
  ck_assert_int_eq(result, 0);
}

START_TEST(s21_is_true_sign_7) {
  char *input_string = "( sin() + 2 )";

  int result = is_true_sign(input_string);
  ck_assert_int_eq(result, 1);
}

Suite *suite_s21_is_true_sign(void) {
  Suite *s22;
  TCase *tc22;
  s22 = suite_create("s21_is_true_sign");
  tc22 = tcase_create("s21_is_true_sign");
  tcase_add_test(tc22, s21_is_true_sign_1);
  tcase_add_test(tc22, s21_is_true_sign_2);
  tcase_add_test(tc22, s21_is_true_sign_3);
  tcase_add_test(tc22, s21_is_true_sign_4);
  tcase_add_test(tc22, s21_is_true_sign_5);
  tcase_add_test(tc22, s21_is_true_sign_6);
  tcase_add_test(tc22, s21_is_true_sign_7);
  suite_add_tcase(s22, tc22);
  return s22;
}