#include "../s21_string.h"

void *s21_memset(void *str, int c, size_t n) {
  unsigned char *temp_str = str;
  for (size_t index = 0; index != n; ++index) {
    temp_str[index] = (unsigned char)c;
  }
  return str;
}
