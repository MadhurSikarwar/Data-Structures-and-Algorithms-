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
    Node(){
        data = 0;
        next = nullptr;
    }
};

Node* createNode(int data1,Node* next1){
    Node* node = new Node(data1,next1);
    if(node == nullptr){
        cout<<"Error in Node creation"<<endl;
        exit(1);
    }
    return node;
}

Node* insert_front(Node* head,int data){
    Node* newHead = new Node(data,head);
    return newHead;
}

Node* delete_front(Node*head){
    if(head == nullptr){
        cout<<"Cannot delete empty list"<<endl;
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* insert_position(Node* head,int data1,int position) {
    if (position == 1) {
        return insert_front(head, data1);
    }
    Node* temp = head;
    //ek position pehele tak loop chalani hai 
    for (int i = 1; i < position - 1; i++) {
        if (temp == nullptr) {
            cout<<"Position out of range"<<endl;
            return head;
        }
        temp = temp->next;
    }
    Node* newNode = createNode(data1, nullptr);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;   
}

Node* delete_position(Node* head, int position) {
    //agar list pehele se hi empty hai nothing to be deleted
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return head;
    }
    //if the position entered is 1 then delete is using the front function 
    if (position == 1) {
        return delete_front(head);
    }
    Node* temp = head;
    //traverse till position - 1
    for (int i = 1; i < position - 1; i++) {
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Illegal Position encountered" << endl;
            return head;
        }
        temp = temp->next;
    }
    Node* toBeDeleted = temp->next;
    if (toBeDeleted == nullptr) {
        cout << "Illegal Position encountered" << endl;
        return head;
    }
    temp->next = toBeDeleted->next;
    delete toBeDeleted;
    return head;
}

Node* insert_end(Node* head, int data1) {
    Node* newNode = createNode(data1, nullptr);
    //If list is empty
    if (head == nullptr) {
        return newNode;   //new Node becomes the new head of the linked list
    }

    //Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode; //link the node to the end 
    return head;
}

Node* delete_end(Node* head) {
    // Cannot delete from a empty list 
    if (head == nullptr) {
        cout << "Cannot delete from an empty list" << endl;
        return head;
    }
    // if only one node present in the linked list 
    if (head->next == nullptr) {
        cout << "Deleted node: " << head->data << endl;
        delete head;
        return nullptr;
    }
    // for more than one node in the list 
    Node* temp = head;
    // Move to second last node
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    Node* lastNode = temp->next;
    cout << "Deleted node: " << lastNode->data << endl;
    temp->next = nullptr; // disconnect
    delete lastNode;
    return head;
}

void search(Node* head,int element){
    Node* temp = head;
    bool flag = false;
    int position = 1;
    while(temp != nullptr){
        if(temp->data == element){
            flag = true;
            break;
        }
        temp = temp->next;
        position++;
    }
    if(flag == true)
    cout<<"Element found in the list at index:"<<position<<endl;
    else
    cout<<"Element not found in the list"<<endl;
}

int count_nodes(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

Node* reverse_list(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // save next node
        curr->next = prev;   // reverse the link
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }

    return prev; // prev becomes the new head
}

void display(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    //Every function in linked list that returns a pointer will return the head of the linked list
    Node* head = nullptr;
    int choice, data, position; //all the variables that might be used further int the code
    while(1){
        cout << "\n\n===== LINKED LIST OPERATIONS =====\n\n";
        cout << "1. Insert at Front"<<endl;
        cout << "2. Insert at End"<<endl;
        cout << "3. Insert at Position"<<endl;
        cout << "4. Delete from Front"<<endl;
        cout << "5. Delete from End"<<endl;
        cout << "6. Delete from Position"<<endl;
        cout << "7. Search Element"<<endl;
        cout << "8. Count Nodes"<<endl;
        cout << "9. Reverse List"<<endl;
        cout << "10. Display List"<<endl;
        cout << "11. Exit"<<endl;
        cout << "-----------------------------------"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter value to insert: ";
                cin >> data;
                head = insert_front(head, data); //as insert_head gives us the new head of the node that is inserted in the code therefore return type is a Node* and is stored in head because the node stored in front would be the new head for the entire linked list
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> data;
                head = insert_end(head, data);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> position;
                head = insert_position(head, data, position);
                break;
            case 4:
                head = delete_front(head);
                break;
            case 5:
                head = delete_end(head);
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                head = delete_position(head, position);
                break;
            case 7:
                cout << "Enter element to search: ";
                cin >> data;
                search(head, data);
                break;
            case 8:
                cout << "Total nodes = " << count_nodes(head) << endl;
                break;
            case 9:
                head = reverse_list(head);
                cout << "List reversed.\n";
                break;
            case 10:
                display(head);
                break;
            case 11:
                cout << "Exiting...\n";
                exit(0);
            default:
                cout << "Invalid Choice. Try again.\n";
        }
    }
    return 0;
}
