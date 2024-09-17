#ifndef TEST_RUNNER_H_
#define TEST_RUNNER_H_

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../brick_game/tetris/tetris.h"

#define SEP "|================================|"

Suite *movement_cases(void);
Suite *making_figure_cases(void);
Suite *game_cases(void);
Suite *field_changing_cases(void);


#endif  // TEST_RUNNER_H_
