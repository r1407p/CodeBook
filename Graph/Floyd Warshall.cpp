#define maxn 2005
vector<vector<int>> dis(maxn,vector<int>(maxn,9999999));
vector<vector<int>> mid(maxn,vector<int>(maxn,-1));
vector<vector<pair<int,int>>> graph;

void floyd_warshall(int n ){ // n is n nodes
	for(int i =0;i<n;i++){
        for(auto path:graph[i]){
            dis[i][path.second] = path.first;
        }
    }
	for (int i=0; i<n; i++)
		dis[i][i] = 0;
	for (int k=0; k<n; k++){
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				if (dis[i][k] + dis[k][j] < dis[i][j] || dis[i][j]==-1){
					dis[i][j] = dis[i][k] + dis[k][j];
					mid[i][j] = k;	// 由i點走到j點經過了k點
				}
            }
        }
    }
}
void find_path(int s, int t){		// 印出最短路徑
	if (mid[s][t] == -1) return;	// 沒有中繼點就結束
	find_path(s, mid[s][t]);		// 前半段最短路徑
	cout << mid[s][t];			// 中繼點
	find_path(mid[s][t], t);		// 後半段最短路徑
}
int main(){
    int n;
    floyd_warshall(n);
    for(int i =0;i<4;i++){
        for(int j = 0 ; j <4;j++)
            cout << dis[i][j]<<" ";
        cout << endl;
    } 
    find_path(0,2);
}