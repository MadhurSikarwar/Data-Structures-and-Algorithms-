#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void enqueue(Node*& front, Node*& rear, int data) {
    Node* newNode = new Node(data);

    if (front == nullptr) {
        front = rear = newNode;
        rear->next = front;
        return;
    }

    rear->next = newNode;
    rear = newNode;
    rear->next = front;
}

void dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) {
        cout << "Queue is empty\n";
        return;
    }

    if (front == rear) {
        delete front;
        front = rear = nullptr;
        return;
    }

    Node* temp = front;
    front = front->next;
    rear->next = front;
    delete temp;
}

void display(Node* front) {
    if (front == nullptr) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);

    cout << endl;
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    int choice, data;

    while (1) {
        cout << "\n===== QUEUE USING CIRCULAR LINKED LIST =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> data;
            enqueue(front, rear, data);
            break;

        case 2:
            dequeue(front, rear);
            break;

        case 3:
            display(front);
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
