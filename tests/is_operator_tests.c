#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/infix.h"

START_TEST(knows_plus_is_operator)
{
	ck_assert_int_eq(is_operator("+"), 1);
}
END_TEST

START_TEST(knows_minus_is_operator)
{
	ck_assert_int_eq(is_operator("-"), 1);
}
END_TEST

START_TEST(knows_multiply_is_operator)
{
	ck_assert_int_eq(is_operator("*"), 1);
}
END_TEST

START_TEST(knows_divide_is_operator)
{
	ck_assert_int_eq(is_operator("/"), 1);
}
END_TEST

Suite *make_is_operator_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Is Operator");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, knows_plus_is_operator);
	tcase_add_test(tc_core, knows_minus_is_operator);
	tcase_add_test(tc_core, knows_multiply_is_operator);
	tcase_add_test(tc_core, knows_divide_is_operator);
	suite_add_tcase(s, tc_core);

	return s;
}