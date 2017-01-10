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
			push(&infix[i]);
		}
		else
		{
			rpn[currentPosition] = infix[i];
			currentPosition++;
		}//if is operator
			//while(infix[i] has lower precedence than top)
				//pop and append to rpn
			//push(infix[i])

		// if(infix[i] != '+' && infix[i] != '-')
		// {

		// 	continue;
		// }
		
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
	if(*character == '+' || *character == '-')
	{
		return 1;
	}
	return 0;
}