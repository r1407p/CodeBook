int dep[N], pa[N], sz[N], nxt[N];
int id[N], rt[N];
int dfs(int u, int lst, int d = 0) {
	dep[u] = d;
	pa[u] = lst;
	sz[u] = 1;
	nxt[u] = -1;
	for (int v: g[u]) {
		if (v == lst) continue;
		sz[u] += dfs(v, u, d + 1);
		if (nxt[u] == -1 || sz[v] > sz[nxt[u]]) {
			nxt[u] = v;
		}
	}
	return sz[u];
}
int tn = 0;
void mapId(int u, int lst, int root) {
	id[u] = ++tn;
	rt[u] = root;
	if (~nxt[u]) mapId(nxt[u], u, root);
	for (int v: g[u]) {
		if (v == lst || v == nxt[u]) continue;
		mapId(v, u, v);
	}
}
void solve() {
	while (rt[a] != rt[b]) {
		if (dep[rt[a]] > dep[rt[b]]) swap(a, b);
		//...
		b = pa[rt[b]];
	}
	if (a != b) {
		if (id[a] > id[b]) swap(a, b);
		//...
	} else {
		//...
	}
}