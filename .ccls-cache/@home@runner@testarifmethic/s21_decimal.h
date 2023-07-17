#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int is_bit(int num, s21_decimal decimal);
void set_bit(int position, s21_decimal *result);
void binary_sum(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void decimal_init(s21_decimal *decimal);
int get_degree(s21_decimal decimal);
void shift(int shift_level, s21_decimal value_1, s21_decimal *result);
void binary_multiply(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result);
void set_degree(int degree, s21_decimal *decimal);
void s21_decimal_copy(s21_decimal from, s21_decimal *to);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_my_add_sub(int value_1_degree, int value_2_degree, s21_decimal value_1,
                    s21_decimal value_2, s21_decimal *result, int is_add);
void binary_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int is_decimal_less(s21_decimal value_1, s21_decimal value_2);
int is_decimal_sign_plus(s21_decimal value_1);
void s21_sub_norm(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result);
void set_decimal_sign(s21_decimal *value_1, int sign);
void s21_norm_add(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result);

int test();

#endif // SRC_S21_STRING_H_