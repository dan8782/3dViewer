#include "../s21_matrix.h"


int s21_create_matrix(int rows, int columns, matrix_t *result){
  //Проверяем, что валидные данные
  int result_code = 0;
  if (rows > 0 & columns > 0 & result!=NULL){
    //заполняем матрицу памятью
    double **matrix = matrix_init(rows, columns);
    //заполняем указатель 
    result ->matrix = matrix;
    result ->columns = columns;
    result ->rows = rows;
  }
  else{
    // иначе изменяем статус на ошибку
    result_code = 1;
  }
  return result_code;
  
}

double ** matrix_init(int rows, int columns){
  double **matrix = (double **)malloc(sizeof(double *) * rows);
  for (int r=0; r<rows; r++){
    matrix[r] = (double *)malloc(sizeof(double) * columns);
  }
  return matrix;
}