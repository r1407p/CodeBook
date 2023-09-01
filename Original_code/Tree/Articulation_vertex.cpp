#include<bits/stdc++.h>
using namespace std;
const int n = 9;
int t =0;
vector<int> disc(n,-1); // Discovery time
vector<int> low(n,-1); // Low time
vector<int> parent_array(n,-1); // Parent in DFS tree
vector<bool> visited(n,false);  
vector<bool> is_articulation(n,false);
vector<vector<int>> graph; 
void dfs_articulation(int node, int parent) {
    visited[node] = true;
    disc[node] = t;
    low[node] = t;
    t++;
    int children = 0;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            children++;
            parent_array[neighbor] = node;
            dfs_articulation(neighbor, node);
            low[node] = min(low[node], low[neighbor]);

            if (low[neighbor] >= disc[node] && parent != -1) {
                is_articulation[node] = true;
            }
        } else if (neighbor != parent) {
            low[node] = min(low[node], disc[neighbor]);
        }
    }

    if (parent == -1 && children > 1) {
        is_articulation[node] = true;
    }
}
int main(){
    graph = {
        {1,2},
        {3},
        {5,6},
        {7},
        {},
        {},
        {},
        {8},
        {4},
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs_articulation(i, -1);
        }
    }
    cout << "Articulation Points: ";
    for (int i = 0; i < n; ++i) {
        if (is_articulation[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}