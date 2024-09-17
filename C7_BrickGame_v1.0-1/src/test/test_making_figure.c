#include "test_runner.h"

START_TEST(making1_ok) {
  Figure figure = Make_Figure();
  while (figure.type != 1)
  {
    figure = Make_Figure();
  }
  
  ck_assert_int_eq(figure.type, 1);
}
END_TEST

START_TEST(making2_ok) {
  Figure figure = Make_Figure();
  while (figure.type != 2)
  {
    figure = Make_Figure();
  }
  
      ck_assert_int_eq(figure.type, 2);
}
END_TEST

START_TEST(making3_ok) {
  Figure figure = Make_Figure();
  while (figure.type != 3)
  {
    figure = Make_Figure();
  }
  
  ck_assert_int_eq(figure.type, 3);
}
END_TEST

START_TEST(making4_ok) {
  Figure figure = Make_Figure();
  while (figure.type != 4)
  {
    figure = Make_Figure();
  }
  
  ck_assert_int_eq(figure.type, 4);
}
END_TEST

START_TEST(making5_ok) {
  Figure figure = Make_Figure();
  while (figure.type != 5)
  {
    figure = Make_Figure();
  }
  
  ck_assert_int_eq(figure.type, 5);
}
END_TEST

START_TEST(making6_ok) {
  Figure figure = Make_Figure();
  while (figure.type != 6)
  {
    figure = Make_Figure();
  }
  
  ck_assert_int_eq(figure.type, 6);
}
END_TEST

START_TEST(making7_ok) {
  Figure figure = Make_Figure();
  while (figure.type != 7)
  {
    figure = Make_Figure();
  }
  
  ck_assert_int_eq(figure.type, 7);
}
END_TEST



Suite *making_figure_cases(void) {
  Suite *suite = suite_create("making_figure_cases");
  TCase *tc = tcase_create("making_figure_tc");

  tcase_add_test(tc, making1_ok);
  tcase_add_test(tc, making2_ok);
  tcase_add_test(tc, making3_ok);
  tcase_add_test(tc, making4_ok);
  tcase_add_test(tc, making5_ok);
  tcase_add_test(tc, making6_ok);
  tcase_add_test(tc, making7_ok);
  


  suite_add_tcase(suite, tc);
  return suite;
}