//Баяк, Вариант 13, задание 1, 12 апреля

#include <stdio.h>
#include "stack.h"
#include "utilis.h"

int main() {
    
    struct Stack* begin1 = NULL; 
    struct Stack* begin2 = NULL;

    enteringFunction(&begin1, &begin2);

    numbersOnlyInFirstStack(begin1, begin2);

    freeStack(&begin1);
    freeStack(&begin2);

    return 0;
}

