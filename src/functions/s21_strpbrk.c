#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  size_t count;
  int flag = 1;
  char *result = NULL;
  for (count = 0; count < s21_strlen(str2) && flag; count++) {
    char *temp = s21_strchr(str1, (int)str2[count]);
    if (temp != NULL) {
      result = temp;
      flag = 0;
    }
  }
  return result;
}
