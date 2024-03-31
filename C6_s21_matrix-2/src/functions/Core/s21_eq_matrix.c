#include "../../s21_matrix.h"
#include "../help/s21_help.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = S21_SUCCESS;
  if (A->columns == B->columns && A->rows == B->rows && is_matrix_exists(A) &&
      is_matrix_exists(B)) {
    for (int i = 0; i < A->rows && result; i++) {
      for (int j = 0; j < A->columns && result; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07)
          result = S21_FAILURE;
      }
    }
  }
  // else if(A->columns == B->columns && A->rows == B->rows && !A->matrix &&
  // !B->matrix) result = S21_SUCCESS;
  else
    result = S21_FAILURE;
  return result;
}