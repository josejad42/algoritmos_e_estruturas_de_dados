#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Graph {
private:
    int n;
    vector<vector<int>> adj;

public:
    Graph(int n) {
        this->n = n;
        adj = vector<vector<int>>(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }
    }

    void add_edge(int u, int v, int w) {
        adj[u][v] = w;
    }

    vector<vector<int>> floyd_warshall() {
        vector<vector<int>> distances = adj;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (distances[i][k] != INF && distances[k][j] != INF) {
                        distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                    }
                }
            }
        }
        return distances;
    }
};
