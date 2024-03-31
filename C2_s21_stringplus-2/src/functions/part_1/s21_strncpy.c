#include "../../s21_string.h"

char* s21_strncpy(char* dest, const char* src, s21_size_t n) {
  unsigned long int i = 0;
  for (; i < n && ((char*)src)[i]; i++) {
    ((char*)dest)[i] = ((char*)src)[i];
  }
  ((char*)dest)[i] = '\0';
  return dest;
}