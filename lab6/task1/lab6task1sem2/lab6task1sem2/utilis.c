#include "utilis.h"
#include <stdio.h>
#include <stdlib.h>

int inputNumber(int* n) {
    char input[100];
    while (1) {
        int sign;
        int isValid = 1;
        int i = 0;

        puts("Enter an integer number:");
        fgets(input, sizeof(input), stdin);

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
            puts("Mistake. Please, enter an integer number, with the amount of characters not bigger than 10 (not counting the '-' or '+').");
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

int inputNumberPositive(int* n) {
    while (1) {
        inputNumber(n);
        if (*n <= 0) {
            puts("Enter a positive number.");
        }
        else {
            return 0;
        }
    }
}
