#include <ctype.h>
#include <getopt.h>
#include <stdio.h>

struct Flags {
  int numberNonEmpty;
  int markEnd;
  int numberAll;
  int squeeze;
  int tab;
  int error;
  int printNonPrint;
};

void check_n_print(FILE *file, struct Flags flags);

void print_symbol(char current_char, struct Flags flags);
void print_M(char current_char, struct Flags flags);
void print_ctrl(char current_char, struct Flags flags);
void print_tab(char current_char, struct Flags flags);
void print_pinteble(char current_char);

void number(char previous_char, char current_char, struct Flags flags);
void count_clear(int *counter_clear, char current_char);

struct Flags ReadFlag(int agrc, char *argv[]);

int main(int agrc, char *argv[]) {
  struct Flags flags = ReadFlag(agrc, argv);
  if (flags.error == 0) {
    for (char **filename = &argv[1], **end = &argv[agrc]; filename != end;
         ++filename) {
      if (**filename != '-') {
        FILE *file = fopen(*filename, "r");
        if (file)
          check_n_print(file, flags);
        else
          fprintf(stderr, "s21_cat: %s: No such file or directory\n",
                  *filename);
      }
    }
  }
}

void check_n_print(FILE *file, struct Flags flags) {
  char current_char = fgetc(file);
  static char previous_char = '\n';
  static int counter_clear = 1;
  while (!feof(file)) {
    if (flags.squeeze) count_clear(&counter_clear, current_char);
    if (current_char != '\n' || counter_clear <= 2) {
      number(previous_char, current_char, flags);
      if (flags.markEnd && current_char == '\n') {  // ending str
        print_pinteble('$');
      }
      print_symbol(current_char, flags);
    }
    previous_char = current_char;
    current_char = fgetc(file);
  }
}

void print_symbol(char current_char, struct Flags flags) {
  if (isprint(current_char)) {  // proverka na obichniy simvol
    print_pinteble(current_char);
  } else if (current_char == '\t') {
    print_tab(current_char, flags);
  } else if (current_char == '\n') {
    print_pinteble(current_char);
  } else if (iscntrl(current_char)) {  // proverka na komandniy simvol
    print_ctrl(current_char, flags);
  } else {
    print_M(current_char, flags);  // ne pechataushiysya simvol "M-.."
  }
}

void print_M(char current_char, struct Flags flags) {
  if (flags.printNonPrint) {
    char meta_char = current_char + 128;
    print_pinteble('M');
    print_pinteble('-');
    if (isprint(meta_char)) {
      print_pinteble(meta_char);
    } else {
      print_ctrl(meta_char, flags);
    }
  } else {
    print_pinteble(current_char);
  }
}

void print_ctrl(char current_char, struct Flags flags) {
  if (flags.printNonPrint) {
    print_pinteble('^');
    if (current_char == 127) {
      print_pinteble('?');
    } else {
      print_pinteble(current_char + 64);
    }
  } else {
    print_pinteble(current_char);
  }
}

void print_tab(char current_char, struct Flags flags) {
  if (flags.tab) {
    print_pinteble('^');
    print_pinteble('I');
  } else {
    print_pinteble(current_char);
  }
}

void print_pinteble(char current_char) { fputc(current_char, stdout); }

void number(char previous_char, char current_char, struct Flags flags) {
  static int line_count = 0;
  if (flags.numberNonEmpty && previous_char == '\n' && current_char != '\n') {
    fprintf(stdout, "%6d\t", ++line_count);
  } else if (flags.numberAll && previous_char == '\n' &&
             !flags.numberNonEmpty) {
    fprintf(stdout, "%6d\t", ++line_count);
  }
}

void count_clear(int *counter_clear, char current_char) {
  if (current_char == '\n') {
    *counter_clear += 1;
  } else {
    *counter_clear = 0;
  }
}

struct Flags ReadFlag(int agrc, char *argv[]) {
  struct option longOption[] = {
      {"number-nonblank", 0, NULL, 'b'},
      {"number", 0, NULL, 'n'},
      {"squeeze-blank", 0, NULL, 's'},
      {NULL, 0, NULL, 0},
  };

  int currentFlag = getopt_long(agrc, argv, "bevEnstT", longOption, NULL);
  struct Flags flags = {0, 0, 0, 0, 0, 0, 0};
  for (; currentFlag != -1;
       currentFlag = getopt_long(agrc, argv, "bevEnstT", longOption, NULL)) {
    switch (currentFlag) {
      case 'b':
        flags.numberNonEmpty = 1;
        break;
      case 'e':
        flags.markEnd = 1;
        flags.printNonPrint = 1;
        break;
      case 'v':
        flags.printNonPrint = 1;
        break;
      case 'E':
        flags.markEnd = 1;
        break;
      case 'n':
        flags.numberAll = 1;
        break;
      case 's':
        flags.squeeze = 1;
        break;
      case 't':
        flags.printNonPrint = 1;
        flags.tab = 1;
        break;
      case 'T':
        flags.tab = 1;
        break;
      default:
        flags.error = 1;
        break;
    }
  }
  return flags;
}
