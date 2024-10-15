#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum number of requests

// Queue structure to hold floor requests
typedef struct {
    int floors[MAX];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Check if the queue is full
int isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

// Add a floor request to the queue
void enqueue(Queue *q, int floor) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add more requests.\n");
        return;
    }
    
    if (isEmpty(q)) {
        q->front = 0;
    }
    
    q->rear++;
    q->floors[q->rear] = floor;
    printf("Request for floor %d added to the queue.\n", floor);
}

// Remove a floor request from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No requests to process.\n");
        return -1;
    }
    
    int floor = q->floors[q->front];
    
    if (q->front == q->rear) {
        // Only one element was in the queue
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    
    return floor;
}

// Elevator logic to move between floors
void moveLift(Queue *q, int currentFloor) {
    while (!isEmpty(q)) {
        int nextFloor = dequeue(q);
        
        if (nextFloor == -1) break;
        
        printf("Lift moving from floor %d to floor %d...\n", currentFloor, nextFloor);
        currentFloor = nextFloor;
        
        printf("Lift arrived at floor %d.\n", currentFloor);
    }
    
    printf("All requests processed. Lift is now idle at floor %d.\n", currentFloor);
}

int main() {
    Queue q;
    initQueue(&q);
    
    int currentFloor = 0; // Lift starts at ground floor (floor 0)
    int choice, floor;
    
    do {
        printf("\n1. Add Floor Request\n2. Process Requests\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter floor number (0-9): ");
                scanf("%d", &floor);
                enqueue(&q, floor);
                break;
                
            case 2:
                moveLift(&q, currentFloor);
                break;
                
            case 3:
                printf("Exiting the system.\n");
                break;
                
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}