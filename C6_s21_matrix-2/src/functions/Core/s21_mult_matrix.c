#include "../../s21_matrix.h"
#include "../help/s21_help.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = S21_OK;

  if (is_matrix_exists(A) && is_matrix_exists(B)) {
    if (A->columns == B->rows) {  //&& A->rows == B->columns
      s21_create_matrix(A->rows, B->columns, result);
      for (int u = 0; u < result->rows; u++) {
        for (int i = 0; i < result->columns; i++) {
          for (int j = 0; j < B->rows; j++) {
            // printf(" %d %d ", u, i);
            result->matrix[u][i] += (A->matrix[u][j] * B->matrix[j][i]);
          }
        }
      }
    } else
      status = S21_MATH_FAIL;
  } else
    status = S21_MATRIX_FAIL;

  return status;
}