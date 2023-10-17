#include <iostream>

struct Node {
	char song;
	Node* llink;
	Node* rlink;
};

Node* head = NULL;

void display() {	
	Node* temp = head;
	while(temp->rlink != NULL) {
		std::cout << temp->song << " <-> ";
		temp = temp->rlink;
	}
	std::cout << temp->song;
	
	std::cout << std::endl;
	std::cout << std::endl;
}

void display_reverse() {
	Node* temp = head;
	while(temp->rlink != NULL) {
		temp = temp->rlink;
	}
	
	while(temp->llink != NULL) {
		std::cout << temp->song << " <-> ";
		temp = temp->llink;
	}
	std::cout << temp->song;
	
	std::cout << std::endl;
	std::cout << std::endl;
	
}

void Playlist () {
	int n;
	char c;
	std::cout << "Enter the number of songs (N): ";
	std::cin >> n;
	std::cout << "Enter the songs: ";
	Node* temp = head;
	for(int i=0; i<n; i++) {
		std::cin >> c;
		Node* newSong = new Node();
		newSong->song = c;
		if(head == NULL) {
			newSong->llink = NULL;
			newSong->rlink = NULL;
			head = newSong;
			temp = newSong;
		} else {
			temp->rlink = newSong;
			newSong->llink = temp;
			newSong->rlink = NULL;
			temp = newSong;
		}	  
	}
	
	std::cout << "The playlist is: ";
	display();
}

void insert_song(Node* head) {
	char c;
	std::cout << "Enter the name of new song: ";
	std::cin >> c;
	Node* newSong = new Node();
	newSong->song = c;
	Node* temp = head;
	while(temp->rlink != NULL) {
		temp = temp->rlink;
	}
	temp->rlink = newSong;
	newSong->llink = temp;
	newSong->rlink = NULL;
	
	std::cout << "The updated playlist is: ";
	display_reverse();
}

void delete_song(Node* &head) {
	char c;
	std::cout << "Enter the song to be deleted: ";
	std::cin >> c;
	Node* temp = head;
	Node* templ;
	Node* tempr;
	while(temp->song != c) {
		temp = temp->rlink;
	}
	if(temp == head) {
		tempr = temp->llink;
		tempr->llink = NULL;
		head = tempr;
		delete(temp);
	} else {
		templ = temp->llink;
		tempr = temp->rlink;
		templ->rlink = temp->rlink;
		tempr->llink = temp->llink;
		delete(temp);
	}
	
	std::cout << "The updated playlist is: ";
	display();
}

int main(){
	Playlist();
	
	insert_song(head);
	
	delete_song(head);
	
}
