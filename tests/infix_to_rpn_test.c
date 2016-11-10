#include <check.h>
#include <stdio.h>
#include <stdlib.h>

START_TEST(test_hello_world)
{
	ck_assert(1);
}
END_TEST

Suite * infix_to_rpn_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Infix to RPN");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_hello_world);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s= infix_to_rpn_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}