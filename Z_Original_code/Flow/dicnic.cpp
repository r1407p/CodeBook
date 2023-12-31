#include <bits/stdc++.h>
#define maxn 2005
#define INF 0x3f3f3f3f
using namespace std;
struct MaxFlow{
    struct edge{
        int  to, cap, flow,rev;
        edge( int v, int c, int f,int r) :  to(v), cap(c), flow(f),rev(r) {}
      };
    vector<edge> G[maxn];
    int s,t,dis[maxn],cur[maxn],vis[maxn];
    void add_edge(int from,int to,int cap){
        G[from].push_back(edge(to,cap,0,G[to].size()));
        G[to].push_back(edge(from,0,0,G[from].size()-1));
    }
    bool bfs(){
        memset(dis, -1, sizeof(dis));
        queue<int> qu;
        qu.push(s);
        dis[s] = 0; 
        while (!qu.empty()) {
            int from = qu.front();
            qu.pop();
            for (auto &e: G[from]) {
                if (dis[e.to]==-1 && e.cap != e.flow) { 
                    dis[e.to] = dis[from] + 1;
                    qu.push(e.to);
                }
            } 
        } 
        return dis[t]!=-1;
    }
    int dfs(int from,int cap){
        if(from==t ||cap==0)return cap;
        for(int &i = cur[from];i<G[from].size();i++){
            edge &e = G[from][i];
            if(dis[e.to]==dis[from]+1 && e.flow!=e.cap){ 
                int df = dfs(e.to,min(e.cap-e.flow,cap));
                if(df){
                    e.flow+=df;
                    G[e.to][e.rev].flow-=df; 
                    return df;
                }
            }
        }
        dis[from] = -1;
        return 0;
    }
    int Maxflow(int s,int t){
        this->s = s,this->t =t;
        int flow = 0;
        int df;
        while(bfs()){
            memset(cur,0,sizeof(cur));
            while(df = dfs(s,INF)){
                flow +=df;
            }
        }
        return flow;
    }
};