#include "../s21_string_test.h"

START_TEST(check_const_single) {
  char str[] =
      "vLQtC[][!RL?HHF3CBzVF*9e6AN%%MRg6x_Qqe(znQ[SNT+t;d6SPd6,{/"
      "t8=Eu+}P2)57)dA-0=M9VVx2E.3)7,4BcCX+A?4_]k*cn1}EP/"
      "F5v+X&3Pw7Tfj05(eGz[5Kk(7yfVmnEC9j)53ukB7MnR5!,V67XjQPv,64838&"
      "K3iawzTQh{N1]2$09Jdu4{AzB!]9EdCe)1df]UQ{-[7._zdkiBEiLxm3.G$HWFZ4Big9]"
      "WrZP[VZZjBK7kr*}b";
  char str2[] =
      "vLQtC[][!RL?HHF3CBzVF*9e6AN%%MRg6x_Qqe(znQ[SNT+t;d6SPd6,{/"
      "t8=Eu+}P2)57)dA-0=M9VVx2E.3)7,4BcCX+A?4_]k*cn1}EP/"
      "F5v+X&3Pw7Tfj05(eGz[5Kk(7yfVmnEC9j)53ukB7MnR5!,V67XjQPv,64838&"
      "K3iawzTQh{N1]2$09Jdu4{AzB!]9EdCe)1df]UQ{-[7._zdkiBEiLxm3.G$HWFZ4Big9]"
      "WrZP[VZZjBK7kr*}b";
  char delim[2] = "";
  delim[0] = _i % 128;
  char *s21_res = s21_strtok(str, delim);
  char *res = strtok(str2, delim);
  int found = 0;
  while (res != NULL) {
    found++;
    ck_assert_str_eq(s21_res, res);
    s21_res = s21_strtok(NULL, delim);
    res = strtok(NULL, delim);
  }
  ck_assert_msg(
      s21_res == NULL,
      "s21_res (%p) != NULL. found = %d. s21_res = \"%s\". delim = \"%s\".",
      (void *)s21_res, found, s21_res, delim);
}
END_TEST

START_TEST(check_const_single_start) {
  char str[] =
      "vLQtC[][!RL?HHF3CBzVF*9e6AN%%MRg6x_Qqe(znQ[SNT+t;d6SPd6,{/"
      "t8=Eu+}P2)57)dA-0=M9VVx2E.3)7,4BcCX+A?4_]k*cn1}EP/"
      "F5v+X&3Pw7Tfj05(eGz[5Kk(7yfVmnEC9j)53ukB7MnR5!,V67XjQPv,64838&"
      "K3iawzTQh{N1]2$09Jdu4{AzB!]9EdCe)1df]UQ{-[7._zdkiBEiLxm3.G$HWFZ4Big9]"
      "WrZP[VZZjBK7kr*}b";
  char str2[] =
      "vLQtC[][!RL?HHF3CBzVF*9e6AN%%MRg6x_Qqe(znQ[SNT+t;d6SPd6,{/"
      "t8=Eu+}P2)57)dA-0=M9VVx2E.3)7,4BcCX+A?4_]k*cn1}EP/"
      "F5v+X&3Pw7Tfj05(eGz[5Kk(7yfVmnEC9j)53ukB7MnR5!,V67XjQPv,64838&"
      "K3iawzTQh{N1]2$09Jdu4{AzB!]9EdCe)1df]UQ{-[7._zdkiBEiLxm3.G$HWFZ4Big9]"
      "WrZP[VZZjBK7kr*}b";
  char delim[2] = "";
  delim[0] = str[_i % strlen(str)];
  char *s21_res = s21_strtok(str, delim);
  char *res = strtok(str2, delim);
  int found = 0;
  while (res != NULL) {
    found++;
    ck_assert_str_eq(s21_res, res);
    s21_res = s21_strtok(NULL, delim);
    res = strtok(NULL, delim);
  }
  ck_assert_msg(
      s21_res == NULL,
      "s21_res (%p) != NULL. found = %d. s21_res = \"%s\". delim = \"%s\".",
      (void *)s21_res, found, s21_res, delim);
}
END_TEST

START_TEST(check_const_mult) {
  char str[] =
      "icK,Yv{K,8M@AhR@F2qpPy?+EwuDq,CPJ:qHegGz!*FY6]w{z+a0XnEyuwWuENL(iCt($"
      "80L)36@XQRq_F(5(9#U%%90#Y![raq={[3w++]1xH2P3B1?}nPiy3VnbTyB4B;PBR0i)"
      "n5xttt/&[]cF[#h2StbTQ6gJ4L-4-,&t9nrQ;HHQg3xLaw:%%Mq!nMx[%%#):.,)-aA_/"
      "-$H8Lc/9d=:Ci[-e4)Wum*%%f}mr+zKe=Q5U.cH](wyL5k36/!McD";
  char str2[] =
      "icK,Yv{K,8M@AhR@F2qpPy?+EwuDq,CPJ:qHegGz!*FY6]w{z+a0XnEyuwWuENL(iCt($"
      "80L)36@XQRq_F(5(9#U%%90#Y![raq={[3w++]1xH2P3B1?}nPiy3VnbTyB4B;PBR0i)"
      "n5xttt/&[]cF[#h2StbTQ6gJ4L-4-,&t9nrQ;HHQg3xLaw:%%Mq!nMx[%%#):.,)-aA_/"
      "-$H8Lc/9d=:Ci[-e4)Wum*%%f}mr+zKe=Q5U.cH](wyL5k36/!McD";
  char delim[10] = "";
  for (int i = 0; i < 9; i++) {
    delim[i] = (_i + 10 * i) % 128;
  }
  char *s21_res = s21_strtok(str, delim);
  char *res = strtok(str2, delim);
  int found = 0;
  while (res != NULL) {
    found++;
    ck_assert_str_eq(s21_res, res);
    s21_res = s21_strtok(NULL, delim);
    res = strtok(NULL, delim);
  }
  ck_assert_msg(
      s21_res == NULL,
      "s21_res (%p) != NULL. found = %d. s21_res = \"%s\". delim = \"%s\".",
      (void *)s21_res, found, s21_res, delim);
}
END_TEST

