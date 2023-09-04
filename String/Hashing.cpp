const ll P = 401, M = 998244353;

ll hashes[10005], modp[10005];
ll hashp(string s, bool saveval) {
	ll val = 0;
	int index = 0;
	for (char c: s) {
		val = ((val * P) % M + c) % M;
		if (saveval) hashes[index++] = val;
	}
	return val;
}
void init(int base, int exp) {
	ll b = 1;
	modp[0] = 1;
	for (int i = 0; i < exp; i++) {
		b = (b * base) % M;
		modp[i + 1] = b;
	}
}
ll subseq(int l, int r) { //[l, r]
	if (l == 0) return hashes[r];
	return ((hashes[r] - hashes[l-1] * modp[r-l+1]) % M + M) % M;
}