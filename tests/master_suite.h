#ifndef MASTERSUITE_H
#define MASTERSUITE_H

#include <check.h>

Suite *make_infix_to_rpn_suite(void);
Suite *make_stack_building_suite(void);
Suite *make_is_operator_suite(void);
Suite *make_has_precedence_suite(void);

#endif /* MASTERSUITE_H */