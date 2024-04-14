#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  size_t len = s21_strlen(str);
  long n = (long)len;
  char *return_p = NULL;
  while (return_p == NULL && n >= 0) {
    if (str[n] == c) {
      return_p = (char *)&str[n];
    }
    n--;
  }
  return return_p;
}
