#include "queue.h"

struct QueueNode* front = NULL;
struct QueueNode* rear = NULL;
int maxSize = 0;    
int currentSize = 0;  

void initQueue() {
    printf("Enter maximum queue size: ");
    scanf_s("%d", &maxSize); 
    getchar(); 
    front = rear = NULL;
    currentSize = 0;
    printf("Queue initialized with max size: %d\n", maxSize);
}

void enqueueFront(char ch) {
    if (currentSize >= maxSize) {
        printf("Queue is full! Cannot enqueue at front.\n");
        return;
    }
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = ch;
    newNode->next = front;
    newNode->prev = NULL;

    if (front == NULL) {
        rear = newNode; 
    }
    else {
        front->prev = newNode;
    }
    front = newNode; 
    currentSize++;
}

void enqueueRear(char ch) {
    if (currentSize >= maxSize) {
        printf("Queue is full! Cannot enqueue at rear.\n");
        return;
    }
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = ch;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear == NULL) {
        front = newNode; 
    }
    else {
        rear->next = newNode; 
    }
    rear = newNode; 
    currentSize++;
}

char dequeueFront() {
    if (front == NULL) {
        printf("Queue is empty! Cannot dequeue from front.\n");
        return '\0'; 
    }
    struct QueueNode* temp = front;
    char data = temp->data;
    front = front->next;

    if (front != NULL) {
        front->prev = NULL; 
    }
    else {
        rear = NULL;
    }
    free(temp);
    currentSize--;
    return data;
}

char dequeueRear() {
    if (rear == NULL) {
        printf("Queue is empty! Cannot dequeue from rear.\n");
        return '\0';
    }
    struct QueueNode* temp = rear;
    char data = temp->data;
    rear = rear->prev;

    if (rear != NULL) {
        rear->next = NULL; 
    }
    else {
        front = NULL;
    }
    free(temp);
    currentSize--;
    return data;
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
