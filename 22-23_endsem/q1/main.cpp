#include<iostream>

using namespace std;


//Create an adjacency matrix graph with n vertices
int** make_graph(int n) {
    int** A;
    A = new int*[n];

    for(int i=0; i<n; i++) {
        cout << "Enter the " << i << "th row of the adjacency matrix: ";
        A[i] = new int[n];
        for(int j=0; j<n; j++){
            cin >> A[i][j];
            char c;
            if(j!=(n-1)) cin >> c;
        }
    }
    
    return A;
}

//Array of possible vertices which could be reached in graph  with n vertices from a given vertex u 
void is_visited(int** A, int n, int u, int visited[]) {
    visited[u] = 1;
    for(int i=0; i<n; i++) {
        if(A[u][i]) {
            if(!visited[i])
                is_visited(A, n, i, visited);
        }
    }
}

//Array of possible vertices which could be reached in a graph with n vertices from a given vertex u at a given distance d
void is_reachable(int** A, int n, int u, int d, int reachable[]) {
    reachable[u] = 1;
    if(d){
        for(int i=0; i<n; i++) {
            if(A[u][i]) {
                if(!reachable[i])
                    is_reachable(A, n, i, d-1, reachable);
            }     
        }
    }
}

int main () {
    cout << "Enter the number of vertices: ";
    int n; 
    cin >> n;

    int** A;
    A = make_graph(n);

    cout << "Enter the source vertex: ";
    int u;
    cin >> u;
    cout << "Enter the destination vertex: ";
    int v;
    cin >> v;

    int visited[n];
    for(int i=0; i<n;i++) visited[i]=0;

    is_visited(A, n, u, visited);
    
    if(visited[v]) cout << "Path exists.";
    else cout << "Path doesn't exists.";

    cout << '\n' << endl;

    cout << "Enter the source vertex: ";
    cin >> u;

    cout << "Enter the distance: ";
    int d;
    cin >> d;

    int reachable[n];
    for(int i=0; i<n;i++) reachable[i]=0;

    is_reachable(A, n, u, d, reachable);

    for(int i=0; i<n; i++) {
        if(!reachable[i]) {
            if(i < n-1) cout << i << ", ";
            else cout << i << endl;
        }
    }

    return 0;
}

//0,1,0,0,0,0,0
//0,0,1,0,1,0,0
//0,0,0,1,0,0,0 
//0,0,0,0,0,0,1
//0,0,0,1,0,0,0
//1,0,0,0,1,0,1
//0,0,0,0,1,0,0