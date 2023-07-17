#include "../s21_matrix.h"
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int result_code = 0;
  if (rows > 0 && columns > 0 && result != NULL) {
    double **matrix = matrix_init(rows, columns);
    result->matrix = matrix;
    result->columns = columns;
    result->rows = rows;
  } else {
    result_code = 1;
  }
  return result_code;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    double **matrix = A->matrix;
    int rows = A->rows;
    if (matrix != NULL) {
      free_matrix(matrix, rows);
    }
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result_code = SUCCESS;
  if (check_matrix(A) && check_matrix(B) && eq_matrix_size(A, B)) {
    if (eq_matrix_value(A, B) == False) {
      result_code = FAILURE;
    }
  } else {
    result_code = FAILURE;
  }
  return result_code;
}
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = 0;
  if (check_matrix(A) && check_matrix(B)) {
    if (eq_matrix_size(A, B)) {
      s21_create_matrix(A->rows, A->columns, result);
      sum_sub_matrix(A, B, result, '+');
    } else {
      result_code = 2;
    }

  } else {
    result_code = 1;
  }
  return result_code;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = 0;
  if (check_matrix(A) && check_matrix(B)) {
    if (eq_matrix_size(A, B)) {
      s21_create_matrix(A->rows, A->columns, result);
      sum_sub_matrix(A, B, result, '-');
    } else {
      result_code = 2;
    }

  } else {
    result_code = 1;
  }
  return result_code;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = 0;
  if (check_matrix(A) && check_matrix(B)) {
    if (is_mult_matrix_size_suit(A, B)) {
      s21_create_matrix(A->rows, B->columns, result);
      mult_matrix(A, B, result);
    } else {
      result_code = 2;
    }

  } else {
    result_code = 1;
  }
  return result_code;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int result_code = 0;
  if (check_matrix(A)) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int r = 0; r < A->rows; r++) {
      for (int c = 0; c < A->columns; c++) {
        result->matrix[r][c] = A->matrix[r][c] * number;
      }
    }
  } else {
    result_code = 1;
  }
  return result_code;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int result_code = 0;
  if (check_matrix(A)) {
    s21_create_matrix(A->columns, A->rows, result);
    transpose(A,result);
  } else {
    result_code = 1;
  }
  return result_code;
}
int s21_determinant(matrix_t *A, double *result){
  int result_code = 0;
  if (check_matrix(A)){
    if(A->columns == A->rows){
      //вызов фунлции вычисления детерминанта
       *result = calculate_determinant(A->matrix, A->columns);
    }
    else{
      result_code = 2;
    }
  } else {
    result_code = 1;
  }
  return result_code;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_flag = 0;

  if (check_matrix(A) && result != NULL) {
    if (A->columns == A->rows) {
      int size = A->rows;
      calc_complements(A, result, size);
    } else {
      return_flag = 2;
    }
  } else {
    return_flag = 1;
  }

  return return_flag;
}
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_flag = 0;
  if (check_matrix(A) && result != NULL) {
    if (A->columns == A->rows) {
      int size = A->rows;
      double determinant = 0;
      s21_determinant(A, &determinant);
      if (determinant != 0) {
        if (size > 1) {
          matrix_t complement_matrix;
          matrix_t transponse_matrix;
          s21_transpose(A, &transponse_matrix);
          s21_calc_complements(&transponse_matrix, &complement_matrix);
          s21_mult_number(&complement_matrix, 1 / determinant, result);
          s21_remove_matrix(&transponse_matrix);
          s21_remove_matrix(&complement_matrix);
        } else {
          s21_create_matrix(1, 1, result);
          result->matrix[0][0] = A->matrix[0][0];
        }
      } else {
        return_flag = 2;
      }
    } else {
      return_flag = 2;
    }
  } else {
    return_flag = 1;
  }

  return return_flag;
}
// utils
int calc_complements(matrix_t *A, matrix_t *result, int size) {
  s21_create_matrix(size, size, result);
      if (size > 1) {
        for (int i = 0; i < size; i++) {
          for (int j = 0; j < size; j++) {
            double **new_matrix = matrix_init(size - 1, size - 1);
            fill_small_matrix(A->matrix, new_matrix, size, i,
                                               j);
            double determinant = calculate_determinant(new_matrix, size - 1);
            free_matrix(new_matrix, size - 1);
            result->matrix[i][j] = determinant * s21_pow(i, j);
          }
        }
      } else {
        result->matrix[0][0] = A->matrix[0][0];
      }
}
double s21_pow(int i, int j) {
  double number = -1;
  for (int k = 0; k <= i + j; k++) {
    number *= -1;
  }
  return number;
}
double calculate_determinant(double **matrix, int size) {
  int result = 0;
  int degree = 1;

  if (size == 1) {
    result = matrix[0][0];
  } else if (size == 2) {
    result = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  } else {
    double **new_matrix = matrix_init(size - 1, size - 1);
    for (int i = 0; i < size; i++) {
      fill_small_matrix(matrix, new_matrix, size, 0, i);
      result +=
          degree * matrix[0][i] * calculate_determinant(new_matrix, size - 1);
      degree *= -1;
    }
    free_matrix(new_matrix, size - 1);
  }

  return result;
}

