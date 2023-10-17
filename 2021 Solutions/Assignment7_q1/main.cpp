#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
};

// Linked list based Queue
template <typename T>
class Queue {
    private:
        struct Node<T>* front;
        struct Node<T>* rear;

    public:
        void Enqueue (T x) {
            Node<T>* newNode = new Node<T>;
            newNode->data = x;
            newNode->next = NULL;
            if(front == NULL && rear == NULL) {
                front = rear = newNode;
                return;
            }
            rear->next = newNode;
            rear = newNode;
        }

        void Dequeue () {
            Node<T>* temp = front;
            if(front == NULL) {
                std::cout << "Queue is empty\n" << std::endl;
                return;
            }
            if(front == rear) {
                front = rear = NULL;
            } else {
                front = front->next;
            }
            free(temp);
        }

        T Front() {
            if(!this->IsEmpty()) {
                return front->data;
            }  
        }

        bool IsEmpty() {
            if(front == NULL && rear == NULL) return true;
            return false;
        }

        void Print() {
            Node<T>* temp = front;
            while(temp != NULL) {
                std::cout << temp->data;
                temp = temp->next;
            }
            std::cout << std::endl;
        }
};

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

void LevelOrder(BSTNode* rootPtr) {
    if(rootPtr == NULL) return;
    Queue<BSTNode*> Q;
    Q.Enqueue(rootPtr);

    while(!Q.IsEmpty()) {
        BSTNode* current = Q.Front();
        std::cout << current->data << " ";
        if(current->left != NULL) Q.Enqueue(current->left);
        if(current->right != NULL) Q.Enqueue(current->right);
    }
}



int main() {
    
    BSTNode* rootPtr = NULL;

    std::cout << "\n==========================================================" << std::endl;
    std::cout << "Enter the node values for tree = ";
    
}