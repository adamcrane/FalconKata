#ifndef STACK_H
#define STACK_H

typedef struct Node Node;
typedef struct Stack Stack;


void initialize_stack(Stack *stack);
void push(Stack *stack, char *value);
char *pop(Stack *stack);

#endif /* STACK_H */