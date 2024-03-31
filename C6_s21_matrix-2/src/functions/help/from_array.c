#include "s21_help.h"

void from_array(double *arr, matrix_t *matrix) {
  int score = 0;
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = arr[score++];
    }
  }
}