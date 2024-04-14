#include "../s21_string_test.h"

START_TEST(check_const_found) {
  char haystack[256] =
      "iJ71Ffdz9UytLIXfOZiaiq7vlmlcFTF0YZTTsGwfKezWCtwbXhA4tWKFGa7jOkTbrIFV4K"
      "rvWmrt7kThXH5tyk4AVdvvwi9qBBCIrGIrqRUA077R3Vn2ZHuiBEKdndAmLUdmNbv2c5vX"
      "BDxkWOKDsW7SqZb7gMdxZhb338GiJgMgcG9Z3Fkw5W3MNrvvniJI62Km2hJUPaNewE850R"
      "clec1crVTc3s4xTdg98RstDGshdz4cAbF8JnZdsA57O";
  char needle_start[] = "iJ71Ffdz9Uy";
  char needle_end[] = "ZdsA57O";
  char needle_mid[] = "077R3Vn2ZHuiBEKdndAmLUdm";
  ck_assert_ptr_eq(s21_strstr(haystack, needle_start),
                   strstr(haystack, needle_start));
  ck_assert_ptr_eq(s21_strstr(haystack, needle_mid),
                   strstr(haystack, needle_mid));
  ck_assert_ptr_eq(s21_strstr(haystack, needle_end),
                   strstr(haystack, needle_end));
}
END_TEST

START_TEST(check_const_not_found) {
  char haystack[256] =
      "iJ71Ffdz9UytLIXfOZiaiq7vlmlcFTF0YZTTsGwfKezWCtwbXhA4tWKFGa7jOkTbrIFV4K"
      "rvWmrt7kThXH5tyk4AVdvvwi9qBBCIrGIrqRUA077R3Vn2ZHuiBEKdndAmLUdmNbv2c5vX"
      "BDxkWOKDsW7SqZb7gMdxZhb338GiJgMgcG9Z3Fkw5W3MNrvvniJI62Km2hJUPaNewE850R"
      "clec1crVTc3s4xTdg98RstDGshdz4cAbF8JnZdsA57OG";
  char needle[3] = "";
  for (int i = 0; i < 47; i++) {
    needle[0] = i;
    needle[1] = i + 1;
    needle[2] = 0;
    ck_assert_ptr_null(s21_strstr(haystack, needle));
  }
}
END_TEST

Suite *strstr_suite(void) {
  Suite *s = suite_create("STRSTR");
  TCase *tc_const = tcase_create("Const case");
  tcase_add_test(tc_const, check_const_found);
  tcase_add_test(tc_const, check_const_not_found);
  suite_add_tcase(s, tc_const);
  return s;
}
