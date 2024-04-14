#include "../s21_string_test.h"

START_TEST(check_const) {
  char str[][64] = {
      "HWkA$TA(MJY0)Z3(A#07zaF,yKf(120=",  "$9Y20hPJr!M:7Gx@@f1-@1$*]UV93qB}",
      "m/ymZfLwgY,$S+Luxm#9@8n%%;1EW-_?1", "JLjwQX&)ahH!/L_DN*N]VPR!*@J,gy,T",
      "M46_%%xg8Zfky4=ZbVcXtw8rMPw-gi(Yh", "mdhccZNxm$6K_,W8;?yFzdKm{HKLN11g",
      "5=+n$hBz=VeN]AMA-vbC(HH7/u:?!S@C",  "2g&g,ABXa80$VT[mn}ykVwPrjHY-D}7)",
      "g?Sz=YexHLXidBz!,x8:-tLq{*5aE.uF",  "]f1!@9(qeN[fvx],7/Dd)mYJ}Nf1D%%7F"};
  char accept[32] = "";
  for (int i = 0; i < 31; i++) {
    accept[i] = (_i * ((_i * _i) + (1 << 30))) % 128;
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_ptr_eq(s21_strpbrk(str[i], accept), strpbrk(str[i], accept));
  }
}
END_TEST

START_TEST(check_dyn) {
  for (int i = 1; i < 126; i += 2) {
    memset(test_string + i - 1, i, 2);
  }
  *(test_string + 126) = 0;
  char accept[32] = "";
  for (int i = 0; i < 31; i++) {
    accept[i] = (_i * ((_i * _i) + (1 << 30))) % 128;
  }
  ck_assert_ptr_eq(s21_strpbrk(test_string, accept),
                   strpbrk(test_string, accept));
}
END_TEST

Suite *strpbrk_suite(void) {
  Suite *s = suite_create("STRPBRK");
  TCase *tc_const = tcase_create("Const case");
  TCase *tc_dyn = tcase_create("Dyn case");
  tcase_add_checked_fixture(tc_dyn, setup_128, teardown);
  tcase_add_loop_test(tc_const, check_const, 0, 128);
  tcase_add_loop_test(tc_dyn, check_dyn, 0, 128);
  suite_add_tcase(s, tc_const);
  suite_add_tcase(s, tc_dyn);
  return s;
}
