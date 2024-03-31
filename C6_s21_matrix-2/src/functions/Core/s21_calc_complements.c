#include "../../s21_matrix.h"
#include "../help/s21_help.h"

void s21_double_calc_complements(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = S21_OK;
  if (is_matrix_exists(A)) {
    if (A->columns == A->rows) {
      s21_create_matrix(A->rows, A->columns, result);
      if (A->rows == 1)
        result->matrix[0][0] = A->matrix[0][0];
      else if (A->rows == 2) {
        s21_double_calc_complements(A, result);
      } else {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            matrix_t small_matrix;
            make_matrix_excluding(A, i, j, &small_matrix);
            double sign = (i + j) % 2 == 0 ? 1 : -1;
            result->matrix[i][j] = sign * determinant_recursion(&small_matrix);
            s21_remove_matrix(&small_matrix);
          }
        }
      }
    } else
      status = S21_MATH_FAIL;
  } else
    status = S21_MATRIX_FAIL;
  return status;
}

void s21_double_calc_complements(matrix_t *A, matrix_t *result) {
  result->matrix[0][0] = A->matrix[1][1];
  result->matrix[0][1] = -A->matrix[1][0];
  result->matrix[1][0] = -A->matrix[0][1];
  result->matrix[1][1] = A->matrix[0][0];
}