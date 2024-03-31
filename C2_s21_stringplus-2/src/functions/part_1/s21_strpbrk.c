#include "../../s21_string.h"

char* s21_strpbrk(const char* str1, const char* str2) {
  char* result = s21_NULL;
  int flag = 0;
  for (int i = 0; str1[i] != '\0' && !flag; i++) {
    if (s21_strchr(str2, str1[i])) {
      flag = 1;
      result = (char*)str1 + i;
    }
  }
  return result;
}