using pdd = pair<double, double>;
#define F first
#define S second
pdd operator-(pdd a, pdd b) {
	return {a.F - b.F, a.S - b.S};
}
double cross(pdd a, pdd b) {
	return a.F * b.S - a.S * b.F;
}
void solve() {
	int n;
	cin >> n;
	vector<pdd> pnts;
	for (int i = 0; i < n; ++i) {
		double x, y;
		cin >> x >> y;
		pnts.push_back(x, y);
	}
	sort(iter(pnts));
	vector<pdd> hull;
	for (int i = 0; i < 2; ++i) {
		int t = hull.size();
		for (pdd j: pnts) {
			while(hull.size() - t >= 2 && cross(j - hull[hull.size() - 2], hull.back() - hull[hull.size() - 2]) >= 0)
				hull.pop_back();
			hull.push_back(j);
		}
		hull.pop_back();
		reverse(iter(pnts));
	}
	double area = 0;
	for (int i=0; i < hull.size(); ++i){
		area += cross(hull[i], hull[(i + 1) % hull.size()]);
	}
	area /= 2.0;
}