#include "../../s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2);

char *s21_strtok(char *str, const char *delim) {
  char *result = s21_NULL;
  static char *buffer;
  if (str != s21_NULL) buffer = str;

  // нашли начало токена
  buffer += s21_strspn(buffer, delim);

  // если есть токен (строка не состоит из delim)
  if (*buffer != '\0') {
    result = buffer;

    // ищем конец токена
    buffer += s21_strcspn(buffer, delim);

    // если это не конец исходной строки
    if (*buffer != '\0') {
      *buffer = '\0';
      buffer++;
    }
  }
  // printf("token in result: \n%s\nstart in buffer:
  // \n%s\n___________________\n", result, buffer);

  return result;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  s21_size_t len = s21_strlen(str1);
  int check = 1;
  for (; check && result < len; result++) {
    if (s21_strchr(str2, str1[result]) == s21_NULL) {
      check = 0;
      result--;
    }
  }
  return (result);
}
