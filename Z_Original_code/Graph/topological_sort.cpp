
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> visit(10,0);
vector<int> order;
int n;
bool cycle;		// 記錄DFS的過程中是否偵測到環
void DFS(int i)
{
	if (visit[i] == 1) {cycle = true; return;}
	if (visit[i] == 2) return;
	visit[i] = 1;
	for(auto to :graph[i])
        DFS(to);
	visit[i] = 2;
    order.push_back(i);
}


int main() {
    graph = {
        {1, 2},
        {3},
        {3, 4},
        {4},
        {}
    };
    n = 5;
	cycle = false; 
	for (int i=0; i<n; ++i){
		if (!visit[i])
			DFS(i);
    }
	if (cycle)
		cout << "圖上有環";
	else
		for (int i=n-1; i>=0; --i)
			cout << order[i];
}