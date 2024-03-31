#include "../../s21_string.h"
#include "s21_sscanf.h"

void convert_sign(char **str, int *neg) {
  if (**str == '-') {
    *neg = 1;
    (*str)++;
  }
  if (**str == '+') (*str)++;
}

long double s21_atoif(modifiers *m, char **str, int is_float) {
  while (**str == ' ' || **str == '\n' || **str == '\t') (*str)++;
  // максимально длинный тип в нашем случае (10 байт)
  long double num = 0.0, decimal = 0.1;
  int i = 0, negative = 0;

  convert_sign(str, &negative);

  // для целой части
  for (; (*str)[i] >= '0' && (*str)[i] <= '9'; i++) {
    num = num * 10.0 + ((*str)[i] - '0');
    m->r_n++;
  }

  // для дробной части
  if ((*str)[i] == '.' && is_float) {
    i++;
    for (m->r_n++; (*str)[i] >= '0' && (*str)[i] <= '9'; i++) {
      num += ((*str)[i] - '0') * decimal;
      decimal *= 0.1;
      m->r_n++;
    }
  }

  if (negative) num *= -1;
  *str = &((*str)[i]);
  return num;
}