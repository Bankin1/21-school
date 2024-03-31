#include "s21_grep.h"

int GetLine(char **str, int *len, FILE *file) {  // getline hand made
  *len = 0;
  int cap = 1;
  int c = fgetc(file);
  *str = (char *)realloc(*str, 1);
  while (c != EOF && c != '\n') {
    (*str)[(*len)++] = (char)c;
    if (*len >= cap) {
      cap *= 2;
      *str = (char *)realloc(*str, cap);
    }
    c = fgetc(file);
  }
  (*str)[(*len)++] = '\0';
  return c;
}

void check_n_print(FILE *file, char *search, struct Flags flags,
                   char *file_name) {
  char *str = (char *)malloc(1);
  int len = 0;
  int nread = !EOF;
  regex_t reegex;
  int counter_match = 0, counter_str = 1, next_file = 0, is_match = 0;
  while (nread != EOF && !next_file) {
    nread = GetLine(&str, &len, file);
    is_match = !match(&reegex, search, str, flags);
    if (is_match && !(nread == EOF && !strcmp(str, ""))) {
      next_file = flags.only_file ? 1 : 0;
      if (!next_file) {
        if (!flags.match_count) {
          if (!flags.only_word) {
            if (flags.file_write && !flags.no_file_name)
              printf("%s:", file_name);
            if (flags.number_find) printf("%d:", counter_str);
            printf("%s\n", str);
          } else {
            if (flags.file_write && !flags.no_file_name)
              printf("%s:", file_name);
            if (flags.number_find) printf("%d:", counter_str);
            printf("%s\n", search);
          }
        } else {
          counter_match++;
        }
      }
    }
    regfree(&reegex);
    counter_str++;
  }
  free(str);
  if (flags.only_file) {
    if (next_file) printf("%s\n", file_name);
  } else {
    if (flags.match_count) {
      if (flags.file_write && !flags.no_file_name) printf("%s:", file_name);
      printf("%d\n", counter_match);
    }
  }
  // regfree(&reegex);
}

int match(regex_t *reegex, char *search, char *str, struct Flags flags) {
  int value;
  if (flags.ignor_reg)
    value = regcomp(reegex, search, REG_EXTENDED | REG_ICASE);
  else
    value = regcomp(reegex, search, REG_EXTENDED);
  if (value != 0) {
    regfree(reegex);
    value = 1;
  } else {
    value = regexec(reegex, str, 0, NULL, 0);
    if (flags.invert) value = !value;
  }
  return value;
}

struct Flags ReadFlag(int argc, char *argv[], char **search) {
  int currentFlag = getopt(argc, argv, "ohe:ivclnf:s");
  struct Flags flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (; currentFlag != -1; currentFlag = getopt(argc, argv, "ohe:ivclnf:s")) {
    switch (currentFlag) {
      case 'o':
        flags.only_word = 1;
        break;
      case 'h':
        flags.no_file_name = 1;
        break;
      case 's':
        flags.no_miss = 1;
        break;
      case 'e':
        if (*search == NULL) {
          *search = (char *)malloc(strlen(optarg) + 1);
          strcpy(*search, optarg);
        } else {
          *search =
              (char *)realloc(*search, strlen(optarg) + strlen(*search) + 4);
          strcat(strcat(*search, "|"), optarg);
        }
        flags.shablon = 1;
        break;
      case 'f':
        flags.file_regul = 1;
        FILE *file = fopen(optarg, "r");
        if (file) {
          char *line = (char *)malloc(1);
          int len = 0;
          int nread = !EOF;
          while (nread != EOF) {
            nread = GetLine(&line, &len, file);
            // if (line[strlen(line) - 1] == '\n') {
            //   line[strlen(line) - 1] = '\0';
            // }
            if (*search == NULL) {
              *search = (char *)malloc(strlen(line) + 1);
              strcpy(*search, line);
            } else {
              *search =
                  (char *)realloc(*search, strlen(line) + strlen(*search) + 4);
              strcat(strcat(*search, "|"), line);
            }
          }
          free(line);
          fclose(file);
        } else {
          if (!flags.no_miss)
            fprintf(stderr, "s21_grep: %s: No such file or directory\n",
                    optarg);
          flags.error = 1;
        }
        break;
      case 'i':
        flags.ignor_reg = 1;
        break;
      case 'v':
        flags.invert = 1;
        break;
      case 'c':
        flags.match_count = 1;
        break;
      case 'l':
        flags.only_file = 1;
        break;
      case 'n':
        flags.number_find = 1;
        break;
      default:
        flags.error = 1;
        break;
    }
  }
  return flags;
}