#ifndef SRC_S21_C_LIBS_H_
#define SRC_S21_C_LIBS_H_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct viwer_input {
  // база
  // перемещение
  double x_move;
  double y_move;
  double z_move;
  // поворот
  double x_turn;
  double y_turn;
  double z_turn;
  double size; //размер в процентах (по умолчанию 100.0)
  const char *file_path; // путь до файла
};
struct poligon {
  int poligon_elems_count;
  long int *poligon_elems;
};

struct point {
  int coordinates_count;
  double *coordinates;
};

struct parser_output {
  int points_count;
  struct point *points;
  int poligons_count;
  struct poligon *poligons_value;
};

int parse_obj_file(struct viwer_input input, struct parser_output *output);
void transformations_main(struct viwer_input input,
                          struct parser_output *viwer_data);
// utils
// parser
void add_point_coordinate_to_buffer(struct point *point_buffer, double point);
int parser_handler(FILE *file, struct parser_output *output);
int point_handler(struct parser_output *output, char *input_str);
int poligon_handler(struct parser_output *output, char *input_str);
int basic_check_str(char *input_str, int input_str_len, char type);
void add_poligon_value(struct poligon *poligon_buffer, long int value);
void add_poligon(struct parser_output *output, struct poligon *poligon_buffer);
void add_point(struct parser_output *output, struct point point_buffer);
// translations
void move(double move_value, struct parser_output *viwer_data, int type);
long double radians(int angle);
void turn_x(int x_turn, struct parser_output *viwer_data);
void turn_y(int y_turn, struct parser_output *viwer_data);
void turn_z(int z_turn, struct parser_output *viwer_data);
void change_size(double size, struct parser_output *viwer_data);
// python utils
void append(char *input_string_orig, char append_sign);
int find(char *input_string, char find_char);
int slice_string(char *input_string, char *out_string, int begin, int end);
#endif // SRC_S21_C_LIBS_H_
