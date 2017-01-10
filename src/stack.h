#ifndef STACK_H
#define STACK_H

typedef struct Node Node;

void initialize_stack();
void push(char *value);
char *pop();
int is_empty();

#endif /* STACK_H */