testsmake: master_suite.c
	gcc -o tests infix_to_rpn_test.c stack_test.c is_operator_tests.c has_precedence_tests.c ../src/infix.c ../src/stack.c master_suite.c `pkg-config --cflags --libs check` -std=c99

clean:
	@rm -f tests