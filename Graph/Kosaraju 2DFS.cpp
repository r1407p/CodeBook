const int n = 16;
vector<vector<int>> graph;
vector<vector<int>> reverse_graph;
int visit[n];
int contract[n]; // 每個點收縮到的點
vector<vector<int>> block;
vector<int> finish;//fake topological sort
// need graph and reverse praph
void dfs1(int x){ 
    visit[x] = true;
    for(auto to:graph[x]){
        if(!visit[to]){
            dfs1(to);
        }
    }
    finish.push_back(x);
}
void dfs2(int x,int c){ 
    contract[x] = c;
    block[c].push_back(x);
    visit[x] = true; 
    for(auto to:reverse_graph[x]){ 
        if(!visit[to]){
            dfs2(to,c);
        }
    }  
}
int main(){
    graph = {};
    reverse_graph = {};
     
    for(int i =0;i<n;i++){
        if (!visit[i])
			dfs1(i);
    }
    int c =0;
    memset(visit,0,sizeof(visit));
    for(int i =  n-1;i>=0;i--){
        if(!visit[finish[i]]){ 
            block.push_back({});
            dfs2(finish[i],c++);
        }
    }
    for(auto t: block){
        for(auto x:t){
            cout << x <<" ";
        }cout <<endl;
    }
}