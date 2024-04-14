#include "../s21_string.h"
size_t s21_strcspn(const char *str1, const char *str2) {
  const char *temp = str1;
  int flag = 1;
  size_t count = 0;
  while (*temp && flag) {
    if (s21_strchr(str2, *temp)) {
      flag = 0;
    } else {
      ++temp;
      ++count;
    }
  }
  return count;
}
