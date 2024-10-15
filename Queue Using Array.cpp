#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the queue

// Queue structure definition
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// Add an element to the queue (enqueue)
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add %d.\n", value);
        return;
    }
    
    if (isEmpty(q)) {
        q->front = 0; // If queue was empty, set front to 0
    }
    
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

// Remove an element from the queue (dequeue)
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    
    int value = q->items[q->front];
    q->front++;
    
    // Reset the queue if no elements are left
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    
    printf("Dequeued %d\n", value);
    return value;
}

// View the element at the front of the queue without removing it
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    
    return q->items[q->front];
}

// Display all elements in the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    
    int choice, value;
    
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display Queue\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
                
            case 2:
                dequeue(&q);
                break;
                
            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Front element is %d\n", value);
                }
                break;
                
            case 4:
                display(&q);
                break;
                
            case 5:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}