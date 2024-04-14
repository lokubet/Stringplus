#include "../s21_string_test.h"

START_TEST(check_const_found) {
  char const_str[256];
  for (int i = 32; i < 127; i++) {
    const_str[i - 32] = i;
  }
  const_str[127] = 0;
  ck_assert_ptr_eq(s21_memchr(const_str, _i, 128), memchr(const_str, _i, 128));
  ck_assert_mem_eq(s21_memchr(const_str, _i, 128), memchr(const_str, _i, 128),
                   sizeof(char));
}
END_TEST

START_TEST(check_const_nf) {
  char const_str[] = "                ";
  ck_assert_ptr_null(s21_memchr(const_str, _i, 17));
}
END_TEST

START_TEST(check_dyn_found) {
  for (int i = 32; i < 127; i++) {
    test_string[i - 32] = i;
  }
  test_string[127] = 0;
  ck_assert_ptr_eq(s21_memchr(test_string, _i, 128),
                   memchr(test_string, _i, 128));
  ck_assert_mem_eq(s21_memchr(test_string, _i, 128),
                   memchr(test_string, _i, 128), sizeof(char));
}
END_TEST

START_TEST(check_dyn_nf) {
  for (int i = 0; i < 32; i++) {
    test_string[i] = ' ';
  }
  test_string[32] = 0;
  ck_assert_ptr_null(s21_memchr(test_string, _i, 32));
}
END_TEST

START_TEST(check_zero) { ck_assert_ptr_null(s21_memchr("", _i, 1)); }
END_TEST

Suite *memchr_suite(void) {
  Suite *s = suite_create("MEMCHR");

  TCase *tc_const = tcase_create("Const case");
  tcase_add_loop_test(tc_const, check_const_found, 32, 127);
  tcase_add_loop_test(tc_const, check_const_nf, 33, 127);
  TCase *tc_dyn = tcase_create("Dynamic case");
  tcase_add_checked_fixture(tc_dyn, setup_128, teardown);
  tcase_add_loop_test(tc_dyn, check_dyn_found, 32, 127);
  tcase_add_loop_test(tc_dyn, check_dyn_nf, 33, 127);
  TCase *tc_var = tcase_create("Various case");
  tcase_add_loop_test(tc_var, check_zero, 1, 128);

  suite_add_tcase(s, tc_const);
  suite_add_tcase(s, tc_dyn);
  suite_add_tcase(s, tc_var);
  return s;
}
