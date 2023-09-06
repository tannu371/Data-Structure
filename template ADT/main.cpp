#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* link;
};

template <typename T>
class Stack {
    private:
        Node<T>* top; 
    public:
        void CreateS() {
            top = NULL;
        }

        void Push(T x) {
            Node<T>* newNode = new Node<T>;
            newNode->data = x;
            newNode->link = NULL;
            top = newNode;
        }

        void Pop() {
            if(top == NULL) return;
            Node<T>* temp = top;
            top = top->link;
            delete(temp);
        }

        int Top() {
            return top->data;
        }

        bool isEmpty() {
            if(top == NULL) return true;
            return false;
        }
};