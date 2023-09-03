int F[maxn]{};
vector<int> match(string& s, string& t) {
	int p = F[0] = -1;
	for (int i = 1; i < t.size(); ++i) {
		while (p != -1 && t[p + 1] != t[i]) p = F[p];
		if (t[p + 1] == t[i]) ++p;
		F[i] = p;
	}
	p = -1;
	vector<int> v;
	for (int i = 0; i < s.size(); ++i) {
		while (p != -1 && t[p + 1] != s[i]) p = F[p];
		if (t[p + 1] == s[i]) ++p;
		if (p == t.size() - 1) v.push_back(i - p), p = F[p];
	}
	return v; //0-based
}