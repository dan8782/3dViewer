#include "../s21_decimal.h"
/*int main() {
  s21_decimal decimal;
  s21_decimal decimal2;
  s21_decimal decimal3;
  decimal_init(&decimal);
  decimal_init(&decimal2);
  decimal_init(&decimal3);
  decimal.bits[0] = 2147483648;
  decimal.bits[3] = 16;
  decimal2.bits[0] = 2147483648;
  decimal2.bits[3] = 12;
  s21_sub(decimal, decimal2, &decimal3);
  printf("%u  %u\n", decimal3.bits[0], decimal3.bits[3]); //не работает сравнение
  return 0;
}*/

int test(){
    return 1;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int result_code = 0;
  //не уходит нормально в минус
  int is_value_1_positive = is_decimal_sign_plus(value_1);
  int is_value_2_positive = is_decimal_sign_plus(value_2);
  if (is_value_1_positive + is_value_2_positive == 2) {
    if (is_decimal_less(value_1, value_2)) {
      s21_sub_norm(value_1, value_2, result);
    } else {
      s21_sub_norm(value_2, value_1, result);
      set_decimal_sign(result, 1);
    }
  }
  if (is_value_1_positive == 1 && is_value_2_positive == 0) {
    s21_norm_add(value_1, value_2, result);
  }
  if (is_value_1_positive == 0 && is_value_2_positive == 1) {
    s21_norm_add(value_1, value_2, result);
    set_decimal_sign(result, 1);
  }
  if (is_value_1_positive == 0 && is_value_2_positive == 0) {
    if (is_decimal_less(value_1, value_2)) {
      s21_sub_norm(value_1, value_2, result);
      set_decimal_sign(result, 1);
    } else {
      s21_sub_norm(value_2, value_1, result);
    }
  }
  return result_code;
}
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
  printf("%u", value_1.bits[0]);
  printf("%u", value_2.bits[0]);
  result->bits[0]=1;
  return 1;
}
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
  printf("%u", value_1.bits[0]);
  printf("%u", value_2.bits[0]);
  result->bits[0]=1;
  return 1;
}
int is_decimal_sign_plus(s21_decimal value_1) {
  int sign = 1;
  if (is_bit(127, value_1)) {
    sign = 0;
  }
  return sign;
}

void s21_sub_norm(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result) {
  int value_1_degree = get_degree(value_1);
  int value_2_degree = get_degree(value_2);
  printf("степени: %d %d\n", value_1_degree, value_2_degree);
  if (value_1_degree == value_2_degree) {
    binary_sub(value_1, value_2, result);
  }
  if (value_1_degree > value_2_degree) {  
    s21_my_add_sub(value_1_degree, value_2_degree, value_1, value_2, result, 0);
  }
  if (value_1_degree < value_2_degree) {
    printf("Степень отрабатывает правильно");
    s21_my_add_sub(value_2_degree, value_1_degree, value_2, value_1, result, 0);
  }
}

void set_decimal_sign(s21_decimal *value_1, int sign) {
  if (sign) {
    value_1->bits[0] = value_1->bits[1] | (1 << (127 - 96));
  } else {
    value_1->bits[0] = value_1->bits[1] | ~(1 << (127 - 96));
  }
}
int is_decimal_less(s21_decimal value_1, s21_decimal value_2) {
  // ?1>2
  int result = 1;
  int i = 1;
  int is_compare = 0;
  while (i < 4 && !is_compare) {
    if (value_1.bits[i] != 0 && value_2.bits[i] != 0) {
      is_compare = 1;
      if (value_1.bits[i] < value_2.bits[i]) {
        result = 0;
      }
    }
    i++;
  }
  return result;
}

