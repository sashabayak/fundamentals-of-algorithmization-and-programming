#ifndef UTILS_H
#define UTILS_H


int compareStrings(const char* str1, const char* str2, int n);
int inputNumber(int* n);
int inputNumberNoNegative(int* n);
void enteringFunction(struct Stack** begin1, struct Stack** begin2);
int inputIncreasingNumbers(int* n, struct Stack* begin);
void printBothStacks(struct Stack* begin1, struct Stack* begin2);

#endif 
