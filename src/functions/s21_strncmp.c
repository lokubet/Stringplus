#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int res = 0;
  size_t len1 = s21_strlen(str1);
  size_t len2 = s21_strlen(str2);
  size_t i = 0;
  while (i < n && i < len1 && i < len2) {
    if (str1[i] > str2[i]) {
      res = str1[i] - str2[i];
      i = n;
    } else if (str2[i] > str1[i]) {
      res = str1[i] - str2[i];
      i = n;
    }
    i++;
  }
  return res;
}
