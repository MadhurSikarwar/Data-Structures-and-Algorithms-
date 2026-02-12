#include <iostream>
using namespace std;

/*
    Node structure for polynomial
*/
class Node {
public:
    int coeff;
    int exp;
    Node* next;

    Node(int c, int e) {
        coeff = c;
        exp = e;
        next = nullptr;
    }
};

/*
    Create a new node
*/
Node* createNode(int coeff, int exp) {
    Node* node = new Node(coeff, exp);
    if (node == nullptr) {
        cout << "Memory allocation failed\n";
        exit(1);
    }
    return node;
}

/*
    Insert a term in descending order of exponent
    Merge coefficients if exponent already exists
*/
Node* insertTerm(Node* head, int coeff, int exp) {
    // Ignore zero coefficient terms
    if (coeff == 0)
        return head;

    // Insert at beginning
    if (head == nullptr || exp > head->exp) {
        Node* temp = createNode(coeff, exp);
        temp->next = head;
        return temp;
    }

    Node* cur = head;

    // Find position to insert
    while (cur->next != nullptr && cur->next->exp > exp)
        cur = cur->next;

    // Same exponent → add coefficients
    if (cur->next != nullptr && cur->next->exp == exp) {
        cur->next->coeff += coeff;
    }
    // Insert new term
    else {
        Node* temp = createNode(coeff, exp);
        temp->next = cur->next;
        cur->next = temp;
    }

    return head;
}

/*
    Multiply two polynomials
*/
Node* multiply(Node* p1, Node* p2) {
    Node* result = nullptr;

    for (Node* i = p1; i != nullptr; i = i->next) {
        for (Node* j = p2; j != nullptr; j = j->next) {
            result = insertTerm(
                result,
                i->coeff * j->coeff,
                i->exp + j->exp
            );
        }
    }
    return result;
}

/*
    Display polynomial
*/
void display(Node* head) {
    if (head == nullptr) {
        cout << "0";
        return;
    }

    while (head != nullptr) {
        cout << head->coeff << "x^" << head->exp;
        if (head->next != nullptr)
            cout << " + ";
        head = head->next;
    }
}

/*
    MAIN FUNCTION
*/
int main() {
    Node* p1 = nullptr;
    Node* p2 = nullptr;

    int n, coeff, exp;

    // Input first polynomial
    cout << "Enter number of terms in Polynomial 1: ";
    cin >> n;
    cout << "Enter coefficient and exponent:\n";
    for (int i = 0; i < n; i++) {
        cin >> coeff >> exp;
        p1 = insertTerm(p1, coeff, exp);
    }

    // Input second polynomial
    cout << "\nEnter number of terms in Polynomial 2: ";
    cin >> n;
    cout << "Enter coefficient and exponent:\n";
    for (int i = 0; i < n; i++) {
        cin >> coeff >> exp;
        p2 = insertTerm(p2, coeff, exp);
    }

    cout << "\nPolynomial 1: ";
    display(p1);

    cout << "\nPolynomial 2: ";
    display(p2);

    Node* result = multiply(p1, p2);

    cout << "\nResultant Polynomial: ";
    display(result);

    cout << endl;
    return 0;
}
