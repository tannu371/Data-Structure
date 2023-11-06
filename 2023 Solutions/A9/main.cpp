#include<iostream>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

const int MAX_VERTEX = 7;

struct GraphNode{
	char c;
	GraphNode* link;
};

GraphNode** Create_graph() {
	GraphNode** A;
	A = new GraphNode* [MAX_VERTEX];
	cout << "Enter the adjacency list: " << endl;
	
	for(int i=0; i<MAX_VERTEX; i++) {
		GraphNode* newNode = new GraphNode;
		newNode->c = i+65;
		newNode->link = NULL;
		A[i] = newNode;
	}

		string s;
	
		while(getline(cin, s,'\n')) {
			int i = int(s[0])-65;
			for(int j=4; j<s.size(); j+=4) {
				GraphNode* newnode = new GraphNode;
				newnode->c = s[j];
				newnode->link = NULL;
				GraphNode* temp = A[i];
				while(temp->link!=NULL) temp = temp->link;
				temp->link = newnode;
			}
		}
	
	return A;
}

void find_degree(GraphNode** A) {
	int id[MAX_VERTEX] = {0}; 
	int od[MAX_VERTEX] = {0};
	
	for(int i=0; i<MAX_VERTEX; i++) {
		GraphNode* temp = A[i];
		while(temp->link != NULL) {
			od[i]++;
			temp = temp->link;
			char c = temp->c;
			int n = int(c)-65;
			id[n]++;
		}
	}

	cout <<"\n"<< endl;
	
	for(int i=0; i<MAX_VERTEX; i++) {
		char c = i+65;
		cout << c << ": " << id[i] << ", " << od[i] << endl;
	}
	
	cout << endl;
}

// Input
// A->B->C->D->F 
// B->E 
// D->B->E 
// E->C->G 
// F->D

// void bfs_traversal(GraphNode** A) {
// 	int n;
// 	cout << "Enter the source vertex: ";
// 	cin >>n;
// 	n-=65;
// 	GraphNode* temp = A[n];
// 	queue<char> q;
// 	while(temp->link != NULL) {
// 		char c = temp->c;
// 	}
	
// }

int main() {
	GraphNode** A = Create_graph();
	find_degree(A);
	
	return 0;
	
}