#include <iostream>
#include <string>
#include <cctype>

struct Node {
    int data;
    Node* link;
};


class Stack {
    private:
        Node* top; 
    public:
        void CreateS() {
            top = NULL;
        }

        void Push(int x) {
            Node* newNode = new Node;
            newNode->data = x;
            newNode->link = top;
            top = newNode;
        }

        void Pop() {
            if(top == NULL) return;
            Node* temp = top;
            top = top->link;
            delete(temp);
        }

        int Top() {
            return top->
            data;
        }

        bool isEmpty() {
            if(top == NULL) return true;
            return false;
        }
};

void display(Stack s) {
    if(s.isEmpty()) return;
    int n =s.Top();
    s.Pop();
    display(s);
    std::cout << n << " ";
}

std::string* findValidSequence (int pushed[], int popped[], int size) {
    Stack s;
    s.CreateS();
    int n = 2*size;
    std::string *sequence = new std::string[n];

    int j=0;
    int k=0;
    for(int i=0; i<size; i++) {
        s.Push(pushed[i]);
        sequence[k] = "push(" + std::to_string(pushed[i]) + ")";
        k++;

        while(!s.isEmpty() && s.Top()==popped[j]) {
            s.Pop();
            sequence[k] = "pop(" + std::to_string(popped[j]) + ")";
            j++;
            k++;
        }
    }

    if(s.isEmpty()) {
        return sequence;
    } else {
        std::string *emptySequence;
        emptySequence = new std::string[1];
        emptySequence[0] = " ";
        return emptySequence;
    }
}

Stack descendingOrder(Stack s) {
    Stack newStack;
    newStack.CreateS();

    newStack.Push(s.Top());
    s.Pop();

    int p;

    while(!s.isEmpty()) {
        while(newStack.Top() > s.Top()) {
            newStack.Push(s.Top());
            s.Pop();
            if(s.isEmpty()) break;
        }

        if(!s.isEmpty()) {
            p = s.Top();
            s.Pop();
            while(newStack.Top() < p) {
                s.Push(newStack.Top());
                newStack.Pop();
            }
            newStack.Push(p);
        }
         
    }

    return newStack;
}

int main() {

    std::cout << "\n==========================================================" << std::endl;
    std::cout << "Question 5(a)\n" << std::endl;

    int pushed[1000];
    int popped[1000];
    

    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int x;
    std::cout << "Enter the entries of array pushed: ";
    for(int i=0; i<n; i++) {
        std::cin >> x;
        pushed[i] = x;
    }
    
    std::cout << "Enter the entries of array popped: ";
    for(int i=0; i<n; i++) {
        std::cin >> x;
        popped[i] = x;
    }
    
    std::string *sequence = findValidSequence(pushed, popped, n);

    if(sequence[0] == " ") {
        std::cout << "False" << std::endl;
    } else {
        std::cout << "True" << std::endl;
        std::cout << "The valid sequence: " << std::endl;
        for(int i=0; i< 2*n; i++) {
            std::cout << sequence[i];
        }
    }
    
    delete[] sequence;

    std::cout << "\n==========================================================" << std::endl;
    std::cout << "Question 5(b)\n" << std::endl;

    Stack s1;
    s1.CreateS();
    Stack s2;

    std::cout << "Enter the size of stack: ";
    std::cin >> n;
    std::cout << "Enter the stack elements in order: ";
    for(int i=0; i<n; i++) {
        std::cin >> x;
        s1.Push(x);
    }

    s2 = descendingOrder(s1);

    display(s2);

    std::cout << "\n=========================================================\n" << std::endl;
    
}