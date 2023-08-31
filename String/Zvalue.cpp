vector<int> Zvalue(string &s) { //t + # + s
	vector<int> Z(s.size());
	int x = 0, y = 0;
	for (int i=0; i<s.size(); ++i) {
		Z[i] = max(0, min(y - i + 1, Z[i - x]));
		while (i + Z[i] < s.size() && s[Z[i]] == s[i + Z[i]])
			x = i, y = i + Z[i], ++Z[i];
	}
	return Z;
}