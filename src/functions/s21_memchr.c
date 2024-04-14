#include "../s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  unsigned char *result = NULL;
  unsigned char *u_char_str = (unsigned char *)str;
  const unsigned char u_c = (unsigned char)c;
  for (size_t i = 0; i < n && u_char_str != NULL && result == NULL;
       u_char_str++, i++)
    result = (*u_char_str == u_c) ? u_char_str : NULL;
  return result;
}
