#include<bits/stdc++.h>
using namespace std;
// Perform DFS to find the farthest node and its distance from the given node
pair<int, int> dfs(int node, int distance, vector<bool>& visited, const vector<vector<int>>& adj_list) {
    visited[node] = true;
    int max_distance = distance;
    int farthest_node = node;
    
    for (int neighbor : adj_list[node]) {
        if (!visited[neighbor]) {
            auto result = dfs(neighbor, distance + 1, visited, adj_list);
            if (result.first > max_distance) {
                max_distance = result.first;
                farthest_node = result.second;
            }
        }
    }
    
    return make_pair(max_distance, farthest_node);
}

// Calculate the radius of the tree using DFS
int tree_radius(const vector<vector<int>>& adj_list) {
    int num_nodes = adj_list.size();
    vector<bool> visited(num_nodes, false);
    
    // Find the farthest node from the root (node 0)
    auto farthest_result = dfs(0, 0, visited, adj_list);
    
    // Reset visited array
    fill(visited.begin(), visited.end(), false);
    
    // Calculate the distance from the farthest node
    int radius = dfs(farthest_result.second, 0, visited, adj_list).first;
    
    return radius;
}

int main() {
    vector<vector<int>> adj_list = {
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1},
        {1},
        {2}
    };
    
    int radius = tree_radius(adj_list);
    cout << "Tree radius: " << radius << endl;
    
    return 0;
}