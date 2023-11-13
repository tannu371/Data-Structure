#include<iostream>

#define MAX_VERTEX 10

using namespace std;

struct GraphNode{
	char c;
	GraphNode* link;
};

// Create a graph with user given adjacency list.
GraphNode** Create_graph() {
	
	cout << "Enter the adjacency list: " << endl;

	string s;

	GraphNode** A;
	A = new GraphNode*[MAX_VERTEX];

	for(int i=0; i<MAX_VERTEX; i++) {
		GraphNode* newNode = new GraphNode;
		newNode->c = i+65;
		newNode->link = NULL;
		A[i] = newNode;
	}
	
	getline(cin, s);

	do {
		for(int j=3; j<s.size(); j+=3) {
			GraphNode* newnode = new GraphNode;
			newnode->c = s[j];
			newnode->link = NULL;
			GraphNode* temp = A[s[0]-65];
			while(temp->link!=NULL) temp = temp->link;
			temp->link = newnode;
		}
		getline(cin, s);
	}while(s.length()!=0);

	return A;
}

// Find in-degree and out-degree and return the number of vertices in adjacency list graph A.
int find_degree(GraphNode** A) {

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
	}while(i<max_vertex);  
	
	int j=0;
	while(j<max_vertex) {
		char c = j+65;
		cout << c << ": " << id[j] << ", " << od[j] << endl;
		j++;
	}
	
	cout << endl;

	return max_vertex;
}

//Check if path exists and print the path from vertex u to v if it exists in  a adjacency list graph A using recursion.
void is_path(GraphNode** A, char u, char v, char path[], int &i, bool &flag) {
	if(!flag) {
		if(u==v) {
			path[i] = v;
			flag  = true;
			cout << "Path exists from " << path[0] << " to " << path[i] << " and the path is ";
			for(int j=0; j<=i; j++) {
				cout << path[j];
				if(j!=i) cout << "->";
			}
			cout << "." << endl;
			return;
		} else {
			path[i++] = u;
			GraphNode* w;
			for(w=A[int(u)-65]; w; w=w->link) {
				bool flag1 = false;
				for(int j=0; j<i; j++)
					if(path[j] == w->c) flag1 = true;
				if(!flag1)
					is_path(A, w->c, v, path, i, flag);
			}
			if(!w) path[i--] = ' ';
		} 
	}
}

struct queue_node{
	GraphNode* g;
	queue_node* link;
};

class Queue{
	public:
		queue_node* front = NULL;
		queue_node* rear = NULL;
		
	void enqueue(GraphNode* node) {
		queue_node* newNode = new queue_node;
		newNode->g = node;
		newNode->link = NULL;
		if(front == NULL) front = rear = newNode;
		else{
			rear->link = newNode;
			rear = newNode;
		}
	}

	GraphNode* dequeue() {
		GraphNode* data = front->g;
		if(front == rear) front = rear = NULL;
		else front = front->link;
		return data;
	}
};

//BFS traveral using queue.
void bfs_traversal(GraphNode** A, char u) {
	GraphNode* w;
	int visited[MAX_VERTEX] {0};
	cout << "The BFS sequence starting from vertex " << u << " is: ";
	cout << u;
	visited[int(u)-65] = 1;
	Queue q;
	q.enqueue(A[int(u)-65]);
	while(q.front) {
		u = q.dequeue()->c;
		for(w = A[int(u)-65]; w; w=w->link) {
			if(!visited[int(w->c)-65]) {
				cout << "->" << w->c;
				q.enqueue(w);
				visited[int(w->c)-65] = 1;
			}
		}
	}
	cout << '\n' << endl;
}

//DFS traversal
void dfs(GraphNode** A, char u, char visited[], int &i, char result[], int &k) {
	visited[i++] = u;
	GraphNode* w;
	for(w=A[int(u)-65]->link; w; w=w->link) {
		bool flag = false;
		for(int j=0; j<i; j++) {
			if(visited[j] == w->c) flag = true;
		}
		if(!flag)
			dfs(A, w->c, visited, i, result, k);
	}
	
	result[k++] = u;
}

// Topological sort based on dfs
void Topo_Sort(GraphNode** A, char start) {
	char visited[MAX_VERTEX];
	char result[MAX_VERTEX];
	int v=0;
	int r=0;
	
	dfs(A, start, visited, v, result, r);

	for(int i=r-1; i>=0; i--) {
		cout << result[i];
		if(i!=0) cout << "->";
	}
	cout << '\n' << endl;
}

int main() {
	GraphNode** A = Create_graph();

	std::cout << "a. ==========================================================\n" << std::endl;

	find_degree(A);

	char path[MAX_VERTEX];
	for(int i=0; i<MAX_VERTEX; i++) path[i]=' ';

	std::cout << "b. ==========================================================\n" << std::endl;

	cout << "Enter the source vertex: ";
	char u;
	cin >> u;
	cout << "Enter the destination vertex: ";
	char v;
	cin >> v;

	int i=0;

	bool flag  = false;

	is_path(A, u, v, path, i, flag);

	if(!flag) cout << "Path doesn't exists from " << path[0] << " to " << path[i] << "." << endl;

	cout << endl;

	std::cout << "c. ==========================================================\n" << std::endl;

	cout << "Enter the source vertex: ";
	char c;
	cin >> c;

	bfs_traversal(A, c);

	std::cout << "d. ==========================================================\n" << std::endl;

	cout << "Enter the source vertex: ";
	char s;
	cin >> s;
	Topo_Sort(A, s);

	return 0;
}

// A->B->C->D->F 
// B->E 
// D->B->E 
// E->C->G 
// F->D