#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        data = value;
        left = right = nullptr;
    }
};

//Node in normal Binary tree to be inserted level wise meaning the left most part to be filled the first and then the right part to be filled
void insertNode(TreeNode* root,int value){
    TreeNode* newNode = new TreeNode(value);
    if(root == nullptr){ //if no node is present in the tree make the newNode as the root node of the tree
        root = newNode;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp->left == nullptr){
            temp->left = newNode;
            return;
        }
        else{
            q.push(temp->left);
        }
        if(temp->right == nullptr){
            temp->right = newNode;
            return;
        }
        else{
            q.push(temp->right);
        }
    }
}

void InOrder(TreeNode* root){
    InOrder(root->left);
    cout<<root->data<<"\t";
    InOrder(root->right);
}

void preOrder(TreeNode* root){
    cout<<root->data<<"\t";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(TreeNode* root){
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<"\t";
}

void levelTraversal(TreeNode* root){
    if(root == nullptr)
    return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp;
        temp = q.front();
        cout<<temp->data<<"\t";
        q.pop();
        if(temp->left != nullptr){
            q.push(root->left);
        }
        if(temp->right != nullptr){
            q.push(root->right);
        }
    }
}

vector<vector<int>> levelOrder(TreeNode* root) {
    //the function will return the two dimensional vector here 
    //output will look like [[1],[1,2],[1]] .... based on the level of binary trees the number of nodes will be on the that index i.e index of array = level of binary tree here 

    vector<vector<int>> v1; //final output of the function to be stored in this vector
    if(root == nullptr) //if the binary tree is empty return the empty vector
        return v1;
    queue<TreeNode*> q; //create a queue
    q.push(root); //pushing the root node of the binary tree in the queue
    while(!q.empty()){ //make the loop run till the queue is not empty
        int levelSize = q.size(); //the size of each level would be same as the size of the queue
        vector<int> currentLevel; //creating an array for the current Level
        for(int i = 0; i < levelSize; i++){ //iterating till the levelSize
            TreeNode* temp = q.front(); //temp to store the front of the array
            q.pop(); //popping from the queue 
            currentLevel.push_back(temp->data); //pushing the data in the currentLevel
            if(temp->left != nullptr){ //if any data is there in the left push it inside the queue
                q.push(temp->left);
            }
            if(temp->right != nullptr){ //if any data is there in the right push it inside the queue
                q.push(temp->right);
            }
        }
        v1.push_back(currentLevel); //push the currentLevel array inside the v1 vector
    }
    return v1;
}
int main(){

}