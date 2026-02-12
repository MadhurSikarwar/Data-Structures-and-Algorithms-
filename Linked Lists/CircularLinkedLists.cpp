#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* createNode(int data) {
    Node* node = new Node(data);
    if (node == nullptr) {
        cout << "Memory allocation failed\n";
        exit(1);
    }
    return node;
}

// Insert at front
Node* insert_front(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;

    return head;
}

// Insert at end
Node* insert_end(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Delete from front
Node* delete_front(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return nullptr;
    }

    if (head->next == head) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    Node* last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;
    delete temp;

    return head;
}

// Delete from end
Node* delete_end(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return nullptr;
    }

    if (head->next == head) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while (temp->next->next != head)
        temp = temp->next;

    Node* last = temp->next;
    temp->next = head;
    delete last;

    return head;
}

// Display
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << "\t";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    Node* head = nullptr;
    int choice, data;

    while (1) {
        cout << "\n===== CIRCULAR SINGLY LINKED LIST =====\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from End\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> data;
            head = insert_front(head, data);
            break;
        case 2:
            cin >> data;
            head = insert_end(head, data);
            break;
        case 3:
            head = delete_front(head);
            break;
        case 4:
            head = delete_end(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
