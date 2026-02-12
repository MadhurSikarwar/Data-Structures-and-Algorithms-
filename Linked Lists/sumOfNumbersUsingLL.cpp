#include <iostream>
using namespace std;

/*
    Node structure: stores one digit
*/
class Node {
public:
    int digit;
    Node* next;

    Node(int d) {
        digit = d;
        next = nullptr;
    }
};

/*
    Insert digit at front of list
*/
Node* insert_front(Node* head, int digit) {
    Node* temp = new Node(digit);
    temp->next = head;
    return temp;
}

/*
    Read a long integer as string
    Store digits in reverse order
*/
Node* readNumber(string s) {
    Node* head = nullptr;

    for (int i = s.length() - 1; i >= 0; i--) {
        head = insert_front(head, s[i] - '0');
    }
    return head;
}

/*
    Add two long integers represented by linked lists
*/
Node* addNumbers(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* tail = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry) {
        int sum = carry;

        if (n1 != nullptr) {
            sum += n1->digit;
            n1 = n1->next;
        }

        if (n2 != nullptr) {
            sum += n2->digit;
            n2 = n2->next;
        }

        int digit = sum % 10;
        carry = sum / 10;

        Node* temp = new Node(digit);

        if (result == nullptr) {
            result = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    return result;
}

/*
    Display number in correct order
*/
void display(Node* head) {
    if (head == nullptr)
        return;

    display(head->next);
    cout << head->digit;
}

/*
    MAIN FUNCTION
*/
int main() {
    string s1, s2;

    cout << "Enter first long integer: ";
    cin >> s1;

    cout << "Enter second long integer: ";
    cin >> s2;

    Node* n1 = readNumber(s1);
    Node* n2 = readNumber(s2);

    Node* result = addNumbers(n1, n2);

    cout << "Sum: ";
    display(result);
    cout << endl;

    return 0;
}
