#include "../../s21_string.h"
#include "s21_sscanf.h"

/* for scientific notation */

void analyze_s_not(modifiers *m, char **str, void *num) {
  long double mantissa = s21_atoif(m, str, 1);

  // пропускаем экспоненту
  if (**str == 'e' || **str == 'e') (*str)++;
  long double extent = s21_atoif(m, str, 0);

  if (extent >= 0.0) {
    for (int i = 0; i < extent; i++) mantissa *= 10.0;
  } else {
    for (int i = 0; i > extent; i--) mantissa /= 10.0;
  }

  // нет длины
  if (!m->l_l && !m->l_L) {
    *((float *)num) = (float)mantissa;
  }
  if (m->l_l) {
    *((double *)num) = (double)mantissa;
  }
  if (m->l_L) {
    *((long double *)num) = mantissa;
  }
}

/* for octal */

void analyze_oct(modifiers *m, char **str, void *number) {
  unsigned int num = 0, oct = 1;
  int i = 0, shift = 0, negative = 0;
  convert_sign(str, &negative);

  if (**str == '0') (*str)++;

  for (; (*str)[i] >= '0' && (*str)[i] <= '7'; i++) m->r_n++;
  shift = i;
  i--;

  for (; i >= 0; i--) {
    num += ((*str)[i] - '0') * oct;
    oct *= 8;  // повышаем на порядок
  }

  (*str) = &((*str)[shift]);

  if (m->r_specifier == 'o') *((unsigned int *)number) = num;
  if (m->r_specifier == 'i') {
    int buff = (int)num;
    if (negative) buff *= -1;
    *((int *)number) = buff;
  }
}

/* for hexadecimal */

void analyze_hex(modifiers *m, char **str, void *number) {
  unsigned int num = 0, hex = 1;
  int i = 0, shift = 0, negative = 0;
  convert_sign(str, &negative);

  if (**str == '0') {
    (*str)++;
    if (**str == 'x' || **str == 'X') (*str)++;
  }
  for (; ((*str)[i] >= '0' && (*str)[i] <= '9') ||
         s21_strchr("ABCDEFabcdef", (*str)[i]);
       i++) {
    m->r_n++;
  }

  shift = i;
  i--;

  for (; i >= 0; i--) {
    if ((*str)[i] >= '0' && (*str)[i] <= '7') {
      num += ((*str)[i] - '0') * hex;
    } else {
      if ((*str)[i] == 'A' || (*str)[i] == 'a') num += 10 * hex;
      if ((*str)[i] == 'B' || (*str)[i] == 'b') num += 11 * hex;
      if ((*str)[i] == 'C' || (*str)[i] == 'c') num += 12 * hex;
      if ((*str)[i] == 'D' || (*str)[i] == 'd') num += 13 * hex;
      if ((*str)[i] == 'E' || (*str)[i] == 'e') num += 14 * hex;
      if ((*str)[i] == 'F' || (*str)[i] == 'f') num += 15 * hex;
    }
    hex *= 16;
  }

  (*str) = &((*str)[shift]);
  if (m->r_specifier == 'x' || m->r_specifier == 'X') {
    spec_x(m, number, num);
  }

  if (m->r_specifier == 'i') {
    spec_i(m, number, num, negative);
  }
}

void spec_x(modifiers *m, void *number, unsigned int num) {
  if (m->l_h)
    *((unsigned short int *)number) = num;
  else if (m->l_l)
    *((unsigned long int *)number) = num;
  else if (m->l_ll)
    *((unsigned long long int *)number) = num;
  else
    *((unsigned int *)number) = num;
}

void spec_i(modifiers *m, void *number, unsigned int num, int negative) {
  if (m->l_h) {
    short int buff = (short int)num;
    if (negative) buff *= -1;
    *((short int *)number) = buff;
  } else if (m->l_l) {
    long int buff = (long int)num;
    if (negative) buff *= -1;
    *((long int *)number) = buff;
  } else if (m->l_ll) {
    long long int buff = (long long int)num;
    if (negative) buff *= -1;
    *((long long int *)number) = buff;
  } else {
    int buff = (int)num;
    if (negative) buff *= -1;
    *((int *)number) = buff;
  }
}