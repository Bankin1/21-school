#include "s21_help.h"

void print_matrix(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      printf("%d/%d ", i, j);
      if (i == (matrix->columns - 1) && j == (matrix->rows - 1))
        printf("%lf\n\n", matrix->matrix[i][j]);
      else if (j == (matrix->columns - 1))
        printf("%lf\n", matrix->matrix[i][j]);
      else
        printf("%lf ", matrix->matrix[i][j]);
    }
  }
}
