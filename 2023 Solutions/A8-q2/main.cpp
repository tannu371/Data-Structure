#include<iostream>

const int MAX_VERTEX = 26;

using namespace std;

struct graph_node {
	char c;
	graph_node* link;
};


int main() {
	graph_node* arr[MAX_VERTEX];
	
	int ARR[MAX_VERTEX][MAX_VERTEX] = {0};
	
	int m, n;
	cout << "Enter the value of m: ";
	cin >> m;
	cout << "Enter the value of n: ";
	cin >> n;
	
	for(int i=0; i<m; i++) {
		graph_node* node = new graph_node;
		node->c = (i+65);
		node->link = NULL;
		arr[i] = node;
	}
	
	char c1, c2, c3;
	
	cout << "Enter the m pair of vertices representing the edges: ";
	for(int j=0; j<n; j++) {
		cin >> c1 >> c2;
		if(j!= n-1) cin >> c3;
		for(int i=0; i<m; i++) {
			if(arr[i]->c == c1) {
				graph_node* temp = arr[i];
				while(temp->link != NULL) {
					temp = temp->link;
				}
				graph_node* node = new graph_node;
				node->c = c2;
				node->link = NULL;
				temp->link = node;
			}
			
			if(arr[i]->c == c2) {
				graph_node* temp = arr[i];
				while(temp->link != NULL) {
					temp = temp->link;
				}
				graph_node* node = new graph_node;
				node->c = c1;
				node->link = NULL;
				temp->link = node;
			}
		}
		
		for(int i=0; i<m; i++) {
			if(i+65 == c1) {
				for(int k=0; k<m; k++) {
					if(k+65 == c2) {
						ARR[i][k] = 1;
						ARR[k][i] = 1;
					}
				}
			}
		}
	}
	
	cout << "\nAdjancency List is:\n";
	
	for(int i=0; i<m; i++) {
		graph_node* temp = arr[i];
		cout << temp->c << " -> ";
		temp = temp->link;
		while(temp->link!=NULL) {
			cout << temp->c << ", ";
			temp = temp->link;
		}
		cout << temp->c << endl;
	}
	
	cout << "\nAdjacency Matrix is:\n";
	
	for(int i=-1; i<m; i++) {
		for(int j=-1;j<m; j++) {
			if(i==-1 && j==-1) cout << "   ";
			else if(i==-1) {
				char c = j+65;
				cout << c << "  ";
			} else if(j==-1) {
				char c = i+65;
				cout << c << "  ";
			} else {
				cout << ARR[i][j] << "  ";
			}
		}
		cout << endl;
	}
		
}
