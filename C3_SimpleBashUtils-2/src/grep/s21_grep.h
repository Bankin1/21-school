#ifndef GREP_H
#define GREP_H

#include <ctype.h>
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Flags {
  int shablon;       // e
  int ignor_reg;     // i
  int invert;        // v
  int match_count;   // c
  int only_file;     // l
  int number_find;   // n
  int file_regul;    // f
  int no_miss;       // s
  int no_file_name;  // h
  int only_word;     // o
  int file_write;    // check for some files
  int error;
};

int GetLine(char **str, int *len, FILE *file);

void check_n_print(FILE *file, char *search, struct Flags flags,
                   char *file_name);

int match(regex_t *reegex, char *search, char *str, struct Flags flags);

struct Flags ReadFlag(int argc, char *argv[], char **search);

#endif