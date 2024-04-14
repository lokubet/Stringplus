#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n) {
  unsigned char *temp_dest = (unsigned char *)dest;
  const unsigned char *temp_src = (const unsigned char *)src;
  for (size_t index = 0; index != n; ++index) {
    temp_dest[index] = temp_src[index];
  }
  return dest;
}
