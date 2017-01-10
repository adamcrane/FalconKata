#ifndef INFIX_H
#define INFIX_H

char *convert_to_rpn(char infix[]);
int is_operator(char* character);
int has_precedence(char* candidate, char* top);
#endif /* INFIX_H */