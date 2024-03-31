CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
TARGET1 = s21_cat

all: s21_cat

s21_cat: 
	$(CC) $(CFLAGS) s21_cat.c -o $(TARGET1) 

style:
	clang-format -i *.c

clean:
	rm -rf $(TARGET1)

rebuild: clean all
