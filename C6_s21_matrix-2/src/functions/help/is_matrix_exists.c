#include "s21_help.h"

int is_matrix_exists(matrix_t *matrix) {
  int result = 1;
  if (matrix->columns <= 0 || matrix->rows <= 0 || matrix->matrix == NULL ||
      !matrix)
    result = 0;
  return result;
}
