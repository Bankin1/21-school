#include "s21_grep.h"

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  char *search = NULL;
  struct Flags flags = ReadFlag(argc, argv, &search);
  if (!flags.shablon && !flags.file_regul) {
    if (optind + 1 < argc) {
      search = argv[optind++];
    }
  }
  if (flags.error == 0 && search != NULL) {
    flags.file_write = (argc - optind > 1) ? 1 : 0;
    for (int i = optind; i < argc; ++i) {
      FILE *file = fopen(argv[i], "r");
      if (file) {
        check_n_print(file, search, flags, argv[i]);
        fclose(file);
      } else {
        if (!flags.no_miss)
          fprintf(stderr, "s21_grep: %s: No such file or directory\n", argv[i]);
      }
    }
  }
  if (flags.file_regul || flags.shablon) free(search);
  return 0;
}
