#include "../s21_string_test.h"

START_TEST(check_err) { ck_assert_str_eq(s21_strerror(_i), strerror(_i)); }
END_TEST

Suite *strerror_suite(void) {
  Suite *s = suite_create("STRERROR");
  TCase *tc = tcase_create("Standard case");
  tcase_add_loop_test(tc, check_err, -1, 135);
  suite_add_tcase(s, tc);
  return s;
}
