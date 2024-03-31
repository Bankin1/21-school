#include "../../s21_string.h"

char* s21_strstr(const char* haystack, const char* needle) {
  char* result = s21_NULL;
  int i = 0, j = 0, flag = 0, begin = 0;
  for (; haystack[i] != '\0' && !flag; i++, j++) {
    if (needle[j] != '\0') {
      if (haystack[i] != needle[j]) {
        j = -1;
        ++begin;
        i = begin;
      }
    } else {
      flag = 1;
      result = (char*)haystack + i - j;
    }
  }
  return result;
}