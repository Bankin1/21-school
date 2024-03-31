#include "../../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *result = str;
  int check = 0;  // для проверки нашелся ли символ
  for (s21_size_t i = 0; check == 0 && i < n; i++) {
    if (result[i] == c) {
      // if (c != '\0')
      result += i;
      check = 1;
    }
  }

  return check ? (void *)result : s21_NULL;
}