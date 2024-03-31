#include <stdarg.h>

#include "../../s21_string.h"

int s21_sprintf(char* str, const char* format, ...) {
  int count_b = 0;
  va_list arguments;
  va_start(arguments, format);
  for (; *format; format++) {
    if (*format != '%') {
      str[count_b] = *format;
      count_b++;
      continue;
    }
    format++;
    if (*format == '%') {
      str[count_b] = *format;
      count_b++;
      continue;
    }
    int min = 0;
    int plus = 0;
    int space = 0;
    int width = 0;
    int prec = 0;
    int is_prec = -1;
    char length = '0';
    while (*format == '+' || *format == '-' ||
           *format == ' ') {  // обрабатываю флаги
      if (*format == '+') {
        plus = 1;
      } else if (*format == '-') {
        min = 1;
      } else {
        space = 1;
      }
      format++;
    }
    while (*format >= '0' && *format <= '9') {  // width
      width = width * 10 + (*format - '0');
      format++;
    }

    if (*format == '.') {  // precision
      format++;
      while (*format >= '0' && *format <= '9') {
        prec = prec * 10 + (*format - '0');
        is_prec = 1;
        format++;
      }
    }
    if (*format == 'h' || *format == 'l') {  // Length
      length = *format;
      format++;
    }

    if (*format == 'd') {
      long int val = va_arg(arguments, long int);
      if (length == 'h') {
        val = (short int)val;
      } else if (length == '0') {
        val = (int)val;
      }
      flags_du(val, str, &count_b, width, min, plus, space, prec, is_prec);
    } else if (*format == 'u') {
      long unsigned int val = va_arg(arguments, long unsigned int);
      if (length == 'h') {
        val = (short unsigned int)val;
      } else if (length == '0') {
        val = (unsigned int)val;
      }
      flags_du(val, str, &count_b, width, min, plus, space, prec, is_prec);
    } else if (*format == 'c') {
      char val;
      if (length == 'l') {
        wchar_t tmp = va_arg(arguments, wchar_t);
        val = (char)tmp;
      } else {
        val = (char)va_arg(arguments, int);
      }
      flag_c(val, str, &count_b, width, min, space);
    } else if (*format == 'f') {
      double val = va_arg(arguments, double);
      flag_f(val, str, &count_b, width, min, plus, space, prec, is_prec);
    } else if (*format == 's') {
      if (length == 'l') {
        wchar_t* val = va_arg(arguments, wchar_t*);
        flag_wide_s(val, str, &count_b, width, min, prec, is_prec);
      } else {
        char* val = va_arg(arguments, char*);
        flag_s(val, str, &count_b, width, min, prec, is_prec);
      }
    }
  }
  va_end(arguments);
  str[count_b] = '\0';
  return count_b;
}

void flags_du(long int value, char* str, int* ind, int width, int min, int plus,
              int space, int prec, int is_prec) {
  int c_prec = 0;
  int c_width = 0;
  int prec_ch = prec;
  long int val = value;

  counting_du(value, &c_prec, &c_width, plus, space, prec, is_prec);

  if (min == 0) {
    while (prec_ch > c_prec) {
      c_width++;
      prec_ch--;
    }

    while (c_width < width) {
      str[(*ind)++] = ' ';
      c_width++;
    }

    sign_flags_du(str, ind, val, plus, space);
    prec_ch = prec;

    while (prec_ch > c_prec) {
      str[*ind] = '0';
      (*ind)++;
      prec_ch--;
    }
    if (!(is_prec != -1 && val == 0 && prec == 0)) {
      s21_itoa(val, str, ind);
    }

  } else {
    sign_flags_du(str, ind, val, plus, space);

    while (prec_ch > c_prec) {  ////
      str[*ind] = '0';
      (*ind)++;
      prec_ch--;
      c_width++;
    }

    if (!(is_prec != -1 && val == 0 && prec == 0)) {
      s21_itoa(val, str, ind);
    } else {
      c_width--;
    }

    while (c_width < width) {
      str[(*ind)++] = ' ';
      c_width++;
    }
  }
}

void counting_du(long int value, int* c_prec, int* c_width, int plus, int space,
                 int prec, int is_prec) {
  long int val = value;

  if (value == 0) {
    (*c_prec)++;
    (*c_width)++;
  }

  if (value == 0 && prec == 0 && is_prec != -1) {
    (*c_width)--;
  }

  while (labs(value) > 0) {
    value /= 10;
    (*c_prec)++;
    (*c_width)++;
  }

  if (val < 0 || (plus == 1 && val >= 0) ||
      (plus != 1 && space == 1 && val >= 0)) {
    (*c_width)++;
  }
}

void sign_flags_du(char* str, int* ind, long int val, int plus, int space) {
  if (plus == 1 && val >= 0) {
    str[*ind] = '+';
    (*ind)++;
  }

  if (plus == 0 && space == 1 && val >= 0) {
    str[*ind] = ' ';
    (*ind)++;
  }

  if (val < 0) {
    str[*ind] = '-';
    (*ind)++;
  }
}

