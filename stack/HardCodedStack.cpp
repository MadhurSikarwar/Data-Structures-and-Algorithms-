#include <iostream>
using namespace std;

#define SIZE 5  // maximum size of stack

class Stack {
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;  // stack is empty initially
    }

    void push(int x) {
        if (top == SIZE - 1) {
            cout << "Stack Overflow! Cannot push " << x << endl;
        } 
        else {
            top++;
            arr[top] = x;
            cout << x << " pushed into stack." << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Nothing to pop." << endl;
        } else {
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void peek() {
        if (top == -1)
            cout << "Stack is empty!" << endl;
        else
            cout << "Top element is: " << arr[top] << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.peek();
    s.pop();
    s.display();

    return 0;
}
