#include <stdlib.h>
#include <string.h>

#include "queue.h"

QUEUE queue_init_default(void) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return (QUEUE)queue;
}

int is_queue_empty(QUEUE hQ) {
    Queue* queue = (Queue*)hQ;
    return queue->front == NULL;
}

void enqueue(QUEUE hQ, int length, const char bank[]) {
    Queue* queue = (Queue*)hQ;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->length = length;
    strcpy(newNode->bank, bank);
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int service(QUEUE hQ) {
    Queue* queue = (Queue*)hQ;
    if (is_queue_empty(hQ)) {
        return -1;
    }
    Node* temp = queue->front;
    int length = temp->length;
    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return length;
}

void queue_destroy(QUEUE* phQ) {
    Queue* queue = (Queue*)*phQ;
    Node* current = queue->front;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(queue);
    *phQ = NULL;
}

