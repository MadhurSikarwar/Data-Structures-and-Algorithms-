void enqueue(Node*& front, Node*& rear, int data) {
    Node* newNode = new Node(data);

    if (front == nullptr) {
        front = rear = newNode;
        rear->next = front;
        return;
    }

    rear->next = newNode;
    rear = newNode;
    rear->next = front;
}