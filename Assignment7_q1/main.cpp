#include <iostream>

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* GetNewNode(int data) {
    BSTNode* newNode = new BSTNode;
    (*newNode).data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BSTNode* Insert(BSTNode* rootPtr, int data) {
    if (rootPtr == NULL) {
        rootPtr = GetNewNode(data);
    } else if (data < rootPtr->data) {
        rootPtr->left = Insert(rootPtr->left, data);
    } else {
        rootPtr->right = Insert(rootPtr->right, data);
    }
    return rootPtr;
}

bool Search(BSTNode* rootPtr, int data) {
    if(rootPtr == NULL) return false;
    else if(rootPtr->data == data) return true;
    else if(rootPtr->data < data) return Search(rootPtr->left, data);
    else return Search(rootPtr->right, data);
}

int FindMin(BSTNode* rootPtr) {
    if(rootPtr->left == NULL) return rootPtr->data;
    else return FindMin(rootPtr->left);
}



int main() {
    
    BSTNode* rootPtr = NULL;

    std::cout << "\n==========================================================" << std::endl;
    std::cout << "Enter the node values for tree = ";
    
}