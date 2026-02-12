#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* createNode(int data1,Node* next1){
    Node* node = (Node*)(malloc(sizeof(Node)));
    if(node == NULL){
        printf("Error in creating node\n");
        return NULL;
    }
    node->data = data1;
    node->next = next1;
    return node;
}

Node* insert_front(Node* first, int item){
    // Node* first is the address of the first node of the linked list 
    // what we have done here is we have made a node here and node will now point to the address of first 
    // first is the address of the node 
    // and node ke andar aage ke node ka address hai
    Node* node = createNode(item,first);
    return node;
}

Node* delete_front(Node* first){
    Node* temp;
    if(first == NULL){
        printf("Cannot delete a empty list\n");
        return NULL;
    }
    temp = first; //pehli node ka address temp mai bhej diya hai 
    first = first->next;
    //first mai jo address hai wo agle node ko point kar rha hai 
    //hamne first mai wahi address print kar diya hai to jo node aage ki hai wahi first ban gyi hai 
    printf("Deleted node %d\n",temp->data);
    free(temp); 
    return first;
}

void display(Node* first){
    if(first == NULL){
        printf("Cannot print the empty list\n");
    }
    else{
        Node* temp = first;
        while(temp != NULL){
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {

    Node* head = NULL;   // start with an empty list
    int choice, value;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert at Front\n");
        printf("2. Delete from Front\n");
        printf("3. Display Linked List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insert_front(head, value);
                printf("Inserted %d at front.\n", value);
                break;

            case 2:
                head = delete_front(head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);    
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
