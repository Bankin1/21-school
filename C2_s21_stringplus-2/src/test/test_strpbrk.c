#include "test_runner.h"

START_TEST(test_strpbrk) {
  char str1[] = {"abcde312$#@"};
  char str2[] = {"*$#"};
  char str3[] = {" cadabra lol"};
  char str4[] = {" lol"};

  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
  ck_assert_str_eq(strpbrk(str3, str4), s21_strpbrk(str3, str4));
  ck_assert_ptr_eq(strpbrk(str1, str4), s21_strpbrk(str1, str4));
}
END_TEST

Suite* s21_strpbrk_cases(void) {
  Suite* suite = suite_create("s21_strpbrk_cases");
  TCase* tc = tcase_create("strpbrk_tc");
  // тесты
  tcase_add_test(tc, test_strpbrk);

  suite_add_tcase(suite, tc);
  return suite;
}