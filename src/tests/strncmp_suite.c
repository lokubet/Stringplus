#include <stdlib.h>
#include <time.h>

#include "../s21_string_test.h"

static const char string_arr[][256] = {
    "m8MQP0Zf4Wz37kjEeTSOqEgXVecm32j0", "yn2U5FHVjGdy2ChyD9rKWBi17S5nOYu8",
    "lyzJy6Dx96LTYIq9ucoHX6jdnDAEogl2", "Jfol8VUZ2sxLKq3JxxgCSAWkVfhWNX21",
    "iP7hgwYlGDD2lpQsjKCyyuTnFP9bFMir", "VEKtBuOKcyZVqjrGNhAlP0FAfClE2EBA",
    "EDmKLyteObNhVJfwqnmHRxfRxnUHuqmn", "lGoXShXCN5pcpC5IEuEgIxxaMPfFvkHN",
    "LIdL8hndKjAMoi8vOrbuegBNiE16S5zs", "qjGEyJ9AabAwu9EdpkkSHcioBrsDIXEj"};

START_TEST(check_const) {
  for (unsigned i = 0; i < strlen(string_arr[_i]); i++) {
    ck_assert_int_eq(
        s21_strncmp(string_arr[_i], string_arr[_i + 1] + i, 31 - i),
        strncmp(string_arr[_i], string_arr[_i + 1] + i, 31 - i));
  }
}
END_TEST

START_TEST(check_dyn) {
  srand(time(0));
  memset(test_string, 0, 256);
  memset(test_string2, 0, 256);
  for (int i = 0; i < 128; i++) {
    test_string[i] = rand() % 127;
    test_string2[i] = test_string[i];
  }
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(s21_strncmp(test_string, test_string2, 128 - i),
                     strncmp(test_string, test_string2, 128 - i));
  }
}
END_TEST

Suite *strncmp_suite(void) {
  Suite *s = suite_create("STRNCMP");
  TCase *tc_const = tcase_create("Const case");
  TCase *tc_dyn = tcase_create("Dyn case");
  tcase_add_checked_fixture(tc_dyn, setup_256, teardown);
  tcase_add_loop_test(tc_const, check_const, 0, 9);
  tcase_add_test(tc_dyn, check_dyn);
  suite_add_tcase(s, tc_const);
  suite_add_tcase(s, tc_dyn);
  return s;
}
