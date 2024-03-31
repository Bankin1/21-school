#include "s21_help.h"

void make_matrix_excluding(matrix_t *matrix, int row, int column,
                           matrix_t *result) {
  // int ii = matrix->rows - 1, jj = matrix->columns - 1;
  s21_create_matrix((matrix->rows - 1), (matrix->columns - 1), result);
  int row_now = 0, column_now = 0;
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      if (i != row && j != column) {
        result->matrix[row_now][column_now] = matrix->matrix[i][j];
        column_now++;
        if (column_now == result->columns) {
          row_now++;
          column_now = 0;
        }
      }
    }
  }
}