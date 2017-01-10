#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/stack.h"

START_TEST(test_can_push_and_pop_item_from_stack)
{
	initialize_stack();
	push("a");
	ck_assert_str_eq(pop(), "a");
}
END_TEST

START_TEST(test_can_push_and_pop_two_items_from_stack)
{
	initialize_stack();
	push("a");
	push("b");
	ck_assert_str_eq(pop(), "b");
	ck_assert_str_eq(pop(), "a");
}
END_TEST

START_TEST(doesnt_blow_up_when_popping_an_empty_stack)
{
	initialize_stack();
	pop();
}
END_TEST

START_TEST(test_can_peek_top_of_stack)
{
	initialize_stack();
	push("a");
	push("b");
	ck_assert_str_eq(peek(), "b");
}
END_TEST

Suite * make_stack_building_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Stack");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_can_push_and_pop_item_from_stack);
	tcase_add_test(tc_core, test_can_push_and_pop_two_items_from_stack);
	tcase_add_test(tc_core, doesnt_blow_up_when_popping_an_empty_stack);
	tcase_add_test(tc_core, test_can_peek_top_of_stack);
	suite_add_tcase(s, tc_core);

	return s;
}