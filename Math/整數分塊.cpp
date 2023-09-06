for(int l=1,r;l<=n;l=r+1){
    r=n/(n/l);
    ans+=(r-l+1)*(n/l);
}

// sum is the prefix of mobius function
// 求 1<=x<=n, 1<=y<=m 且 gcd(x,y)==1 的二元组数量。
for(int l=1,r;l<=min(n,m);l=r+1){
    r=min(n/(n/l),m/(m/l));
    ans+=(sum[r]-sum[l-1])*(n/l)*(m/l);
}
