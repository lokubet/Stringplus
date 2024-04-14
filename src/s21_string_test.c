#include "s21_string_test.h"

#include <stdio.h>

int main(void) {
  int number_failed;
  SRunner *sr;
  sr = srunner_create(memchr_suite());
  srunner_add_suite(sr, memcmp_suite());
  srunner_add_suite(sr, memcpy_suite());
  srunner_add_suite(sr, memset_suite());
  srunner_add_suite(sr, strchr_suite());
  srunner_add_suite(sr, strcspn_suite());
  srunner_add_suite(sr, strerror_suite());
  srunner_add_suite(sr, strlen_suite());
  srunner_add_suite(sr, strncat_suite());
  srunner_add_suite(sr, strncmp_suite());
  srunner_add_suite(sr, strncpy_suite());
  srunner_add_suite(sr, strrchr_suite());
  srunner_add_suite(sr, strpbrk_suite());
  srunner_add_suite(sr, strstr_suite());
  srunner_add_suite(sr, strtok_suite());
  srunner_add_suite(sr, sprintf_suite());
  srunner_set_log(sr, "test.log");
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  printf("TESTS FAILED: %d", number_failed);

  return 0;
}
