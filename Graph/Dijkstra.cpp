#define maxn 200005
vector<int> dis(maxn,-1);
vector<int> parent(maxn,-1);
vector<bool> vis(maxn,false);
vector<vector<pair<int,int>>> graph;
void dijsktra(int source){
    dis[source] =0 ;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,source});
    while(!pq.empty()){
        int from  = pq.top().second;
        pq.pop();
        // cout <<vis[from]<<endl;
        if(vis[from])continue;
        vis[from] = true;
        for(auto next : graph[from]){
            int to = next.second;
            int weight = next.first;
            // cout <<from<<' ' <<to<<' ' <<weight;
            if(dis[from]+weight< dis[to] || dis[to]==-1){
                dis[to] = dis[from]+weight;
                parent[to] = from;
                pq.push({dis[from]+weight,to});
            }
        }
    }
}
int main(){
    int startpoint;
    dijsktra(startpoint);
    //dis and parent
}