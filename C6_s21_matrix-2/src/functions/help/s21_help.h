#ifndef S21_HELP_H_
#define S21_HELP_H_

#include "../../s21_matrix.h"

void print_matrix(matrix_t *matrix);
void full_one(matrix_t *matrix);
void identity_matrix(matrix_t *matrix);
int is_matrix_exists(matrix_t *matrix);
void from_array(double *arr, matrix_t *matrix);
double determinant_recursion(matrix_t *matrix);
void make_matrix_excluding(matrix_t *matrix, int row, int column, matrix_t *result);
double minor(matrix_t *matrix);

#endif  // S21_HELP_H_