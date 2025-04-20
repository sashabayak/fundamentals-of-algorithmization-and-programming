#ifndef STACK_H
#define STACK_H

struct Stack {
    int info;
    struct Stack* next;
};

void printStack(struct Stack* top);
int isIncreasing(int value, struct Stack* begin);
void push(struct Stack** begin, int value);
void freeStack(struct Stack** begin);
void fillStack(struct Stack** begin, int maxSize);
int pop(struct Stack** top);
int isEmpty(struct Stack* top);
void sortStacks(struct Stack** stack1, struct Stack** stack2, struct Stack** sortedStack);


#endif 