void binary_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int memorized = 0;
  int cure_bit = 0;
  printf("%u\n%u\n%u\n%u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2], value_1.bits[3]);
  for (int i = 0; i <= 95; i++) {
    int val_1_bit = is_bit(i, value_1);
    int val_2_bit = is_bit(i, value_2);
    printf("i =  %d, 1_bit = %d 2_bit = %d\n", i, val_1_bit, val_2_bit);
    if (val_1_bit == 1 && val_2_bit == 1) {
      if (memorized == 1) {
        cure_bit = 1;
      } else {
        cure_bit = 0;
      }
    }
    if (val_1_bit == 0 && val_2_bit == 1) {
      if (memorized == 0) {
        cure_bit = 1;
        memorized = 1;
        
      } else {
        
        cure_bit = 0;
      }
    }
    if (val_1_bit == 1 && val_2_bit == 0) {
      if (memorized == 1) {
        cure_bit = 0;
        memorized = 0;
      } else {
        cure_bit = 1;
      }
    }
    if (val_1_bit + val_2_bit == 0) {
      if (memorized == 1) {
        cure_bit = 1;
      } else {
        cure_bit = 0;
      }
    }
    if (cure_bit) {
      printf("1");
      set_bit(i, result);
    }
    else{
      printf("0");
    }
  }
  printf("decimal after sub\n %u\n%u\n%u\n%u\n", result->bits[0], result->bits[1], result->bits[2], result->bits[3]);
}

void binary_multiply(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result) {
  //перебираю то число, которое надо умножить, если бит == 1, то складываю
  //верхнее с верхним, сдвинутым на и-1
  s21_decimal sum_buffer;

  decimal_init(&sum_buffer);
  for (int i = 0; i < 96; i++) {
    if (is_bit(i, value_2)) {
      s21_decimal shift_buffer;
      decimal_init(&shift_buffer);
      s21_decimal sum_buffer_res;
      decimal_init(&sum_buffer_res);
      // printf("sum1 %d\n", sum_buffer.bits[3]);
      shift(i, value_1, &shift_buffer);
      // printf("shift %d\n", shift_buffer.bits[3]);
      binary_sum(sum_buffer, shift_buffer, &sum_buffer_res);
      for (int i = 0; i < 3; i++) {
        sum_buffer.bits[i] = sum_buffer_res.bits[i];
      }
      // printf("sum %d\n\n", sum_buffer.bits[3]);
    }

  }
  for (int i = 0; i < 3; i++) {
    result->bits[i] = sum_buffer.bits[i];
  }

}

void shift(int shift_level, s21_decimal value_1, s21_decimal *result) {
  s21_decimal buffer;
  decimal_init(&buffer);
  for (int i = shift_level; i < 69; i++) {
    if (is_bit(i - shift_level, value_1)) {
      set_bit(i, result);
    }
  }
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  //не работает с отрицательными числами
  s21_norm_add(value_1, value_2, result);
  return 1;
}

