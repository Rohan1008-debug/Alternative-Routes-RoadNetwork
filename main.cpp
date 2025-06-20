#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj; // {node, weight}

public:
    Graph(int v) : V(v) {
        adj.resize(v);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected
    }

    void dijkstra(int src) {
        vector<int> dist(V, INF);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for (auto &edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[v] > d + weight) {
                    dist[v] = d + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i < V; ++i)
            cout << "To " << i << ": " << dist[i] << " units\n";
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 9);
    g.addEdge(3, 4, 4);

    g.dijkstra(0);

    return 0;
}
