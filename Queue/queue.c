#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // maximum size of the queue

// Define a structure for the Queue
typedef struct {
    int arr[SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize queue
void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    return (q->rear == SIZE - 1);
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// Function to insert element into queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (q->front == -1)  // first element insertion
        q->front = 0;

    q->arr[++(q->rear)] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove element from queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Nothing to remove.\n");
        return -1;
    }

    int value = q->arr[(q->front)++];
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to display queue elements
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

int main() {
    Queue q;
    initialize(&q);

    int choice, value;

    while (1) {
        printf("\n---- Queue Menu ----\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
