#include "../../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i += 1) {
    ((char *)dest)[i] = ((char *)src)[i];
  }
  return dest;
}
