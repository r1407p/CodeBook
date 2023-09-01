const ll inf = 2000000000;
struct Point {
	ll x, y;
	Point(ll x = 0, ll y = 0):x(x), y(y){}
	Point operator+(const Point p) const {
		return Point(x + p.x, y + p.y); }
	Point operator-(const Point p) const {
		return Point(x - p.x, y - p.y); }
	ll operator*(const Point p) const { //dot
		return x * p.x + y * p.y; }
	ll operator^(const Point p) const { //cross
		return x * p.y - y * p.x; }
};
bool onseg(Point a, Point b, Point o) {
	return ((a - o) ^ (b - o)) == 0 && ((a - o) * (b - o)) <= 0;
}
int ori(Point a, Point b, Point o) {
	ll w = (a - o) ^ (b - o);
	return (w ? (w > 0 ? 1 : -1) : 0);
}
bool inters(Point a, Point b, Point c, Point d) {
	if (onseg(a, b, c) || onseg(a, b, d)) return 1;
	if (onseg(c, d, a) || onseg(c, d, b)) return 1;
	if (ori(a, b, c) * ori(a, b, d) < 0 && ori(c, d, a) * ori(c, d, b) < 0) return 1;
	return 0;
}
Point poly[maxn];
void solve(int n, Point p) {
	poly[n] = poly[0];
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (onseg(poly[i], poly[i + 1], p)) {
			cnt = -1;
			break;
		}
		if (inters(poly[i], poly[i + 1], p, Point(inf, p.y))) {
			++cnt;
		}
		Point hi = (poly[i].y > poly[i + 1].y ? poly[i] : poly[i + 1]);
		if (hi.y == p.y && hi.x > p.x) {
			--cnt;
		}
	}
	if (cnt < 0)
		cout << "BOUNDARY\n";
	else if (cnt % 2)
		cout << "INSIDE\n";
	else
		cout << "OUTSIDE\n";
}