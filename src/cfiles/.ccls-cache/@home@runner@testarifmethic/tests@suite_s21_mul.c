#include "../test_main.h"

START_TEST(mul_0) {
  //15 * 25 = 375
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000001111
  decimal.bits[0] = 15;
  
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000011001
  decimal2.bits[0] = 25;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000101110111
  ck_assert_int_eq(decimal3.bits[0], 375);
  ck_assert_int_eq(decimal3.bits[1], 0);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], 0);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(mul_1) {
  //15 * -25 = -375
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000001111
  decimal.bits[0] = 15;
  
  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000011001
  decimal2.bits[0] = 25;
  decimal2.bits[3] = MINUS_SIGN;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000101110111
  ck_assert_int_eq(decimal3.bits[0], 375);
  ck_assert_int_eq(decimal3.bits[1], 0);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], MINUS_SIGN);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(mul_2) {
  //-15 * -25 = 375
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000001111
  decimal.bits[0] = 15;
  decimal.bits[3] = MINUS_SIGN;
  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000011001
  decimal2.bits[0] = 25;
  decimal2.bits[3] = MINUS_SIGN;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000101110111
  ck_assert_int_eq(decimal3.bits[0], 375);
  ck_assert_int_eq(decimal3.bits[1], 0);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], 0);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(mul_3) {
  //0.015 * 0.0000025 = 0.0000000375
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000011 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000001111
  decimal.bits[0] = 15;
  decimal.bits[3] = 196608;
  //0000000000000111 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000011001
  decimal2.bits[0] = 25;
  decimal2.bits[3] = 458752;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //0000000000001010 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000101110111
  ck_assert_int_eq(decimal3.bits[0], 375);
  ck_assert_int_eq(decimal3.bits[1], 0);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], 655360);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(mul_4) {
  //0.0000000375 * 0.0000000375 = 0.00000000000000140625
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000001010 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000101110111
  decimal.bits[0] = 375;
  decimal.bits[3] = 655360;
  //0000000000001010 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000101110111
  decimal2.bits[0] = 375;
  decimal2.bits[3] = 655360;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //0000000000010100 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000010 0010010101010001
  ck_assert_int_eq(decimal3.bits[0], 140625);
  ck_assert_int_eq(decimal3.bits[1], 0);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], 1310720);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(mul_5) {
  //2147483648 * 2 = 4294967296
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  1000000000000000 0000000000000000
  decimal.bits[0] = 2147483648;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000010
  decimal2.bits[0] = 2;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000001  0000000000000000 0000000000000000
  ck_assert_int_eq(decimal3.bits[0], 0);
  ck_assert_int_eq(decimal3.bits[1], 1);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], 0);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(mul_6) {
  //2147483648 * 3 = 6442450944
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  1000000000000000 0000000000000000
  decimal.bits[0] = 2147483648;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000011
  decimal2.bits[0] = 3;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000001  1000000000000000 0000000000000000
  ck_assert_int_eq(decimal3.bits[0], 2147483648);
  ck_assert_int_eq(decimal3.bits[1], 1);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], 0);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(mul_7) {
  //39614081257132168796771975168 * 10
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 1;
  //0000000000000000 0000000000000000  1000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  decimal.bits[0] = 2147483648;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000001010
  decimal2.bits[0] = 10;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000001  1000000000000000 0000000000000000
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(mul_8) {
  //very small numbers
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 2;
  //0000000000011100 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  decimal.bits[0] = 1;
  //0000000000011100 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000001010
  decimal2.bits[0] = 10;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

Suite *suite_s21_mul(void) {
  Suite *s23;
  TCase *tc23;
  s23 = suite_create("s21_MUL");
  tc23 = tcase_create("case_MUL");
  tcase_add_test(tc23, mul_0);
  tcase_add_test(tc23, mul_1);
  tcase_add_test(tc23, mul_2);
  tcase_add_test(tc23, mul_3);
  tcase_add_test(tc23, mul_4);
  tcase_add_test(tc23, mul_5);
  tcase_add_test(tc23, mul_6);
  tcase_add_test(tc23, mul_7);
  tcase_add_test(tc23, mul_8);

  suite_add_tcase(s23, tc23);
  return s23;
}