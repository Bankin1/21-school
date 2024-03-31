#include "s21_help.h"

double determinant_recursion(matrix_t *matrix) {
  double result = 0;
  double sign = 1;

  if (matrix->rows == 2) {
    result = minor(matrix);
  } else {
    for (int i = 0; i < matrix->columns; i++) {
      matrix_t small_matrix;
      make_matrix_excluding(matrix, 0, i, &small_matrix);
      result +=
          matrix->matrix[0][i] * determinant_recursion(&small_matrix) * sign;
      sign = -sign;
      s21_remove_matrix(&small_matrix);
    }
  }

  return result;
}

double minor(matrix_t *matrix) {
  return matrix->matrix[0][0] * matrix->matrix[1][1] -
         matrix->matrix[0][1] * matrix->matrix[1][0];
}