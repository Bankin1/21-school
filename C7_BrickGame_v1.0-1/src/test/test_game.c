#include "test_runner.h"

START_TEST(speed_up_ok) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Speed_Up(LVL10, &game_inf);
  int test = game_inf.level;
  Clear_GameInfo_t(&game_inf);
  ck_assert_int_eq(test, 10);
}
END_TEST

START_TEST(score_ok) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Score(0, &game_inf);
  ck_assert_int_eq(game_inf.score, 0);
  Score(1, &game_inf);
  ck_assert_int_eq(game_inf.score, 100);
  Score(2, &game_inf);
  ck_assert_int_eq(game_inf.score, 400);
  Score(3, &game_inf);
  ck_assert_int_eq(game_inf.score, 1100);
  Score(4, &game_inf);
  ck_assert_int_eq(game_inf.score, 2600);
  Clear_GameInfo_t(&game_inf);
}
END_TEST

START_TEST(input_ok) {
  UserAction_t act = input('A');
  int test;
  UserAction_t testing = Left;
  if (act == testing) test = 1;
  ck_assert_int_eq(test, 1);

  act = input('D');
  testing = Right;
  if (act == testing) test = 1;
  ck_assert_int_eq(test, 1);

  act = input('S');
  testing = Down;
  if (act == testing) test = 1;
  ck_assert_int_eq(test, 1);
  
  act = input('W');
  testing = Action;
  if (act == testing) test = 1;
  ck_assert_int_eq(test, 1);
  
  act = input('Q');
  testing = Pause;
  if (act == testing) test = 1;
  ck_assert_int_eq(test, 1);
  
  act = input('\033');
  testing = Terminate;
  if (act == testing) test = 1;
  ck_assert_int_eq(test, 1);
  
  act = input('R');
  testing = Start;
  if (act == testing) test = 1;
  ck_assert_int_eq(test, 1);
  
  act = input('P');
  testing = Miss_clock;
  if (act == testing) test = 1;
  ck_assert_int_eq(test, 1);
}
END_TEST

START_TEST(user_input_ok) {
  GameInfo_t game_inf = Init_GameInfo_t();
  Figure figure = Make_Figure();
  int test = figure.y;
  UserAction_t act = Left;
  userInput(act, &figure, &game_inf);

  act = Right;
  userInput(act, &figure, &game_inf);
  ck_assert_int_eq(test, figure.y);

  test = figure.x;
  act = Action;
  userInput(act, &figure, &game_inf);
  act = Down;
  userInput(act, &figure, &game_inf);
  act = Miss_clock;
  userInput(act, &figure, &game_inf);
  ck_assert_int_eq(test+1, figure.x);

  act = Down;
  while (figure.type != 1) figure = Make_Figure();
  figure.y = 8;
  userInput(act, &figure, &game_inf);
  ck_assert_int_eq(0, figure.x);

  Clear_GameInfo_t(&game_inf);
}
END_TEST


Suite *game_cases(void) {
  Suite *suite = suite_create("game_cases");
  TCase *tc = tcase_create("game_tc");

  tcase_add_test(tc, speed_up_ok);
  tcase_add_test(tc, score_ok);
  tcase_add_test(tc, input_ok);
  tcase_add_test(tc, user_input_ok);


  suite_add_tcase(suite, tc);
  return suite;
}