#include "../tetris.h"

void Speed_Up(int score, GameInfo_t* game_inf) {
  if (score >= LVL1) game_inf->level = 1;
  if (score >= LVL2) game_inf->level = 2;
  if (score >= LVL3) game_inf->level = 3;
  if (score >= LVL4) game_inf->level = 4;
  if (score >= LVL5) game_inf->level = 5;
  if (score >= LVL6) game_inf->level = 6;
  if (score >= LVL7) game_inf->level = 7;
  if (score >= LVL8) game_inf->level = 8;
  if (score >= LVL9) game_inf->level = 9;
  if (score >= LVL10) game_inf->level = 10;
}

void Score(int lines, GameInfo_t* game_inf) {
  int current_score = 0;
  if (lines != 0) {
    if (lines == 1)
      current_score = 100;
    else if (lines == 2)
      current_score = 300;
    else if (lines == 3)
      current_score = 700;
    else if (lines == 4)
      current_score = 1500;
    game_inf->score += current_score;
    if (game_inf->score >= game_inf->high_score) {
      FILE* file = fopen("data.txt", "r+");
      if (file != NULL) {
        rewind(file);
        fprintf(file, "%d\n", game_inf->score);
        fclose(file);
      }
      game_inf->high_score = game_inf->score;
    }
    Speed_Up(game_inf->score, game_inf);
  }
}

void Spawn_And_Check(Figure* figure, GameInfo_t* game_inf) {
  Connecting(*figure, game_inf);
  Score(Chech_And_Clear_lines(game_inf), game_inf);
  // Chech_And_Clear_lines(game_inf);
  Spawn_New_Figure(figure, game_inf);
}

void userInput(UserAction_t action, Figure* figure, GameInfo_t* game_inf) {
  switch (action) {
    case Left:
      Move_Left(figure, *game_inf);
      break;
    case Right:
      Move_Right(figure, *game_inf);
      break;
    case Action:
      Rotate_Figure(figure, *game_inf);
      break;
    case Down:
      if (Move_Down(figure, *game_inf) == FAIL) {
        Spawn_And_Check(figure, game_inf);
      }
      break;

    default:
      break;
  }
}

UserAction_t input(int ch) {
  UserAction_t input;
  switch (ch) {
    case 'A': {
      input = Left;
      break;
    }
    case 'D': {
      input = Right;
      break;
    }
    case 'S': {
      input = Down;
      break;
    }
    case 'W': {
      input = Action;
      break;
    }
    case 'Q': {
      input = Pause;
      break;
    }
    case '\033': {
      input = Terminate;
      break;
    }
    case 'R': {
      input = Start;
      break;
    }
    default: {
      input = Miss_clock;
      break;
    }
  }
  return input;
}