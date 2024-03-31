#include "../../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *src_copy = s21_NULL, *result = s21_NULL;

  if (src && trim_chars) {
    char *trim = (char *)trim_chars;
    src_copy = (char *)src;
    int start_index = 0, match = 0, end = 0;
    for (; src_copy[start_index] && !end; start_index++) {
      match = 0;
      for (int j = 0; trim[j] && !match; j++) {
        if (src_copy[start_index] == trim[j]) match = 1;
      }
      if (!match) {
        src_copy = &src_copy[start_index];
        start_index = 0;
        end = 1;
      }
    }

    int end_index = (s21_strlen(src_copy) - 1);
    for (end = 0; src_copy[end_index] && !end; end_index--) {
      match = 0;
      for (int j = 0; trim[j] && !match; j++) {
        if (src_copy[end_index] == trim[j]) match = 1;
      }
      if (!match) end = 1;
    }

    if (src_copy) {
      end_index++;
      result = calloc((end_index + 2), 1);
      int i = 0;
      for (; i <= end_index; i++) {
        result[i] = src_copy[i];
      }
      result[i] = '\0';
    }
  }
  return result;
}
// iterates through src_copy to find he start and the end indicies for the
// trimed string
/// @brief Возвращает новую строку, в которой удаляются все начальные и конечные
/// вхождения набора заданных символов (trim_chars) из данной строки (src). Если
/// возникла ошибка - возвращает значение NULL
/// @param src строка-источник
/// @param trim_chars набор удаляемых символов
/// @return указатель на новую строку или ошибку (NULL)
