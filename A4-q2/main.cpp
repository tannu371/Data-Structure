#include <iostream> 

struct Node{
    char data;
    Node* link;
};

class Stack {
    private:
        Node* top = NULL;
    public:
        void PUSH(char c) {
            Node* newNode = new Node;
            newNode->data = c;
            newNode->link = top;
            top = newNode;
        }

        int POP() {
            if(top == NULL) return -1;
            int n = top->data;
            Node *temp = top;
            top = top->link;
            delete(temp);
            return n;
        }
};

bool checkPalindrome(std::string str) {

    Stack s;
    char c;

    for(int i=0; i<str.length()/2; i++) {
        s.PUSH(str[i]);
    }

    for(int i=(str.length()+1)/2; i < str.length(); i++) {
        c = s.POP();
        if(c != str[i]) return false;
    }

    return true;

}

int main () {

    std::cout << "\n==========================================================" << std::endl;

    std::string str;
    std::cout << "Enter String: ";
    std::getline(std::cin, str);

    bool isPalindrome = checkPalindrome(str);

    if(isPalindrome) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }

    std::cout << "\n==========================================================" << std::endl;


}