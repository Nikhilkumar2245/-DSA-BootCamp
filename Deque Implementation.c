#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} Deque;

void insertFront(Deque* dq, int value);
void insertRear(Deque* dq, int value);
int deleteFront(Deque* dq);
int deleteRear(Deque* dq);
int isFull(Deque* dq);
int isEmpty(Deque* dq);
void display(Deque* dq);

int main() {
    Deque dq;
    dq.front = -1;
    dq.rear = -1;

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    display(&dq);

    printf("Deleted from front: %d\n", deleteFront(&dq));
    display(&dq);

    insertFront(&dq, 30);
    display(&dq);

    return 0;
}

void insertFront(Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = SIZE - 1; // Wrap around
    } else {
        dq->front--;
    }
    dq->items[dq->front] = value;
    printf("Inserted %d at front\n", value);
}

void insertRear(Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (dq->rear == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % SIZE; // Circular increment
    }
    dq->items[dq->rear] = value;
    printf("Inserted %d at rear\n", value);
}

int deleteFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    int value = dq->items[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1; // Queue becomes empty
    } else {
        dq->front = (dq->front + 1) % SIZE;
    }
    return value;
}

int deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    int value = dq->items[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1; // Queue becomes empty
    } else if (dq->rear == 0) {
        dq->rear = SIZE - 1; // Wrap around
    } else {
        dq->rear--;
    }
    return value;
}

int isFull(Deque* dq) {
    return (dq->front == (dq->rear + 1) % SIZE);
}

int isEmpty(Deque* dq) {
    return (dq->front == -1);
}

void display(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->items[i]);
        if (i == dq->rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
