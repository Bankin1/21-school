#include "../../s21_string.h"

int s21_memcmp(const void* str1, const void* str2, size_t n) {
  int code = 0;
  for (long unsigned i = 0; i < n && code == 0; i++) {
    code = ((char*)str1)[i] - ((char*)str2)[i];
  }
  return code;
}
