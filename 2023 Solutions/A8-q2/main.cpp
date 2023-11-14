#include<iostream>

const int MAX_VERTEX = 26;

using namespace std;

struct graph_node {
	char c;
	graph_node* link;
};

struct queue_node {
	char c;
	queue_node* link;
};

class Queue {
	public:
		queue_node* front = NULL;
		queue_node* rear = NULL;

		void enqueue(char data) {
			queue_node* newNode = new queue_node;
			newNode->c = data;
			newNode->link = NULL;
			if(front == NULL) front = rear = newNode;
			else {
				rear->link = newNode;
				rear = newNode;
			}
		}

		char dequeue() {
			queue_node* temp = front;
			if(front == rear) front = rear = NULL;
			else front = front->link;
			return temp->c;
		}
};

int eccentricity(graph_node**G, int n, char start) {
	int visited[n];
	int e=0;
	bool flag = false;
	for(int i=0; i<n; i++) visited[i] = 0;
	visited[int(start)-65] = 1;
	Queue q;
	q.enqueue(G[int(start)-65]->c);
	char v;
	graph_node* w;
	while(q.front) {
		v = q.dequeue();
		for(w = G[int(v)-65]; w; w=w->link) {
			if(!visited[int(w->c)-65]) {
				if(!flag) {
					e++;
					flag = true;
				}
				q.enqueue(w->c);
				visited[int(w->c)-65] = 1;
			}	
		}
		flag = false;
	}

	return e;
}

void find_eccentricity(graph_node** G, int n) {
	int* eccentricities;
	eccentricities = new int[n];
	for(int i=0; i<n; i++) eccentricities[i]=0;
	
	int min_eccentricity = n;

	cout << "The eccentricites of the vertices are: " << endl;
	for(int i=0; i<n; i++) {
		eccentricities[i] = eccentricity(G, n, (i+65));
		char c = i+65;
		cout << c << " = " << eccentricities[i] << endl;
		if(eccentricities[i] < min_eccentricity) min_eccentricity = eccentricities[i];
	}
	cout << endl;

	int num = 0;
	for(int i=0; i<n; i++) {
		if(eccentricities[i] == min_eccentricity)
			num = i;
	}

	cout << "The centre of the graph is: ";
	for(int i=0; i<n; i++) {
		if(eccentricities[i] == min_eccentricity) {
			char c = i+65;
			cout << c;
			if(i != num) cout << ", ";
		}		
	}
	cout << endl;
}


int main() {
	graph_node** arr;
	
	int ARR[MAX_VERTEX][MAX_VERTEX] {{0}};
	
	int m, n;
	cout << "Enter the value of m (number of vertices): ";
	cin >> m;
	cout << "Enter the value of n (number of edges): ";
	cin >> n;
	
	arr = new graph_node*[n];

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

	find_eccentricity(arr, n);

}

// AB, AC, AD, CD, CE