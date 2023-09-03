int a[N], sp[__lg(N) + 1][N]{};
void init(int n) { //0-based
	for (int i = 0; i < n; ++i) {
		sp[0][i] = a[i];
	}
	for (int i = 0; i < __lg(n); ++i) {
		for (int j = 0; j+(1<<i) < n; ++j) {
			sp[i + 1][j] = max(sp[i][j], sp[i][j+(1<<i)]);
		}
	}
}
int query(int l, int r) { //[l, r]
	int p = __lg(r - l + 1);
	return max(sp[p][l], sp[p][r-(1<<p)+1]);
}