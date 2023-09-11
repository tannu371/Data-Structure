#include <iostream>
#include <string>

struct Node {
    int data;
    Node *link;
};

Node *head = NULL;

void create_cll() {
    std::cout << "Enter the data values of the node in the list: ";
    int n;
    for (int i=0; i<6; i++) {
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

void insert_cll() {
	int K, P, N=1, position;
	std::cout << "Enter the value of K: ";
	std::cin >> K;
	std::cout << "Enter the value of P: ";
	std::cin >> P;
	Node *temp = head;
	while(temp->link != head) {
		N++;
		temp = temp->link;
	}
	position = P%N +1;
	Node *temp1 = head;
	for(int i=2; i<position; i++) {
		temp1 = temp1->link;
	}
	Node *newNode = new Node();
	newNode -> data = K;
	newNode -> link = temp1->link;
	temp1 -> link = newNode;	
}

void delete_cll() {
	int N=1;
	std::string pattern;
	std::cout << "Pattern of deletion is: ";
	std::cin >> pattern;
	
	Node *temp = head;
	while(temp->link != head) {
		N++;
		temp = temp->link;
	}
	
	for(int i=N; i>=1; i-=2) {
		temp = head;
		Node *temp2;
		if(pattern == "odd" && i%2 == 1) {
			if(i==1) {
				head = temp->link;
				delete(temp);
			} else {
				for(int j=2; j<i; j++) {
					temp = temp->link;
				}
				temp2 = temp->link;
				temp->link = temp2->link;
				delete(temp2);
			}
			
		} else if (pattern == "even" && i%2 == 0) {
				for(int j=2; j<i; j++) {
					temp = temp->link;
				}
				temp2 = temp->link;
				temp->link = temp2->link;
				delete(temp2);
		}
	}
	
}

void display() {
    Node *temp = head;
    std::cout << temp->data;
    temp = temp->link;
    
    while(temp != head) {
        std::cout << " -> " << temp->data;
        temp = temp->link;
        }
    std::cout<< '\n' << '\n' << std::endl;
}

int main () {
	create_cll();
	display();
	
	insert_cll();
	display();

	std::cout << "The original list is: ";	
	display();
	delete_cll();
	display();
	
	return 0;
}

