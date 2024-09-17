#include "../tetris.h"

void Connecting(Figure figure, GameInfo_t* game_inf) {
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (figure.figure[i][j] == BLOCK &&
          game_inf->field[figure.x + i][figure.y + j] != 2) {
        game_inf->field[figure.x + i][figure.y + j] = BLOCK;
      }
    }
  }
}

int Chech_And_Clear_lines(GameInfo_t* game_inf) {
  int fullLine, linesRemoved = 0;

  for (int y = HEIGHT - 1; y >= 0; y--) {
    fullLine = 1;
    for (int x = 1; x < WIDTH + 1; x++) {
      if (game_inf->field[y][x] == 0) {
        fullLine = 0;
        break;
      }
    }

    if (fullLine) {
      // Сдвигаем все строки выше удаленной вниз
      for (int i = y; i > 0; i--) {
        for (int x = 1; x < WIDTH + 1; x++) {
          if (i != HEIGHT) game_inf->field[i][x] = game_inf->field[i - 1][x];
        }
      }
      // Обнуляем верхнюю строку
      for (int x = 1; x < WIDTH + 1; x++) {
        game_inf->field[0][x] = 0;
      }
      linesRemoved++;
      y++;  // Повторная проверка текущей строки
    }
  }
  return linesRemoved;
}

void Spawn_New_Figure(Figure* figure, GameInfo_t* game_inf) {
  *figure = game_inf->next;
  game_inf->next = Make_Figure();
}