#include "../../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = S21_OK;
  if (!(rows > 0 && columns > 0))
    status = S21_MATRIX_FAIL;
  else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)malloc(columns * sizeof(double));
    }
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = 0;
      }
    }
  }

  return status;
}

// if (!(rows > 0 && columns > 0))
//     status = S21_MATRIX_FAIL;
//   else {
//     if ((result->matrix = (double **)malloc(rows * sizeof(double *)))){
//       result->rows = rows;
//       result->columns = columns;
//       for (int i = 0; i < rows && status == S21_OK; i++) {
//          if (!(result->matrix[i] = (double *)malloc(columns *
//          sizeof(double)))){
//           for (int x = 0; x < i; x++){
//             free(result->matrix[x]);
//           }
//           free(result->matrix);
//           status = 3;
//          }
//       }
//       if (status == S21_OK){
//         for (int i = 0; i < rows; i++) {
//           for (int j = 0; j < columns; j++) {
//             result->matrix[i][j] = 0;
//           }
//         }
//       }
//     }
//     else status = 3;
//   }