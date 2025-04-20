#include <stdio.h>
#include "utilis.h"


int compareStrings(const char* str1, const char* str2, int n) {
    for (int i = 0; i < n; i++) {
        if (str1[i] == '\0' && str2[i] == '\0') {
            return 0;
        }
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return 0;
}



int inputIncreasingNumbers(int* n, struct Stack* begin) {
    while (1) {

        if (inputNumber(n) == -1) {
            return -1;
        }
        
        if (!isIncreasing(*n, begin)) {
            puts("Mistake!!!\nEnter a number bigger than the privious one.");
        }

        else {
            return 0;
        }

    }
}

int inputNumber(int* n) {
    char input[100];
    while (1) {
        int sign;
        int isValid = 1;
        int i = 0;

        puts("Enter an integer number (or type 'exit' to finish):");
        fgets(input, sizeof(input), stdin);

        if (compareStrings(input, "exit", 4) == 0) {
            return -1;
        }


        while (input[i] == ' ') {
            i++;
        }

        if (input[i] == '\0' || input[i] == '\n') {
            isValid = 0;
        }

        if (input[i] == '-' || input[i] == '+') {
            i++;
        }

        while (input[i] != '\0' && input[i] != '\n') {
            if (input[i] < '0' || input[i] > '9') {
                isValid = 0;
                break;
            }
            i++;
            if (i > 10) {
                isValid = 0;
                break;
            }
        }

        if (!isValid) {
            puts("Mistake. Please, enter an integer number, with the amount of characters not bigger then 10 ( not counting the '-' or '+'.");
        }
        else {
            *n = 0;
            i = 0;
            while (input[i] == ' ') {
                i++;
            }
            sign = 1;
            if (input[i] == '-') {
                sign = -1;
                i++;
            }
            else if (input[i] == '+') {
                i++;
            }
            while (input[i] != '\0' && input[i] != '\n') {
                *n = *n * 10 + (input[i] - '0');
                i++;
            }
            *n *= sign;
            return 0;
        }
    }
}

int inputNumberNoNegative(int* n) {
    while (1) {
        if (inputNumber(n) == -1) {
            return -1;
        }
        if (*n < 0) {
            puts("Enter a non negative number.");
        }
        else {
            return 0;
        }
    }
}

void enteringFunction(struct Stack** begin1, struct Stack** begin2) {
    int size1, size2;

    puts("Enter the maximum size of the first stack");
    inputNumberNoNegative(&size1);

    puts("Enter the maximum size of the second stack");
    inputNumberNoNegative(&size2);

    puts("Fill the first stack. One by one.");
    fillStack(begin1, size1);

    puts("First stack is sucsessfully filled.\n\n");

    puts("Fill the second stack. One by one.");
    fillStack(begin2, size2);
}


void printBothStacks(struct Stack* begin1, struct Stack* begin2) {
    puts("Elements from the first stack:");
    printStack(begin1);
    puts("Elements from the second stack:");
    printStack(begin2);
}