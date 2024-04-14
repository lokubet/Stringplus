#include <math.h>
#include <stdarg.h>
#include <stdio.h>

#include "../s21_string.h"

#ifndef S21_MSPRINTF_ADDITIONAL_FUNCS
#define S21_MSPRINTF_ADDITIONAL_FUNCS
void s21_scan_format(char **format_str, mformat_t *format_f, va_list *args);
void s21_gen_str_from_format(char **str, mformat_t *format, va_list *args);
void s21_put_format(mformat_t *format_f, int arg, enum put_format_rule rule);

void gen_c_format(char **str, mformat_t *format, va_list *args);
void gen_percent_format(char **str, mformat_t *format);
void gen_d_format(char **str, mformat_t *format, va_list *args);
void gen_f_format(char **str, mformat_t *format, va_list *args);
void gen_u_format(char **str, mformat_t *format, va_list *args);
void gen_s_format(char **str, mformat_t *format, va_list *args);

#define PUT_N_C_TO_STR(n, str, c) \
  while (((n)--) > 0) {           \
    *(str) = (c);                 \
    *(++(str)) = '\0';            \
  }

#define WIDTH_FORMAT(code)                                    \
  if (!(format->flags & MINUS)) PUT_N_C_TO_STR(len, *str, c); \
  code if ((format->flags & MINUS)) PUT_N_C_TO_STR(len, *str, c);

#endif

int s21_sprintf(char *str, char *format, ...) {
  va_list args;
  va_start(args, format);
  char *start = str;
  while (*format != '\0') {
    if (*format == '%') {
      mformat_t format_f = {0};
      format_f.accuracy = -1;
      s21_scan_format(&format, &format_f, &args);
      s21_gen_str_from_format(&str, &format_f, &args);
    } else {
      *str = *format;
      str++;
      *str = '\0';
    }
    format++;
  }
  return (int)(str - start);
}

void s21_scan_format(char **format_str, mformat_t *format_f, va_list *args) {
  // putting flags into format_f
  // пока есть символы обозначающие флаги
  while (s21_strchr(FLAG_CHARS, *++(*format_str))) {
    s21_put_format(format_f, **format_str, FLAG_RULE);
  }
  // когда символы закончились возвращаемся на символ назад
  (*format_str)--;

  // putting width into format_f
  // если встречаем звездочку то берем ширину из варгов
  if (s21_strchr("*", *++(*format_str)))
    format_f->width = va_arg(*args, int);
  else {
    // если звезда не встретилась то возвращаемся на символ назад и начинаем
    // считывать ширину заново
    (*format_str)--;
    // пока встречаем цифры добавляем их к ширине
    while (s21_strchr(NUMERICAL_CHARS, *++(*format_str)))
      s21_put_format(format_f, **format_str, WIDTH_RULE);
    // встретили не цифру > возвращаемся назад
    (*format_str)--;
  }

  // putting accuracy into format_f
  format_f->accuracy = -1;
  // если встретили точку то начинаем парсить точность
  if (s21_strchr(".", *++(*format_str))) {
    format_f->accuracy = 0;
    // встретили звезду > берем точность из аргументов
    if (s21_strchr("*", *++(*format_str)))
      format_f->accuracy = va_arg(*args, int);
    else {
      // встретили не звезду > возвращаемся назад
      (*format_str)--;
      // пока встречаем цифры добавляем их к точности
      while (s21_strchr(NUMERICAL_CHARS, *++(*format_str)))
        s21_put_format(format_f, **format_str, ACCURACY_RULE);
      // цифры закончились, возвращаемся
      (*format_str)--;
    }
  } else
    (*format_str)--;
  // если встретили не точку то возвращаемся назад

  // putting length into format_f
  // если следующий символ отображает длину то все с кайфом
  if (s21_strchr(LENGTH_CHARS, *++(*format_str)))
    s21_put_format(format_f, **format_str, LENGTH_RULE);
  // иначе возвращаемся назад
  else
    (*format_str)--;

  // putting spec into format_f
  // если встречаем символ отображающий спек то кладем его format_f
  if (s21_strchr(SPEC_CHARS, *++(*format_str))) format_f->spec = **format_str;

  // таким образом мы остановились на символе спецификатора
  // значение на указателе равно символу спека
}

