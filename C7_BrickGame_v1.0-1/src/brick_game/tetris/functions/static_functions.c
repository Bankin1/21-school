#include "../tetris.h"

void Init_Matrix(int **matrix) {
  for (int i = 0; i < HEIGHT + 1; i++) {
    for (int j = 0; j < WIDTH + 2; j++) {
      if (j == 0 || j == WIDTH + 1 || i == HEIGHT)
        matrix[i][j] = 2;
      else
        matrix[i][j] = CLEAR_BLOCK;
    }
  }
}

GameInfo_t Init_GameInfo_t() {
  FILE *file = fopen("data.txt", "r+");
  GameInfo_t game_inf;
  if (file == NULL) {
    game_inf.high_score = 0;
  } else {
    if (fgetc(file) == EOF) {
      fprintf(file, "%d\n", 0);
    }
    rewind(file);
    fscanf(file, "%d", &game_inf.high_score);
    fclose(file);
  }
  srand(time(0));

  game_inf.score = 0;
  game_inf.level = 1;
  game_inf.speed = 1;

  game_inf.field = (int **)malloc((HEIGHT + 1) * sizeof(int *));
  for (int i = 0; i < HEIGHT + 1; i++) {
    game_inf.field[i] = (int *)malloc((WIDTH + 2) * sizeof(int));
  }
  Init_Matrix(game_inf.field);

  game_inf.next = Make_Figure();
  return game_inf;
}

void Clear_GameInfo_t(GameInfo_t *game_inf) {
  for (int i = 0; i < HEIGHT + 1; i++) {
    free(game_inf->field[i]);
  }
  free(game_inf->field);
  game_inf->score = 0;
  game_inf->level = 1;
  game_inf->speed = 0;
}

int Check_Collision(Figure figure, GameInfo_t game_inf) {
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (figure.figure[i][j] == BLOCK &&
          (figure.x + i >= HEIGHT || figure.y + j >= WIDTH + 2 ||
           game_inf.field[figure.x + i][figure.y + j] == 2 ||
           game_inf.field[figure.x + i][figure.y + j] == 1)) {
        return COLLIDED;
      }
    }
  }
  return NOT_COLLIDED;
}