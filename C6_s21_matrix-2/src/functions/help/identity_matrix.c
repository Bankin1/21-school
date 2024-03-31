#include "s21_help.h"

void identity_matrix(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      if (i == j) matrix->matrix[i][j] = 1;
    }
  }
}
