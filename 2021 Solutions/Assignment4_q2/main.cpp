#include <iostream>

struct Node {
    int data;
    Node *llink;
    Node *rlink;
};

void create_list(Node *&head) {
    std::cout << "Enter the page numbers = ";
    int n;
    for(int i=0; i<6; i++) {
        std::cin >> n;
        Node *newNode = new Node();
        newNode->data = n;
        if(head == NULL) {
            head = newNode;
            newNode->llink = head;
            newNode->rlink = head;
        } else {
            Node *temp = head;
            while(temp->rlink != head) {
                temp = temp->rlink;
            }
            newNode->llink = temp;
            newNode->rlink = temp->rlink;
            temp->rlink = newNode;
        }
    }    
}

void insert_begn(Node *&head) {
    int n;
    std::cout << "Insert the value of the node = ";
    std::cin >> n;
    Node *newNode = new Node();
    newNode->data = n;
    if(head == NULL) {
        head = newNode;
        newNode->llink = head;
        newNode->rlink = head;
    } else {
        Node *temp1 = head;
        temp1->llink = newNode;
        while(temp1->rlink != head) {
            temp1 = temp1->rlink;
        }
        newNode->llink = temp1;
        newNode->rlink = head;
        head = newNode;
        temp1->rlink = head;
    }
}

void insert_last(Node *&head) {
    int n;
    std::cout << "Insert the value of the node = ";
    std::cin >> n;
    Node *newNode = new Node();
    newNode->data = n;
    if(head == NULL) {
        head = newNode;
        newNode->llink = head;
        newNode->rlink = head;
    } else {
        Node *temp1 = head;
        while(temp1->rlink != head) {
            temp1 = temp1->rlink;
        }
        newNode->llink = temp1;
        newNode->rlink = temp1->rlink;
        temp1->rlink = newNode;
    }
}

void insert_loc (Node *&head, int prev, int current) {
    Node *newNode = new Node();
    newNode->data = current;
    Node *temp1 = head;
    Node *temp2;
    while(temp1->data != prev) {
        temp1 = temp1->rlink;
    }
    temp2 = temp1->rlink;
    newNode->llink = temp1;
    newNode->rlink = temp2;
    temp1->rlink = newNode;
    temp2->llink = newNode;
}

void display (Node *&head) {
    std::cout << "The linked list is: ";
    Node *temp = head;
    if(temp->rlink == head) {
        std::cout << head->data << std::endl;
    } else {
        while(temp->rlink != head) {
            std::cout << temp->data << " <-> ";
            temp = temp->rlink;
        }
        std::cout << temp->data << std::endl;
    }
        std::cout << std::endl;
    }


int main() {
    Node *head = NULL;

    create_list(head);
    display(head);

    insert_begn(head);
    display(head);

    insert_last(head);
    display(head);

    int prev, current;
    std::cout << "Enter the web page number of the node after which insertion will be peerformed = ";
    std::cin >> prev;
    std::cout << "Enter the web page of the inserted node = ";
    std::cin >> current;
    insert_loc(head, prev, current);
    display(head);

    return 0;
}