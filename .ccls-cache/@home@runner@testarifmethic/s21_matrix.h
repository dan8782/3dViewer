#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
int s21_create_matrix(int rows, int columns, matrix_t *result);

double ** matrix_init(int rows, int columns)
int test();

#endif // SRC_S21_MATRIX_H_