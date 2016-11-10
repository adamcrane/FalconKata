#include <stdlib.h>
#include "infix.h"

struct Infix
{
	char *representation;
};

Infix *init_with_infix_string(char *infix_string)
{
	Infix *I = malloc(sizeof(Infix));

	if (I == NULL)
	{
		return NULL;
	}

	I->representation = infix_string;
	return I;
}

char *convert_to_rpn(Infix *Infix){
	return "ab+";
}