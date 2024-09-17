#ifndef TETRIS_FRONTEND_H_
#define TETRIS_FRONTEND_H_

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "../../brick_game/tetris/tetris.h"

void show_field(GameInfo_t game_inf, Figure figure);
void show_stats(GameInfo_t game_inf);
void txt_hello();
bool txt_end(GameInfo_t game_inf);
bool pause();
bool exitt();
bool pause_and_exit(UserAction_t action);

#endif  // TETRIS_frontend_H_