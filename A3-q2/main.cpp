#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

struct Node {
    char data;
    Node *link;
};

Node *head = NULL;

void display() {
    Node *temp = head;
    if(temp == head) {
        std::cout << temp->data;
        temp = temp->link;
    }
    while(temp != NULL) {
        std::cout << " -> " << temp->data;
        temp = temp->link;
        }
    std::cout<< '\n' << '\n' << std::endl;
}

void insert_word() {
	char c;
	std::string str;
	std::cout << "Enter the string: ";
	std::getline(std::cin, str);
	for(int i=0; i<str.length(); i++) {
		c = str[i];
		Node *newNode = new Node();
		if(c ==' ') {
			newNode->data = '$';
		} else {
			newNode->data = c;
		}
		newNode->link = NULL;
		
		if(head == NULL) {
			head = newNode;
		} else {
			Node *temp = head;
			while(temp->link != NULL){
				temp = temp->link;
			}
			temp = newNode;
		}
	}
	
	std::cout << "Linked list before insertion: ";
	display();
	
	
	int position;
	std::cout << "Enter the new word to insert: ";
	std::getline(std::cin, str);
	for(int i=0; i<str.length(); i++) {
		c = str[i];
		Node *newNode = new Node();
		if(c ==' ') {
			newNode->data = '$';
		} else {
			newNode->data = c;
		}
		
		Node *temp = head;
		for(int j=2; j<position; j++) {
			temp = temp->link;
		}
		newNode->link = temp->link;
		temp->link = newNode;
	}
	
	std::cout << "Linked list after insertion: ";
	display();
		
}

void delete_word() {
	std::string str;
	std::cout << "Enter the word to be deleted: ";
	std::cin >> str;
	
	std::string list;
	
	Node *temp = head;
    if(temp == head) {
        list += temp->data;
        temp = temp->link;
    }
    while(temp != head) {
        list += temp->data;
        temp = temp->link;
    }
        
    Node *temp1 = head; 
    int position = 1;
    for (int i=0; i<list.length(); i++) {
    	while(list.substr(i, str.length()) != str) {
    		position++;	
		}
	}
	
	for(int i=2; i<position; i++) {
		temp1 = temp1->link;
	}
	
	Node *temp2 = temp1;
	for(int i=0; i<str.length(); i++) {
		temp2 = temp->link;
	}
        
	
	char c;
	for(int i=0; i<str.length(); i++) {
		c = str[i];
		Node *temp1 = head;
		while(temp1->link->data != c) {
			temp1 = temp1->link;
		}
		Node *temp2 = temp1->link;
		
		delete(temp2);
	}
}



int main() {
	insert_word();
	
}
