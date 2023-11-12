#include<iostream>
#include<string>
#include<queue>

#define MAX_VERTEX 10

using namespace std;

struct GraphNode{
	char c;
	GraphNode* link;
};

GraphNode** Create_graph() {
	
	cout << "Enter the adjacency list: " << endl;

	string s;

	GraphNode** A;
	A = new GraphNode*[MAX_VERTEX];
	
	getline(cin, s);
	int i=0;
	do {
		GraphNode* newNode = new GraphNode;
		newNode->c = s[0];
		newNode->link = NULL;
		A[i] = newNode;
		for(int j=3; j<s.size(); j+=3) {
			GraphNode* newnode = new GraphNode;
			newnode->c = s[j];
			newnode->link = NULL;
			GraphNode* temp = A[i];
			while(temp->link!=NULL) temp = temp->link;
			temp->link = newnode;
		}
		getline(cin, s);
		i++;
	}while(s.length()!=0);

	A[i] = NULL;

	return A;
}

void find_degree(GraphNode** A) {

	int id[MAX_VERTEX] = {0}; 
	int od[MAX_VERTEX] = {0};

	int max_vertex =0;
	
	int i=0;
	do{
		GraphNode* temp = A[i];
		char c= temp->c;
		int n = int(c)-65;
		if((n+1)>max_vertex) max_vertex=n+1;
		while(temp->link != NULL) {
			od[n]++;
			temp = temp->link;
			c = temp->c;
			int m = int(c)-65;
			if((m+1)>=max_vertex) max_vertex=m+1;
			id[m]++;
		}
		i++;
	}while(A[i] != NULL);  
	
	for(int j=0; j<max_vertex; j++) {
		char c = j+65;
		cout << c << ": " << id[j] << ", " << od[j] << endl;
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