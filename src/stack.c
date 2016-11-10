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
	node->next = stack->top;
	stack->top = node;
}

char *pop(Stack *stack)
{
	Node *tempNode;
	char *value;

	if (stack->top == NULL)
	{
		free(tempNode);
		free(value);
		
		exit(0);
	}

	tempNode = stack->top;
	value = tempNode->value;
	stack->top = tempNode->next;
	free(tempNode);

	return value;
}