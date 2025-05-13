#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct QueueNode {
    char data;
    struct QueueNode* next;
    struct QueueNode* prev;
};

extern struct QueueNode* front;
extern struct QueueNode* rear;
extern int maxSize;
extern int currentSize;

void initQueue();
void enqueue(char ch);
void displayQueue();
void clearQueue();
void showLeftSymbol(int count);

#endif // QUEUE_H