void free_matrix(double **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

void fill_small_matrix(double **matrix, double **new_matrix,
                                        int size, int row, int columnn) {
  int switch_row = 0;
  int switch_column = 0;

  for (int i = 0; i < size - 1; i++) {
    if (i == row) {
      switch_row = 1;
    }
    for (int j = 0; j < size - 1; j++) {
      if (j == columnn) {
        switch_column = 1;
      }
      new_matrix[i][j] = matrix[i + switch_row][j + switch_column];
    }
    switch_column = 0;
  }
}
void transpose(matrix_t *A, matrix_t *result) {
  for (int c = 0; c < A->columns; c++) {
    for (int r = 0; r < A->rows; r++) {
      result->matrix[c][r] = A->matrix[r][c];
    }
  }
}
void mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_rows = A->rows;
  int result_columns = B->columns;
  for (int r = 0; r < result_rows; r++) {
    for (int c = 0; c < result_columns; c++) {
      result->matrix[r][c] = calc_matrix_mul_elem(A, B, r, c);
    }
  }
}

double calc_matrix_mul_elem(matrix_t *A, matrix_t *B, int r, int c) {
  double result_value = 0;
  for (int j = 0; j < B->rows; j++) {
    // printf("r %d j %d  j%d c%d\n", r,j,j,c);
    result_value += A->matrix[r][j] * B->matrix[j][c];
  }
  return result_value;
}
int is_mult_matrix_size_suit(matrix_t *A, matrix_t *B) {
  return A->columns == B->rows;
}
void sum_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result, char type) {
  int rows = A->rows;
  int columns = A->columns;
  double **matrixA = A->matrix;
  double **matrixB = B->matrix;
  double **matrixR = result->matrix;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < columns; c++) {
      if (type == '-') {
        matrixR[r][c] = matrixA[r][c] - matrixB[r][c];
      }
      if (type == '+') {
        matrixR[r][c] = matrixA[r][c] + matrixB[r][c];
      }
    }
  }
}

double **matrix_init(int rows, int columns) {
  double **matrix = (double **)malloc(sizeof(double *) * rows);
  for (int r = 0; r < rows; r++) {
    matrix[r] = (double *)malloc(sizeof(double) * columns);
  }
  return matrix;
}

int check_matrix(matrix_t *A) {
  return A != NULL && A->rows > 0 && A->columns > 0 && A->matrix != NULL;
}

int eq_matrix_size(matrix_t *A, matrix_t *B) {
  int result = True;
  if (A->rows == B->rows) {
    if (A->columns != B->columns) {
      result = False;
    }
  } else {
    result = False;
  }
  return result;
}

int eq_matrix_value(matrix_t *A, matrix_t *B) {
  int rows = A->rows;
  int columns = A->columns;
  int result = True;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < columns; c++) {
      if (A->matrix[r][c] - B->matrix[r][c] > 1e-7) {
        result = False;
      }
    }
  }
  return result;
}