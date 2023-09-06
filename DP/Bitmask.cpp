// n個城市，m個單向邊，求從1出發走到n的所有路徑數
// 遞迴版本，存反向圖
ll alln;
ll tbl[20][1<<20]; // 建表
ll dp(int i, ll vs) {
    if(tbl[i][vs]) return tbl[i][vs];
    if(vs == alln && i == 0) return 1;
    if(vs == alln || i == 0) return 0;
    ll r = 0;
    For(j, n) {
        if(!g[i][j]) continue;
        if(vs&(1<<j)) continue;
        r += dp(j, vs|(1<<j))*g[i][j];
        r %= mod;
    }
    return tbl[i][vs] = r % mod;
}

alln = (1<<n)-1;
ans = dp(n-1, 1<<(n-1))%mod; //從最後一點遞迴回去，bitmask n-1位為1，其餘為0

// TLE版本，迴圈版很難壓常，存正向圖
N = (1<<n)-1; // 可表示n個bit的bitmask
dp[0][1] = 1;
for(int mask = 1; mask <= N; mask++) {
    for(int i = 0; i < n; i++) {
        if(!(1 & mask>>i)) continue;
        int mask2 = mask - (1<<i);
        for(int j = 0; j < n; j++) {
            if(!(1 & mask2>>j) || g[j][i] == 0) continue;
            dp[i][mask] += dp[j][mask2]*g[j][i]; // 非簡單圖，可能有重複單向邊，g[i][j]存邊數
            dp[i][mask] %= mod;
        }
    }
}
cout << dp[n-1][N] % mod << '\n';
