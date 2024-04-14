#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  const unsigned char *buf1 = str1, *buf2 = str2;
  int temp = 0, flag = 1;
  for (size_t index = 0; index != n && flag; ++index) {
    if (buf1[index] != buf2[index]) {
      temp = buf1[index] - buf2[index];
      flag = 0;
    }
  }
  return temp;
}
