CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
V_COMMAND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt
L_COMMAND = leaks -atExit --


TARGET = tetris.out
PAHT_TO_ROOT_BUILD = ./build
PATH_TO_TESTS = test/
PATH_TO_FUNCTIONS = brick_game/tetris/functions/
PATH_TO_ROOT = brick_game/tetris/
COV_REPORT = report/
EXEC = s21_tetris.a
EXEC_T = unit_tests

SRC = $(wildcard $(PATH_TO_FUNCTIONS)*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
SRC_T = $(wildcard $(PATH_TO_TESTS)*.c)
OBJ_T = $(patsubst %.c, %.o, $(SRC_T))

PATH_TO_FRONT_ROOT = gui/cli/
PATH_TO_FRONT = gui/cli/functions/
SRC_F = $(wildcard $(PATH_TO_FRONT)*.c)
OBJ_F = $(patsubst %.c, %.o, $(SRC_F))

OS := $(shell uname -s)

all: install

install: s21_tetris.a front.a
	@mkdir build
	@touch data.txt
	@echo "0" >> data.txt
	@$(CC) $(CFLAGS) tetris.c -lncurses -L. -I. -l:s21_tetris.a -l:front.a -o $(PAHT_TO_ROOT_BUILD)/$(TARGET)

uninstall: clean
	@rm -rf data.txt
	@rm -rf $(PAHT_TO_ROOT_BUILD)

open:
	@$(PAHT_TO_ROOT_BUILD)/$(TARGET)
	
dist: install
	@mkdir -p dist
	@cp -R build dist && cp data.txt dist
	@cd dist && tar cvzf tetris.tgz *
	@cd dist && rm -rf build data.txt

s21_tetris.a: $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

front.a: $(OBJ_F)
	ar rc $@ $(OBJ_F)
	ranlib $@

test: $(OBJ_T) s21_tetris.a
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(OBJ_T) $(EXEC) -o $(PATH_TO_TESTS)$(EXEC_T) -lcheck -L. -I. -l:s21_tetris.a
	$(PATH_TO_TESTS)./$(EXEC_T)
else
	$(CC) $(CFLAGS) $(OBJ_T) $(EXEC) -o $(PATH_TO_TESTS)$(EXEC_T) -lcheck -lsubunit -lrt -lpthread -lm -L. -I. -l:s21_tetris.a
	$(PATH_TO_TESTS)./$(EXEC_T)
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

format-check:
	@cp ../materials/linters/.clang-format ./
	@clang-format -n $(PATH_TO_FUNCTIONS)*.c # $(PATH_TO_TESTS)*.c $(PATH_TO_TESTS)*.h
	@clang-format -n *.c $(PATH_TO_FRONT)*.c  $(PATH_TO_ROOT)*.h $(PATH_TO_FRONT_ROOT)*.h
	@rm .clang-format

format:
	@cp ../materials/linters/.clang-format ./
	@clang-format -i $(PATH_TO_FUNCTIONS)*.c # $(PATH_TO_TESTS)*.c $(PATH_TO_TESTS)*.h
	@clang-format -i *.c $(PATH_TO_FRONT)*.c  $(PATH_TO_ROOT)*.h $(PATH_TO_FRONT_ROOT)*.h
	@rm .clang-format

cppcheck:
	@cppcheck --enable=all --suppress=missingIncludeSystem $(PATH_TO_FUNCTIONS)*.c $(PATH_TO_TESTS)*.c $(PATH_TO_ROOT)*.h
	@cppcheck --enable=all --suppress=missingIncludeSystem $(PATH_TO_FRONT)*.c $(PATH_TO_FRONT_ROOT)*.h *.h

valgrind: test
	$(V_COMMAND) ./$(PATH_TO_TESTS)$(EXEC_T)

leaks: test
	$(L_COMMAND) ./$(PATH_TO_TESTS)$(EXEC_T)

coverage_flag:
	$(eval CFLAGS += --coverage)

sanitize: sanitize_flag test
	./$(PATH_TO_TESTS)$(EXEC_T)

sanitize_flag:
	$(eval CFLAGS += -fsanitize=address -fsanitize=leak)

gcov_report: coverage_flag test
	@#./$(PATH_TO_TESTS)$(EXEC_T)
	@rm -rf $(PATH_TO_TESTS)*.gcda $(PATH_TO_TESTS)*.gcno
	@rm -rf $(PATH_TO_TESTS)*.gcda $(PATH_TO_TESTS)*.gcno
	@rm -rf $(COV_REPORT)
	@mkdir $(COV_REPORT)
	@gcov -b -l -p -c $(PATH_TO_FUNCTIONS)*.gcno
	@gcovr -o $(COV_REPORT)gcov_report.html --html --html-details
	@rm -rf *.gcno && rm -rf *.gcda
	@rm -rf *.info && rm -rf *.gcov

dvi:
	@open dvi.txt

clean:
	@rm -rf $(PATH_TO_FUNCTIONS)*.o $(EXEC) front.a $(PATH_TO_TESTS)*.o $(PATH_TO_TESTS)./$(EXEC_T) $(PATH_TO_FRONT)*.o
	@rm -rf $(PATH_TO_FUNCTIONS)*.gcno && rm -rf $(PATH_TO_FUNCTIONS)*.gcda
	@rm -rf $(PATH_TO_FUNCTIONS)*.info && rm -rf $(PATH_TO_FUNCTIONS)*.gcov
	@rm -rf $(PATH_TO_TESTS)*.gcda $(PATH_TO_TESTS)*.gcno
	@rm -rf $(PATH_TO_TESTS)*.gcda $(PATH_TO_TESTS)*.gcno
	@rm -rf RESULT_VALGRIND.txt gcov_*
	@rm -rf $(COV_REPORT)
	@rm -rf $(DOCUMENTATION)
	@rm -rf build
	# @rm -rf dist
