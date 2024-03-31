CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -std=c11 #-posix
TARGET1 = s21_grep

all: s21_grep

s21_grep: 
	$(CC) $(CFLAGS) s21_grep.c s21_grep_funk.c -o $(TARGET1) 

clean:
	rm -rf $(TARGET1)

rebuild: clean all