#include <stdio.h>

#include "../s21_string_test.h"

START_TEST(check_c) {
  char str1[256] = "";
  char str2[256] = "";
  char src = (char)(_i % 128);
  ck_assert_int_eq(s21_sprintf(str1, "%c", src), sprintf(str2, "%c", src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_d) {
  char str1[256] = "";
  char str2[256] = "";
  int src = (int)(_i * ((412374612 * _i) << 16) * 3167);
  ck_assert_int_eq(s21_sprintf(str1, "%d", src), sprintf(str2, "%d", src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_f) {
  char str1[256] = "";
  char str2[256] = "";
  double src = _i * (((98481672 * _i) << 12) / (double)(127772 << 14));
  ck_assert_int_eq(s21_sprintf(str1, "%f", src), sprintf(str2, "%f", src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_s) {
  char str1[256] = "";
  char str2[256] = "";
  char src[256] = "";
  for (int i = 0; i < 64; i++) {
    src[i] = (char)((_i + i * ((4761234 + i * i) << 8)) % 128);
  }
  ck_assert_int_eq(s21_sprintf(str1, "%s", src), sprintf(str2, "%s", src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_u) {
  char str1[256] = "";
  char str2[256] = "";
  unsigned int src = (unsigned int)(_i * ((412374612 * _i) << 16) * 3167);
  ck_assert_int_eq(s21_sprintf(str1, "%u", src), sprintf(str2, "%u", src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_c_width_number) {
  char str1[256] = "";
  char str2[256] = "";
  char src = 'A';
  char fmt[10] = "";
  sprintf(fmt, "%%%dc", _i);
  ck_assert_int_eq(s21_sprintf(str1, fmt, src), sprintf(str2, fmt, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_c_width_star) {
  char str1[256] = "";
  char str2[256] = "";
  char src = 'A';
  ck_assert_int_eq(s21_sprintf(str1, "%*c", _i, src),
                   sprintf(str2, "%*c", _i, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_d_width_number) {
  char str1[256] = "";
  char str2[256] = "";
  int src = 1234;
  char fmt[10] = "";
  sprintf(fmt, "%%%dd", _i);
  ck_assert_int_eq(s21_sprintf(str1, fmt, src), sprintf(str2, fmt, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_d_width_star) {
  char str1[256] = "";
  char str2[256] = "";
  int src = 1234;
  ck_assert_int_eq(s21_sprintf(str1, "%*d", _i, src),
                   sprintf(str2, "%*d", _i, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_f_width_number) {
  char str1[256] = "";
  char str2[256] = "";
  double src = 12.345;
  char fmt[10] = "";
  sprintf(fmt, "%%%df", _i);
  ck_assert_int_eq(s21_sprintf(str1, fmt, src), sprintf(str2, fmt, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_f_width_star) {
  char str1[256] = "";
  char str2[256] = "";
  double src = 12.345;
  ck_assert_int_eq(s21_sprintf(str1, "%*f", _i, src),
                   sprintf(str2, "%*f", _i, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_u_width_number) {
  char str1[256] = "";
  char str2[256] = "";
  unsigned src = 1234;
  char fmt[10] = "";
  sprintf(fmt, "%%%du", _i);
  ck_assert_int_eq(s21_sprintf(str1, fmt, src), sprintf(str2, fmt, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_u_width_star) {
  char str1[256] = "";
  char str2[256] = "";
  unsigned src = 1234;
  ck_assert_int_eq(s21_sprintf(str1, "%*u", _i, src),
                   sprintf(str2, "%*u", _i, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_s_width_number) {
  char str1[256] = "";
  char str2[256] = "";
  char src[] = "UwU";
  char fmt[10] = "";
  sprintf(fmt, "%%%ds", _i);
  ck_assert_int_eq(s21_sprintf(str1, fmt, src), sprintf(str2, fmt, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_s_width_star) {
  char str1[256] = "";
  char str2[256] = "";
  char src[] = "Senpai";
  ck_assert_int_eq(s21_sprintf(str1, "%*s", _i, src),
                   sprintf(str2, "%*s", _i, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_d_precision_number) {
  char str1[256] = "";
  char str2[256] = "";
  int src = 1234;
  char fmt[10] = "";
  sprintf(fmt, "%%.%dd", _i);
  ck_assert_int_eq(s21_sprintf(str1, fmt, src), sprintf(str2, fmt, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_d_precision_star) {
  char str1[256] = "";
  char str2[256] = "";
  int src = -1234;
  ck_assert_int_eq(s21_sprintf(str1, "%.*d", _i, src),
                   sprintf(str2, "%.*d", _i, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_f_precision_number) {
  char str1[256] = "";
  char str2[256] = "";
  double src = 1.23456789;
  char fmt[10] = "";
  sprintf(fmt, "%%.%df", _i);
  ck_assert_int_eq(s21_sprintf(str1, fmt, src), sprintf(str2, fmt, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_f_precision_star) {
  char str1[256] = "";
  char str2[256] = "";
  double src = 1.23456789;
  ck_assert_int_eq(s21_sprintf(str1, "%.*f", _i, src),
                   sprintf(str2, "%.*f", _i, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_s_precision_number) {
  char str1[256] = "";
  char str2[256] = "";
  char src[] = "Omae Wa Mou Shindeiru";
  char fmt[10] = "";
  sprintf(fmt, "%%.%ds", _i);
  ck_assert_int_eq(s21_sprintf(str1, fmt, src), sprintf(str2, fmt, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_s_precision_star) {
  char str1[256] = "";
  char str2[256] = "";
  char src[] = "Omae Wa Mou Shindeiru";
  ck_assert_int_eq(s21_sprintf(str1, "%.*s", _i, src),
                   sprintf(str2, "%.*s", _i, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_u_precision_number) {
  char str1[256] = "";
  char str2[256] = "";
  unsigned src = 1234;
  char fmt[10] = "";
  sprintf(fmt, "%%.%du", _i);
  ck_assert_int_eq(s21_sprintf(str1, fmt, src), sprintf(str2, fmt, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_u_precision_star) {
  char str1[256] = "";
  char str2[256] = "";
  unsigned src = 4000000000u;
  ck_assert_int_eq(s21_sprintf(str1, "%.*u", _i, src),
                   sprintf(str2, "%.*u", _i, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(check_c_length) {
//   char str1[256] = "";
//   char str2[256] = "";
//   char src = 'A';
//   ck_assert_int_eq(s21_sprintf(str1, "%Lc", src), sprintf(str2, "%Lc", src));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(check_d_length) {
  char str1[256] = "";
  char str2[256] = "";
  long long src = (_i * ((412ll * 312) << 16) * 31);
  s21_sprintf(str1, "%hd", (short)src);
  sprintf(str2, "%hd", (short)src);
  ck_assert_str_eq(str1, str2);
  s21_sprintf(str1, "%ld", (long)src);
  sprintf(str2, "%ld", (long)src);
  ck_assert_str_eq(str1, str2);
  // s21_sprintf(str1, "%Ld", (long long)src);
  // sprintf(str2, "%Ld", (long long)src);
  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_f_length) {
  char str1[256] = "";
  char str2[256] = "";
  long double src = _i * (((98481672 * _i) << 12) / (double)(127772 << 14));
  ck_assert_int_eq(s21_sprintf(str1, "%lf", (double)src),
                   sprintf(str2, "%lf", (double)src));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%Lf", src), sprintf(str2, "%Lf", src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(check_s_length) {
//     char str1[256] = "";
//     char str2[256] = "";
//     wchar_t src[256] = {0};
//     for (int i = 0; i < 64; i++) {
//         src[i] = (wchar_t)((_i + i * ((4761234 + i * i) << 8)));
//     }
//     ck_assert_int_eq(s21_sprintf(str1, "%ls", src), sprintf(str2, "%ls",
//     src)); ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(check_u_length) {
  char str1[256] = "";
  char str2[256] = "";
  long long unsigned int src =
      (long long unsigned)(_i * ((412374612llu * _i) << 16) * 3167);
  ck_assert_int_eq(s21_sprintf(str1, "%hu", (short unsigned)src),
                   sprintf(str2, "%hu", (short unsigned)src));
  ck_assert_str_eq(str1, str2);
  memset(str1, 0, 256);
  memset(str2, 0, 256);
  ck_assert_int_eq(s21_sprintf(str1, "%lu", (long unsigned)src),
                   sprintf(str2, "%lu", (long unsigned)src));
  ck_assert_str_eq(str1, str2);
  // memset(str1, 0, 256);
  // memset(str2, 0, 256);
  // s21_sprintf(str1, "%Lu", (long long unsigned)src);
  // sprintf(str2, "%Lu", (long long unsigned)src);
  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_c_width_number_flag) {
  char flags[] = "-+ #";
  char str1[256] = "";
  char str2[256] = "";
  char src = 'A';
  char fmt[10] = "";
  sprintf(fmt, "%%%c%dc", flags[_i % 4], _i);
  ck_assert_int_eq(s21_sprintf(str1, fmt, src), sprintf(str2, fmt, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_d_width_number_flag) {
  char flags[] = "-+ #0";
  char str1[256] = "";
  char str2[256] = "";
  int src = 1234;
  char fmt[10] = "";
  sprintf(fmt, "%%%c%dd", flags[_i % 5], _i);
  ck_assert_int_eq(s21_sprintf(str1, fmt, src), sprintf(str2, fmt, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_f_width_number_flag) {
  char flags[] = "-+ #0";
  char str1[256] = "";
  char str2[256] = "";
  double src = 12.345;
  char fmt[10] = "";
  sprintf(fmt, "%%%c%df", flags[_i % 5], _i);
  ck_assert_int_eq(s21_sprintf(str1, fmt, src), sprintf(str2, fmt, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_u_width_number_flag) {
  char flags[] = "-+ #0";
  char str1[256] = "";
  char str2[256] = "";
  unsigned src = 1234;
  char fmt[10] = "";
  sprintf(fmt, "%%%c%du", flags[_i % 5], _i);
  ck_assert_int_eq(s21_sprintf(str1, fmt, src), sprintf(str2, fmt, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(check_s_width_number_flag) {
  char flags[] = "-+ #";
  char str1[256] = "";
  char str2[256] = "";
  char src[] = "UwU";
  char fmt[10] = "";
  sprintf(fmt, "%%%c%ds", flags[_i % 4], _i);
  ck_assert_int_eq(s21_sprintf(str1, fmt, src), sprintf(str2, fmt, src));
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *sprintf_suite(void) {
  Suite *s = suite_create("SPRINTF");
  TCase *tc_specifiers = tcase_create("Specifiers case");
  TCase *tc_width = tcase_create("Width case");
  TCase *tc_precision = tcase_create("Precision case");
  TCase *tc_length = tcase_create("Length case");
  TCase *tc_flag = tcase_create("Flag case");
  tcase_add_loop_test(tc_specifiers, check_c, 0, 128);
  tcase_add_loop_test(tc_specifiers, check_d, 0, 128);
  tcase_add_loop_test(tc_specifiers, check_f, 0, 128);
  tcase_add_loop_test(tc_specifiers, check_s, 0, 16);
  tcase_add_loop_test(tc_specifiers, check_u, 0, 128);
  tcase_add_loop_test(tc_width, check_c_width_number, 0, 32);
  tcase_add_loop_test(tc_width, check_c_width_star, 0, 32);
  tcase_add_loop_test(tc_width, check_d_width_number, 0, 32);
  tcase_add_loop_test(tc_width, check_d_width_star, 0, 32);
  tcase_add_loop_test(tc_width, check_f_width_number, 0, 32);
  tcase_add_loop_test(tc_width, check_f_width_star, 0, 32);
  tcase_add_loop_test(tc_width, check_s_width_number, 0, 32);
  tcase_add_loop_test(tc_width, check_s_width_star, 0, 32);
  tcase_add_loop_test(tc_width, check_u_width_number, 0, 32);
  tcase_add_loop_test(tc_width, check_u_width_star, 0, 32);
  tcase_add_loop_test(tc_precision, check_d_precision_number, 0, 32);
  tcase_add_loop_test(tc_precision, check_d_precision_star, 0, 32);
  tcase_add_loop_test(tc_precision, check_f_precision_number, 0, 18);
  tcase_add_loop_test(tc_precision, check_f_precision_star, 0, 18);
  tcase_add_loop_test(tc_precision, check_s_precision_number, 0, 32);
  tcase_add_loop_test(tc_precision, check_s_precision_star, 0, 32);
  tcase_add_loop_test(tc_precision, check_u_precision_number, 0, 32);
  tcase_add_loop_test(tc_precision, check_u_precision_star, 0, 32);
  tcase_add_loop_test(tc_length, check_d_length, 0, 128);
  tcase_add_loop_test(tc_length, check_f_length, 0, 128);
  // tcase_add_loop_test(tc_length, check_s_length, 0, 16);
  // tcase_add_loop_test(tc_length, check_c_length, 0, 128);
  tcase_add_loop_test(tc_length, check_u_length, 0, 128);
  tcase_add_loop_test(tc_flag, check_c_width_number_flag, 0, 32);
  tcase_add_loop_test(tc_flag, check_d_width_number_flag, 0, 32);
  tcase_add_loop_test(tc_flag, check_f_width_number_flag, 0, 32);
  tcase_add_loop_test(tc_flag, check_s_width_number_flag, 0, 32);
  tcase_add_loop_test(tc_flag, check_u_width_number_flag, 0, 32);
  suite_add_tcase(s, tc_specifiers);
  suite_add_tcase(s, tc_width);
  suite_add_tcase(s, tc_precision);
  suite_add_tcase(s, tc_length);
  suite_add_tcase(s, tc_flag);
  return s;
}
