#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/infix.h"

START_TEST(converts_simple_addition)
{
	ck_assert_str_eq(convert_to_rpn("a+b"), "ab+");
}
END_TEST

START_TEST(converts_simple_subtraction)
{
	ck_assert_str_eq(convert_to_rpn("a-b"), "ab-");
}
END_TEST

START_TEST(converts_simple_subtraction_with_addition)
{
	ck_assert_str_eq(convert_to_rpn("a+b-c"), "abc-+");
}
END_TEST

START_TEST(converts_simple_subtraction_with_multiplication)
{
	ck_assert_str_eq(convert_to_rpn("a*b-c"), "ab*c-");
}
END_TEST

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

Suite *make_infix_to_rpn_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Infix to RPN");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, converts_simple_addition);
	tcase_add_test(tc_core, converts_simple_subtraction);
	tcase_add_test(tc_core, converts_simple_subtraction_with_addition);
	tcase_add_test(tc_core, converts_simple_subtraction_with_multiplication);
	tcase_add_test(tc_core, knows_plus_is_operator);
	tcase_add_test(tc_core, knows_minus_is_operator);
	suite_add_tcase(s, tc_core);

	return s;
}
