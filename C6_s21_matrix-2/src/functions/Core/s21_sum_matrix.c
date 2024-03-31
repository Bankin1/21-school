#include "../../s21_matrix.h"
#include "../help/s21_help.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = S21_OK;

  if (is_matrix_exists(A) && is_matrix_exists(B)) {
    if (A->columns == B->columns && A->rows == B->rows) {
      s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    } else
      status = S21_MATH_FAIL;
  } else
    status = S21_MATRIX_FAIL;

  return status;
}