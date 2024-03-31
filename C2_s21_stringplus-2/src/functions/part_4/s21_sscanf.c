#include "s21_sscanf.h"

#include "../../s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  modifiers m = {0};
  char **format_copy = (char **)&format;
  char **str_copy = (char **)&str;
  int error = 0;

  /* start */
  if (!(**str_copy)) error = 1;

  analyze_strformat(&m, format_copy);

  int count = 0, n = 0;  // количество считаных аргументов и символов

  while (*format_copy && *str_copy && **format_copy && **str_copy) {
    processing(&m, &args, str_copy, n);  // выполняем действия;

    if (!m.w_asterisk && m.r_specifier != '%') count++;
    n += m.r_n;
    s21_memset(&m, 0, sizeof(m));  // очистить структуру
    analyze_strformat(&m, format_copy);
  }

  n += m.r_n;

  // последний раз
  if (*format_copy && *str_copy) processing(&m, &args, str_copy, n);
  if (!m.w_asterisk && m.r_specifier != '%') count++;
  if (error) count *= -1;

  va_end(args);
  return count;
}

void analyze_strformat(modifiers *m, char **str) {
  // ищем процент
  *str = s21_strchr(*str, '%');

  // передвигаем указатель на первый символ модификатора/на спецификатор
  if (*str) {
    (*str)++;

    // обработка спецификатора %
    if (**str == '%') {
      // смещаем указатель со спецификатора %%
      m->r_specifier = '%';
      (*str)++;
    } else {
      // обработка [+-№ 0]
      analyze_sign(m, str);

      // обработка "*/num"
      analyze_width(m, str);

      // обработка "." "*/num"
      analyze_accuracy(m, str);

      // обработка длины && спецификаторов
      analyze_len_spec(m, str);
    }

    if (**str != '%' && **str != '\0') (*str)++;  // error?
  }
}

void analyze_sign(modifiers *m, char **str) {
  if (**str == '+') {
    (*str)++;
    m->f_sign = 1;
  }
  if (**str == '-') {
    (*str)++;
    m->f_sign = -1;
  }
  if (**str == '0') {
    (*str)++;
    m->f_zero = 1;
  }
  if (**str == ' ' && (*str)[1] != '%' && (*str)[1] != '\0') {
    (*str)++;
    m->f_space = 1;
  }
  if (**str == '#') {
    (*str)++;
    m->f_sharp = 1;
  }
}

void analyze_width(modifiers *m, char **str) {
  if (**str == '*') {
    m->w_asterisk = 1;
    (*str)++;
  }
  if (**str >= '0' && **str <= '9') {
    m->w_num = (int)s21_atoif(m, str, 0);
  }
}

void analyze_accuracy(modifiers *m, char **str) {
  if (**str == '.') {
    (*str)++;
    if (**str == '*') {
      (*str)++;
      m->a_asterisk = 1;
    } else
      m->a_num = (int)s21_atoif(m, str, 0);
  }
}

void analyze_len_spec(modifiers *m, char **str) {
  // длина
  if (**str == 'h') {
    (*str)++;
    m->l_h = 1;
  }
  if (**str == 'l') {
    if ((*str)[1] == 'l') {
      (*str) += 2;
      m->l_ll = 1;
    } else {
      (*str)++;
      m->l_l = 1;
    }
  }
  if (**str == 'L') {
    (*str)++;
    m->l_L = 1;
  }

  // спецификатор
  if (**str == 'c') m->r_specifier = 'c';
  if (**str == 'd') m->r_specifier = 'd';
  if (**str == 'i') m->r_specifier = 'i';
  if (**str == 'e') m->r_specifier = 'e';
  if (**str == 'E') m->r_specifier = 'E';
  if (**str == 'f') m->r_specifier = 'f';
  if (**str == 'g') m->r_specifier = 'g';
  if (**str == 'G') m->r_specifier = 'G';
  if (**str == 'o') m->r_specifier = 'o';
  if (**str == 's') m->r_specifier = 's';
  if (**str == 'u') m->r_specifier = 'u';
  if (**str == 'x') m->r_specifier = 'x';
  if (**str == 'X') m->r_specifier = 'X';
  if (**str == 'p') m->r_specifier = 'p';
  if (**str == 'n') m->r_specifier = 'n';
}

