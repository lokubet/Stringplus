#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *tmp = NULL;
  size_t len1 = s21_strlen(haystack);
  size_t len2 = s21_strlen(needle);
  for (size_t i = 0; i < len1 && tmp == NULL; i++) {
    if (haystack[i] == needle[0]) {
      size_t k = i + 1;
      size_t j = 1;
      int flag = 1;
      while (j < len2 && k < len1 && flag) {
        if (haystack[k] != needle[j]) {
          flag = 0;
        }
        j++;
        k++;
      }
      tmp = (flag) ? (char *)&(haystack[i]) : NULL;
    }
  }
  return tmp;
}
