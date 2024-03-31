#include "../../s21_matrix.h"
#include "../help/s21_help.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = S21_OK;
  if (is_matrix_exists(A)) {
    if (A->columns == A->rows) {
      if (A->rows == 1)
        *result = A->matrix[0][0];
      else
        *result = determinant_recursion(A);
    } else
      status = S21_MATH_FAIL;
  } else
    status = S21_MATRIX_FAIL;
  return status;
}