void analyze_char(modifiers *m, char **str, char **symbol, int width) {
  for (int i = 0; i < width; i++) {
    if (!m->w_asterisk) (*symbol)[i] = **str;
    (*str)++;
    m->r_n++;
  }
}

void analyze_string(modifiers *m, char **str, char **destination, int width) {
  while (**str == ' ' || **str == '\n' || **str == '\t') (*str)++;

  int i = 0, flag = width;
  if (!m->w_num) flag += 2;  // чтобы был один цикл под %s and %4s

  for (; !s21_strchr(" \n\t", **str) && **str && i < flag; i++) {
    (*destination)[i] = **str;
    m->r_n++;
    (*str)++;

    // if %s, continue
    if (!width) flag += 1;
  }
  (*destination)[i] = '\0';
}

void processing(modifiers *m, va_list *args, char **str, int n) {
  // if %c
  if (m->r_specifier == 'c') {
    char *symbol = NULL;
    if (!m->w_asterisk) symbol = va_arg(*args, char *);
    // if %c or %*c
    if (!m->w_num) analyze_char(m, str, &symbol, 1);
    // if %[num]c
    else
      analyze_char(m, str, &symbol, m->w_num);
  }
  // if %s
  if (m->r_specifier == 's') {
    char *string = va_arg(*args, char *);
    analyze_string(m, str, &string, m->w_num);
  }
  // if signed int
  if (s21_strchr("diouxX", m->r_specifier)) {
    void *integer = va_arg(*args, void *);
    processing_integers(m, str, integer);
  }
  // if floating
  if (s21_strchr("eEfgG", m->r_specifier)) {
    void *floating = va_arg(*args, void *);
    processing_floating(m, str, floating);
  }
  // // if ptr
  // if (m->r_specifier == 'p') {
  //   void *pointer = va_arg(args, void *);
  //   void **double_ptr = &pointer;
  //   void *adress = NULL;
  //   analyze_hex(m, str, adress);
  //   *double_ptr = (void *)(*((uintptr_t *)adress));
  // }

  // if %n
  if (m->r_specifier == 'n') {
    int *n_count = va_arg(*args, int *);
    *n_count = n + m->r_n;
  }
  // if %%
  if (m->r_specifier == '%') {
    while (**str == ' ') (*str)++;
    m->r_n++;
    if (**str == '%') (*str) += 2;
  }
}

void processing_integers(modifiers *m, char **str, void *integer) {
  while (**str == ' ' || **str == '\n' || **str == '\t') (*str)++;

  // if signed int
  if (m->r_specifier == 'd') {  // dec
    *((int *)integer) = (int)s21_atoif(m, str, 0);
  }

  if (m->r_specifier == 'i') {  // dec, oct, hex
    if (**str != '0') *((int *)integer) = s21_atoif(m, str, 0);
    if (**str == '0' && !((*str)[1] == 'x' || (*str)[1] == 'X'))
      analyze_oct(m, str, integer);
    if (**str == '0' && ((*str)[1] == 'x' || (*str)[1] == 'X'))
      analyze_hex(m, str, integer);
  }

  // if unsigned int
  if (m->r_specifier == 'o') {  // oct
    analyze_oct(m, str, integer);
  }
  if (m->r_specifier == 'u') {  // dec
    *((unsigned int *)integer) = (unsigned int)s21_atoif(m, str, 0);
  }
  if (m->r_specifier == 'x' || m->r_specifier == 'X') {  // hex
    analyze_hex(m, str, integer);
  }
}

void processing_floating(modifiers *m, char **str, void *floating) {
  while (**str == ' ' || **str == '\n' || **str == '\t') (*str)++;

  // научная нотация может быть только в числах с плавающей точкой
  // проверяем на научную нотацию, идем, пока это цифры
  int exp = 0, i = 0;
  if (**str == '-' || **str == '+') i++;
  for (; ((*str)[i] >= '0' && (*str)[i] <= '9') || (*str)[i] == '.'; i++)
    ;
  if ((*str)[i] == 'e' || (*str)[i] == 'E') exp = 1;

  if (exp) {
    analyze_s_not(m, str, floating);
  } else {
    if (m->l_l) {
      *((double *)floating) = (double)s21_atoif(m, str, 1);
    } else if (m->l_L) {
      *((long double *)floating) = s21_atoif(m, str, 1);
    } else {
      *((float *)floating) = (float)s21_atoif(m, str, 1);
    }
  }
}