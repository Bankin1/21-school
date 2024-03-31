#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_NULL ((void *)0)

typedef long unsigned s21_size_t;

// part 1 (string.h)
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

// s21_size_t s21_strspn(const char *str1, const char *str2);

// part 2 (sprintf)
int s21_sprintf(char *str, const char *format, ...);
void flags_du(long int value, char *str, int *ind, int width, int min, int plus,
              int space, int prec, int is_prec);
void counting_du(long int value, int *c_prec, int *c_width, int plus, int space,
                 int prec, int is_prec);
void sign_flags_du(char *str, int *ind, long int val, int plus, int space);
void s21_itoa(long int value, char *buffer, int *ind);
void flag_c(char value, char *str, int *ind, int width, int min, int space);
void flag_f(double value, char *str, int *ind, int width, int min, int plus,
            int space, int prec, int is_prec);
void flag_wide_s(wchar_t *value, char *str, int *ind, int width, int min,
                 int prec, int is_prec);
void flag_s(char *value, char *str, int *ind, int width, int min, int prec,
            int is_prec);

// part 5 (bonus)
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif  // SRC_S21_STRING_H_