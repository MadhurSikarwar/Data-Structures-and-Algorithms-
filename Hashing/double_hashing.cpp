#include <iostream>
using namespace std;

// Size of the hash table (array)
#define TABLE_SIZE 10

// Prime number smaller than TABLE_SIZE
// Used in second hash function
#define PRIME 7

// The hash table array
// -1 means the slot is empty
int hashTable[TABLE_SIZE];


// First hash function
// Gives the starting index
int hash1(int key)
{
    return key % TABLE_SIZE;
}


// Second hash function
// Gives the step size (jump length)
int hash2(int key)
{
    return PRIME - (key % PRIME);
}


// Initialize all slots of the hash table to -1 (empty)
void initHash()
{
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}


// Insert a key using Double Hashing
void insertKey(int key)
{
    // Get initial index from first hash function
    int index = hash1(key);

    // Get jump size from second hash function
    int step = hash2(key);

    // Try TABLE_SIZE number of times to find empty slot
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        // Calculate new index using double hashing formula
        int newIndex = (index + i * step) % TABLE_SIZE;

        // If slot is empty, place the key here
        if (hashTable[newIndex] == -1)
        {
            hashTable[newIndex] = key;
            return;
        }
    }

    // If no empty slot was found
    cout << "Hash Table is Full\n";
}


// Search for a key
int searchKey(int key)
{
    int index = hash1(key);
    int step = hash2(key);

    // Try the same probing sequence used in insertion
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int newIndex = (index + i * step) % TABLE_SIZE;

        // If we hit an empty slot, key does not exist
        if (hashTable[newIndex] == -1)
            break;

        // If key is found
        if (hashTable[newIndex] == key)
            return newIndex;
    }

    // Key not found
    return -1;
}


// Delete a key
void deleteKey(int key)
{
    // First find the key
    int pos = searchKey(key);

    // If not found
    if (pos == -1)
        cout << "Key not found\n";
    else
        hashTable[pos] = -1;   // Mark the slot empty
}


// Display the hash table
void printHash()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] == -1)
            cout << "Empty at index " << i << endl;
        else
            cout << hashTable[i] << " at index " << i << endl;
    }
}


// Main function
int main()
{
    int choice, key;

    // Initialize the hash table
    initHash();

    cout << "1.Insert  2.Search  3.Delete  4.Display  5.Exit\n";

    while (true)
    {
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key: ";
            cin >> key;
            insertKey(key);
            break;

        case 2:
            cout << "Enter key: ";
            cin >> key;
            key = searchKey(key);

            if (key == -1)
                cout << "Not found\n";
            else
                cout << "Found at index " << key << endl;
            break;

        case 3:
            cout << "Enter key: ";
            cin >> key;
            deleteKey(key);
            break;

        case 4:
            printHash();
            break;

        case 5:
            return 0;
        }
    }
}
