#ifndef STACK_H
#define STACK_H

struct Stack {
    int info;               
    struct Stack* next;    
};

void push(struct Stack** begin, int value);
int contains(struct Stack* begin, int value);
void freeStack(struct Stack** begin);
void fillStack(struct Stack** begin, int maxSize);
void numbersOnlyInFirstStack(struct Stack* begin1, struct Stack* begin2);

#endif // STACK_H
