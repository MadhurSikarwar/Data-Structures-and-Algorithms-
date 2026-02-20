#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int val;
    Node* left;
    Node* right;

    Node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};

// Binary Search Tree class
class BST
{
private:
    Node* root;
    // Insert helper
    Node* insert(Node* node, int val)
    {
        if (node == NULL)
            return new Node(val);

        if (val < node->val)
            node->left = insert(node->left, val);
        else if (val > node->val)
            node->right = insert(node->right, val);

        return node;
    }

    // Find smallest value in a subtree
    Node* minValueNode(Node* node)
    {
        Node* current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    // Delete helper
    Node* deleteNode(Node* node, int key)
    {
        if (node == NULL)
            return node;

        if (key < node->val)
            node->left = deleteNode(node->left, key);

        else if (key > node->val)
            node->right = deleteNode(node->right, key);

        else
        {
            // Case 1: no left child
            if (node->left == NULL)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // Case 2: no right child
            else if (node->right == NULL)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: two children
            Node* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteNode(node->right, temp->val);
        }

        return node;
    }

    // Traversals
    void inorder(Node* node)
    {
        if (node)
        {
            inorder(node->left);
            cout << node->val << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node)
    {
        if (node)
        {
            cout << node->val << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node)
    {
        if (node)
        {
            postorder(node->left);
            postorder(node->right);
            cout << node->val << " ";
        }
    }

public:
    BST()
    {
        root = NULL;
    }

    void insertValue(int val)
    {
        root = insert(root, val);
    }

    void deleteValue(int val)
    {
        root = deleteNode(root, val);
    }

    void showInorder()
    {
        inorder(root);
        cout << endl;
    }

    void showPreorder()
    {
        preorder(root);
        cout << endl;
    }

    void showPostorder()
    {
        postorder(root);
        cout << endl;
    }
};

// Driver
int main()
{
    BST tree;
    int choice, val;

    cout << "1.Insert  2.Delete  3.Inorder  4.Preorder  5.Postorder\n";

    while (true)
    {
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            tree.insertValue(val);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            tree.deleteValue(val);
            break;

        case 3:
            cout << "Inorder: ";
            tree.showInorder();
            break;

        case 4:
            cout << "Preorder: ";
            tree.showPreorder();
            break;

        case 5:
            cout << "Postorder: ";
            tree.showPostorder();
            break;
        }
    }
}