// %[флаги][ширина][.точность][длина]спецификатор
void s21_gen_str_from_format(char **str, mformat_t *format, va_list *args) {
  static int flag_num = 0;
  // printf("%d flags: %d\n", flag_num, format->flags);
  // printf("%d width: %d\n", flag_num, format->width);
  // printf("%d accuracy: %d\n", flag_num, format->accuracy);
  // printf("%d length: %c\n", flag_num, format->length);
  // printf("%d spec: %c\n", flag_num, format->spec);
  switch (format->spec) {
    case C:
      gen_c_format(str, format, args);
      break;
    case PERCENT:
      gen_percent_format(str, format);
      break;
    case D:
      gen_d_format(str, format, args);
      break;
    case F:
      gen_f_format(str, format, args);
      break;
    case U:
      gen_u_format(str, format, args);
      break;
    case S:
      gen_s_format(str, format, args);
      break;
    default:
      break;
  }
  flag_num++;
}

void gen_c_format(char **str, mformat_t *format, va_list *args) {
  int len = (format->width - 1);
  int c = ' ';
  c = (format->flags & ZERO) ? '0' : ' ';
  WIDTH_FORMAT(**str = va_arg(*args, int); *++*str = '\0';)
}

void gen_percent_format(char **str, mformat_t *format) {
  int len = (format->width - 1);
  int c = ' ';
  c = (format->flags & ZERO) ? '0' : ' ';
  WIDTH_FORMAT(**str = PERCENT; *++*str = '\0';)
}

void gen_s_format(char **str, mformat_t *format, va_list *args) {
  char *arg = va_arg(*args, char *);
  int count_of_chars = s21_strlen(arg);
  if (format->accuracy != -1 && format->accuracy < count_of_chars) {
    count_of_chars = format->accuracy;
  }
  int len = (format->width - count_of_chars);
  int c = ' ';
  c = (format->flags & ZERO) ? '0' : ' ';
  WIDTH_FORMAT(for (int i = 0; arg[i] != '\0' && i < count_of_chars; i++) {
    **str = arg[i];
    *++*str = '\0';
  })
}

void gen_d_format(char **str, mformat_t *format, va_list *args) {
  long int arg_i;
  if (format->length == L) {
    arg_i = (long)va_arg(*args, long int);
  } else if (format->length == H) {
    arg_i = (int)va_arg(*args, int);
  } else {
    arg_i = (int)va_arg(*args, int);
  }
  int negative = 0;
  if (arg_i < 0) negative = 1;
  arg_i = ABS(arg_i);
  int num_len = s21_len_of_int(arg_i);
  int len = (format->width - num_len);
  if (format->flags & SPACE)
    len -= 1;
  else
    len -= (format->flags & PLUS || negative) ? 1 : 0;
  len -= (format->accuracy > num_len) ? (format->accuracy - num_len) : 0;
  char c = ' ';
  c = (format->flags & ZERO) ? '0' : ' ';
  char buffer[30];
  WIDTH_FORMAT(
      if (format->flags & PLUS || negative) {
        **str = (negative) ? '-' : '+';
        *++*str = '\0';
      } else if (format->flags & SPACE) {
        **str = ' ';
        *++*str = '\0';
      }

      for (int i = 0; i < format->accuracy - num_len; i++) {
        **str = '0';
        *++*str = '\0';
      } s21_int_to_str(arg_i, buffer);
      int i = 0; while (buffer[i] != '\0') {
        **str = buffer[i];
        *++*str = '\0';
        i++;
      })
}

void gen_u_format(char **str, mformat_t *format, va_list *args) {
  // char * start = *str;
  long unsigned arg_i;
  if (format->length == L) {
    arg_i = (long unsigned)va_arg(*args, long unsigned);
  } else if (format->length == H) {
    arg_i = (unsigned)va_arg(*args, unsigned);
  } else {
    arg_i = (unsigned)va_arg(*args, unsigned);
  }
  int num_len = s21_len_of_uint(arg_i);
  int len = (format->width - num_len);
  // if (format->flags & SPACE) len -= 1;
  // else if (format->flags & PLUS) len -= 1;
  len -= (format->accuracy > num_len) ? (format->accuracy - num_len) : 0;
  char c = ' ';
  c = (format->flags & ZERO) ? '0' : ' ';
  char buffer[30];
  WIDTH_FORMAT(
      // if (format->flags & PLUS) {
      //     **str = '+';
      //     * ++*str = '\0';
      // } else if (format->flags & SPACE) {
      //     **str = ' ';
      //     * ++*str = '\0';
      // }

      for (int i = 0; i < format->accuracy - num_len; i++) {
        **str = '0';
        *++*str = '\0';
      } s21_uint_to_str(arg_i, buffer);
      int i = 0; while (buffer[i] != '\0') {
        **str = buffer[i];
        *++*str = '\0';
        i++;
      })
}

