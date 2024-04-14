#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
  char *start = dest;
  if (dest != NULL && src != NULL) {
    dest = s21_strchr(dest, '\0');
    while (*src != '\0' && n--) {
      *dest = *src;
      dest++;
      src++;
    }
    *dest = '\0';
    // printf("DEBUG: %s\n", dest-6);
  }
  return start;
}
