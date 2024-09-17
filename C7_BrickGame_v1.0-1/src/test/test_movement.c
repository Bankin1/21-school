#include "test_runner.h"

START_TEST(move_left_ok) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Figure figure = Make_Figure();
  int test = Move_Left(&figure, game_inf);
  Clear_GameInfo_t(&game_inf);
  ck_assert_int_eq(test, SUCCESS);
}
END_TEST

START_TEST(move_left_fail) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Figure figure = Make_Figure();
  figure.y = 14;
  int test = Move_Left(&figure, game_inf);
  Clear_GameInfo_t(&game_inf);
  ck_assert_int_eq(test, FAIL);
}
END_TEST

START_TEST(move_right_ok) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Figure figure = Make_Figure();
  int test = Move_Right(&figure, game_inf);
  Clear_GameInfo_t(&game_inf);
  ck_assert_int_eq(test, SUCCESS);
}
END_TEST

START_TEST(move_right_fail) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Figure figure = Make_Figure();
  figure.y = 14;
  int test = Move_Right(&figure, game_inf);
  Clear_GameInfo_t(&game_inf);
  ck_assert_int_eq(test, FAIL);
}
END_TEST

START_TEST(move_down_ok) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Figure figure = Make_Figure();
  int test = Move_Down(&figure, game_inf);
  Clear_GameInfo_t(&game_inf);
  ck_assert_int_eq(test, SUCCESS);
}
END_TEST

START_TEST(move_down_fail) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Figure figure = Make_Figure();
  figure.y = 14;
  int test = Move_Down(&figure, game_inf);
  Clear_GameInfo_t(&game_inf);
  ck_assert_int_eq(test, FAIL);
}
END_TEST

START_TEST(rotate2_ok) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Figure figure = Make_Figure();
  figure.type = 2;
  int test = Rotate_Figure(&figure, game_inf);
  Clear_GameInfo_t(&game_inf);
  ck_assert_int_eq(test, SUCCESS);
}
END_TEST

START_TEST(rotate1_ok) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Figure figure = Make_Figure();
  figure.type = 1;
  int test = Rotate_Figure(&figure, game_inf);
  Clear_GameInfo_t(&game_inf);
  ck_assert_int_eq(test, SUCCESS);
}
END_TEST

START_TEST(rotate34567_ok) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Figure figure = Make_Figure();
  while (figure.type == 1) figure = Make_Figure();
  int test = Rotate_Figure(&figure, game_inf);
  Clear_GameInfo_t(&game_inf);
  ck_assert_int_eq(test, SUCCESS);
}
END_TEST

START_TEST(rotate_fail) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Figure figure = Make_Figure();
  while (figure.type == 1) figure = Make_Figure();
  figure.y = 14;
  int test = Rotate_Figure(&figure, game_inf);
  Clear_GameInfo_t(&game_inf);
  ck_assert_int_eq(test, FAIL);
}
END_TEST

START_TEST(rotate8_fail) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Figure figure = Make_Figure();
  figure.type = 8;
  int test = Rotate_Figure(&figure, game_inf);
  Clear_GameInfo_t(&game_inf);
  ck_assert_int_eq(test, FAIL);
}
END_TEST

START_TEST(rotate1_fail) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Figure figure = Make_Figure();
  while (figure.type != 1) figure = Make_Figure();
  figure.y = 14;
  int test = Rotate_Figure(&figure, game_inf);
  Clear_GameInfo_t(&game_inf);
  ck_assert_int_eq(test, FAIL);
}
END_TEST


Suite *movement_cases(void) {
  Suite *suite = suite_create("movement_cases");
  TCase *tc = tcase_create("movement_tc");

  tcase_add_test(tc, move_left_ok);
  tcase_add_test(tc, move_left_fail);
  tcase_add_test(tc, move_right_ok);
  tcase_add_test(tc, move_right_fail);
  tcase_add_test(tc, move_down_ok);
  tcase_add_test(tc, move_down_fail);
  tcase_add_test(tc, rotate1_ok);
  tcase_add_test(tc, rotate2_ok);
  tcase_add_test(tc, rotate34567_ok);
  tcase_add_test(tc, rotate_fail);
  tcase_add_test(tc, rotate1_fail);
  tcase_add_test(tc, rotate8_fail);


  suite_add_tcase(suite, tc);
  return suite;
}