#include <bits/stdc++.h>
using namespace std;
class Queue
{
private:
    int capacity;
    int *arr; // for allocating memory dynamically in the array
    int front;
    int rear;
    int currentSize;

public:
    // Constructor to initialize the queue
    Queue(int size)
    {
        capacity = size;
        arr = new int[capacity]; // Memory Allocation for the queue
        front = 0;
        rear = -1;
        currentSize = 0;
    }

    // Destructor to free the dynamically allocated memory for the queue
    ~Queue()
    {
        delete[] arr;
    }

    bool isFull()
    {
        return (currentSize == capacity);
        // If current Size == Capacity, it will return the queue is full
    }

    bool isEmpty()
    {
        return (currentSize == 0);
        // If currentSize is 0, it will return that the queue is empty
    }

    void insertQueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow - Cannot insert Element" << endl;
            return;
        }
        else
        {
            rear++;
            arr[rear] = value;
            currentSize++; // also to be increased
            cout << value << " inserted to the Queue" << endl;
        }
    }

    int deleteFromQueue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow - Cannot delete from the Queue" << endl;
            return -1;
        }
        else
        {
            int val = arr[front];
            cout << val << " removed from the queue" << endl;

            // Shift elements left to fill the gap
            for (int i = 0; i < currentSize - 1; i++)
            {
                arr[i] = arr[i + 1];
            }

            rear--; // Decrease rear because we've removed the front element
            currentSize--;
            return val;
        }
    }

    int peekFront()
    {
        if (isEmpty())
        {
            cout << "Cannot peek - The Queue is Empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int peekRear()
    {
        if (isEmpty())
        {
            cout << "Cannot peek - The Queue is Empty" << endl;
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Cannot Print the Queue as the Queue is Empty" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    Queue q(size);

    while (true)
    {
        cout << "Enter 1 for inserting to the queue" << endl;
        cout << "Enter 2 for removing from the queue" << endl;
        cout << "Enter 3 for peeking at the front" << endl;
        cout << "Enter 4 for peeking at the rear" << endl;
        cout << "Enter 5 for displaying the queue" << endl;
        cout << "Enter 6 for exit" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the value to insert to the queue: ";
            int val;
            cin >> val;
            q.insertQueue(val);
            break;
        }
        case 2:
        {
            cout << "Removing " << q.deleteFromQueue() << " from the queue" << endl;
            break;
        }
        case 3:
        {
            cout << "The front element is: " << q.peekFront() << endl;
            break;
        }
        case 4:
        {
            cout << "The rear element is: " << q.peekRear() << endl;
            break;
        }
        case 5:
        {
            cout << "Displaying the queue:" << endl;
            q.display();
            break;
        }
        case 6:
            cout << "Exiting" << endl;
            exit(0);
        default:
            cout << "Enter number only from the options" << endl;
            break;
        }
    }

    return 0;
}
