#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} CircularQueue;

void enQueue(CircularQueue* q, int value);
int deQueue(CircularQueue* q);
int isFull(CircularQueue* q);
int isEmpty(CircularQueue* q);
void display(CircularQueue* q);

int main() {
    CircularQueue q;
    q.front = -1;
    q.rear = -1;

    enQueue(&q, 10);
    enQueue(&q, 30);
    display(&q);

    printf("Dequeued: %d\n", deQueue(&q));
    display(&q);

    return 0;
}

void enQueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = value;
    printf("Inserted %d\n", value);
}

int deQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    return value;
}

int isFull(CircularQueue* q) {
    return (q->front == (q->rear + 1) % SIZE);
}

int isEmpty(CircularQueue* q) {
    return (q->front == -1);
}

void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
