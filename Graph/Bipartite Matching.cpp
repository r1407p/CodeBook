const int MAXN = 100;

struct Bipartite_matching{
    int mx[MAXN], my[MAXN], vy[MAXN]; //matchX, matchY, visitY
    vector<int> edge[MAXN]; //adjcent list;
    int x_cnt;
    bool dfs(int x){
        for(auto y: edge[x]){ //對 x 可以碰到的邊進行檢查
            if(vy[y] == 1) continue; //避免遞迴 error
            
            vy[y] = 1;
            if(my[y] == -1 || dfs(my[y])){ //分析 3
                mx[x] = y;
                my[y] = x;
                return true;
            }
        }
        return false; //分析 4
    }

    int bipartite_matching(){
        memset(mx, -1, sizeof(mx)); //分析 1,2
        memset(my, -1, sizeof(my));
        int ans = 0;
        for(int i = 0; i < x_cnt; i++){  //對每一個 x 節點進行 DFS(最大匹配)
            memset(vy, 0, sizeof(vy));
            if(dfs(i)) ans++;
        }
        return ans;
    }
    vector<vector<int>> get_match(){
        vector<vector<int>> res;
        for(int i =0 ;i<x_cnt;i++){
            if(mx[i]!=-1){
                res.push_back({i,mx[i]});
            }
        }
        return res;
    }
    void add_edge(int i,int j){
        edge[i].push_back(j);
    }
    void init(int x){
        x_cnt = x;
    }
};
int main(){
    int n,m;
    Bipartite_matching bm;
    for(int i = 0;i<m;i++){
        int a , b;cin >>a>>b;
        bm.add_edge(a,b);
    }
    bm.init(n);
    cout << bm.bipartite_matching()<<endl;
    auto match = bm.get_match();
    for(auto t: match){  
        cout << t[0]<<" "<<t[1]<<endl;
    }

}