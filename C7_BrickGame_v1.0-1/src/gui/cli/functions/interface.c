#include "../front.h"

bool pause_and_exit(UserAction_t action) {
  if (action == Pause) {
    return pause();
  }
  if (action == Terminate) {
    return exitt();
  }
  return true;
}

bool exitt() { return false; }

bool pause() {
  mvprintw(10, 5, "Game on pause!\n To continue press 'R'");
  refresh();
  while (1) {
    char key = getch();
    if (key == 'R') {
      return true;
    }
    if (key == '\033') {
      return false;
    }
  }
  return true;
}

void show_stats(GameInfo_t game_inf) {
  int end_field = WIDTH * 2 + 10;

  init_pair(1, COLOR_BLACK, COLOR_GREEN);
  init_pair(2, COLOR_GREEN, COLOR_BLUE);

  mvprintw(0, end_field, "Next figure: ");
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      attron(COLOR_PAIR(game_inf.next.figure[i][j]));
      mvprintw(1 + i, (j)*2 + end_field, "  ");  // Вывод ячейки матрицы
      attroff(COLOR_PAIR(game_inf.next.figure[i][j]));
    }
  }
  mvprintw(6, end_field, "High score: %d", game_inf.high_score);
  mvprintw(7, end_field, "Score: %d", game_inf.score);
  mvprintw(8, end_field, "Level: %d", game_inf.level);
}

void show_field(GameInfo_t game_inf, Figure figure) {
  init_pair(1, COLOR_BLACK, COLOR_GREEN);
  init_pair(2, COLOR_BLACK, COLOR_BLUE);

  // Вывод матрицы с соответствующими цветами
  for (int i = 0; i < HEIGHT + 1; i++) {
    for (int j = 0; j < WIDTH + 2; j++) {
      attron(COLOR_PAIR(game_inf.field[i][j]));
      mvprintw(i, j * 2, "  ");  // Вывод ячейки матрицы
      attroff(COLOR_PAIR(game_inf.field[i][j]));
    }
  }

  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (figure.figure[i][j] == 1) {
        attron(COLOR_PAIR(figure.figure[i][j]));
        mvprintw(figure.x + i, (figure.y + j) * 2,
                 "  ");  // Вывод ячейки матрицы
        attroff(COLOR_PAIR(figure.figure[i][j]));
      }
    }
  }
}

void txt_hello() {
  printw("\t\tHello friend! We want to offer you to play tetris!\n");
  printw("\t\t  Keyboard commands that will be useful to you:\n");
  printw("\t 'A' - to move left, 'D' - to move right, 'S' - to move down, \n");
  printw("\t\t'W' - to rotate, 'Q' - to pause, 'esc' - to exit, \n");
  printw("\t\t\t   To start, press any key...\n");

  while (1) {
    char key = getch();
    if (key == '\n' || key == '\r') {
      continue;
    }
    break;
  }
}

bool txt_end(GameInfo_t game_inf) {
  clear();
  printw("\t\t\tGame over!\n");
  printw("\t  Score: %d | High score: %d | Level: %d\n", game_inf.score,
         game_inf.high_score, game_inf.level);
  printw("\tPress 'R' to restart, 'esc' to exit the game\n");
  printw("\t\t Thank you for playing! GG! \n");
  refresh();
  while (1) {
    char key = getch();
    if (key == 'R') {
      clear();
      return true;
    }
    if (key == '\033') {
      return false;
    }
  }
  return false;
}