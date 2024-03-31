#include "test_runner.h"

START_TEST(test_memset) {
  char src[] = {"vot eto mem konechno"};
  char src_1[] = {"vot eto mem konechno"};

  memset(src, '1', 5);
  s21_memset(src_1, '1', 5);

  ck_assert_str_eq(src, src_1);
  // проверка на работоспособность тестов
  //  ck_assert_str_eq(src, "error");
}
END_TEST

Suite* s21_memset_cases(void) {
  Suite* suite = suite_create("s21_memset_cases");
  TCase* tc = tcase_create("memset_tc");
  // тесты
  tcase_add_test(tc, test_memset);

  suite_add_tcase(suite, tc);
  return suite;
}