int sz[maxn]{};
void dfs(int u, int lst) {
	sz[u] = 1;
	for (int v: g[u]) {
		if (v == lst) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
int findcentroid(int u, int lst, int n) {
	for (int v: g[u]) {
		if (v == lst) continue;
		if (2 * sz[v] >= n) return findcentroid(v, u, n);
	}
	return u;
}