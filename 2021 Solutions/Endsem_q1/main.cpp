#include<iostream>
#include<vector>

using namespace std;

struct graph_edge{
    int u;
    int v;
    int weight;
};

struct graph_node{
    int vertex;
    graph_node* link;
};


class graph {
    public:
        vector<graph_edge> edges;

        graph(int n, int m) {
            graph_node* g[n];
            for(int i=0; i<n; i++) {
                graph_node* node = new graph_node;
                node->vertex = i+1;
                node->link = NULL;
                g[i] = node;
            }

            cout << "Enter the edges: ";
            int a, b;
            char c;

            for(int i=0; i<m; i++) {
                cin >> a >> b;
                graph_node* node1 = g[a-1];
                graph_node* node2 = g[b-1];
                g[a-1]->link = node2;
                g[b-1]->link = node1;
                if(i!=m-1) cin >> c;

                graph_edge e;
                e.u = a;
                e.v = b;
                edges.push_back(e);
            }

            int k;
            cout << "Enter K = ";
            cin >> k;

            for(int i=0; i<m; i++) {
                cout << "Weight of edge (" << edges[i].u << ", " << edges[i].v << ") = ";
                cin >> edges[i].weight;
            }
        }

        int partition(int low, int high) {
            int pIndex = low;

        }

        void quick_sort(int low, int high) {
            if(low>=high) return;
            int pIndex = partition(low, high);
            quick_sort(low, pIndex-1);
            quick_sort(pIndex+1, high);
        }

        void find_mst(int n) {
            vector<graph_edge> T;
            while(T.size()<n && !edges.empty()) {
                
            }
        }
};

int main() {
    int n, m;
    cout << "Enter number of users: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
}