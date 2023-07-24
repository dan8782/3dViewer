#include "../test_main.h"

START_TEST(sub_0_1) {
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  decimal.bits[0] = 3;
  decimal2.bits[0] = 2;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  int true_result_status = 0;
  ck_assert_int_eq(decimal3.bits[0], 1);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_1) {
  // 4294967296 / 4294967295 = 1
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  decimal.bits[0] = 0;
  decimal.bits[1] = 1;
  decimal2.bits[0] = 4294967295;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  ck_assert_int_eq(decimal3.bits[0], 1);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_2) {
  //4294967296-429496729,5 = 3865470566,5
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  decimal.bits[0] = 0;
  decimal.bits[1] = 1;
  decimal2.bits[0] = 4294967295;
  decimal2.bits[3] = 65536;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  ck_assert_int_eq(decimal3.bits[0], 1);
  ck_assert_int_eq(decimal3.bits[1], 9);
  ck_assert_int_eq(decimal3.bits[3], 65536);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_3) {
  // 4294967296 -(- 4294967295) = 8589934591
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000001  0000000000000000 0000000000000000
  decimal.bits[0] = 0;
  decimal.bits[1] = 1;
  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  1111111111111111 1111111111111111
  decimal2.bits[0] = 4294967295;
  decimal2.bits[3] = MINUS_SIGN;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000001  1111111111111111 1111111111111111
  ck_assert_int_eq(decimal3.bits[0], 4294967295);
  ck_assert_int_eq(decimal3.bits[1], 1);
  ck_assert_int_eq(decimal3.bits[3], 0);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_4) {
  // 18446744073709551616 -(4294967295) = 18446744069414584321
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000001
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  decimal.bits[0] = 0;
  decimal.bits[1] = 0;
  decimal.bits[2] = 1;
  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  1111111111111111 1111111111111111
  decimal2.bits[0] = 4294967295;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //1111111111111111 1111111111111111  0000000000000000 0000000000000000
  ck_assert_int_eq(decimal3.bits[0], 0);
  ck_assert_int_eq(decimal3.bits[1], 4294967295);
  ck_assert_int_eq(decimal3.bits[3], 0);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_5) {
  // 79228162514264337593543950335 -(4294967296) = 79228162514264337589248983039
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  1111111111111111 1111111111111111
  //1111111111111111 1111111111111111  1111111111111111 1111111111111111
  decimal.bits[0] = 4294967295;
  decimal.bits[1] = 4294967295;
  decimal.bits[2] = 4294967295;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000001  0000000000000000 0000000000000000
  decimal2.bits[0] = 0;
  decimal2.bits[1] = 1;
  decimal2.bits[3] = 0;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  1111111111111111 1111111111111111
  //1111111111111111 1111111111111110  1111111111111111 1111111111111111
  ck_assert_int_eq(decimal3.bits[0], 4294967295);
  ck_assert_int_eq(decimal3.bits[1], 4294967294);
  ck_assert_int_eq(decimal3.bits[2], 4294967295);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_6) {
  // 39614081257132168796771975168 -(1) = 39614081257132168796771975167
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  1000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  decimal.bits[0] = 0;
  decimal.bits[1] = 0;
  decimal.bits[2] = 2147483648;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000001
  decimal2.bits[0] = 1;
  decimal2.bits[1] = 0;
  decimal2.bits[3] = 0;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  0111111111111111 1111111111111111
  //1111111111111111 1111111111111111  1111111111111111 1111111111111111
  ck_assert_int_eq(decimal3.bits[0], 4294967295);
  ck_assert_int_eq(decimal3.bits[1], 4294967294);
  ck_assert_int_eq(decimal3.bits[2], 2147483647);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_7) {
  // 429496.7296 - 42.94967295 = 429453.77992705
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000010 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000001  0000000000000000 0000000000000000
  decimal.bits[0] = 0;
  decimal.bits[1] = 1;
  decimal.bits[3] = 131072;
  
  //0000000000000100 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  1111111111111111 1111111111111111
  decimal2.bits[0] = 4294967295;
  decimal2.bits[1] = 0;
  decimal2.bits[3] = 262144;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  //0000000000000100 0000000000000000  0111111111111111 1111111111111111
  //0000000000000000 0010011100001111  0000000000000000 0000000000000001
  ck_assert_int_eq(decimal3.bits[0], 1);
  ck_assert_int_eq(decimal3.bits[1], 9999);
  ck_assert_int_eq(decimal3.bits[2], 2147483647);
  ck_assert_int_eq(decimal3.bits[3], 262144);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST
START_TEST(sub_8) {
  // 3961.4081257132168796771975168 - 0.0000000000000000000000000001 = 3961.4081257132168796771975168
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000011001 0000000000000000  1000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  decimal.bits[0] = 0;
  decimal.bits[2] = 1;
  decimal.bits[3] = 1638400;
  
  //0000000000011100 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000001
  decimal2.bits[0] = 1;
  decimal2.bits[3] = 1835008;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  //0000000000011001 0000000000000000  1000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  ck_assert_int_eq(decimal3.bits[0], 0);
  ck_assert_int_eq(decimal3.bits[2], 1);
  ck_assert_int_eq(decimal3.bits[3], 1638400);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_9) {
  //3961.4081257132168796771975168 - 0.0000000000000000000000000008 = 3961.4081257132168796771975168
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000011001 0000000000000000  1000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  decimal.bits[0] = 0;
  decimal.bits[2] = 1;
  decimal.bits[3] = 1638400;
  
  //0000000000011100 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000001000
  decimal2.bits[0] = 8;
  decimal2.bits[3] = 1835008;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  //0000000000011001 0000000000000000  1000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  ck_assert_int_eq(decimal3.bits[0], 0);
  ck_assert_int_eq(decimal3.bits[2], 1);
  ck_assert_int_eq(decimal3.bits[3], 1638400);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_10) {
  //3961.4081257132168796771975168 - 0.0000000000000000000000008128 = 3961.4081257132168796771975160
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000011001 0000000000000000  1000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  decimal.bits[0] = 0;
  decimal.bits[2] = 1;
  decimal.bits[3] = 1638400;
  
  //0000000000011100 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0001111111000000
  decimal2.bits[0] = 8128;
  decimal2.bits[3] = 1835008;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  //0000000000011001 0000000000000000  0111111111111111 1111111111111111
  //1111111111111111 1111111111111111  1111111111111111 1111111111111000
  ck_assert_int_eq(decimal3.bits[0], 4294967288);
  ck_assert_int_eq(decimal3.bits[1], 4294967295);
  ck_assert_int_eq(decimal3.bits[2], 2147483647);
  ck_assert_int_eq(decimal3.bits[3], 1638400);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_11) {
  //79,228,162,514,264,337,593,543,950,335 - 0,6 = 79,228,162,514,264,337,593,543,950,335
  // пример из ридми
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  1111111111111111 1111111111111111
  //1111111111111111 1111111111111111  1111111111111111 1111111111111111
  decimal.bits[0] = 4294967295;
  decimal.bits[1] = 4294967295;
  decimal.bits[2] = 4294967295;
  decimal.bits[3] = 1638400;
  
  //0000000000000001 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000110
  decimal2.bits[0] = 6;
  decimal2.bits[3] = 65536;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  1111111111111111 1111111111111111
  //1111111111111111 1111111111111111  1111111111111111 1111111111111110
  ck_assert_int_eq(decimal3.bits[0], 4294967294);
  ck_assert_int_eq(decimal3.bits[1], 4294967295);
  ck_assert_int_eq(decimal3.bits[2], 4294967295);
  ck_assert_int_eq(decimal3.bits[3], 0);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_12) {
  //75 - 12 = 63
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000001001011
  decimal.bits[0] = 75;
  
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000001100
  decimal2.bits[0] = 12;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000111111
  ck_assert_int_eq(decimal3.bits[0], 63);
  ck_assert_int_eq(decimal3.bits[3], 0);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_13) {
  //-75 - 12 = -87
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000001001011
  decimal.bits[0] = 75;
  decimal.bits[3]=MINUS_SIGN;
  
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000001100
  decimal2.bits[0] = 12;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000001010111
  ck_assert_int_eq(decimal3.bits[0], 87);
  ck_assert_int_eq(decimal3.bits[3], MINUS_SIGN);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_14) {
  //12 - 75 = 63
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000001100
  decimal.bits[0] = 12;
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000001001011
  
  decimal2.bits[0] = 75;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000111111
  ck_assert_int_eq(decimal3.bits[0], 63);
  ck_assert_int_eq(decimal3.bits[3], MINUS_SIGN);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_15) {
  //12 - (-75) = 87
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 0;
  
  
  //0000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000001100
  decimal.bits[0] = 12;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);

  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000001001011
  decimal2.bits[0] = 75;
  decimal2.bits[3]=MINUS_SIGN;
  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000001010111
  ck_assert_int_eq(decimal3.bits[0], 87);
  ck_assert_int_eq(decimal3.bits[3], 0);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_16) {
  //79,228,162,514,264,337,593,543,950,335 - (-1)
  // пример из ридми
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 1;
  //0000000000000000 0000000000000000  1111111111111111 1111111111111111
  //1111111111111111 1111111111111111  1111111111111111 1111111111111111
  decimal.bits[0] = 4294967295;
  decimal.bits[1] = 4294967295;
  decimal.bits[2] = 4294967295;
  decimal.bits[3] = 0;
  
  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000001
  decimal2.bits[0] = 1;
  decimal2.bits[3] = MINUS_SIGN;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

START_TEST(sub_17) {
  //-1 - 79,228,162,514,264,337,593,543,950,335 
  // пример из ридми
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  int true_result_status = 2;
  //0000000000000000 0000000000000000  1111111111111111 1111111111111111
  //1111111111111111 1111111111111111  1111111111111111 1111111111111111
  decimal2.bits[0] = 4294967295;
  decimal2.bits[1] = 4294967295;
  decimal2.bits[2] = 4294967295;
  decimal2.bits[3] = 0;
  
  //1000000000000000 0000000000000000  0000000000000000 0000000000000000
  //0000000000000000 0000000000000000  0000000000000000 0000000000000001
  decimal.bits[0] = 1;
  decimal.bits[3] = MINUS_SIGN;
  int our_result_status = s21_sub(decimal, decimal2, &decimal3);
  ck_assert_int_eq(our_result_status, true_result_status);
}
END_TEST

Suite *suite_s21_sub(void) {
  Suite *s23;
  TCase *tc23;
  s23 = suite_create("s21_SUB");
  tc23 = tcase_create("case_SUB");
  tcase_add_test(tc23, sub_0_1);
  tcase_add_test(tc23, sub_1);
  tcase_add_test(tc23, sub_2);
  tcase_add_test(tc23, sub_3);
  tcase_add_test(tc23, sub_4);
  tcase_add_test(tc23, sub_5);
  tcase_add_test(tc23, sub_6);
  tcase_add_test(tc23, sub_7);
  tcase_add_test(tc23, sub_8);
  tcase_add_test(tc23, sub_9);
  tcase_add_test(tc23, sub_10);
  tcase_add_test(tc23, sub_11);
  tcase_add_test(tc23, sub_12);
  tcase_add_test(tc23, sub_13);
  tcase_add_test(tc23, sub_14);
  tcase_add_test(tc23, sub_15);
  tcase_add_test(tc23, sub_16);
  tcase_add_test(tc23, sub_17);
  suite_add_tcase(s23, tc23);
  return s23;
}