#include "../s21_string_test.h"

START_TEST(check_const) {
  char str[256] = "";
  memset(str, _i % 128, _i);
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(check_dyn) {
  memset(test_string, 0, 129);
  memset(test_string, _i, _i);
  ck_assert_int_eq(s21_strlen(test_string), strlen(test_string));
}
END_TEST

Suite *strlen_suite(void) {
  Suite *s = suite_create("STRLEN");
  TCase *tc_const = tcase_create("Const case");
  TCase *tc_dyn = tcase_create("Dynamic case");
  tcase_add_checked_fixture(tc_dyn, setup_128, teardown);
  tcase_add_loop_test(tc_const, check_const, 0, 255);
  tcase_add_loop_test(tc_dyn, check_dyn, 0, 128);
  suite_add_tcase(s, tc_const);
  suite_add_tcase(s, tc_dyn);
  return s;
}
