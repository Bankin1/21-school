#ifndef TETRIS_H_
#define TETRIS_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 20
#define FIGURE_SIZE 4

#define COLLIDED -1
#define NOT_COLLIDED 1

#define BLOCK 1
#define CLEAR_BLOCK 0

#define SUCCESS 1
#define FAIL -1

#define LVL1 0
#define LVL2 600
#define LVL3 1200
#define LVL4 1800
#define LVL5 2400
#define LVL6 3000
#define LVL7 3600
#define LVL8 4200
#define LVL9 4800
#define LVL10 5400

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Down,
  Action,
  Miss_clock
} UserAction_t;

typedef struct {
  int figure[4][4];
  int x;
  int y;
  int type;
} Figure;

typedef struct {
  int** field;     // JUST FIELD
  Figure next;     // NEXT ITEM
  int score;       // CURRENT SCORE
  int high_score;  // U KNOW THAT IT IS HIGH SCORE
  int level;       // CURRENT LVL FROM 1 TO 10
  int speed;       // CURRENT SPEED
} GameInfo_t;

// static_funсtions
GameInfo_t Init_GameInfo_t();
void Init_Matrix(int** matrix);
void Clear_GameInfo_t(GameInfo_t* game_inf);
int Check_Collision(Figure figure, GameInfo_t game_inf);

// game
void Speed_Up(int score, GameInfo_t* game_inf);
void Spawn_And_Check(Figure* figure, GameInfo_t* game_inf);
void userInput(UserAction_t action, Figure* figure, GameInfo_t* game_inf);
UserAction_t input(int ch);
void Score(int lines, GameInfo_t* game_inf);
// GameInfo_t updateCurrentState();

// field_changing
void Connecting(Figure figure, GameInfo_t* game_inf);
void Spawn_New_Figure(Figure* figure, GameInfo_t* game_inf);
int Chech_And_Clear_lines(GameInfo_t* game_inf);

// moving_figure
int Rotate_Figure(Figure* figure, GameInfo_t game_inf);
int Move_Left(Figure* figure, GameInfo_t game_inf);
int Move_Right(Figure* figure, GameInfo_t game_inf);
int Move_Down(Figure* figure, GameInfo_t game_inf);

// making_figure
Figure Make_Figure();

#endif  // TETRIS_H_