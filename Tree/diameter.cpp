#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int diameter = 0;
int dfs(int start, int parent){
    int h1 = 0, h2 = 0;
    for (auto child : graph[start]){
        if (child != parent){
            int h = dfs(child, start) + 1;
            if (h > h1){
                h2 = h1;
                h1 = h;
            }
            else if (h > h2){
                h2 = h;
            }
        }
    }
    diameter = max(diameter, h1 + h2);
    return h1;
}
// call diameter
int main(){
    dfs(0,-1);
    cout << diameter<<endl;
}