void s21_norm_add(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result) {
  int value_1_degree = get_degree(value_1);
  int value_2_degree = get_degree(value_2);
  if (value_1_degree == value_2_degree) {
    binary_sum(value_1, value_2, result);
  }
  if (value_1_degree > value_2_degree) {
    //Нужно приводить к единой степени десятки(мантиссу тоже умножать и
    //суммировать)
    s21_my_add_sub(value_1_degree, value_2_degree, value_1, value_2, result, 1);
  }
  if (value_1_degree < value_2_degree) {
    s21_my_add_sub(value_2_degree, value_1_degree, value_2, value_1, result, 1);
  }
}
void s21_my_add_sub(int value_1_degree, int value_2_degree, s21_decimal value_1,
                    s21_decimal value_2, s21_decimal *result, int is_add) {
  set_degree(value_1_degree, &value_2);
  printf("degree = %u", value_2.bits[3]);
  s21_decimal multiply_buffer;
  decimal_init(&multiply_buffer);
  s21_decimal_copy(value_2, &multiply_buffer);
  s21_decimal ten_struct;
  decimal_init(&ten_struct);
  ten_struct.bits[0] = 1;
  for (int i = 0; i < value_1_degree - value_2_degree; i++) {
    ten_struct.bits[0] *= 10;
  }
  if (is_add) {
    binary_sum(value_1, value_2, result);
  } else {
    printf("\nsub!!!\n");
    printf("%u\n%u\n%u\n%u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2], value_1.bits[3]);
    binary_sub(value_1, value_2, result);
  }
}

void set_degree(int degree, s21_decimal * decimal) {
  s21_decimal degree_buffer;
  decimal_init(&degree_buffer);
  degree_buffer.bits[0]=degree;
  for (int i = 16; i < 24; i++) {
    if (is_bit(i - 16, degree_buffer)) {
      set_bit(96 + i, decimal);
    }
  }
}
int get_degree(s21_decimal decimal) {
  int degree = 0;
  s21_decimal buffer;
  decimal_init(&buffer);
  for (int i = 16; i < 24; i++) {
    if (is_bit(96 + i, decimal)) {
      set_bit(i - 16, &buffer);
    }
  }
  degree = buffer.bits[0];
  return degree;
}
void s21_decimal_copy(s21_decimal from, s21_decimal *to) {
  for (int i = 0; i < 4; i++) {
    to->bits[i] = from.bits[i];
  }
}

void binary_sum(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int memorized = 0;
  int cure_bit = 0;
  for (int i = 0; i <= 95; i++) {
    int val_1_bit = is_bit(i, value_1);
    int val_2_bit = is_bit(i, value_2);
    if (val_1_bit == 1 && val_2_bit == 1) {
      if (memorized == 1) {
        cure_bit = 1;
      } else {
        cure_bit = 0;
      }
      memorized = 1;
    }
    if (val_1_bit + val_2_bit == 1) {
      if (memorized == 1) {
        cure_bit = 0;
      } else {
        cure_bit = 1;
        memorized = 0;
      }
    }
    if (val_1_bit + val_2_bit == 0) {
      if (memorized == 1) {
        cure_bit = 1;
      } else {
        cure_bit = 0;
      }
      memorized = 0;
    }
    if (cure_bit) {
      set_bit(i, result);
    }
  }
}
void set_bit(int position, s21_decimal *result) {
  if (0 <= position && position <= 31) {
    result->bits[0] = result->bits[0] | (1 << position);
  }
  if (32 <= position && position <= 63) {
    result->bits[1] = result->bits[1] | (1 << (position - 32));
  }
  if (64 <= position && position <= 95) {
    result->bits[2] = result->bits[2] | (1 << (position - 64));
  }
  if (96 <= position && position <= 130) {
    result->bits[3] = result->bits[3] | (1 << (position - 96));
  }
}

int is_bit(int num, s21_decimal decimal) {
  int result = 0;
  if (0 <= num && num <= 31) {
    unsigned int cure = decimal.bits[0];
    // printf("u = %u\n", cure);
    unsigned int check = (1 << num);
    unsigned int end = (cure & check);
    if (end == check && cure != 0) {
      result = 1;
    }
  }
  if (32 <= num && num <= 63) {
    unsigned int cure = decimal.bits[1];
    // printf("u = %u d = %d \n", cure, num - 32);
    unsigned int check = (1 << (num - 32));
    unsigned int end = (cure & check);
    if (end == check && cure != 0) {
      result = 1;
    }
  }
  if (64 <= num && num <= 95) {
    unsigned int cure = decimal.bits[2];
    unsigned int check = (1 << (num - 64));
    unsigned int end = (cure & check);
    if (end == check && cure != 0) {
      result = 1;
    }
  }
  if (96 <= num && num <= 130) {
    unsigned int cure = decimal.bits[3];
    unsigned int check = (1 << (num - 96));
    unsigned int end = (cure & check);
    if (end == check && cure != 0) {
      result = 1;
    }
  }
  return result;
}
void decimal_init(s21_decimal *decimal) {
  for (int i = 0; i < 4; i++) {
    decimal->bits[i] = 0;
  }
}
