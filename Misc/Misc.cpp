mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int lb, int ub) {
	return uniform_int_distribution<int>(lb, ub)(rng);
} //static unsigned x = 19; ++(x *= 0xdefaced);

#define SECs ((double)clock() / CLOCKS_PER_SEC)

struct KeyHasher {
	size_t operator()(const Key& k) const {
		return k.first + k.second * 100000;
}	};
typedef unordered_map<Key,int,KeyHasher> map_t;

__lg
__gcd

__builtin_popcount  // 二進位有幾個1
__builtin_clz       // 左起第一個1之前0的個數
__builtin_parity    // 1的個數的奇偶性