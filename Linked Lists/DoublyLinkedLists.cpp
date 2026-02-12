#include <iostream>
using namespace std;

/*
    Node class represents a single node of the Doubly Linked List
    Each node has:
    1. data  -> stores the value
    2. prev  -> pointer to previous node
    3. next  -> pointer to next node
*/
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor with all parameters
    Node(int data1, Node* prev1, Node* next1) {
        data = data1;
        prev = prev1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        prev = nullptr;
        next = nullptr;
    }

    // Default constructor
    Node() {
        data = 0;
        prev = nullptr;
        next = nullptr;
    }
};

/*
    Function to dynamically create a new node
    Returns pointer to the newly created node
*/
Node* createNode(int data1, Node* prev1, Node* next1) {
    Node* node = new Node(data1, prev1, next1);

    // Safety check (rare in C++, but good practice)
    if (node == nullptr) {
        cout << "Error in Node creation" << endl;
        exit(1);
    }
    return node;
}

/*
    INSERT AT FRONT
    Steps:
    1. Create a new node
    2. New node's next points to current head
    3. Head's prev points back to new node
    4. New node becomes the new head
*/
Node* insert_front(Node* head, int data) {
    Node* newHead = createNode(data, nullptr, head);

    if (head != nullptr)
        head->prev = newHead;

    return newHead;
}

/*
    DELETE FROM FRONT
    Steps:
    1. Store current head
    2. Move head to next node
    3. Update new head's prev to NULL
    4. Delete old head
*/
Node* delete_front(Node* head) {
    if (head == nullptr) {
        cout << "Cannot delete empty list" << endl;
        return nullptr;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete temp;
    return head;
}

/*
    INSERT AT END
    Steps:
    1. Create new node
    2. Traverse till last node
    3. Link last node to new node
*/
Node* insert_end(Node* head, int data) {
    Node* newNode = createNode(data, nullptr, nullptr);

    // If list is empty
    if (head == nullptr)
        return newNode;

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

/*
    DELETE FROM END
    Steps:
    1. Traverse to last node
    2. Disconnect last node
    3. Delete it
*/
Node* delete_end(Node* head) {
    if (head == nullptr) {
        cout << "Cannot delete from empty list" << endl;
        return head;
    }

    // If only one node exists
    if (head->next == nullptr) {
        cout << "Deleted node: " << head->data << endl;
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    cout << "Deleted node: " << temp->data << endl;
    temp->prev->next = nullptr;
    delete temp;

    return head;
}

/*
    INSERT AT GIVEN POSITION
    Steps:
    1. Traverse till (position - 1)
    2. Adjust next and prev pointers carefully
*/
Node* insert_position(Node* head, int data, int position) {
    if (position == 1)
        return insert_front(head, data);

    Node* temp = head;

    for (int i = 1; i < position - 1; i++) {
        if (temp == nullptr) {
            cout << "Position out of range" << endl;
            return head;
        }
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range" << endl;
        return head;
    }

    Node* newNode = createNode(data, temp, temp->next);

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
    return head;
}

/*
    DELETE FROM GIVEN POSITION
    Steps:
    1. Traverse to that position
    2. Fix both prev and next links
    3. Delete node
*/
Node* delete_position(Node* head, int position) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return head;
    }

    if (position == 1)
        return delete_front(head);

    Node* temp = head;

    for (int i = 1; i < position; i++) {
        if (temp == nullptr) {
            cout << "Illegal Position encountered" << endl;
            return head;
        }
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Illegal Position encountered" << endl;
        return head;
    }

    temp->prev->next = temp->next;
    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
    return head;
}

/*
    SEARCH ELEMENT IN DLL
*/
void search(Node* head, int element) {
    Node* temp = head;
    int position = 1;

    while (temp != nullptr) {
        if (temp->data == element) {
            cout << "Element found at position: " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Element not found in the list" << endl;
}

/*
    COUNT TOTAL NODES
*/
int count_nodes(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

/*
    REVERSE DOUBLY LINKED LIST
    Key idea:
    Swap prev and next pointers of each node
*/
Node* reverse_list(Node* head) {
    Node* temp = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != nullptr)
        head = temp->prev;

    return head;
}

/*
    DISPLAY THE LIST (FORWARD)
*/
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

/*
    MAIN FUNCTION
    Menu-driven DLL operations
*/
int main() {
    Node* head = nullptr;
    int choice, data, position;

    while (1) {
        cout << "\n===== DOUBLY LINKED LIST OPERATIONS =====\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Front\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Search Element\n";
        cout << "8. Count Nodes\n";
        cout << "9. Reverse List\n";
        cout << "10. Display List\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
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
            cin >> data;
            search(head, data);
            break;

        case 8:
            cout << "Total nodes = " << count_nodes(head) << endl;
            break;

        case 9:
            head = reverse_list(head);
            cout << "List reversed\n";
            break;

        case 10:
            display(head);
            break;

        case 11:
            exit(0);

        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
