#include "../s21_c_libs.h"
#include "string.h"
int s21_numeric_expression_validator(char *input_string) {
  printf("%s\n", input_string);
  // наличие знаков(чаров) кроме синус, косинусов и т.д.
  // правильность скобок is done!!!
  // обязательность выражения у тригонометрии
  return 1;
}

int is_true_sign(char *input_string_orig) {
  int input_length = strlen(input_string_orig);
  char input_string[270] = "\0";
  strcpy(input_string, input_string_orig);
  int i = 0;
  while (i < input_length) {
    char char_buffer[260] = "\0";
    while (input_string[i] < 48 && input_string[i] > 57) {
      append(char_buffer, input_string[i]);
    }
  }
}

void append(char *input_string_orig, char append_sign) {
  int input_len = strlen(input_string_orig);
  input_string_orig[input_len + 1] = append_sign;
  input_string_orig[input_len + 2] = '\0';
}

int is_brakets_valid(char *input_string_orig) {
  if (count_c(input_string_orig, '(') != count_c(input_string_orig, ')')) {
    return 0;
  }
  char input_string[270] = "\0";
  strcpy(input_string, input_string_orig);
  int close_bracket_pos = find(input_string, ')');
  char left_part_with_full_bracket[270] = "\0";
  slice_string(input_string, left_part_with_full_bracket, 0,
               close_bracket_pos + 1);
  int open_bracket_pos = rfind(left_part_with_full_bracket, '(');
  while ((open_bracket_pos != -1 && close_bracket_pos != -1) &&
         open_bracket_pos < close_bracket_pos) {
    char rigth_part[270] = "\0";
    char left_part_without_full_bracket[270] = "\0";
    slice_string(left_part_with_full_bracket, left_part_without_full_bracket, 0,
                 open_bracket_pos);
    slice_string(input_string, rigth_part, close_bracket_pos + 1,
                 strlen(input_string));
    strcat(left_part_without_full_bracket, rigth_part);
    strcpy(input_string, left_part_without_full_bracket);
    close_bracket_pos = find(input_string, ')');
    slice_string(input_string, left_part_with_full_bracket, 0,
                 close_bracket_pos + 1);
    open_bracket_pos = rfind(left_part_with_full_bracket, '(');
  }
  close_bracket_pos = find(input_string, ')');
  close_bracket_pos = find(input_string, ')');
  int result = 1;
  if (close_bracket_pos != -1 || close_bracket_pos != -1) {
    result = 0;
  }
  return result;
}

int count_c(char *input_string_orig, char find_char) {
  int count = 0;
  int input_length = strlen(input_string_orig);
  for (int i = 0; i < input_length; i++) {
    if (input_string_orig[i] == find_char) {
      count++;
    }
  }
  return count;
}

int slice_string(char *input_string, char *out_string, int begin, int end) {
  //вырезает строку с end(включительно) до begin(не включительно)
  if (end <= begin || (begin < 0 || end < 0) || begin > strlen(input_string)) {
    return 0;
  }
  int result_size = end - begin;
  for (int i = 0; i < result_size; i++) {
    out_string[i] = input_string[i + begin];
  }
  out_string[result_size + 1] = '\0';
  return 1;
}

int find(char *input_string, char find_char) {
  int input_length = strlen(input_string);
  int result = -1;
  for (int i = 0; i < input_length; i++) {
    if (input_string[i] == find_char && result == -1) {
      result = i;
    }
  }
  return result;
}
int rfind(char *input_string, char find_char) {
  int input_length = strlen(input_string);
  int result = -1;
  for (int i = 0; i < input_length; i++) {
    if (input_string[i] == find_char) {
      result = i;
    }
  }
  return result;
}