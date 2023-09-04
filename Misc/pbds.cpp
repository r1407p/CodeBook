#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
	ordered_set<int64_t> rbt;
	// .insert(x); .erase(x)
	// .lower_bound(x); .upper_bound(x): iter
	// .find_by_order(k): find k-th small value(iter)
	// .order_of_key(x): return x is k-th big
	// .join(rbt2): merge with no mutiple same element
	// .split(key, rbt2): rbt keeps value <= key, others to rbt2
}