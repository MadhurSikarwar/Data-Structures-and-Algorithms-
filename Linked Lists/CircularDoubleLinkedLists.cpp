#include <iostream>
using namespace std;

/*
    Node structure for Circular Doubly Linked List
*/
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data1) {
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

/*
    Function to create a new node
*/
Node* createNode(int data) {
    Node* node = new Node(data);
    if (node == nullptr) {
        cout << "Memory allocation failed\n";
        exit(1);
    }
    return node;
}

/*
    Insert at Front
*/
Node* insert_front(Node* head, int data) {
    Node* newNode = createNode(data);

    // Empty list
    if (head == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;

    head = newNode;
    return head;
}

/*
    Insert at End
*/
Node* insert_end(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;

    return head;
}

/*
    Delete from Front
*/
Node* delete_front(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return nullptr;
    }

    // Single node
    if (head->next == head) {
        delete head;
        return nullptr;
    }

    Node* last = head->prev;
    Node* temp = head;

    head = head->next;
    head->prev = last;
    last->next = head;

    delete temp;
    return head;
}

/*
    Delete from End
*/
Node* delete_end(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return nullptr;
    }

    if (head->next == head) {
        delete head;
        return nullptr;
    }

    Node* last = head->prev;
    Node* newLast = last->prev;

    newLast->next = head;
    head->prev = newLast;

    delete last;
    return head;
}

/*
    Insert at Position
*/
Node* insert_position(Node* head, int data, int position) {
    if (position == 1)
        return insert_front(head, data);

    Node* temp = head;

    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            cout << "Position out of range\n";
            return head;
        }
    }

    Node* newNode = createNode(data);

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

/*
    Delete from Position
*/
Node* delete_position(Node* head, int position) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return nullptr;
    }

    if (position == 1)
        return delete_front(head);

    Node* temp = head;

    for (int i = 1; i < position; i++) {
        temp = temp->next;
        if (temp == head) {
            cout << "Position out of range\n";
            return head;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    return head;
}

/*
    Display Forward
*/
void display_forward(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

/*
    Display Backward
*/
void display_backward(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head->prev;
    Node* last = temp;

    do {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != last);

    cout << endl;
}

/*
    Count Nodes
*/
int count_nodes(Node* head) {
    if (head == nullptr)
        return 0;

    int count = 0;
    Node* temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

/*
    MAIN FUNCTION
*/
int main() {
    Node* head = nullptr;
    int choice, data, position;

    while (1) {
        cout << "\n===== CIRCULAR DOUBLY LINKED LIST =====\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Front\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Count Nodes\n";
        cout << "10. Exit\n";
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
            cin >> data >> position;
            head = insert_position(head, data, position);
            break;

        case 4:
            head = delete_front(head);
            break;

        case 5:
            head = delete_end(head);
            break;

        case 6:
            cin >> position;
            head = delete_position(head, position);
            break;

        case 7:
            display_forward(head);
            break;

        case 8:
            display_backward(head);
            break;

        case 9:
            cout << "Total nodes = " << count_nodes(head) << endl;
            break;

        case 10:
            exit(0);

        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
