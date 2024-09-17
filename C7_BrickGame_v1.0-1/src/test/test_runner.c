#include "test_runner.h"

int main(void) {
  Suite *array_tests[] = {movement_cases(), making_figure_cases(), game_cases(), field_changing_cases()};
  int size = 4;

  for (int i = 0; i < size; i++) {
    printf("%s\n", SEP);
    printf("TEST NUMBER: %d \n", i + 1);

    SRunner *runner = srunner_create(array_tests[i]);

    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }

  return 0;
}
