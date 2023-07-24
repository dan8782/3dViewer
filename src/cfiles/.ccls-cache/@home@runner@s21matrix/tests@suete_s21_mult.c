#include "../test_main.h"

START_TEST(s21_mult_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;

  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 6;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;

  int result = s21_mult_matrix(&A, &B, &res);
  ck_assert_int_eq(6, res.matrix[0][0]);
  ck_assert_int_eq(0, res.matrix[0][1]);
  ck_assert_int_eq(22, res.matrix[1][0]);
  ck_assert_int_eq(15, res.matrix[1][1]);
  ck_assert_int_eq(res.rows, 2);
  ck_assert_int_eq(res.columns, 2);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

START_TEST(s21_mult_matrix_2) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(1, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 9;

  s21_create_matrix(2, 3, &B);
  B.matrix[0][0] = 6;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 8;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 9;

  int result = s21_mult_matrix(&A, &B, &res);

  ck_assert_int_eq(24, res.matrix[0][0]);
  ck_assert_int_eq(27, res.matrix[0][1]);
  ck_assert_int_eq(89, res.matrix[0][2]);
  ck_assert_int_eq(res.rows, 1);
  ck_assert_int_eq(res.columns, 3);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

START_TEST(s21_mult_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(4, 3, &A);
  s21_create_matrix(2, 3, &B);
  int result = s21_mult_matrix(&A, &B, &res);
  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_mult_matrix_4) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(5, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 6;
  A.matrix[3][0] = 7;
  A.matrix[3][1] = 8;
  A.matrix[4][0] = 9;
  A.matrix[4][1] = 10;

  s21_create_matrix(2, 3, &B);
  B.matrix[0][0] = 6;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 8;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 9;

  int result = s21_mult_matrix(&A, &B, &res);

  ck_assert_int_eq(10, res.matrix[0][0]);
  ck_assert_int_eq(6, res.matrix[0][1]);
  ck_assert_int_eq(26, res.matrix[0][2]);
  ck_assert_int_eq(26, res.matrix[1][0]);
  ck_assert_int_eq(12, res.matrix[1][1]);
  ck_assert_int_eq(60, res.matrix[1][2]);
  ck_assert_int_eq(42, res.matrix[2][0]);
  ck_assert_int_eq(18, res.matrix[2][1]);
  ck_assert_int_eq(94, res.matrix[2][2]);
  ck_assert_int_eq(58, res.matrix[3][0]);
  ck_assert_int_eq(24, res.matrix[3][1]);
  ck_assert_int_eq(128, res.matrix[3][2]);
  ck_assert_int_eq(74, res.matrix[4][0]);
  ck_assert_int_eq(30, res.matrix[4][1]);
  ck_assert_int_eq(162, res.matrix[4][2]);
  
  ck_assert_int_eq(res.rows, 5);
  ck_assert_int_eq(res.columns, 3);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

Suite *suite_s21_matrix_mult(void) {
  Suite *s22;
  TCase *tc22;
  s22 = suite_create("s21_mul");
  tc22 = tcase_create("case_mul");
  tcase_add_test(tc22, s21_mult_matrix_1);
  tcase_add_test(tc22, s21_mult_matrix_2);
  tcase_add_test(tc22, s21_mult_matrix_3);
  tcase_add_test(tc22, s21_mult_matrix_4);
  suite_add_tcase(s22, tc22);
  return s22;
}