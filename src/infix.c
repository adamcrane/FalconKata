#include <stdlib.h>
#include <stdio.h>
#include "infix.h"
#include "stack.h"

char* convert_to_rpn(char infix[])
{
	initialize_stack();
	char* rpn = (char *)malloc(sizeof(infix));
	int currentPosition = 0;
	int i;
	for(i = 0; infix[i] != '\0'; i++)
	{
		if(is_operator(&infix[i]) == 1)
		{
			while(has_precedence(&infix[i], peek())){
				rpn[currentPosition] = *pop();
				currentPosition++;
			}
			push(&infix[i]);
		}
		else
		{
			rpn[currentPosition] = infix[i];
			currentPosition++;
		}
	}

	while(is_empty() != 1)
	{
		rpn[currentPosition] = *pop();
		currentPosition++;
	}

	return rpn;
}

int is_operator(char* character)
{
	if(*character == '+' || *character == '-'
	 || *character == '*' || *character == '/')
	{
		return 1;
	}
	return 0;
}

int has_precedence(char* candidate, char* top)
{
	if(*candidate == '-' || *candidate == '+')
	{
		return 0;
	}
	return 1;
}