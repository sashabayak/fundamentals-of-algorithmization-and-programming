#include "queue.h"
#include "utilis.h"

struct QueueNode* front = NULL;
struct QueueNode* rear = NULL;
int maxSize = 0;    
int currentSize = 0;  

void initQueue() {
    printf("Enter maximum queue size: ");
    inputNumberPositive(&maxSize);
    front = rear = NULL;
    currentSize = 0;
    printf("Queue initialized with max size: %d\n", maxSize);
}

void showLeftSymbol(int count) {
    int t = 0;
    struct QueueNode* current = front;
    while (t != count) {
        current = current->next;
        t++;
    }
    printf(" %c\n", current->data);
}

void enqueue(char ch) {
    if (currentSize >= maxSize) {
        printf("Queue is full!\n");
        return;
    }

    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = ch;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (front == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
    currentSize++;
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct QueueNode* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void clearQueue() {
    struct QueueNode* temp;
    while (front != NULL) {
        temp = front;
        front = front->next;
        free(temp);
    }
    rear = NULL;
    currentSize = 0;
    printf("Queue cleared!\n");
}