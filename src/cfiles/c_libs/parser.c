#include "../s21_c_libs.h"

void remove_parser_output(struct parser_output *output) {
  for (int i = 0; i < output->poligons_count; i++) {
    free(output->poligons_value[i].poligon_elems);
  }
  free(output->poligons_value);
  for (int i = 0; i < output->points_count; i++) {
    free(output->points[i].coordinates);
  }
  free(output->points);
}
int parse_obj_file(struct viwer_input input, struct parser_output *output) {
  output->points = NULL;
  output->points_count = 0;
  output->poligons_count = 0;
  output->poligons_value = NULL;
  FILE *file;
  file = fopen(input.file_path, "r");
  int resut_code = 1;
  // Проверяем, удалось ли открыть файл
  if (file != NULL) {

    parser_handler(file, output);
    fclose(file);
  } else {
    resut_code = 0;
  }

  return resut_code;
}
int parser_handler(FILE *file, struct parser_output *output) {
  char string[1024] = "\0";
  while (fgets(string, sizeof(string), file) != NULL) {

    // Если первый символ f - обработка точки
    // Если первый символ v - обработка полигона
    if (string[0] == 'v') {
      point_handler(output, string);
    }
    if (string[0] == 'f') {
      poligon_handler(output, string);
    }
  }
  return 1;
}
int poligon_handler(struct parser_output *output, char *input_str) {
  int result_code = 1;
  int input_str_len = strlen(input_str);
  result_code *= basic_check_str(input_str, input_str_len, 'f');
  int input_str_index = 2;
  struct poligon poligon_buffer;
  poligon_buffer.poligon_elems = NULL;
  poligon_buffer.poligon_elems_count = 0;
  char buffer[1024] = "\0";
  while (input_str_len >= input_str_index && result_code) {
    char cure_sign = input_str[input_str_index];
    if ((cure_sign < 58 && cure_sign > 47)||
        (cure_sign == '-' && strlen(buffer) == 0) || cure_sign == '/') {
      append(buffer, cure_sign);
    }
    if ((cure_sign == ' ' || cure_sign == '\0') && strlen(buffer)) {
      char first_num_buffer[1024] = "\0";
      int slash_index = find(buffer, '/');
      if (slash_index != -1) {
        slice_string(buffer, first_num_buffer, 0, slash_index);
      } else {
        strcpy(first_num_buffer, buffer);
      }
      long int poligon_value = 0;
      sscanf(first_num_buffer, "%ld", &poligon_value);
      add_poligon_value(&poligon_buffer, poligon_value);
      buffer[0] = '\0';
    }
    input_str_index++;
  }
  if (poligon_buffer.poligon_elems_count > 1) {
    add_poligon(output, &poligon_buffer);
  } else {
    free(poligon_buffer.poligon_elems);
  }
  return result_code;
}
void add_poligon(struct parser_output *output, struct poligon *poligon_buffer) {
  struct poligon *tmp =
      realloc(output->poligons_value,
              (output->poligons_count + 1) * sizeof(struct poligon));
  if (tmp != NULL) {
    output->poligons_value = tmp;
    output->poligons_value[output->poligons_count] = *poligon_buffer;
    output->poligons_count++;
  }
}
void add_poligon_value(struct poligon *poligon_buffer, long int value) {
  long int *tmp =
      realloc(poligon_buffer->poligon_elems,
              (poligon_buffer->poligon_elems_count + 1) * sizeof(long int));
  if (tmp != NULL) {
    poligon_buffer->poligon_elems = tmp;
    poligon_buffer->poligon_elems[poligon_buffer->poligon_elems_count] = value;
    poligon_buffer->poligon_elems_count++;
  }
}
int basic_check_str(char *input_str, int input_str_len, char type) {
  int result_code = 1;
  if (input_str_len < 7) {
    //минимальный размер валидной строки
    result_code = 0;
  }
  if (input_str[0] != type || input_str[1] != ' ') {
    result_code = 0;
  }
  return result_code;
}
int point_handler(struct parser_output *output, char *input_str) {
  int result_code = 1;
  int input_str_len = strlen(input_str);
  result_code *= basic_check_str(input_str, input_str_len, 'v');

  int input_str_index = 2;
  char buffer[1024] = "\0";
  struct point point_buffer;
  point_buffer.coordinates_count = 0;
  point_buffer.coordinates = NULL;

  while (input_str_len >= input_str_index && result_code) {
    char cure_sign = input_str[input_str_index];
    if ((cure_sign < 58 && cure_sign > 47) ||
        (cure_sign == '.' && strlen(buffer) > 0 && find(buffer, '.') == -1) ||
        (cure_sign == '-' && strlen(buffer) == 0)) {
      //если знак число или точка(если точек ещё не было),или унарный минус то
      //добавляем знак в буфер
      append(buffer, cure_sign);
    }
    if ((cure_sign == ' ' || cure_sign == '\0') && strlen(buffer)) {
      // если пробел и в буфере что-то есть, то добавляем эту координату
      double buffer_value = 0.0;
      sscanf(buffer, "%lf", &buffer_value);
      add_point_coordinate_to_buffer(&point_buffer, buffer_value);
      buffer[0] = '\0';
    }
    input_str_index++;
  }
  if (point_buffer.coordinates_count == 3) {
    // добавляем точку в главную структуру
    add_point(output, point_buffer);
  } else {
    result_code = 0;
    //очищаем память из под неиспользованной точке
    free(point_buffer.coordinates);
  }
  return result_code;
}
void add_point(struct parser_output *output, struct point point_buffer) {
  struct point *tmp = realloc(output->points, (output->points_count + 1) *
                                                  sizeof(struct point));
  if (tmp != NULL) {
    output->points = tmp;
    // Добавляем новую структуру point в конец массива points
    output->points[output->points_count] = point_buffer;
    output->points_count++;
  }
}
void add_point_coordinate_to_buffer(struct point *point_buffer, double point) {
  // Выделяем память для нового значения
  double *tmp = realloc(point_buffer->coordinates,
                        (point_buffer->coordinates_count + 1) * sizeof(double));
  if (tmp != NULL) {
    point_buffer->coordinates = tmp;
    // Добавляем новое значение в массив кординат
    point_buffer->coordinates[point_buffer->coordinates_count] = point;
    // Увеличиваем счетчик количества координат
    point_buffer->coordinates_count++;
  }
}

void append(char *input_string_orig, char append_sign) {
  int input_len = strlen(input_string_orig);
  input_string_orig[input_len] = append_sign;
  input_string_orig[input_len + 1] = '\0';
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

int slice_string(char *input_string, char *out_string, int begin, int end) {
  //вырезает строку с end(включительно) до begin(не включительно)
  if (end <= begin || (begin < 0 || end < 0) || begin > (int)strlen(input_string)) {
    return 0;
  }
  int result_size = end - begin;
  for (int i = 0; i < result_size; i++) {
    out_string[i] = input_string[i + begin];
  }
  out_string[result_size + 1] = '\0';
  return 1;
}
