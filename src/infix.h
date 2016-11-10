#ifndef INFIX_H
#define INFIX_H

typedef struct Infix Infix;

Infix *init_with_infix_string(char* infix_string);
char *convert_to_rpn(Infix * infix);

#endif /* INFIX_H */