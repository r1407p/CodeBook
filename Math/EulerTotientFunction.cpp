ll phi[maxn];
for (int i = 0; i < maxn; ++i) {
	phi[i] = i;
}
for (int i = 2; i < maxn; ++i) if (phi[i] == i) {
	phi[i] = i - 1; //prime
	for (int j = 2; i*j < maxn; ++j) { //overflow
		phi[i*j] = (phi[i*j] / i) * (i - 1);
	}
}