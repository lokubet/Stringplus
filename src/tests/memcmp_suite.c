#include "../s21_string_test.h"

static const char const_string[][101] = {
    "Kw4wdEgxx9RQW@Bv)pe0cc2uUx!x]*Um+Y]u_^YKR7JfGAu>}M_G*kr=fWa?E2!B!8+_7D="
    "12G_?d+:M+!t43C3H1orKH~u@Q#.*",
    "4WAU3Wr!QFaex^k}wkK0a2,GWz#!xj6Z8Qg.+des~@c.*ZN%%aN}0kXrhead16qiboX7km=F.?"
    "irh]=7D_YopqwMLT4D*zM9yQXB_",
    "p2T>uZg7FZfD941in^wTwk@=j3E9]H-?@R]!_pGaRvce]Kob,=vCom!vw0qvv^g3K7.2k_"
    "U7VdYiaG7DAUva!>>-c:Fz~qB6]cV.",
    "+]FRyyd8fg>HK,M1Dn.qn!7-+BDU2YoiefbGED8rMFzZadgF]ggZV-Lgt8YGy3+rEJvm2BbEv+"
    "hZ+6qcUa4U8.>wt#cnL9k]:quf",
    ",Jq>#YKL2M0hX}TtP2bLN12ZZCjQ*5ib~e~M!zn>Lc0kd}Ri3D6r]qZH@cm==K)CaX+wBg>"
    "xofokeKP@v=H!L=n:}EL@xWjsE.=g",
    "Kw4wdEgxx9RQW@Bv)pe0cc2uUx!x]*Um+Y]u_^YKR7JfGAu>}M_G*kr=fWa?E2!B!8+_7D="
    "12G_?d+:M+!t43C3H1orKH~u@Q#.*",
    "4WAU3Wr!QFaex^k}wkK0a2,GWz#!xj6Z8Qg.+des~@c.*ZN%%aN}0kXrhead16qiboX7km=F.?"
    "irh]=7D_YopqwMLT4D*zM9yQXB_",
    "p2T>uZg7FZfD941in^wTwk@=j3E9]H-?@R]!_pGaRvce]Kob,=vCom!vw0qvv^g3K7.2k_"
    "U7VdYiaG7DAUva!>>-c:Fz~qB6]cV.",
    "+]FRyyd8fg>HK,M1Dn.qn!7-+BDU2YoiefbGED8rMFzZadgF]ggZV-Lgt8YGy3+rEJvm2BbEv+"
    "hZ+6qcUa4U8.>wt#cnL9k]:quf",
    ",Jq>#YKL2M0hX}TtP2bLN12ZZCjQ*5ib~e~M!zn>Lc0kd}Ri3D6r]qZH@cm==K)CaX+wBg>"
    "xofokeKP@v=H!L=n:}EL@xWjsE.=g"};

START_TEST(check_const_identical) {
  ck_assert_int_eq(s21_memcmp(const_string[_i], const_string[_i + 5], 101),
                   memcmp(const_string[_i], const_string[_i + 5], 101));
}
END_TEST

START_TEST(check_const_diff) {
  for (int j = 0; j < 10; j == _i - 1 ? j += 2 : j++) {
    ck_assert_int_eq(s21_memcmp(const_string[j], const_string[_i], 101),
                     memcmp(const_string[j], const_string[_i], 101));
  }
}
END_TEST

START_TEST(check_dyn_identical) {
  memset(test_string, 0, 129);
  memset(test_string2, 0, 129);
  memset(test_string, _i, _i);
  memset(test_string2, _i, _i);
  ck_assert_int_eq(s21_memcmp(test_string, test_string2, 129),
                   memcmp(test_string, test_string2, 129));
}
END_TEST

START_TEST(check_dyn_diff) {
  memset(test_string, 0, 129);
  memset(test_string2, 0, 129);
  memset(test_string, _i, _i);
  memset(test_string2, 128 - _i, _i);
  ck_assert_int_eq(s21_memcmp(test_string, test_string2, 129),
                   memcmp(test_string, test_string2, 129));
}
END_TEST

START_TEST(check_zero) {
  ck_assert_int_eq(s21_memcmp(test_string, test_string2, 0),
                   memcmp(test_string, test_string2, 0));
}
END_TEST

Suite *memcmp_suite(void) {
  Suite *s = suite_create("MEMCMP");
  TCase *tc_const = tcase_create("Const case");
  tcase_add_loop_test(tc_const, check_const_identical, 0, 5);
  tcase_add_loop_test(tc_const, check_const_diff, 1, 5);
  TCase *tc_dyn = tcase_create("Dynamic case");
  tcase_add_checked_fixture(tc_dyn, setup_128, teardown);
  tcase_add_loop_test(tc_dyn, check_dyn_identical, 0, 128);
  tcase_add_loop_test(tc_dyn, check_dyn_diff, 1, 128);
  TCase *tc_var = tcase_create("Various case");
  tcase_add_checked_fixture(tc_var, setup_16, teardown);
  tcase_add_loop_test(tc_var, check_zero, 0, 128);
  suite_add_tcase(s, tc_const);
  suite_add_tcase(s, tc_dyn);
  suite_add_tcase(s, tc_var);
  return s;
}
