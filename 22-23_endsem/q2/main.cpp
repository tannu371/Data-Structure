#include<iostream>

using namespace std;

// Tree Node
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Implementation of queue on linked list
struct Node{
    TreeNode* data; 
    Node* link;
};

class Queue {
        private: 
        Node* front = NULL;
        Node* back = NULL;
    
        public:
        void enqueue(TreeNode* node) {
            Node* newNode = new Node;
            newNode->data = node;
            newNode->link = NULL;
            if(front == NULL) {
                front = back = newNode;
            } else {
                back->link = newNode;
                back = newNode;
            }
        }

        TreeNode* dequeue() {
            Node* temp = front;
            if(front == back) front = back = NULL;
            else front = front->link;
            return temp->data;
        }

        bool Is_Empty() {
            if(front == NULL) return true;
            return false;
        }
};

// Create an instance of tree node
TreeNode* new_node(int n) {
    TreeNode* newNode = new TreeNode;
    newNode->data = n;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Create a complete binary tree from user given keys
TreeNode* CompBT() {
    cout << "Enter the value of nodes: ";
    TreeNode* root = NULL;

    int n;
    cin >> n;
    char c;

    root = new_node(n);

    Queue q;
    q.enqueue(root);
    
    TreeNode* current;
    while(1) {
        current = q.dequeue();
        cin.get(c);
        if(c=='\n') break;
        else {
            cin >> n;
            current->left = new_node(n);
        }
        cin.get(c);
        if(c=='\n') break;
        else {
            cin >> n;
            current->right = new_node(n);
        }
        q.enqueue(current->left);
        q.enqueue(current->right);
    }
    return root;
}

//Find leaf node having minimum value
int min_leaf(TreeNode* root) {
    Queue q;
    q.enqueue(root);

    TreeNode* current = root;

    while(current->left != NULL || current->right!=NULL) {
        TreeNode* left = current->left;
        TreeNode* right = current->right;
        q.enqueue(left);
        q.enqueue(right);
        current = q.dequeue();
    }

    int min = current->data;

    while(!q.Is_Empty()) {
        int n = q.dequeue()->data;
        if(min > n) min = n; 
    }
    
    return min;
}

//Check if tree is binary search tree or not
bool isBST(TreeNode* root) {
    Queue q;
    q.enqueue(root);
    TreeNode* current = q.dequeue();
    while(current->left != NULL && current->right != NULL) {
        if(current->left != NULL) {
            if(current->left->data > current->data) return false;
        } 
        if(root->right != NULL) {
            if(current->right->data < current->data) return false;
        }
        q.enqueue(current->left);
        q.enqueue(current->right);
        current = q.dequeue();
    } 
    return true;
}

int main() {
    TreeNode* root = CompBT();

    cout << min_leaf(root) << endl;
    
    if(isBST(root)) cout << "TRUE" << endl;
    else cout << "FALSE" << endl;
}

//50, 30, 65, 25, 20, 60, 70