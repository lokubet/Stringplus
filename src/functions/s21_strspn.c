#include "../s21_string.h"

size_t s21_strspn(const char *str1, const char *str2) {
  size_t counter = 0;
  int was = -1;
  for (size_t i = 0; i < s21_strlen(str1) && was != 0; i++) {
    was = 0;
    for (size_t j = 0; j < s21_strlen(str2) && was != 1; j++) {
      if (str1[i] == str2[j]) {
        counter++;
        was = 1;
      }
    }
  }
  return counter;
}
