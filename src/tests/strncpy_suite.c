#include "../s21_string_test.h"

START_TEST(check_const) {
  char str[256] = "asd";
  char str2[256] = "";
  memset(str2, _i, 255);
  for (int i = 0; i < _i; i++) {
    ck_assert_ptr_eq(s21_strncpy(str, str2, i), str);
    ck_assert_mem_eq(str, str2, i);
    memset(str, 0, 256);
  }
}
END_TEST

START_TEST(check_dyn) {
  memset(test_string, 0, 257);
  memset(test_string2, 0, 257);
  memset(test_string2, _i, 256);
  for (int i = 0; i < _i; i++) {
    ck_assert_ptr_eq(s21_strncpy(test_string, test_string2, i), test_string);
    ck_assert_mem_eq(test_string, test_string2, i);
    memset(test_string, 0, 257);
  }
}
END_TEST

START_TEST(check_const_over) {
  char str[256] = "123";
  char str2[256] = "";
  memset(str2, _i, 5);
  for (int i = 6; i < _i; i++) {
    ck_assert_ptr_eq(s21_strncpy(str, str2, i), str);
    ck_assert_mem_eq(str, str2, i);
    memset(str, 0, 256);
  }
}
END_TEST

START_TEST(check_dyn_over) {
  memset(test_string, 0, 257);
  memset(test_string, 64, 12);
  memset(test_string2, 0, 257);
  memset(test_string2, _i, 5);
  for (int i = 6; i < _i; i++) {
    ck_assert_ptr_eq(s21_strncpy(test_string, test_string2, i), test_string);
    ck_assert_mem_eq(test_string, test_string2, i);
    memset(test_string, 0, 257);
  }
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *s = suite_create("STRNCPY");
  TCase *tc_const = tcase_create("Const case");
  TCase *tc_dyn = tcase_create("Dyn case");
  tcase_add_checked_fixture(tc_dyn, setup_256, teardown);
  tcase_add_loop_test(tc_const, check_const, 0, 256);
  tcase_add_loop_test(tc_const, check_const_over, 7, 256);
  tcase_add_loop_test(tc_dyn, check_dyn, 0, 257);
  tcase_add_loop_test(tc_dyn, check_dyn_over, 7, 257);
  suite_add_tcase(s, tc_const);
  suite_add_tcase(s, tc_dyn);
  return s;
}
