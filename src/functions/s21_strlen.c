#include "../s21_string.h"

size_t s21_strlen(const char *str) {
  size_t len = 0;
  while (*str != '\0') {
    len++;
    str++;
  }
  return len;
}
