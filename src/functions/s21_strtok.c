#include "../s21_string.h"

char *findDelim(char *str, const char *delim) {
  char *delimPtr = str;
  while ((s21_strchr(delim, *delimPtr) == NULL) && (*delimPtr != '\0'))
    delimPtr++;
  return delimPtr;
}

char *s21_strtok(char *str, const char *delim) {
  static char *strForSearch;
  static char *delimPtr;
  const char *result = NULL;

  if (str) {
    strForSearch = str + s21_strspn(str, delim);
  } else {
    strForSearch = strForSearch + s21_strspn(strForSearch, delim);
  }

  delimPtr = findDelim(strForSearch, delim);
  if (*delimPtr == 0 && *strForSearch != 0) {
    result = strForSearch;
    strForSearch += s21_strlen(strForSearch);
  } else if (*strForSearch != 0) {
    *delimPtr = '\0';
    result = strForSearch;
    strForSearch = delimPtr + 1;
  }
  return (char *)result;
}