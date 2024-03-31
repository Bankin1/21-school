#include "../../s21_matrix.h"
#include "../help/s21_help.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = S21_OK;
  if (is_matrix_exists(A)) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  } else
    status = S21_MATRIX_FAIL;
  return status;
}