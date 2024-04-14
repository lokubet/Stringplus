#ifndef S21_STRING_H
#define S21_STRING_H

#ifndef NULL
#define NULL ((void *)0)
#endif

#define ABS(a) (((a) > 0) ? (a) : ((a) * -1))
#define NUMERICAL_CHARS "0123456789"
#define FLAG_CHARS "-+ #0"
#define LENGTH_CHARS "hlL"
#define SPEC_CHARS "cdieEfgGosuxXpn%"

#define S21_EOL '\0'

typedef unsigned long size_t;

// basic functions
void *s21_memchr(const void *str, int c, size_t n);             // +
int s21_memcmp(const void *str1, const void *str2, size_t n);   // +
void *s21_memcpy(void *dest, const void *src, size_t n);        // +
void *s21_memset(void *str, int c, size_t n);                   // +
char *s21_strncat(char *dest, const char *src, size_t n);       // +
char *s21_strchr(const char *str, int c);                       // +
int s21_strncmp(const char *str1, const char *str2, size_t n);  // +
char *s21_strncpy(char *dest, const char *src, size_t n);       // +
size_t s21_strcspn(const char *str1, const char *str2);         // +
char *s21_strerror(int errnum);                                 // +
size_t s21_strlen(const char *str);                             // +
char *s21_strpbrk(const char *str1, const char *str2);          // +
char *s21_strrchr(const char *str, int c);                      // +
char *s21_strstr(const char *haystack, const char *needle);     // +
char *s21_strtok(char *str, const char *delim);                 // +
size_t s21_strspn(const char *str1, const char *str2);          // +

// Дополнительная функция для strerror
char *s21_strcat(char *dest, const char *src);
// Записывает инт в буффер
void s21_int_to_str(long int n, char *buffer);
// Переворачивает первые len символов строки
void s21_reverse_str(char *buffer, int len);
// Находит длину инта так, будто бы его записали в строку
int s21_len_of_int(long int n);
void s21_uint_to_str(unsigned long int n, char *buffer);
int s21_len_of_uint(unsigned long int n);

// Sprintf implementation by alemaduri
typedef struct mformat_s {
  int flags;
  int width;
  int accuracy;
  char length;
  char spec;
} mformat_t;

enum put_format_rule { FLAG_RULE, WIDTH_RULE, ACCURACY_RULE, LENGTH_RULE };

int s21_msprintf(char *str, char *format, ...);

// End of alemaduri implementation

typedef enum flags {
  MINUS = 1 << 0,
  PLUS = 1 << 1,
  SPACE = 1 << 2,
  HASH = 1 << 3,
  ZERO = 1 << 4,
  NO_FLAG = 0
} flags;

typedef enum spec {
  C = 'c',
  D = 'd',
  I = 'i',
  E = 'e',
  EE = 'E',
  F = 'f',
  G = 'g',
  GG = 'G',
  O = 'o',
  S = 's',
  U = 'u',
  X = 'x',
  XX = 'X',
  P = 'p',
  N = 'n',
  PERCENT = '%',
  NO_SPEC = '\0'
} spec;

typedef enum length { H = 'h', L = 'l', LL = 'L', NO_LEN } length;

typedef struct Format {
  flags flag;
  int width;
  int accuracy;
  length len;
  spec type;
  size_t format_str_start;  // %
  size_t format_str_end;    // спецификатор
} Format;

// i/o functions
int s21_sscanf(const char *str, const char *format, ...);
int s21_sprintf(char *str, char *format, ...);
// int s21_sprintf(char *str, const char *format, ...);

// bonus C# functions
void *s21_to_upper(const char *str);                                     // +
void *s21_to_lower(const char *str);                                     // +
void *s21_insert(const char *src, const char *str, size_t start_index);  // +
void *s21_trim(const char *src, const char *trim_chars);                 // +

// additional functions
char *change_case(const char *str, const int size);
size_t count_args(const char *format_str, Format ***formats);
void parse_format(Format **formats, const char *format_str, size_t args_count);
size_t parse_flags(Format *format, char flag);
size_t parse_width(Format *format, char *format_str);
size_t parse_accuracy(Format *format, char *format_str);
size_t parse_length(Format *format, char len);
void parse_spec(Format *format, char type);

double s21_round_float(long double num, int accuracy);
void s21_put_float_into_str(char *buffer, long double num, int accuracy);

#endif  // S21_STRING_H
