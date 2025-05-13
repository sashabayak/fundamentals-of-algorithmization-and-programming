#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

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
void enqueueFront(char ch);
void enqueueRear(char ch);
char dequeueFront();
char dequeueRear();
void displayQueue();
void clearQueue();

#endif // QUEUE_H
