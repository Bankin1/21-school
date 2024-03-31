#include "../../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *result = s21_NULL;
  for (int i = s21_strlen(str) - 1; result == s21_NULL && i >= 0; i--) {
    if (str[i] == c) {
      result = (str + i);
    }
  }
  return (char *)result;
}