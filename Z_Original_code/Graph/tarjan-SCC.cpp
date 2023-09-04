#include <bits/stdc++.h>
using namespace std;
const int n = 16;
vector<vector<int>> graph;
int visit[n], low[n],t = 0;
int st[n], top =0;
bool instack[n];
int contract[n]; // 每個點收縮到的點
vector<vector<int>> block;
void dfs(int x,int parent){
    // cout <<x<<endl;
    visit[x] = low[x] = ++t;
	st[top++] = x;
	instack[x] = true;
    for(auto to: graph[x]){
        if(!visit[to])
            dfs(to,x);

        if(instack[to])
            low[x] = min(low[x],low[to]);
    }
    if(visit[x]==low[x]){ //scc 裡最早拜訪的
        int j;
        block.push_back({});
        do{
            j = st[--top];
            instack[j] = false;
            block[block.size()-1].push_back(j);
            contract[j] =x;
        }while(j!=x);
    }
}
int main(){
    graph = {
        {1},
        {3,4,5},
        {6},
        {2},
        {7},
        {11,15},
        {2,3},
        {4,6,9},
        {},
        {},
        {},
        {15},
        {14},
        {13,5},
        {15},
        {10,12,13}
    };
    for(int i =0;i<n;i++){
        if (!visit[i])
			dfs(i, i);
    }
    for(auto t: block){
        for(auto x:t){
            cout << x <<" ";
        }cout <<endl;
    }
}