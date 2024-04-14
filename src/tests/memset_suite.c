#include "../s21_string_test.h"

START_TEST(check_dyn) {
  memset(test_string, _i, _i);
  ck_assert_ptr_eq(s21_memset(test_string2, _i, _i), test_string2);
  ck_assert_mem_eq(test_string2, test_string, _i);
}
END_TEST

START_TEST(check_const) {
  char str[256] = "";
  char str2[256] = "";
  memset(str, _i, _i);
  ck_assert_ptr_eq(s21_memset(str2, _i, _i), str2);
  ck_assert_mem_eq(str2, str, _i);
}
END_TEST

Suite *memset_suite(void) {
  Suite *s = suite_create("MEMSET");
  TCase *tc_const = tcase_create("Const case");
  TCase *tc_dyn = tcase_create("Dynamic case");
  tcase_add_checked_fixture(tc_dyn, setup_4096, teardown);
  tcase_add_loop_test(tc_const, check_const, 0, 255);
  tcase_add_loop_test(tc_dyn, check_dyn, 0, 1024);
  suite_add_tcase(s, tc_const);
  suite_add_tcase(s, tc_dyn);
  return s;
}