void gen_f_format(char **str, mformat_t *format, va_list *args) {
  long double arg;
  if (format->length == LL) {
    arg = (long double)va_arg(*args, long double);
  } else {
    arg = (double)va_arg(*args, double);
  }
  if (format->accuracy == -1) format->accuracy = 6;
  // printf("DEBUG: %f\n", arg);
  int len = format->width;
  int negative = (arg < 0) ? 1 : 0;
  if (format->flags & SPACE)
    len -= 1;
  else if ((format->flags & PLUS || negative))
    len -= 1;
  arg = ABS(arg);
  // arg = s21_round_float(arg, format->accuracy);
  char buffer[128];
  s21_put_float_into_str(buffer, arg, format->accuracy);
  // printf("DEBUG: %s\n", buffer);

  int num_len = s21_strlen(buffer);
  int count_of_zeros = 0;
  count_of_zeros =
      format->accuracy - (num_len - 1 - s21_len_of_int((long int)arg));
  if (format->accuracy == 0) count_of_zeros = 0;
  // printf("DEBUG: %d\n", count_of_zeros);
  len -= num_len;
  len -= count_of_zeros;
  char c = ' ';
  c = (format->flags & ZERO) ? '0' : ' ';
  WIDTH_FORMAT(
      if (format->flags & PLUS && !negative) {
        **str = '+';
        *++*str = '\0';
      } else if (negative) {
        **str = '-';
        *++*str = '\0';
      } else if (format->flags & SPACE) {
        **str = ' ';
        *++*str = '\0';
      }

      s21_strncpy(*str, buffer, num_len + 1);
      for (int i = 0; i < 30 && buffer[i] != '\0'; i++) {
        **str = buffer[i];
        *++*str = '\0';
      }

          // printf("DEBUG: %s\n", *str);
          *str = s21_strchr(*str, '\0');
      for (int i = 0; i < count_of_zeros; i++) {
        **str = '0';
        *++*str = '\0';
      })
  // printf("%s", *str);
}

void s21_put_float_into_str(char *buffer, long double num, int accuracy) {
  num = ABS(num);
  s21_int_to_str((long int)num, buffer);
  buffer += s21_len_of_int((long int)num);
  if (accuracy > 0) {
    long double number_to_divide = 5;
    for (int i = 0; i < accuracy + 1; i++) number_to_divide /= 10;
    num += number_to_divide;
    *buffer = '.';
    *++buffer = '\0';
    num -= (long double)(long int)num;
    for (int i = 0; i < accuracy; i++) {
      num *= 10;
      // printf("DEBUG: %Lf\n", num);
      if (i + 1 == accuracy) {
      }
      *buffer = NUMERICAL_CHARS[(int)(num) % 10];
      num -= (int)num;
      *++buffer = '\0';
    }
    // int count_of_zeros = accuracy - s21_len_of_int((long int)num);
    // for(int i = 0; i < count_of_zeros; i ++) {
    //     *buffer = '0';
    //     * ++buffer = '\0';
    // }
    // s21_int_to_str((long int)num, buffer);
  }
}

double s21_round_float(long double num, int accuracy) {
  long double result = num;
  for (int i = 0; i < accuracy; i++) result *= 10;
  for (int i = 0; i < accuracy + 1; i++) num *= 10;
  result = (long double)(long int)result;
  if (((long int)num % 10) >= 5) result += 1;
  for (int i = 0; i < accuracy; i++) result /= 10;
  // *len = 0;
  // *len += s21_len_of_int((long int) result);
  // *len += (accuracy > 0) ? accuracy + 1 : 0;
  return result;
}

void s21_put_format(mformat_t *format_f, int arg, enum put_format_rule rule) {
  int flag = 0;
  switch (rule) {
    case FLAG_RULE:
      switch (arg) {
        case '-':
          flag = MINUS;
          break;
        case '+':
          flag = PLUS;
          break;
        case ' ':
          flag = SPACE;
          break;
        case '#':
          flag = HASH;
          break;
        case '0':
          flag = ZERO;
          break;
        default:
          break;
      }
      format_f->flags |= flag;
      break;
    case WIDTH_RULE:
      format_f->width *= 10;
      format_f->width += arg - 48;
      break;
    case ACCURACY_RULE:
      if (format_f->accuracy == -1) format_f->accuracy = 0;
      format_f->accuracy *= 10;
      format_f->accuracy += arg - 48;
      break;
    case LENGTH_RULE:
      format_f->length = arg;
      break;
    default:
      break;
  }
}