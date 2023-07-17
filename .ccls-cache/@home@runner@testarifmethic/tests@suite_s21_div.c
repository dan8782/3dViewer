#include "../test_main.h"

START_TEST(div_0) {
  // 6 / 3 = 2
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000110
  decimal.bits[0] = 6;
  
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000011
  decimal2.bits[0] = 3;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000010
  ck_assert_int_eq(decimal3.bits[0], 2);
  ck_assert_int_eq(decimal3.bits[1], 0);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], 0);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(div_1) {
  // 4294967296 / 2 = 2147483648
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000001  0000000000000000 0000000000000000
  decimal.bits[1] = 1;
  
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000010
  decimal2.bits[0] = 3;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 1000000000000000
  ck_assert_int_eq(decimal3.bits[0], 2147483648);
  ck_assert_int_eq(decimal3.bits[1], 0);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], 0);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(div_2) {
  // 4294967296 / 3 = 1431655765
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000001  0000000000000000 0000000000000000
  decimal.bits[1] = 1;
  
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0101010101010101 0101010101010101
  decimal2.bits[0] = 1431655765;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000010
  ck_assert_int_eq(decimal3.bits[0], 2);
  ck_assert_int_eq(decimal3.bits[1], 0);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], 0);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(div_3) {
  // 429496729.6 / 2 = 21474836.48
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000001 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000001  0000000000000000 0000000000000000
  decimal.bits[1] = 1;
  decimal.bits[3] = 65536;
  
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000010
  decimal2.bits[0] = 2;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //0000000000000010 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  1000000000000000 0000000000000000
  ck_assert_int_eq(decimal3.bits[0], 2147483648);
  ck_assert_int_eq(decimal3.bits[1], 0);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], 131072);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(div_4) {
  // 3 / 5 = 0.6
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000011
  decimal.bits[1] = 3;
  
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000101
  decimal2.bits[0] = 5;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //0000000000000001 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000110
  ck_assert_int_eq(decimal3.bits[0], 6);
  ck_assert_int_eq(decimal3.bits[1], 0);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], 65536);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(div_5) {
  // 1 / 3 = 0.3333333333
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000001
  decimal.bits[0] = 1;
  
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000011
  decimal2.bits[0] = 3;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //0000000000011010 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000111111100 1010000001010101
  ck_assert_int_eq(decimal3.bits[0], 33333333);
  ck_assert_int_eq(decimal3.bits[1], 0);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], 1703936);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(div_6) {
  // 2 / 3 = 0.6666666667
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000010
  decimal.bits[0] = 2;
  
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000011
  decimal2.bits[0] = 3;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //0000000000011010 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000001111111001 0100000010101011
  ck_assert_int_eq(decimal3.bits[0], 66666667);
  ck_assert_int_eq(decimal3.bits[1], 0);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], 1703936);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(div_7) {
  // -6/3
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000110
  decimal.bits[0] = 6;
  
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000011
  decimal2.bits[0] = 3;
  int our_result_status = s21_mul(decimal, decimal2, &decimal3);
  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000010
  ck_assert_int_eq(decimal3.bits[0], 2);
  ck_assert_int_eq(decimal3.bits[1], 0);
  ck_assert_int_eq(decimal3.bits[2], 0);
  ck_assert_int_eq(decimal3.bits[3], MINUS_SIGN);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST


Suite *suite_s21_div(void) {
  Suite *s23;
  TCase *tc23;
  s23 = suite_create("s21_DIV");
  tc23 = tcase_create("case_DIV");
  tcase_add_test(tc23, div_0);
  tcase_add_test(tc23, div_1);
  tcase_add_test(tc23, div_2);
  tcase_add_test(tc23, div_3);
  tcase_add_test(tc23, div_4);
  tcase_add_test(tc23, div_5);
  tcase_add_test(tc23, div_6);
  tcase_add_test(tc23, div_7);

  suite_add_tcase(s23, tc23);
  return s23;
}