#include "../../s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *result = s21_NULL;
  int len = s21_strlen(str);
  for (int i = 0; result == s21_NULL && i < len; i++) {
    if (str[i] == c) {
      result = (str + i);
    }
  }
  return (char *)result;
}