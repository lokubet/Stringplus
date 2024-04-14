#include "../s21_string_test.h"

START_TEST(check_dyn) {
  memset(test_string, 0, 129);
  memset(test_string2, _i, 128);
  memset(test_string2 + 128, 0, 1);
  ck_assert_ptr_eq(s21_memcpy(test_string, test_string2, 129), test_string);
  ck_assert_pstr_eq(test_string, test_string2);
}
END_TEST

START_TEST(check_const) {
  char str[256] = "";
  char str2[256] = "";
  for (int i = 0; i < _i; i++) {
    str2[i] = _i % 128;
  }
  ck_assert_ptr_eq(s21_memcpy(str, str2, _i), str);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *s = suite_create("MEMCPY");
  TCase *tc_const = tcase_create("Const case");
  TCase *tc_dyn = tcase_create("Dynamic case");
  tcase_add_checked_fixture(tc_dyn, setup_128, teardown);
  tcase_add_loop_test(tc_const, check_const, 0, 255);
  tcase_add_loop_test(tc_dyn, check_dyn, 10, 120);
  suite_add_tcase(s, tc_const);
  suite_add_tcase(s, tc_dyn);
  return s;
}
