#include <stdlib.h>
#include "stack.h"

struct Node
{
	Node *next;
	char *value;
}*top;

void initialize_stack()
{
	top = NULL;
}

void push(char* value)
{
	Node *node;
	node = (Node *)malloc(sizeof(Node));
	node->value = value;
	if(top == NULL)
	{
		top = node;
		top->next = NULL;
	}
	else 
	{
		node->next = top;
		top = node;
	}
}

int is_empty()
{
	if(top == NULL)
	{
		return 1;
	}
	return 0;
}

char *pop()
{
	if(top == NULL)
	{
		exit(0);
	}
	Node *temp;
	temp = top;
	top = top->next;
	return temp->value;
}