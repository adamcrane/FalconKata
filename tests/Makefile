testsmake: infix_to_rpn_test.c
	gcc -o tests infix_to_rpn_test.c ../src/infix.c `pkg-config --cflags --libs check`

clean:
	@rm -f tests