#include<bits/stdc++.h>
using namespace std;
const int n = 9;
vector<vector<int>> graph; 
vector<int> visit(n,0);
vector<int> trace(n,0);
vector<vector<int>> bridge;
int t = 0;
void dfs(int x,int parent){
    visit[x] = ++t;
    trace[x] =x;// 最高祖先預設為自己
    for(auto to:graph[x]){
        if(visit[to]){ //back edge
            if(to!=parent  ){
                trace[x] = to;
            }
        }else{  //treeedge
            dfs(to,x);
            if (visit[trace[to]] < visit[trace[x]])
					trace[x] = trace[to];

				// 子樹回不到祖先暨自身。
				if (visit[trace[to]] > visit[x])
					bridge.push_back({x,to});
        }
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
    for(int i =0;i<9;i++){
        if(!visit[i])
            dfs(i,-1);
    }
    for(auto x: bridge){
        cout << x[0]<<" "<< x[1]<<endl;
    }
}