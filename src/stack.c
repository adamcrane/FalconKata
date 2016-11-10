#include <stdlib.h>
#include "stack.h"

struct Node
{
	Node *next;
	char *value;
};

struct Stack
{
	Node *top;
};

void initialize_stack(Stack *stack)
{
	stack->top = NULL;
}

void push(Stack *stack, char *value)
{
	Node *node;
	node = (Node *)malloc(sizeof(Node));

	if (node == NULL)
	{
		exit(1);
	}

	node->value = value;
	stack->top = node;
}

char *pop(Stack *stack)
{
	return stack->top->value;
}