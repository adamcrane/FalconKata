#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/stack.h"

START_TEST(test_can_push_and_pop_item_from_stack)
{
	Stack *stack;
	initialize_stack(stack);
	push(stack, "a");
	ck_assert_str_eq(pop(stack), "a");
}
END_TEST

Suite * make_stack_building_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Stack");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_can_push_and_pop_item_from_stack);
	suite_add_tcase(s, tc_core);

	return s;
}