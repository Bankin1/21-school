#include "../../s21_matrix.h"
#include "../help/s21_help.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = S21_OK;
  if (is_matrix_exists(A)) {
    if (A->columns == A->rows) {
      double determinant;
      s21_determinant(A, &determinant);
      if (determinant != 0) {
        if (A->columns == 1) {
          s21_create_matrix(1, 1, result);
          result->matrix[0][0] = 1 / determinant;
        } else {
          matrix_t calc_complements, calc_complements_transpose;
          s21_calc_complements(A, &calc_complements);
          s21_transpose(&calc_complements, &calc_complements_transpose);
          s21_mult_number(&calc_complements_transpose, 1 / determinant, result);
          s21_remove_matrix(&calc_complements);
          s21_remove_matrix(&calc_complements_transpose);
        }
      } else
        status = S21_MATH_FAIL;
    } else
      status = S21_MATH_FAIL;
  } else
    status = S21_MATRIX_FAIL;
  return status;
}