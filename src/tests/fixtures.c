#include "../s21_string_test.h"

char *test_string;
char *test_string2;

void teardown(void) {
  free(test_string);
  free(test_string2);
}

void setup_16(void) {
  test_string = malloc(17);
  test_string2 = malloc(17);
}

void setup_128(void) {
  test_string = malloc(129);
  test_string2 = malloc(129);
}

void setup_256(void) {
  test_string = malloc(257);
  test_string2 = malloc(257);
}

void setup_4096(void) {
  test_string = malloc(4097);
  test_string2 = malloc(4097);
}
