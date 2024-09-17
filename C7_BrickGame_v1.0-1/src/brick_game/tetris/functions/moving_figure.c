#include "../tetris.h"

int rotate_1(Figure* figure, GameInfo_t game_inf);
int rotate_34567(Figure* figure, GameInfo_t game_inf);

void toTmp(Figure* tmp, Figure figure) {
  tmp->x = figure.x;
  tmp->y = figure.y;
  tmp->type = figure.type;
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      tmp->figure[i][j] = figure.figure[i][j];
    }
  }
}

void copy(Figure* figure, Figure tmp) {
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      figure->figure[i][j] = tmp.figure[i][j];
    }
  }
}

int Move_Down(Figure* figure, GameInfo_t game_inf) {
  Figure tmp;
  toTmp(&tmp, *figure);
  tmp.x += 1;
  if (Check_Collision(tmp, game_inf) == NOT_COLLIDED) {
    figure->x = tmp.x;
    return SUCCESS;
  }
  return FAIL;
}

int Move_Left(Figure* figure, GameInfo_t game_inf) {
  Figure tmp;
  toTmp(&tmp, *figure);
  tmp.y -= 1;
  if (Check_Collision(tmp, game_inf) == NOT_COLLIDED) {
    figure->y = tmp.y;
    return SUCCESS;
  }
  return FAIL;
}

int Move_Right(Figure* figure, GameInfo_t game_inf) {
  Figure tmp;
  toTmp(&tmp, *figure);
  tmp.y += 1;
  if (Check_Collision(tmp, game_inf) == NOT_COLLIDED) {
    figure->y = tmp.y;
    return SUCCESS;
  }
  return FAIL;
}

int Rotate_Figure(Figure* figure, GameInfo_t game_inf) {
  int type = figure->type;
  if (type == 2) return SUCCESS;
  if (type == 1) return rotate_1(figure, game_inf);
  if (type >= 3 && type <= 7) return rotate_34567(figure, game_inf);
  return FAIL;
}

int rotate_1(Figure* figure, GameInfo_t game_inf) {
  Figure tmp;
  toTmp(&tmp, *figure);
  int row = 3;
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      tmp.figure[j][row] = figure->figure[i][j];
    }
    row--;
  }
  if (Check_Collision(tmp, game_inf) == NOT_COLLIDED) {
    copy(figure, tmp);
    return SUCCESS;
  }
  return FAIL;
}

int rotate_34567(Figure* figure, GameInfo_t game_inf) {
  Figure tmp;
  toTmp(&tmp, *figure);
  int row = 2;
  for (int i = 0; i < FIGURE_SIZE - 1; i++) {
    for (int j = 0; j < FIGURE_SIZE - 1; j++) {
      tmp.figure[j][row] = figure->figure[i][j];
    }
    row--;
  }
  if (Check_Collision(tmp, game_inf) == NOT_COLLIDED) {
    copy(figure, tmp);
    return SUCCESS;
  }
  return FAIL;
}
