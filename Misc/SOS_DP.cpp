int n = 20;
vector<int> a(1<<n);
vector<int> sos(1<<n);
//O(3^n)
for (int i = 0; i < (1<<n); ++i) {
	sos[i] = a[0];
	//iterate over all subsets of i
	for (int j = i; j > 0; j = (j - 1) & i) {
		sos[i] += a[j];
	}
}
//O(3^n)
vector<vector<int>> dp(1<<n, vector<int>(n + 1));
for (int i = 0; i < (1<<n); ++i) {
	dp[i][0] = a[i];
	for (int j = 1; j <= n; ++j) {
		dp[i][j] = dp[i][j - 1];
		if (i & (1 << (j - 1))) {
			dp[i][j] += dp[i - (1 << (j - 1))][j - 1];
		}
	}
	sos[i] = dp[i][n];
}