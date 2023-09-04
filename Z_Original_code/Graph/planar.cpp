#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;
    Graph(int vertices) : V(vertices), adj(vertices) {}
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

bool containsSubgraph(const Graph& graph, const vector<int>& subgraph) {
    unordered_set<int> subgraphVertices(subgraph.begin(), subgraph.end());
    for (int vertex : subgraphVertices) {
        for (int neighbor : graph.adj[vertex]) {
            if (subgraphVertices.count(neighbor) == 0) {
                bool found = true;
                for (int v : subgraph) {
                    if (v != vertex && v != neighbor) {
                        if (graph.adj[v].size() < 3) {
                            found = false;
                            break;
                        }
                    }
                }
                if (found)
                    return true;
            }
        }
    }
    return false;
}

bool isPlanar(const Graph& graph) {
    // Subgraphs isomorphic to K₅ and K₃,₃
    vector<int> k5 = {0, 1, 2, 3, 4};       // Vertices of K₅
    vector<int> k33a = {0, 1, 2};           // Vertices of K₃,₃ (part A)
    vector<int> k33b = {3, 4, 5};           // Vertices of K₃,₃ (part B)

    if (containsSubgraph(graph, k5) || containsSubgraph(graph, k33a) || containsSubgraph(graph, k33b)) {
        return false; // The graph is non-planar
    }
    return true; // The graph is planar
}

int main() {
    int vertices, edges;
    cin >> vertices;
    cin >> edges;

    Graph graph(vertices);
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }
    if (isPlanar(graph)) {
        cout << "The graph is planar." << endl;
    } else {
        cout << "The graph is non-planar." << endl;
    }

    return 0;
}
