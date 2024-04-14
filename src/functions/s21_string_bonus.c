#include <stdlib.h>

#include "../s21_string.h"

#define UP 1
#define LOW 0

void *s21_to_upper(const char *str) {
  return (str) ? change_case(str, UP) : NULL;
}

void *s21_to_lower(const char *str) {
  return (str) ? change_case(str, LOW) : NULL;
}

char *change_case(const char *str, const int size) {
  size_t len = s21_strlen(str);
  char *tmp = (char *)malloc(sizeof(char) * (len + 1));
  for (size_t i = 0; i < len; i++) {
    if (size) {
      if (str[i] >= 97 && str[i] <= 122) {
        tmp[i] = str[i] - 32;
      } else {
        tmp[i] = str[i];
      }
    } else {
      if (str[i] >= 65 && str[i] <= 90) {
        tmp[i] = str[i] + 32;
      } else {
        tmp[i] = str[i];
      }
    }
  }
  tmp[len] = S21_EOL;
  return tmp;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *tmp = NULL;
  size_t src_len = s21_strlen(src);
  size_t str_len = s21_strlen(str);
  if (start_index <= src_len) {
    tmp = (char *)malloc(sizeof(char) * (src_len + str_len + 1));
  }
  if (tmp) {
    s21_strncpy(tmp, src, start_index);
    s21_strncpy(tmp + start_index, str, str_len);
    for (size_t i = start_index; i < src_len; i++) {
      tmp[i + str_len] = src[i];
    }
    tmp[str_len + src_len] = S21_EOL;
  }
  return tmp;
}
#include <stdio.h>
void *s21_trim(const char *src, const char *trim_chars) {
  char *tmp = (char *)malloc(sizeof(char) * (s21_strlen(src) + 1));
  if (tmp) {
    s21_strncpy(tmp, src, s21_strlen(src));
    int flag = 1;
    for (size_t i = 0; i < s21_strlen(tmp) && flag; i++) {
      int change = 0;
      for (size_t j = 0; j < s21_strlen(trim_chars) && !change; j++) {
        if (tmp[i] == trim_chars[j]) {
          s21_strncpy(tmp, tmp + i + 1, s21_strlen(tmp) - i - 1);
          tmp[s21_strlen(tmp) - 1] = S21_EOL;
          change = 1;
          i--;
        }
      }
      flag = (change) ? 1 : 0;
    }
    flag = 1;
    for (size_t i = s21_strlen(tmp) - 1; flag; i--) {
      int change = 0;
      for (size_t j = 0; j < s21_strlen(trim_chars) && !change; j++) {
        if (tmp[i] == trim_chars[j]) {
          s21_strncpy(tmp, tmp, i - 1);
          tmp[i] = S21_EOL;
          change = 1;
        }
      }
      flag = (change) ? 1 : 0;
    }
    size_t len = s21_strlen(tmp);
    char *tmp2 = (char *)malloc(sizeof(char) * (len + 1));
    s21_strncpy(tmp2, tmp, len);
    free(tmp);
    tmp = tmp2;
  }
  return tmp;
}
