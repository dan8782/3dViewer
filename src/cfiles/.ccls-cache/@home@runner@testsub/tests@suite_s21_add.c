#include "../test_main.h"

START_TEST(add_0) {
  //4294967296 + 429496729,5 = 4724464025.5
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000001  0000000000000000 0000000000000000
  decimal.bits[1] = 1;
  
  //0000000000000001 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  1111111111111111 1111111111111111
  decimal2.bits[0] = 4294967295;
  decimal2.bits[3] = 65536;
  int our_result_status = s21_add(decimal, decimal2, &decimal3);
  //0000000000000001 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000001010  1111111111111111 1111111111111111
  ck_assert_int_eq(decimal3.bits[0], 4294967295);
  ck_assert_int_eq(decimal3.bits[1], 10);
  ck_assert_int_eq(decimal3.bits[3], 65536);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(add_1) {
  //4294967296 + 429496729,5 = 4724464025.5
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
  
  //1000000000000001 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  1111111111111111 1111111111111111
  decimal2.bits[0] = 4294967295;
  decimal2.bits[3] = 2147549184;
  int our_result_status = s21_add(decimal, decimal2, &decimal3);
  //0000000000000001 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000001001  0000000000000000 0000000000000001
  ck_assert_int_eq(decimal3.bits[0], 1);
  ck_assert_int_eq(decimal3.bits[1], 9);
  ck_assert_int_eq(decimal3.bits[3], 2147549184);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(add_2) {
  //12 + 75,5 = 87.5
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000001100
  decimal.bits[1] = 12;
  
  //0000000000000001 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000001011110011
  decimal2.bits[0] = 755;
  decimal2.bits[3] = 65536;
  int our_result_status = s21_add(decimal, decimal2, &decimal3);
  //0000000000000001 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000001101101011
  ck_assert_int_eq(decimal3.bits[0], 875);
  ck_assert_int_eq(decimal3.bits[3], 65536);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST


Suite *suite_s21_sub(void) {
  Suite *s23;
  TCase *tc23;
  s23 = suite_create("s21_SUB");
  tc23 = tcase_create("case_SUB");
  tcase_add_test(tc23, add_0);
  tcase_add_test(tc23, add_1);
  tcase_add_test(tc23, add_2);

  suite_add_tcase(s23, tc23);
  return s23;
}