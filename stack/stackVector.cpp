#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v; // vector acts as our dynamic stack

public:
    void push(int x) {
        v.push_back(x); //element pushed into stack
        cout << x << " pushed into stack." << endl;
    }

    void pop() {
        if (v.empty()) { //if vector is empty nothing to pop
            cout << "Stack Underflow! Nothing to pop." << endl;
        } 
        else 
        {
            cout << v.back() << " popped from stack." << endl; 
            v.pop_back();
        }
    }

    void peek() {
        if (v.empty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Top element is: " << v.back() << endl;
        }
    }

    void display() {
        if (v.empty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements (top to bottom): ";
            for (int i = v.size() - 1; i >= 0; i--) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }

    bool isEmpty() {
        return v.empty();
    }
};

int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n===== Stack Menu =====" << endl;
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                return 0;  // exits the loop and program
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
