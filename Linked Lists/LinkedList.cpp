#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){

    // STATIC LINKED LIST
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->next = n3;

    Node* temp = n1;
    while(temp != nullptr){
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl << endl;

    // DYNAMIC LINKED LIST
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    cout << "Enter how many nodes to be made: ";
    cin >> n;

    while(n--){
        int num;
        cout << "Enter the number: ";
        cin >> num;

        Node* newNode = new Node(num);  // uses your constructor

        if (head == nullptr) {
            // first node
            head = newNode;
            tail = newNode;
        } 
        else {
            tail->next = newNode;  // connect last node → new node (purane wale tail mai next node ka address daal diya )
            tail = newNode;        // move tail forward (aur naya node jo bana hai uska address tail ko de diya )
        }
    }

    // PRINT dynamic list
    Node* temp1 = head;
    while (temp1 != nullptr) {
        cout << temp1->data << "\t";
        temp1 = temp->next;
    }
    //head ko kabhi bhi nhi badalna hai 
    return 0;
}
