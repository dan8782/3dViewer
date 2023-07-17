#include "../s21_c_libs.h"
void transformations_main(struct viwer_input input,
                       struct parser_output *viwer_data) {
  if (input.x_move != 0) {
    // перемещение по иксу
    move(input.x_move, viwer_data, 0);
  }
  if (input.y_move != 0) {
    // перемещение по y
    move(input.y_move, viwer_data, 1);
  }
  if (input.z_move != 0) {
    // перемещение по z
    move(input.z_move, viwer_data, 2);
  }

  if (input.x_turn != 0) {
    // поворот по иксу
    turn_x(input.x_turn, viwer_data);
  }
  if (input.y_turn != 0) {
    // поворот по y
    turn_y(input.y_turn, viwer_data);
  }
  if (input.z_turn != 0) {
    // поворот по z
    turn_z(input.z_turn, viwer_data);
  }
  if (input.size != 100) {
    //масштабирование
    change_size(input.size, viwer_data);
  }
}

void move(double move_value, struct parser_output *viwer_data, int type) {
  for (int i = 0; i < viwer_data->points_count; i++) {
    viwer_data->points[i].coordinates[type] =
        viwer_data->points[i].coordinates[type] + move_value;
  }
}
long double radians(int angle) { return angle * 3.14 / 180.0; }
void turn_x(int x_turn, struct parser_output *viwer_data) {
  double turn_radians = radians(x_turn);
  for (int i = 0; i < viwer_data->points_count; i++) {
    double y = viwer_data->points[i].coordinates[1];
    double z = viwer_data->points[i].coordinates[2];
    // x'=x;
    // y':=y*cos(L)+z*sin(L) ;
    // z':=-y*sin(L)+z*cos(L) ;
    viwer_data->points[i].coordinates[1] =
        y * cos(turn_radians) + z * sin(turn_radians); // y
    viwer_data->points[i].coordinates[2] =
        -y * sin(turn_radians) + z * cos(turn_radians); // z
  }
}

void turn_y(int y_turn, struct parser_output *viwer_data) {
  double turn_radians = radians(y_turn);
  for (int i = 0; i < viwer_data->points_count; i++) {

    double x = viwer_data->points[i].coordinates[0];
    double z = viwer_data->points[i].coordinates[2];
    // x'=x*cos(L)+z*sin(L);
    // y'=y;
    // z'=-x*sin(L)+z*cos(L);
    viwer_data->points[i].coordinates[0] =
        x * cos(turn_radians) + z * sin(turn_radians); // x
    viwer_data->points[i].coordinates[2] =
        -x * sin(turn_radians) + z * cos(turn_radians); // z
  }
}

void turn_z(int z_turn, struct parser_output *viwer_data) {
  double turn_radians = radians(z_turn);
  for (int i = 0; i < viwer_data->points_count; i++) {

    double x = viwer_data->points[i].coordinates[0];
    double y = viwer_data->points[i].coordinates[1];
    // x'=x*cos(L)-y*sin(L);
    // y'=x*sin(L)+y*cos(L);
    // z'=z;
    viwer_data->points[i].coordinates[0] =
        x * cos(turn_radians) - y * sin(turn_radians); // x
    viwer_data->points[i].coordinates[1] =
        x * sin(turn_radians) + y * cos(turn_radians); // y
  }
}

void change_size(double size, struct parser_output *viwer_data) {
  for (int i = 0; i < viwer_data->points_count; i++) {
    for (int j = 0; j < viwer_data->points[i].coordinates_count; j++) {
      viwer_data->points[i].coordinates[j] *=(size / 100.0);
    }
  }
}