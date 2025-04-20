// Bayak, task2, variant3, 16.04.2025

#include <stdio.h>
#include "stack.h"
#include "utilis.h"

int main() {
    
    struct Stack* begin1 = NULL;
    struct Stack* begin2 = NULL;
    struct Stack* begin3 = NULL;

    enteringFunction(&begin1, &begin2);

    printBothStacks(begin1, begin2);

    sortStacks(&begin1, &begin2, &begin3);

    
    freeStack(&begin1);
    
    freeStack(&begin2);
    
    freeStack(&begin3);

    return 0;
}
