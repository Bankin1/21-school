#include "../tetris.h"

Figure make_first_type();
Figure make_second_type();
Figure make_therd_type();
Figure make_fourth_type();
Figure make_fiveth_type();
Figure make_sixth_type();
Figure make_seventh_type();

Figure Make_Figure() {
  int randomNumber = rand() % 7;  // генерация случайного числа от 0 до 6
  Figure figure;
  switch (randomNumber) {
    case 0:
      figure = make_first_type();
      break;
    case 1:
      figure = make_second_type();
      break;
    case 2:
      figure = make_therd_type();
      break;
    case 3:
      figure = make_fourth_type();
      break;
    case 4:
      figure = make_fiveth_type();
      break;
    case 5:
      figure = make_sixth_type();
      break;
    case 6:
      figure = make_seventh_type();
      break;
  }
  return figure;
}

Figure make_first_type() {
  Figure figure = {
      {{1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 0, 4, 1};
  return figure;
}

Figure make_second_type() {
  Figure figure = {
      {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 0, 5, 2};
  return figure;
}

Figure make_therd_type() {
  Figure figure = {
      {{1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 0, 4, 3};
  return figure;
}

Figure make_fourth_type() {
  Figure figure = {
      {{0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 0, 4, 4};
  return figure;
}

Figure make_fiveth_type() {
  Figure figure = {
      {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 0, 5, 5};
  return figure;
}

Figure make_sixth_type() {
  Figure figure = {
      {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 0, 4, 6};
  return figure;
}

Figure make_seventh_type() {
  Figure figure = {
      {{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 0, 5, 7};
  return figure;
}