for(int i = 0; i < 100005; i++) dp[i] = dp1[i] = 205;
dp[0] = dp1[0] = 0;
for(int i = 1; i <= n; i++) {
   for(int j = 1e5+1; j >= a[i]; j--) { // 到著做回來
       dp[j] = min(dp[j-a[i]] + 1, dp[j]);
   }
}
