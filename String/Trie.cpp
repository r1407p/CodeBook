struct node {
	int ch[26]{};
	int cnt = 0;
};
struct Trie {
	vector<node> t;
	void init() {
		t.clear();
		t.emplace_back(node());
	}
	void insert(string s) {
		int ptr = 0;
		for (char i: s) {
			if (!t[ptr].ch[i - 'a']) {
				t[ptr].ch[i - 'a'] = (int)t.size();
				t.emplace_back(node());
			}
			ptr = t[ptr].ch[i - 'a'];
		}
		t[ptr].cnt++;
	}
} trie;