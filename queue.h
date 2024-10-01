#ifndef QUEUE_H
#define QUEUE_H

typedef void* QUEUE;

typedef struct node Node;
struct node {
    int length;
    char bank[6];
    struct node* next;
};

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

QUEUE queue_init_default(void);
void queue_destroy(QUEUE* phQ);
int is_queue_empty(QUEUE hQ);
void enqueue(QUEUE hQ, int length, const char bank[]);
int service(QUEUE hQ);

#endif