void s21_itoa(long int value, char* buffer, int* ind) {
  int start = *ind;

  if (value < 0) {
    value = -value;
  }

  do {
    buffer[(*ind)++] = '0' + (value % 10);
    value /= 10;
  } while (value > 0);

  int end = *ind - 1;
  while (start < end) {
    char temp = buffer[start];
    buffer[start] = buffer[end];
    buffer[end] = temp;
    start++;
    end--;
  }
}

void flag_c(char value, char* str, int* ind, int width, int min, int space) {
  int c_width = 0;
  if (min == 0) {
    while (c_width < width - 1) {
      str[(*ind)++] = ' ';
      c_width++;
    }

    if (space) {
      str[*ind] = ' ';
      (*ind)++;
    }
    str[(*ind)++] = value;
  } else {
    if (space) {
      str[*ind] = ' ';
      (*ind)++;
      c_width++;
    }
    str[(*ind)++] = value;
    c_width++;
    while (c_width < width) {
      str[(*ind)++] = ' ';
      c_width++;
    }
  }
}

void flag_f(double value, char* str, int* ind, int width, int min, int plus,
            int space, int prec, int is_prec) {
  int start_ind = *ind;
  if (is_prec != -1 && prec == 0) {
    prec = 1;
    flags_du((long int)value, str, ind, width, min, plus, space, prec, is_prec);
  } else if (is_prec == -1) {
    if (min == 0) {
      flags_du((long int)value, str, ind, width - 7, min, plus, space, prec,
               is_prec);

    } else {
      flags_du((long int)value, str, ind, 0, min, plus, space, prec, is_prec);
    }
    start_ind = *ind - start_ind;
    str[*(ind)] = '.';
    (*ind)++;
    start_ind++;
    prec = 6;
    start_ind += 6;
    for (int i = 0; i < prec; i++) {
      value *= 10;
      s21_itoa((long int)value % 10, str, ind);
    }
    while (start_ind < width) {
      str[(*ind)] = ' ';
      (*ind)++;
      start_ind++;
    }
  } else {
    if (min == 0) {
      flags_du((long int)value, str, ind, width - prec - 1, min, plus, space, 0,
               -1);
    } else {
      flags_du((long int)value, str, ind, 0, min, plus, space, 0, -1);
    }
    start_ind = *ind - start_ind;
    str[(*ind)] = '.';
    (*ind)++;
    start_ind++;
    start_ind += prec;
    for (int i = 0; i < prec - 1; i++) {
      value *= 10;
      s21_itoa((long int)value % 10, str, ind);
    }
    value *= 100;
    if (labs((long int)value) % 10 >= 5) {
      value /= 10;
      s21_itoa(labs((long int)value % 10) + 1, str, ind);
    } else {
      value /= 10;
      s21_itoa((long int)value % 10, str, ind);
    }
    while (start_ind < width) {
      str[(*ind)] = ' ';
      (*ind)++;
      start_ind++;
    }
  }
}

void flag_wide_s(wchar_t* value, char* str, int* ind, int width, int min,
                 int prec, int is_prec) {
  char temp_str[1000] = {0};
  int i = 0;
  int c_width = 0;
  size_t val_length;
  while (value[i]) {
    temp_str[i] = value[i];
    ++i;
  }
  temp_str[i] = '\0';
  if (is_prec == -1) {
    val_length = s21_strlen(temp_str);
  } else {
    val_length = prec;
  }
  if (min) {
    size_t val_ind = 0;
    while (val_ind < val_length) {
      str[(*ind)++] = temp_str[val_ind];
      val_ind++;
      c_width++;
    }
    while (c_width < width) {
      str[(*ind)++] = ' ';
      c_width++;
    }
  } else {
    while (c_width < width - (int)val_length) {
      str[(*ind)++] = ' ';
      c_width++;
    }
    size_t val_ind = 0;
    while (val_ind < val_length) {
      str[(*ind)++] = temp_str[val_ind];
      val_ind++;
    }
  }
}

void flag_s(char* value, char* str, int* ind, int width, int min, int prec,
            int is_prec) {
  int c_width = 0;
  size_t val_length;
  if (is_prec == -1) {
    val_length = s21_strlen(value);
  } else {
    val_length = prec;
  }
  if (min == 1) {
    size_t val_ind = 0;
    while (val_ind < val_length) {
      str[(*ind)++] = value[val_ind];
      val_ind++;
      c_width++;
    }
    while (c_width < width) {
      str[(*ind)++] = ' ';
      c_width++;
    }
  } else {
    while (c_width < width - (int)val_length) {
      str[(*ind)++] = ' ';
      c_width++;
    }
    size_t val_ind = 0;
    while (val_ind < val_length) {
      str[(*ind)++] = value[val_ind];
      val_ind++;
    }
  }
}
