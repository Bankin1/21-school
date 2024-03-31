#include "../../s21_matrix.h"
#include "../help/s21_help.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = S21_OK;

  if (is_matrix_exists(A)) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  } else
    status = S21_MATRIX_FAIL;

  return status;
}