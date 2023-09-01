#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class TwoSAT {
public:
    TwoSAT(int n) : n(n), graph(2 * n), visited(2 * n, false) {}

    void addClause(int a, int b) {// 0-base;
        a *=2;
        b *=2;
        // Add implications (~a => b) and (~b => a)
        graph[a ^ 1].push_back(b);
        graph[b ^ 1].push_back(a);
    }

    bool solve() {
        // Find SCCs and check for contradictions
        for (int i = 0; i < 2 * n; ++i) {
            if (!visited[i]) {
                dfs1(i);
            }
        }
        reverse(processingOrder.begin(), processingOrder.end());//topological sort
        for (int i = 0; i < 2 * n; ++i) {
            visited[i] = false;
        }
        for (int node : processingOrder) {
            if (!visited[node]) {
                scc.clear();
                dfs2(node);
                if (!checkSCCConsistency()) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    int n;
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> processingOrder;
    vector<int> scc;

    void dfs1(int node) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs1(neighbor);
            }
        }
        processingOrder.push_back(node);
    }

    void dfs2(int node) {
        visited[node] = true;
        scc.push_back(node);
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs2(neighbor);
            }
        }
    }

    bool checkSCCConsistency() {
        for (int node : scc) {
            if (find(scc.begin(), scc.end(), node ^ 1) != scc.end()) {
                return false; // Contradiction found in the same SCC
            }
        }
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m; // Number of variables and clauses

    TwoSAT twoSat(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        twoSat.addClause(a, b);
    }

    if (twoSat.solve()) {
        cout << "Satisfiable" << endl;
    } else {
        cout << "Unsatisfiable" << endl;
    }

    return 0;
}