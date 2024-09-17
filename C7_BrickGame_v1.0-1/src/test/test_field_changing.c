#include "test_runner.h"

START_TEST(check_and_clear_ok) {
  GameInfo_t game_inf = Init_GameInfo_t();
  for (int i = 1; i < 11; i++){
    game_inf.field[18][i] = 1;
    game_inf.field[19][i] = 1;
  }
  int test = Chech_And_Clear_lines(&game_inf);
  Clear_GameInfo_t(&game_inf);
  ck_assert_int_eq(test, 2);
}
END_TEST



Suite *field_changing_cases(void) {
  Suite *suite = suite_create("field_changing_cases");
  TCase *tc = tcase_create("field_changing_tc");

  tcase_add_test(tc, check_and_clear_ok);


  suite_add_tcase(suite, tc);
  return suite;
}