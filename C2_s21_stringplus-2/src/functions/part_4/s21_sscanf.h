#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <stdarg.h>

typedef struct {
  // result
  char r_specifier;
  // int r_result;
  int r_n;

  // flags
  int f_sign;  // 1 = '+'; -1 = '-'
  int f_space;
  int f_sharp;  // #
  int f_zero;

  // width
  int w_num;       // %num
  int w_asterisk;  // %*

  // accuracy
  int a_num;       // .num
  int a_asterisk;  // .*

  // length
  int l_h;  // short
  int l_l;  // long integer
  int l_ll; // long long integer
  int l_L;  // long floating
} modifiers;

typedef unsigned long s21_uintptr_t;

/* for help */

void spec_x(modifiers *m, void *number, unsigned int num);
void spec_i(modifiers *m, void *number, unsigned int num, int negative);

/// @brief обрабатывает научную нотацию
/// @param m структура для учета модификаторов и спецификаторов при обработке
/// @param str строка-источник
/// @param num указатель, через который запишем обработанное десятичное число
void analyze_s_not(modifiers *m, char **str, void *num);

/// @brief обрабатывает знаки +/- из строки
/// @param str строка-источник
/// @param neg переменная-флаг (1 - считал минус, 0 - считал плюс)
void convert_sign(char **str, int *neg);

/* convert numbers */

/// @brief конвертирует строку (не в научной нотации) в целочисленное или дробное число
/// @param m структура для учета модификаторов и спецификаторов при обработке
/// @param str строка-источник
/// @param is_float флаг (является ли число дробным)
/// @return преобразованное число
long double s21_atoif(modifiers *m, char **str, int is_float);

/* analyze format */

/// @brief обрабатывает из форматной строки по одному формату за раз, заполняя структуру
/// @param m структура, в которой будут храниться считанные модификаторы и спецификаторы
/// @param str строка-источник
void analyze_strformat(modifiers *m, char **str);

/// @brief анализ модификаторов "+", "-", " ", "0", "#"
/// @param m структура, в которой будут храниться считанные модификаторы
/// @param str строка-источник
void analyze_sign(modifiers *m, char **str);

/// @brief анализ модификаторов ширины "*", "num"
/// @param m структура, в которой будут храниться считанные модификаторы
/// @param str строка-источник
void analyze_width(modifiers *m, char **str);

/// @brief анализ модификаторов точности ".*", ".num"
/// @param m структура, в которой будут храниться считанные модификаторы
/// @param str строка-источник
void analyze_accuracy(modifiers *m, char **str);

/// @brief анализ модификаторов длины "l", "ll", "L" и "h" и спецификаторов
/// @param m структура, в которой будут храниться считанные модификаторы и спецификатор
/// @param str строка-источник
void analyze_len_spec(modifiers *m, char **str);

/* analyze string */

/// @brief считывание символа из строки (ширина "*" подавляет присваивание, "num" позволяет считать энное количество char из строки и записать их в массив без '\0')
/// @param m структура, в которой хранятся считанные модификаторы и спецификатор
/// @param str строка-источник
/// @param symbol указатель, через который запишем символ или массив символов
/// @param width флаг (ширина, т.е. количество считываемых символов)
void analyze_char(modifiers *m, char **str, char **symbol, int width);

/// @brief считывание подстроки (ширина "*" подавляет присваивание, "num" ограничивает количество считываемых символов; если модификатора ширины нет, считывает до пробельных символов или до конца строки)
/// @param m структура, в которой хранятся считанные модификаторы и спецификатор
/// @param str строка-источник
/// @param destination строка, в которую записывается подстрока
/// @param width флаг (ширина, т.е. количество считываемых символов)
void analyze_string(modifiers *m, char **str, char **destination, int width);

/// @brief конвертирует строку с восьмеричным числом в целочисленное десятичное число (int: oct -> dec)
/// @param m структура для учета модификаторов и спецификаторов при обработке
/// @param str строка-источник
/// @param num указатель, через который запишем число в десятичной системе
void analyze_oct(modifiers *m, char **str, void *number);

/// @brief конвертирует строку с шестнадцатеричным числом в целочисленное десятичное число (int: oct -> dec)
/// @param m структура для учета модификаторов и спецификаторов при обработке
/// @param str строка-источник
/// @param num указатель, через который запишем число в десятичной системе
void analyze_hex(modifiers *m, char **str, void *number);

/* process */

/// @brief функция вызова вспомогательных функций в зависимости от текущего спецификатора
/// @param m структура для учета модификаторов и спецификаторов при обработке
/// @param args структура данных, в которой хранится вариативное количество аргументов-указателей, которые принимал sscanf()
/// @param str строка-источник с данными
/// @param n количество считанных символов до вызова функции (для спецификатора %n)
void processing(modifiers *m, va_list *args, char **str, int n);

/// @brief функция обработки целочисленных чисел
/// @param m структура для учета модификаторов и спецификаторов при обработке
/// @param str строка-источник
/// @param integer указатель, куда надо будет записать считанное число (типизируем позже в зависимости от спецификатора и модификатора длины)
void processing_integers(modifiers *m, char **str, void *integer);

/// @brief функция обработки дробных чисел
/// @param m структура для учета модификаторов и спецификаторов при обработке
/// @param str строка-источник
/// @param integer указатель, куда надо будет записать считанное число (типизируем позже в зависимости от спецификатора и модификатора длины)
void processing_floating(modifiers *m, char **str, void *integer);

/* main */

/// @brief считывает форматированный ввод из строки
/// @param str строка с данными
/// @param format строка с форматами
/// @param ... вариативное количество аргументов-указателей на переменные, в которые нужно записать считанные данные
/// @return количество успешно считанных элементов
int s21_sscanf(const char *str, const char *format, ...);

/* для проверок */
/*
  printf(
      "s:%c\tres:%d\t%%n:%d\t+:%d\t' "
      "':%d\t#:%d\t0:%d\tnum:%d\t*:%d\t.num:%d\t.*:%d\th:%dl:%dL;%d\n",
      m.r_specifier, m.r_result, m.r_n, m.f_sign, m.f_space, m.f_sharp,
      m.f_zero, m.w_num, m.w_asterisk, m.a_num, m.a_asterisk, m.l_h, m.l_l,
      m.l_L);
      */

#endif