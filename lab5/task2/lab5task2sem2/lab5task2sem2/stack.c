#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int isIncreasing(int value, struct Stack* begin) {
    if (begin == NULL) {
        return 1; 
    }
    return value > begin->info; 
}

void printStack(struct Stack* top) {
    if (isEmpty(top)) {
        puts("Stack is empty.");
        return;
    }

    struct Stack* current = top;
    puts("Stack contents (from the top to bottom):");
    while (current != NULL) {
        printf("%d ", current->info);
        current = current->next;
    }
    printf("\n");
}


void push(struct Stack** begin, int value) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    if (newNode == NULL) {
        puts("Error in memory!\n");
        return;
    }
    newNode->info = value;
    newNode->next = *begin;
    *begin = newNode;
}

void freeStack(struct Stack** begin) {
    if (begin == NULL) return;  

    while (*begin != NULL) {
        struct Stack* temp = *begin;
        *begin = (*begin)->next;
        free(temp);
    }
}



void fillStack(struct Stack** begin, int maxSize) {
    int value;
    for (int i = 0; i < maxSize; i++) {
        if (inputIncreasingNumbers(&value, *begin) == -1) {
            break;
        }
        push(begin, value);
    }
}

int pop(struct Stack** top) {
    if (*top == NULL) {
        return -1; 
    }
    struct Stack* temp = *top;
    int value = temp->info;
    *top = (*top)->next;
    free(temp);
    return value;
}

int isEmpty(struct Stack* top) {
    return top == NULL;
}

void sortStacks(struct Stack** stack1, struct Stack** stack2, struct Stack** sortedStack) {
    struct Stack* tempStack = NULL;

  
    while (!isEmpty(*stack1)) {
        int value = pop(stack1);
        while (!isEmpty(tempStack) && tempStack->info <value) {
            push(stack1, pop(&tempStack));
        }
        push(&tempStack, value);
    }

   
    while (!isEmpty(*stack2)) {
        int value = pop(stack2);
        while (!isEmpty(tempStack) && tempStack->info <value) {
            push(stack2, pop(&tempStack));
        }
        push(&tempStack, value);
    }

   
    while (!isEmpty(tempStack)) {
        push(sortedStack, pop(&tempStack));
    }
    puts("The combined elements of the first and the second stacks placed in the increasing order:");
    printStack(*sortedStack);
}