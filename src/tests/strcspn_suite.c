#include <stdlib.h>
#include <time.h>

#include "../s21_string_test.h"

static const char string_arr[][256] = {
    "MVWOJbR08wEdyZ6g7BU38L4WMXmU5pqq", "r8HJbXGLmGn6I0FRgLVhNMGwZ6QtfNLz",
    "dujO7niHReAI1Uly5tUa4zcDydviWPa5", "hB41lB0o6xSWl5IQphrr1gvGUf7L4TRb",
    "51bfsbSsRF0yKNlo93s6FZSaLrW3bOXn", "i3NWZlwhRQbAXhkSzQvKiid0iZxYq969",
    "e953FoZUQDBInZeq2RRH2fH6MNLxq2zy", "AXlGBij9boxKhUJt5fHPJXzTdF5DfFuL",
    "I6VFVrbSwIbqedJSU6X04IJpgYkTd9Q7", "5iSo5eRXVnuUlTiw6Uco7v3EXmC5Dfv7"};

START_TEST(check_const) {
  for (unsigned i = 0; i < strlen(string_arr[_i]); i++) {
    ck_assert_int_eq(s21_strcspn(string_arr[_i], string_arr[_i + 1] + i),
                     strcspn(string_arr[_i], string_arr[_i + 1] + i));
  }
}
END_TEST

START_TEST(check_dyn) {
  srand(time(0));
  memset(test_string, 0, 256);
  memset(test_string2, 0, 256);

  for (int i = 0; i < 128; i++) {
    test_string[i] = rand() % 127;
    test_string2[i] = rand() % 127;
  }
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(s21_strcspn(test_string, test_string2 + i),
                     strcspn(test_string, test_string2 + i));
  }
}
END_TEST

Suite *strcspn_suite(void) {
  Suite *s = suite_create("STRCSPN");
  TCase *tc_const = tcase_create("Const case");
  TCase *tc_dyn = tcase_create("Dyn case");
  tcase_add_checked_fixture(tc_dyn, setup_256, teardown);
  tcase_add_loop_test(tc_const, check_const, 0, 9);
  tcase_add_test(tc_dyn, check_dyn);
  suite_add_tcase(s, tc_const);
  suite_add_tcase(s, tc_dyn);
  return s;
}
