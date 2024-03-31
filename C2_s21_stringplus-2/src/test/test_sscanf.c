#include "test_runner.h"
#define MAX 20

typedef struct {
  int n_spec;

  int i_num;
  unsigned int ui_num;
  short int hi_num;
  short unsigned int hui_num;
  long int li_num;
  long long int lli_num;
  long unsigned int lui_num;

  int ui_num_1;  // oct num
  int ui_num_2;
  int ui_num_3;

  long int li_num_1;  // hex num
  long int li_num_2;
  long int li_num_3;

  float f_num;
  float uf_num;
  double d_num;
  double ud_num;
  long double ld_num;

  char symbol;
  unsigned char usymbol;
  char string[MAX];
} output;

/* without modifiers */

START_TEST(test_specifiers_wo_mods) {
  output my = {0};
  output ori = {0};

  char source_1[] =
      "-2147483648   4294967295 -20000 65535 -2147483648 9.223372037E+018 "
      "4294967295  ";
  char format_1[] = " %d%u %hd%hu %ld%Ld %lu  ";

  char source_2[] = "";  // проверка на ошибки формата
  char format_2[] = "%d %c %c";

  char source_3[] = "023 023 053 0xAB3 0X1F 1F";
  char format_3[] = "%o%o%o  %x%x%x";

  // запись в переменные
  sscanf(source_1, format_1, &ori.i_num, &ori.ui_num, &ori.hi_num, &ori.hui_num,
         &ori.li_num, &ori.li_num, &ori.lui_num);
  s21_sscanf(source_1, format_1, &my.i_num, &my.ui_num, &my.hi_num, &my.hui_num,
             &my.li_num, &my.li_num, &my.lui_num);

  int error = 0, error_1 = 0;
  ck_assert_int_eq(sscanf(source_2, format_2, &error),
                   s21_sscanf(source_2, format_2, &error_1));

  ck_assert_int_eq(
      sscanf(source_3, format_3, &ori.ui_num_1, &ori.ui_num_2, &ori.ui_num_3,
             &ori.li_num_1, &ori.li_num_2, &ori.li_num_3),
      s21_sscanf(source_3, format_3, &my.ui_num_1, &my.ui_num_2, &my.ui_num_3,
                 &my.li_num_1, &my.li_num_2, &my.li_num_3));

  ck_assert_uint_eq(ori.ui_num_1, my.ui_num_1);
  ck_assert_uint_eq(ori.ui_num_2, my.ui_num_2);
  ck_assert_uint_eq(ori.ui_num_3, my.ui_num_3);

  ck_assert(ori.li_num_1 == my.li_num_1);
  ck_assert(ori.li_num_2 == my.li_num_2);
  ck_assert(ori.li_num_3 == my.li_num_3);

  ck_assert_int_eq(ori.i_num, my.i_num);
  ck_assert_uint_eq(ori.ui_num, my.ui_num);

  ck_assert_int_eq(ori.hi_num, my.hi_num);
  ck_assert_uint_eq(ori.hui_num, my.hui_num);

  ck_assert(ori.li_num == my.li_num);
  ck_assert(ori.lui_num == my.lui_num);
  ck_assert(ori.lli_num == my.lli_num);

  ck_assert_float_eq(ori.f_num, my.f_num);
  ck_assert(ori.uf_num == my.uf_num);

  ck_assert_double_eq(ori.d_num, my.d_num);
  ck_assert(ori.ud_num == my.ud_num);

  ck_assert_ldouble_eq(ori.ld_num, my.ld_num);

  ck_assert(ori.symbol == my.symbol);

  // if (!ori.string) {
  //   ck_assert_ptr_eq(ori.string, my.string);
  // } else
  //   ck_assert_str_eq(ori.string, my.string);
}
END_TEST

START_TEST(test_specifiers_wo_mods_1) {
  output my = {0};
  output ori = {0};

  char source_1[] = "a herestring ";
  char format_1[] = "%c%s";  // " %c" - интересно

  ck_assert_int_eq(sscanf(source_1, format_1, &ori.symbol, ori.string),
                   s21_sscanf(source_1, format_1, &my.symbol, my.string));

  ck_assert(ori.symbol == my.symbol);
  ck_assert_str_eq(ori.string, my.string);

  char source_2[] = "9.234 12345.6789 123456789.123456789";
  char format_2[] = "%f %lf %Lf";

  ck_assert_int_eq(
      sscanf(source_2, format_2, &ori.f_num, &ori.d_num, &ori.ld_num),
      s21_sscanf(source_2, format_2, &my.f_num, &my.d_num, &my.ld_num));

  ck_assert_float_eq(ori.f_num, my.f_num);
  ck_assert_double_eq(ori.d_num, my.d_num);
  // printf("%.15Lf\n%.15Lf\n", ori.ld_num, my.ld_num);
  ck_assert_ldouble_eq_tol(ori.ld_num, my.ld_num, 1e-11);
}
END_TEST

START_TEST(test_specifiers_wo_mods_2) {
  output my = {0};
  output ori = {0};

  char source_1[] = "0.123e-1 0.12345e10 0.45678e-2 %%";
  char format_1[] = "%f%lf%Lf%%";

  ck_assert_int_eq(
      sscanf(source_1, format_1, &ori.f_num, &ori.d_num, &ori.ld_num),
      s21_sscanf(source_1, format_1, &my.f_num, &my.d_num, &my.ld_num));

  ck_assert_float_eq(ori.f_num, my.f_num);
  ck_assert_double_eq(ori.d_num, my.d_num);
  ck_assert_ldouble_eq_tol(ori.ld_num, my.ld_num, 1e-11);
}
END_TEST

START_TEST(test_specifiers_wo_mods_3) {
  output my = {0};
  output ori = {0};

  char source_1[] = "0x123 0x12346 011 0x2";
  char format_1[] = "%i%li%hi%lli";

  ck_assert_int_eq(sscanf(source_1, format_1, &ori.i_num, &ori.li_num,
                          &ori.hi_num, &ori.lli_num),
                   s21_sscanf(source_1, format_1, &my.i_num, &my.li_num,
                              &my.hi_num, &my.lli_num));

  ck_assert_int_eq(ori.i_num, my.i_num);
  ck_assert_int_eq(ori.li_num, my.li_num);
  ck_assert_int_eq(ori.hi_num, my.hi_num);
  ck_assert_int_eq(ori.lli_num, my.lli_num);
}
END_TEST

Suite *s21_sscanf_cases(void) {
  Suite *s_sscanf;
  TCase *tc_core;

  s_sscanf = suite_create("\n \033[1;30;46m\tTesting sscanf\t\033[0m");
  tc_core = tcase_create("Sscanf");
  tcase_add_test(tc_core, test_specifiers_wo_mods);
  tcase_add_test(tc_core, test_specifiers_wo_mods_1);
  tcase_add_test(tc_core, test_specifiers_wo_mods_2);
  tcase_add_test(tc_core, test_specifiers_wo_mods_3);

  suite_add_tcase(s_sscanf, tc_core);

  return s_sscanf;
}
