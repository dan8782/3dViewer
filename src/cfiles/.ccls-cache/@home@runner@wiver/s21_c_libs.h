#ifndef SRC_S21_C_LIBS_H_
#define SRC_S21_C_LIBS_H_
#include <stdio.h>
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
  char *file_path; // путь до файла
};
struct poligon {
  int poligon_elems_count;
  int * poligon_elems;
};
struct parser_output {
  int points_count;
  double * points;
  int poligons_count;
  struct poligon *poligon_value;
};

int parse_obj_file(char *file_path, struct parser_output* output);
int parser_handler(FILE *file, struct parser_output *output);
#endif // SRC_S21_C_LIBS_H_