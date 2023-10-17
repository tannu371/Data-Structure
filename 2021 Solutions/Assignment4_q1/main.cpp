#include <iostream>

struct Node {
    int data;
    Node *link;
};

void create_cirlist(Node *&head) {
    std::cout << "Enter the process numbers = ";
    int n;
    for (int i=0; i<7; i++) {
        std::cin >> n;
        Node *newNode = new Node();
        Node *temp = head;

        newNode->data = n;
        if(head == NULL) {
            head = newNode;
            head->link = head;
        } else {
            while (temp->link != head) {
                temp = temp->link;
            }
            temp->link = newNode;
            newNode->link = head;
        }  
    }
}

void del_began(Node *&head) {
    std::cout << "Deletion from the begining of the list" << std::endl;
    if(head->link == head) {
        delete(head->link);
        head = NULL;
    } else {
        Node *temp = head; 
        Node *temp2 = head; 
        while(temp->link != head) {
            temp = temp->link;
        }
        head = head->link;
        temp->link = head;
        delete(temp2);
    }
}

void del_last(Node *&head) {
    std::cout << "Deletion from the ending of the list" << std::endl;
    if(head->link == head) {
        delete(head->link);
        head = NULL;
    } else {
        Node *temp = head;
        while(temp->link->link != head) {
            temp = temp->link;
        }
        delete(temp->link);
        temp->link = head;
    }
}

void del_loc(Node *&head, int loc) {
    if(head->link == head) {
        delete(head->link);
        head = NULL;
    } else {
        Node *temp1 = head;
        for(int i=2; i<loc; i++) {
            temp1 = temp1->link;
        }
        Node *temp2 = temp1->link;
        temp1->link = temp2->link;
        delete(temp2);
    }
}


void display(Node *&head) {
    Node *temp = head;
    if(temp == head) {
        std::cout << temp->data;
        temp = temp->link;
    }
    while(temp != head) {
        std::cout << " -> " << temp->data;
        temp = temp->link;
        }
    std::cout<< '\n' << '\n' << std::endl;
}




int main() {
    Node *head = NULL;
    create_cirlist(head);
    std::cout << "The circular linked list is: ";
    display(head);

    del_began(head);
    std::cout << "The linked list is: ";
    display(head);

    del_last(head);
    std::cout << "The linked list is: ";
    display(head);

    int n;
    std::cout << "Enter the location of the node to be deleted = ";
    std::cin >> n;
    del_loc(head, n);
    std::cout << "The modified linked list is: ";
    display(head);

    return 0;
}