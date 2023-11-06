#include<iostream>

using namespace std;

struct node{
    int vertex;
    node* link;
};

node** make_graph(int m, int n) {
    node** A;
    A = new node* [m];
    for(int i=0; i<m; i++) {
        node* newNode = new node;
        newNode->vertex = i+1;
        newNode->link = NULL;
        A[i] = newNode;
    }

    cout << "Edges: ";
    int v1, v2;
    char c;
    for(int i=0; i<n; i++){
        if(i==n-1) cin >> v1 >> v2;
        else cin >> v1 >> v2 >> c;
        for(int j=0; j<m; j++) {
            if(A[j]->vertex == v1) {
                node* newNode = new node;
                newNode->vertex = v2;
                newNode->link = NULL;
                node* temp = A[j];
                while(temp->link != NULL) {
                    temp = temp->link;
                }
                temp->link = newNode; 
                break;
            }
        }
    }

    cout << "The graph is: ";
    for(int i=0; i<m; i++) {
        cout << A[i]->vertex << " -> ";
        node* temp = A[i];
        while(temp->link != NULL) {
            temp = temp->link;
            cout << temp->vertex << " ";
        }
        cout << endl;
    }
    return A;
}

bool path_exist(node** A, int m, int n) {
    for(int i=0; i<m; i++) {

    }
    return false;
}

int main() {
    int m, n;
    cout << "m = ";
    cin >> m;
    cout << "n = ";
    cin >> n;
    node** A = make_graph(m, n);
    cout << path_exist(A, m, n);
}