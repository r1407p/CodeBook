int sz[maxn]{};
bool ok[maxn]{};
int get_subtree_size(int u, int lst) {
	sz[u] = 1;
	for (int v: g[u]) {
		if (v == lst || ok[v]) continue;
		sz[u] += get_subtree_size(v, u);
	}
	return sz[u];
}
int get_centroid(int u, int lst, int tree_size) {
	for (int v: g[u]) {
		if (v == lst || ok[v]) continue;
		if (2 * sz[v] >= tree_size) {
			return get_centroid(v, u, tree_size);
		}
	}
	return u;
}
void centroid_decomp(int u = 1) { //1-based
	int centroid = get_centroid(u, u, get_subtree_size(u, u));
	//...
	ok[centroid] = 1;
	for (int v: g[centroid]) if (!ok[v]) {
		centroid_decomp(v);
	}
}