double dis(pdd a, pdd b) {
	double dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}
double sq(double x) {
	return x * x;
}
pdd excenter(pdd p1, pdd p2, pdd p3) {
	double a1 = p1.x - p2.x, a2 = p1.x - p3.x;
	double b1 = p1.y - p2.y, b2 = p1.y - p3.y;
	double c1 = (sq(p1.x) - sq(p2.x) + sq(p1.y) - sq(p2.y)) / 2;
	double c2 = (sq(p1.x) - sq(p3.x) + sq(p1.y) - sq(p3.y)) / 2;
	double dd = a1*b2 - a2*b1;
	return {(c1*b2 - c2*b1) / dd, (a1*c2 - a2*c1) / dd};
}
void solve(pdd a[], int n) {
	shuffle(a, a + n, rng);
	pdd center = a[0];
	double r = 0;
	for (int i = 1; i < n; ++i) {
		if (dis(center, a[i]) <= r) continue;
		center = a[i], r = 0;
		for (int j = 0; j < i; ++j) {
			if (dis(center, a[j]) <= r) continue;
			center.x = (a[i].x + a[j].x) / 2;
			center.y = (a[i].y + a[j].y) / 2;
			r = dis(center, a[i]);
			for (int k = 0; k < j; ++k) {
				if (dis(center, a[k]) <= r) continue;
				center = excenter(a[i], a[j], a[k]);
				r = dis(center, a[i]);
			}
		}
	}
	cout << fixed << setprecision(10) << r << '\n';
	cout << center.x << ' ' << center.y << '\n';
}