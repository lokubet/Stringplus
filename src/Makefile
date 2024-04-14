CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
COMP = $(CC) $(CFLAGS)
LDFLAGS = -L. -ls21_string -lcheck -lm
BUILD_DIR = ../build
FUNCTIONS := $(wildcard functions/*.c)
TESTS := $(wildcard tests/*.c)

LINUX_FLAGS =
OS := $(shell uname -s)
ifeq ($(OS), Linux)
	LINUX_FLAGS += -lsubunit
endif

all: s21_string.a test

dirs:
	mkdir -p ../build
	mkdir -p ../build/functions
	mkdir -p ../build/tests

functions: dirs $(FUNCTIONS)
	$(COMP) -c $(FUNCTIONS) 
	mv *.o $(BUILD_DIR)/functions/

cov_functions: dirs $(FUNCTIONS)
	$(COMP) -g -O0 -fprofile-arcs -ftest-coverage -c $(FUNCTIONS)
	mv *.o $(BUILD_DIR)/functions/

cov_lib: cov_functions
	ar rcs s21_string.a $(BUILD_DIR)/functions/*.o
	ar rcs libs21_string.a $(BUILD_DIR)/functions/*.o

tests: dirs $(TESTS)
	$(COMP) -c $(TESTS) s21_string_test.c
	mv *.o $(BUILD_DIR)/tests

s21_string.a: functions
	ar rcs s21_string.a $(BUILD_DIR)/functions/*.o
	ar rcs libs21_string.a $(BUILD_DIR)/functions/*.o

test: s21_string.a tests
	$(COMP) $(BUILD_DIR)/tests/*.o -o $(BUILD_DIR)/test.out $(LDFLAGS) $(LINUX_FLAGS)
	$(BUILD_DIR)/test.out

gcov_report: tests cov_lib
	$(COMP) $(BUILD_DIR)/tests/*.o -o $(BUILD_DIR)/test.out $(LDFLAGS) $(LINUX_FLAGS) -lgcov --coverage
	$(BUILD_DIR)/test.out
	lcov -o report.info -c -d .
	genhtml --function-coverage --branch-coverage -o report report.info
	open report/index.html

remove_obj:
	rm *.o

clean:
	rm -f *.out
	rm -f *.o
	rm -f *.a
	rm -rf $(BUILD_DIR)
	rm -f *.gc*
	rm -f report.info
	rm -f test.log
	rm -rf report

format:
	clang-format -i $(FUNCTIONS)
	clang-format -i $(TESTS)
	clang-format -i *.c *.h

rebuild: clean all

.PHONY: clean format all dirs remove_obj
