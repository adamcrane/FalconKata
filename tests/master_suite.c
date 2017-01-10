#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "master_suite.h"

int main(void)
{
	int number_failed;
	SRunner *sr;

	sr = srunner_create(make_infix_to_rpn_suite());
	srunner_add_suite(sr, make_stack_building_suite());
	srunner_add_suite(sr, make_is_operator_suite());
	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}