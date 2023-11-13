#include<iostream>

using namespace std;

template<typename T>
int partition(T a[], int low, int high) {
    int pIndex = low;
    T pivot = a[pIndex];
    int i=low, j=high;
    while(i<j) {
        while(a[i] >= pivot && i<=high) i++;
        while(a[j] < pivot) j--;
        if(i<j) {
            T temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j--;
        }
    }

    a[pIndex] = a[j];
    a[j] = pivot;
    pIndex = j;
    return pIndex;
}

template<typename T>
void quick_sort(T a[], int low, int high) {
    if(low>=high) return;
    int pIndex = partition(a, low, high);
    quick_sort(a, low, pIndex-1);
    quick_sort(a, pIndex+1, high);
}

struct graph_node{
    int vertex;
    graph_node* link;
};

struct graph_edge{
    int u;
    int v;
    int weight;
    bool operator< (const graph_edge &rhs) const {
        return this->weight < rhs.weight;
    }

    bool operator>= (const graph_edge &rhs) const {
        return this->weight >= rhs.weight;
    }
};

graph_edge* find_mst(graph_edge edges[],  int n, int m) {
    quick_sort<graph_edge>(edges, 0, m);
    graph_edge* T;
    T = new graph_edge[n-1];

    int i=0;
    while(i<n-1 && m--) {
        graph_edge e = edges[m];
        bool flag1 = false;
        for(int j=0; j<i; j++) {
            if(T[j].u == e.u || T[j].v == e.u) flag1 = true;
        }
        bool flag2 = false;
        if(flag1) {
            for(int j=0; j<i; j++) {
                if(T[j].u == e.v || T[j].v == e.v) flag2 = true;
            }
        }
        if(!flag2) {
            T[i++] = e;
        }
    }
    return T;
}

graph_node* new_node(int n) {
    graph_node* node = new graph_node;
    node->vertex = n;
    node->link = NULL;
    return node;
}

graph_edge* graph() {
    int n, m;
    cout << "Enter number of users: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    
    graph_edge* edges;
    edges = new graph_edge[m];

    cout << "Enter the edges: ";
    int a, b;
    char c;

    for(int i=0; i<m; i++) {
        cin >> a >> b;
        if(i!=m-1) cin >> c;
        edges[i].u = a;
        edges[i].v = b;
    }

    int k;
    cout << "Enter K = ";
    cin >> k;

    for(int i=0; i<m; i++) {
        cout << "Weight of edge (" << edges[i].u << ", " << edges[i].v << ") = ";
        cin >> edges[i].weight;
    }

    graph_edge* T;
    T = find_mst(edges, n, m);

    graph_node** g;
    g = new graph_node*[n];

    int p=0;
    int i = n-1;
    while(i) {
        bool flag1 = false;
        for(int j=0; j<p; j++) {
            if(g[j]->vertex == T[i].u) flag1 = true;
        }
        if(!flag1) g[p++] = new_node(T[i].u);

        bool flag2 = false;
        for(int j=0; j<p; j++) {
            if(g[j]->vertex == T[i].u) flag2 = true;
        }
        if(!flag2) g[p++] = new_node(T[i].v);
    }

    return edges;
}


int main() {
    
    
    
}