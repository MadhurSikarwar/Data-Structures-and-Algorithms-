#include<iostream>
using namespace std;

class Stack{
    private:
        int* arr;
        int top;
        int size;
    public:
        Stack(int n){
            size = n;
            arr = new int[size];
            top = -1;
        }

        void push(int n){
            if(top == size-1){
                cout << "Cannot push - STACK OVERFLOW" << endl;
            }
            else{
                top++;
                *(arr + top) = n;
            }
        }

        int pop(){
            if(top == -1){
                cout << "Cannot pop - STACK UNDERFLOW" << endl;
                return -1;  // return a sentinel value for underflow
            }
            else{
                int n = *(arr + top);
                top--;
                return n;
            }
        }

        void display(){
            if(top == -1){
                cout << "Cannot print - Nothing in Stack" << endl;
            }
            else{
                for(int i = top; i >= 0; i--){
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }

        // Destructor
        ~Stack() {
            delete[] arr;
        }   
};

int main(){
    int size;
    cout << "Enter size of the stack: ";
    cin >> size;

    // Check for valid size
    if(size <= 0) {
        cout << "Invalid size. Size should be greater than 0." << endl;
        return 1;
    }

    Stack s(size);
    int choice, val;
    
    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                {
                    int poppedValue = s.pop();
                    if (poppedValue != -1) {
                        cout << "Popped: " << poppedValue << endl;
                    }
                }
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
