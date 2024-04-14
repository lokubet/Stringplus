#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
  if (dest != NULL && src != NULL) {
    dest[0] = '\0';
    size_t i = 0;
    while (src[i] != '\0' && i < n) {
      dest[i] = src[i];
      dest[i + 1] = '\0';
      i++;
    }
    if (i < n) {
      while (i++ < n) {
        dest[i] = '\0';
      }
    }
  }
  return dest;
}
