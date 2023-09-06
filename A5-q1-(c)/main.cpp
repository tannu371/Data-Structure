#include <iostream>
#include <string>

struct Node {
    char data;
    Node* link;
};

class Stack {
    private:
        Node* top; 
    public:
        void CreateS() {
            top = NULL;
        }

        void Push(char c) {
            Node* newNode = new Node;
            newNode->data = c;
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
            return top->data;
        }

        bool isEmpty() {
            if(top == NULL) return true;
            return false;
        }
};

int ISP(char c) {
    switch (c) {
        case '^':return 3;
        case '*':return 2;
        case '/':return 2;
        case '+':return 1;
        case '-':return 1;
        case '(':return 0;
        case '#': return -1;
        default : return -1;
    }
}

int ICP(char c) {
    switch (c) {
        case '^':return 4;
        case '*':return 2;
        case '/':return 2;
        case '+':return 1;
        case '-':return 1;
        case '(':return 4;
        default : return -1;
    }
}

std::string ToPostfix(std::string E) {
    Stack stack;
    stack.CreateS();
    std::string s;

    stack.Push('#');

    for(char c : E) {
        if(isspace(c)) {
            continue;
        } else if(isdigit(c)) {
            s += c;
        } else if(c == '(') {
            stack.Push(c);
        } else if(c == ')') {
            while(stack.Top() != '(') {
                s += stack.Top();
                stack.Pop();
            }
            stack.Pop();
        } else if(ispunct(c)) {
            while(ISP(stack.Top()) >= ICP(c)) {
                s += stack.Top();
                stack.Pop();
            }
            stack.Push(c);
        }
    }

    while(ISP(stack.Top()) > 0) {
        s += stack.Top();
        stack.Pop();
    }

    return s;
}

int main() {

    std::cout << "\n==========================================================" << std::endl;

    std::string E;
    std::cout << "Enter the infix expression: ";
    std::getline(std::cin, E);

    std::string s = ToPostfix(E);

    std::cout << s << std::endl;

    std::cout << "\n==========================================================" << std::endl;
    
}