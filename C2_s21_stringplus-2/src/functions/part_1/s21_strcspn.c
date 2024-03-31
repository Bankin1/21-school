#include "../../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  s21_size_t len = s21_strlen(str1);
  int check = 1;
  for (; check && result < len; result++) {
    if (s21_strchr(str2, str1[result]) != s21_NULL) {
      check = 0;
      result--;
    }
  }
  return (result);
}