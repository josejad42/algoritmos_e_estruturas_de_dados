#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Graph {
private:
    int n;
    list<pair<int, int>> *adj;
    vector<int> parents;
    vector<bool> visited;

public:
    Graph(int n) {
        this->n = n;
        adj = new list<pair<int, int>>[n];
        parents = vector<int>(n, -1);
        visited = vector<bool>(n, false);
    }

    void add_edge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void setMark(int u, bool mark) {
        visited[u] = mark;
    }

    bool getMark(int u) {
        return visited[u];
    }

    vector<int> dijkstra(int source) {
        vector<int> distances(n, INF);
        distances[source] = 0;
        setMark(source, true);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, source));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (!getMark(v) && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    parents[v] = u;
                    pq.push(make_pair(distances[v], v));
                }
            }

            setMark(u, true);
        }

        return distances;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }

    int source = 0;
    vector<int> distances = g.dijkstra(0);

    return 0;
}
