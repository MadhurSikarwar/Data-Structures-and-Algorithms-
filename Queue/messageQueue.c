#include <stdio.h>
#include <string.h>
#define SIZE 20  // Maximum number of messages and message length

// Define a structure for the Queue
typedef struct {
    char data[SIZE][SIZE];  // 2D array to store up to SIZE messages (each max SIZE characters)
    int front, rear;         // Indices for front and rear of queue
} Queue;

// Initialize the queue
void init(Queue* q)
{
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue* q)
{
    // If next position of rear becomes front, queue is full (circular)
    return ((q->rear + 1) % SIZE == q->front);
}

// Function to check if the queue is empty
int isEmpty(Queue* q)
{
    return (q->front == -1);
}

// Function to "send" (enqueue) a message into the queue
void send(Queue* q, char msg[])
{
    if (isFull(q)) {
        printf("\nQueue Full! Cannot send more messages.\n");
        return;
    }

    // If the queue is empty, set front to 0 (first element)
    if (q->front == -1)
        q->front = 0;

    // Move rear circularly and copy message
    q->rear = (q->rear + 1) % SIZE;
    strcpy(q->data[q->rear], msg);

    printf("\nMessage sent successfully!\n");
}

// Function to "receive" (dequeue) a message from the queue
void receive(Queue* q)
{
    char msg[SIZE];

    if (isEmpty(q)) {
        printf("\nQueue Empty! No message to receive.\n");
        return;
    }

    // Copy the message at the front to 'msg'
    strcpy(msg, q->data[q->front]);

    // If there was only one message, reset the queue
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % SIZE; // Move front circularly

    printf("\nReceived Message: %s\n", msg);
}

// Function to display all messages currently in the queue
void display(Queue* q)
{
    if (isEmpty(q)) {
        printf("\nQueue is Empty! No messages to display.\n");
        return;
    }

    printf("\n--- Messages in Queue ---\n");
    int i = q->front;
    while (1) {
        printf("%s\n", q->data[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % SIZE;  // Circular increment
    }
    printf("--------------------------\n");
}

// Main function: menu-driven program
int main()
{
    int choice;
    char msg[SIZE];
    Queue q;

    init(&q);  // Initialize the queue

    printf("===== MESSAGE QUEUE SYSTEM =====\n");
    printf("1. Send Message\n");
    printf("2. Receive Message\n");
    printf("3. Display All Messages\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter message: ");
            scanf("%s", msg);  // Read one-word message
            send(&q, msg);
            break;

        case 2:
            receive(&q);
            break;

        case 3:
            display(&q);
            break;

        case 4:
            printf("\nExiting... Goodbye!\n");
            return 0;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }
}
