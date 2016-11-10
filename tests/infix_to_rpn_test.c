#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/infix.h"

START_TEST(converts_simple_addition)
{
	Infix * infix;
	infix = init_with_infix_string("a+b");
	ck_assert_str_eq(convert_to_rpn(infix), "ab+");
}
END_TEST

START_TEST(converts_simple_subtraction)
{
	Infix * infix;
	infix = init_with_infix_string("a-b");
	ck_assert_str_eq(convert_to_rpn(infix), "ab-");
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
	suite_add_tcase(s, tc_core);

	return s;
}

// int main(void)
// {
// 	int number_failed;
// 	SRunner *sr;

// 	sr = srunner_create(make_infix_to_rpn_suite());

// 	srunner_run_all(sr, CK_NORMAL);
// 	number_failed = srunner_ntests_failed(sr);
// 	srunner_free(sr);
// 	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
// }