#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/infix.h"

START_TEST(plus_does_not_have_precedence_over_minus)
{
	ck_assert_int_eq(has_precedence("+", "-"), 0);
}
END_TEST

START_TEST(minus_does_not_have_precedence_over_plus)
{
	ck_assert_int_eq(has_precedence("-", "+"), 0);
}
END_TEST

START_TEST(multiply_has_precedence_over_plus)
{
	ck_assert_int_eq(has_precedence("*", "+"), 1);
}
END_TEST

Suite *make_has_precedence_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Precedence");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, plus_does_not_have_precedence_over_minus);
	tcase_add_test(tc_core, minus_does_not_have_precedence_over_plus);
	tcase_add_test(tc_core, multiply_has_precedence_over_plus);
	suite_add_tcase(s, tc_core);

	return s;
}