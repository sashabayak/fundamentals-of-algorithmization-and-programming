#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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

int contains(struct Stack* begin, int value) {
    struct Stack* current = begin; 
    while (current != NULL) {
        if (current->info == value) {
            return 1; 
        }
        current = current->next; 
    }
    return 0; 
}

void freeStack(struct Stack** begin) {
    while (*begin != NULL) {
        struct Stack* temp = *begin;
        *begin = (*begin)->next;
        free(temp);
    }
}

void fillStack(struct Stack** begin, int maxSize) {
    int value;
    for (int i = 0; i < maxSize; i++) {
        if (inputNumber(&value) == -1) {
            break; 
        }
        push(begin, value);
    }
}

void numbersOnlyInFirstStack(struct Stack* begin1, struct Stack* begin2) {
    struct Stack* current = NULL;

    puts("Elements from the first stack which are not met in the second stack:");

    current = begin1;
    while (current != NULL) {
        if (!contains(begin2, current->info)) {
            printf("%d ", current->info);
        }
        current = current->next;
    }
    printf("\n");
}