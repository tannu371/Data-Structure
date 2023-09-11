#include <iostream>

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

class Tree {
    private:
        BSTNode* rootPtr = NULL;
    public:
        BSTNode* GetNewNode(int data) {
            BSTNode* newNode = new BSTNode;
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        void insert(int data) {
            if(rootPtr == NULL) {
                rootPtr = GetNewNode(data);
            } else {
                BSTNode* temp = rootPtr;
                while(temp->left != NULL || temp->right != NULL) {
                    if(data < temp->data) {
                        temp = temp->left;
                    } else {
                        temp = temp->right;
                    }
                }
                
                // if(data < temp->data) {
                //     temp->left = = GetNewNode(data);
                // } else {
                //     temp->right = GetNewNode(data);
                // }
                 
                
            }
        }

        int findMin() {
            BSTNode* current = rootPtr;
            while(current->left != NULL) {
                current = current->left;
            }
            return current->data;
        }

        
};


int main() {
    Tree tree;
    tree.insert(5);
    tree.insert(10);
    tree.insert(2);
    tree.insert(4);
    tree.insert(1);

    int min = tree.findMin();

    std::cout << min;


}