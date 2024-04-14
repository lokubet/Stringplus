#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *tmp = (char *)str;
  while (*tmp != (char)c && *tmp != '\0') {
    tmp++;
  }
  tmp = (*tmp == '\0' && (char)c != '\0') ? NULL : tmp;
  return tmp;
}
