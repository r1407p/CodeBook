#include<bits/stdc++.h>
using namespace std;
int n, logn,t=0;
vector<vector<int>> graph; 
vector<vector<int>> ancestor;
vector<int> tin, tout;
void dfs(int x){
    tin[x] = t++;
	for(auto y:graph[x]){
        if(y!= ancestor[x][0]){
            ancestor[y][0] = x;
            dfs(y);
        }
    }
    tout[x] = t++;
}
bool is_ancestor(int x, int y){
	return tin[x] <= tin[y] && tout[x] >= tout[y];
}
void table(){
	for (int i=1; i<logn; i++)// 上兩輩祖先、上四輩祖先、上八輩祖先、……
		for (int x=0; x<n; ++x)
			ancestor[x][i] = ancestor[ancestor[x][i-1]][i-1];
}

int kth_ancestor(int x, int k){
	for (int i=0; i<logn; i++)// k拆解成二進位位數，找到第k祖先。不斷上升逼近之。
		if (k & (1<<i))
			x = ancestor[x][i];
	return x;
}

void rooted_tree(int root){// build the tree with root at "root"
	ancestor[root][0] = root;
	dfs(root);
	table();
}
int LCA(int x,int y){
    if (is_ancestor(x, y)) return x;
	if (is_ancestor(y, x)) return y;
    for (int i=logn-1; i>=0; i--)
		if (!is_ancestor(ancestor[x][i], y))
			x = ancestor[x][i];
	return ancestor[x][0];
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
    n = 9;
    logn = ceil(log2(n));
    ancestor.resize(n,vector<int>(logn));
    tin.resize(n);
    tout.resize(n);

    rooted_tree(0);
    while(true){
        int a,b;
        cin >>a>>b;
        cout <<LCA(a,b)<<endl;;
    }
}