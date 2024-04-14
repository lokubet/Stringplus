#ifndef S21_STRING_TEST
#define S21_STRING_TEST

#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

#ifndef TEST_STRINGS
#define TEST_STRINGS
extern char *test_string;
extern char *test_string2;
#endif  // TEST_STRINGS

Suite *memchr_suite(void);
Suite *memcmp_suite(void);
Suite *memcpy_suite(void);
Suite *memset_suite(void);
Suite *strncat_suite(void);
Suite *strchr_suite(void);
Suite *strncmp_suite(void);
Suite *strncpy_suite(void);
Suite *strcspn_suite(void);
Suite *strerror_suite(void);
Suite *strlen_suite(void);
Suite *strrchr_suite(void);
Suite *strstr_suite(void);
Suite *strpbrk_suite(void);
Suite *strtok_suite(void);
Suite *sscanf_suite(void);
Suite *sprintf_suite(void);
Suite *strtok_suite(void);

void teardown(void);
void setup_16(void);
void setup_128(void);
void setup_256(void);
void setup_4096(void);

#endif  // S21_STRING_TEST
