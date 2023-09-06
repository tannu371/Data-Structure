#include <iostream>
#include <string>
#include <sstream>

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

int performOperation(int operand1, int operand2, char op) {
    switch (op)
    {
    case '+':
        return operand1 + operand2;
        break;
    case '-':
        return operand1 - operand2;
        break;
    case '*':
        return operand1 * operand2;
        break;
    case '/':
        return operand1 / operand2;
        break;

    default: 
        return 1;
        break;
    }
}

int Postfix_Evaluation(std::string E) {
    int result;
    Stack s;
    s.CreateS();

    std::string num;
    int n;

    int elem1, elem2;

    for(int i=0; i<E.size(); i++) {
        if(isdigit(E[i])) {
            num = E[i];
            while(!ispunct(E[++i])) {
                num += E[i];
            }
            std::stringstream ss {num};
            ss >> n;
            s.Push(n); 
        } else if(E[i] == ',' || E[i] == ' ') {
            continue;
        } else if(E[i] == '#') {
            break;
        } else {
            elem1 = s.Top();
            s.Pop();
            elem2 = s.Top();
            result = performOperation(elem2, elem1, E[i]);
            s.Push(result);
        }
    }

    return result;
}

int main() {
    std::cout << "\n==========================================================" << std::endl;

    std::string E;
    std::cout << "Enter the postfix expression: ";
    std::getline(std::cin, E);

    int result = Postfix_Evaluation(E);

    std::cout << result << std::endl;
    std::cout << "\n==========================================================" << std::endl;
}

// 2, 3, *,4,+,#