START_TEST(check_const_mult_start) {
  char str[] =
      "icK,Yv{K,8M@AhR@F2qpPy?+EwuDq,CPJ:qHegGz!*FY6]w{z+a0XnEyuwWuENL(iCt($"
      "80L)36@XQRq_F(5(9#U%%90#Y![raq={[3w++]1xH2P3B1?}nPiy3VnbTyB4B;PBR0i)"
      "n5xttt/&[]cF[#h2StbTQ6gJ4L-4-,&t9nrQ;HHQg3xLaw:%%Mq!nMx[%%#):.,)-aA_/"
      "-$H8Lc/9d=:Ci[-e4)Wum*%%f}mr+zKe=Q5U.cH](wyL5k36/!McD";
  char str2[] =
      "icK,Yv{K,8M@AhR@F2qpPy?+EwuDq,CPJ:qHegGz!*FY6]w{z+a0XnEyuwWuENL(iCt($"
      "80L)36@XQRq_F(5(9#U%%90#Y![raq={[3w++]1xH2P3B1?}nPiy3VnbTyB4B;PBR0i)"
      "n5xttt/&[]cF[#h2StbTQ6gJ4L-4-,&t9nrQ;HHQg3xLaw:%%Mq!nMx[%%#):.,)-aA_/"
      "-$H8Lc/9d=:Ci[-e4)Wum*%%f}mr+zKe=Q5U.cH](wyL5k36/!McD";
  char delim[10] = "";
  for (int i = 0; i < 9; i++) {
    delim[i] = str[i % _i % strlen(str)];
  }
  char *s21_res = s21_strtok(str, delim);
  char *res = strtok(str2, delim);
  int found = 0;
  while (res != NULL) {
    found++;
    ck_assert_str_eq(s21_res, res);
    s21_res = s21_strtok(NULL, delim);
    res = strtok(NULL, delim);
  }
  ck_assert_msg(
      s21_res == NULL,
      "s21_res (%p) != NULL. found = %d. s21_res = \"%s\". delim = \"%s\".",
      (void *)s21_res, found, s21_res, delim);
}
END_TEST

START_TEST(check_const_single_repeat) {
  char str[] =
      "abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh"
      "abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh"
      "abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh"
      "abcdefghabcdefghabcdefghabcdefghabcdefg";
  char str2[] =
      "abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh"
      "abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh"
      "abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh"
      "abcdefghabcdefghabcdefghabcdefghabcdefg";
  char delim[2] = "";
  delim[0] = str[_i + 'a' % 8];
  char *s21_res = s21_strtok(str, delim);
  char *res = strtok(str2, delim);
  int found = 0;
  while (res != NULL) {
    found++;
    ck_assert_str_eq(s21_res, res);
    s21_res = s21_strtok(NULL, delim);
    res = strtok(NULL, delim);
  }
  ck_assert_msg(
      s21_res == NULL,
      "s21_res (%p) != NULL. found = %d. s21_res = \"%s\". delim = \"%s\".",
      (void *)s21_res, found, s21_res, delim);
}
END_TEST

START_TEST(check_const_mult_repeat) {
  char str[] =
      "abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh"
      "abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh"
      "abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh"
      "abcdefghabcdefghabcdefghabcdefghabcdef";
  char str2[] =
      "abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh"
      "abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh"
      "abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh"
      "abcdefghabcdefghabcdefghabcdefghabcdef";
  char delim[10] = "";
  for (int i = 0; i < 4; i++) {
    delim[i] = str[_i % strlen(str)];
  }
  char *s21_res = s21_strtok(str, delim);
  char *res = strtok(str2, delim);
  int found = 0;
  while (res != NULL) {
    found++;
    ck_assert_str_eq(s21_res, res);
    s21_res = s21_strtok(NULL, delim);
    res = strtok(NULL, delim);
  }
  ck_assert_msg(
      s21_res == NULL,
      "s21_res (%p) != NULL. found = %d. s21_res = \"%s\". delim = \"%s\".",
      (void *)s21_res, found, s21_res, delim);
}
END_TEST

Suite *strtok_suite(void) {
  Suite *s = suite_create("STRTOK");
  TCase *tc_const = tcase_create("Const case");
  tcase_add_loop_test(tc_const, check_const_single, 0, 128);
  tcase_add_loop_test(tc_const, check_const_mult, 0, 128);
  tcase_add_loop_test(tc_const, check_const_single_start, 0, 128);
  tcase_add_loop_test(tc_const, check_const_mult_start, 1, 128);
  tcase_add_loop_test(tc_const, check_const_single_repeat, 0, 128);
  tcase_add_loop_test(tc_const, check_const_mult_repeat, 0, 128);
  suite_add_tcase(s, tc_const);
  return s;
}
