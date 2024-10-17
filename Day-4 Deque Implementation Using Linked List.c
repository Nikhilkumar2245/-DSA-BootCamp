#include <stdio.h>
#include <stdlib.h>

// Define the structure for a deque node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Define the structure for the deque
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new deque
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

// Function to check if the deque is empty
int isEmptyDeque(struct Deque* deque) {
    return deque->front == NULL;
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = deque->front;
    newNode->prev = NULL;

    if (isEmptyDeque(deque)) {
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
    }

    deque->front = newNode;
    printf("%d inserted at front of deque\n", data);
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (isEmptyDeque(deque)) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
    }

    deque->rear = newNode;
    printf("%d inserted at rear of deque\n", data);
}

// Function to delete an element from the front of the deque
int deleteFront(struct Deque* deque) {
    if (isEmptyDeque(deque)) {
        printf("Deque underflow\n");
        return -1; // Return an error value
    }

    struct Node* temp = deque->front;
    int deletedValue = temp->data;
    deque->front = deque->front->next;

    if (deque->front == NULL) {
        deque->rear = NULL; // Deque becomes empty
    } else {
        deque->front->prev = NULL;
    }

    free(temp);
    return deletedValue;
}

// Function to delete an element from the rear of the deque
int deleteRear(struct Deque* deque) {
    if (isEmptyDeque(deque)) {
        printf("Deque underflow\n");
        return -1; // Return an error value
    }

    struct Node* temp = deque->rear;
    int deletedValue = temp->data;
    deque->rear = deque->rear->prev;

    if (deque->rear == NULL) {
        deque->front = NULL; // Deque becomes empty
    } else {
        deque->rear->next = NULL;
    }

    free(temp);
    return deletedValue;
}

// Function to peek at the front element of the deque
int peekFront(struct Deque* deque) {
    if (isEmptyDeque(deque)) {
        printf("Deque is empty\n");
        return -1; // Return an error value
    }
    return deque->front->data;
}

// Function to peek at the rear element of the deque
int peekRear(struct Deque* deque) {
    if (isEmptyDeque(deque)) {
        printf("Deque is empty\n");
        return -1; // Return an error value
    }
    return deque->rear->data;
}

// Main function to demonstrate deque operations
int main() {
    struct Deque* deque = createDeque();

    insertRear(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 5);
    insertFront(deque, 0);

    printf("%d deleted from front of deque\n", deleteFront(deque));
    printf("%d deleted from rear of deque\n", deleteRear(deque));
    printf("Front element is %d\n", peekFront(deque));
    printf("Rear element is %d\n", peekRear(deque));

    // Free remaining nodes
    while (!isEmptyDeque(deque)) {
        deleteFront(deque);
    }
    free(deque); // Free the deque structure

    return 0;
}
