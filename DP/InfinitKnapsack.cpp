// 找零問題
int main() {    //O(n^2)
    dp[0] = 1;
    for(ll i = 1; i <= n; i++) {
        for(ll j = a[i]; j < 30001; j++) { // 順著做過去
            dp[j] += dp[j-a[i]];
            if(dp[j-a[i]]) coin[j] = i; // 此金額當前拿ㄌ哪一個錢幣
        }
    }
    ll ans = dp[sum]; // sum = 所求金額
    while (sum) {
        ans.push_back(coin[sum]);
        sum -= a[coin[sum]];    // 遞迴找用過哪些錢幣
    }
}
