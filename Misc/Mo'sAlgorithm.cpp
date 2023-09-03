struct Query {
	int L, R;
	//...
};
vector<Query> query;
void solve() { //K = n / sqrt(q)
	sort(iter(query), [&](Query &a, Query &b) {
		if (a.L / K != b.L / K) return a.L < b.L;
		return a.L / K % 2 ? a.R < b.R : a.R > b.R;
	});
	int L = 0, R = 0;
	for (auto x: query) {
		while (R < x.R) add(arr[++R]);
		while (L > x.L) add(arr[--L]);
		while (R > x.R) sub(arr[R--]);
		while (L < x.L) sub(arr[L++]);
		//...
	}
}