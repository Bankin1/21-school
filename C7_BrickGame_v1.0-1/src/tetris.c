#include "./brick_game/tetris/tetris.h"

#include "./gui/cli/front.h"

bool game(GameInfo_t game, Figure figure);

int main() {
  if (!(initscr())) {  // Инициализация экрана ncurses
    fprintf(stderr, "type: initscr() failed\n\n");
    return 1;
  }

  if ((LINES < HEIGHT + 1) || (COLS < WIDTH + 52)) {
    fprintf(stderr, "screen too small\n\n");
    endwin();
    return 1;
  }
  curs_set(0);    // Убрать отображение курсора
  start_color();  // Включение поддержки цветов
  noecho();       // чтобы не было видно ввода

  txt_hello();  // приветственный экран
  clear();      // отчистка экрана
  bool play = true;
  while (play) {
    GameInfo_t game_inf = Init_GameInfo_t();
    Figure figure = Make_Figure();
    play = game(game_inf, figure);
    Clear_GameInfo_t(&game_inf);
  }

  clear();
  refresh();  // Обновление экрана
  endwin();   // Освобождение ресурсов ncurses

  return 0;
}

bool game(GameInfo_t game, Figure figure) {
  clock_t start_time = clock();
  clock_t current_time;
  double time_passed;

  bool InGame = true, contin = false;
  while (InGame) {
    if (Check_Collision(figure, game) == COLLIDED) {
      InGame = false;
      contin = txt_end(game);
      break;
    }
    current_time = clock();
    time_passed = (double)(current_time - start_time) / CLOCKS_PER_SEC;
    if (time_passed >= (11 - game.level) * 0.1) {
      if (Move_Down(&figure, game) == FAIL) {
        Spawn_And_Check(&figure, &game);
      }
      start_time = clock();
    }
    nodelay(stdscr, TRUE);  // Включить неблокирующий режим ввода

    int ch = getch();
    if (ch != ERR) {  // Проверить, был ли нажат какой-либо ключ
      UserAction_t action = input(ch);
      userInput(action, &figure, &game);
      InGame = pause_and_exit(action);
      contin = InGame;
    }
    show_field(game, figure);
    show_stats(game);
    refresh();
  }

  return contin;
}
