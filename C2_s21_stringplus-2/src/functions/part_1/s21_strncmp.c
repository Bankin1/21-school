#include "../../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  int check = 1;
  for (s21_size_t i = 0; check && i < n; i++) {
    if (str1[i] != str2[i]) {
      result = str1[i] - str2[i];
      check = 0;
    }
  }
  return result;
}