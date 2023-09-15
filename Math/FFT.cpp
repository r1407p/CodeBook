//OI Wiki
#include <complex>
using cd = complex<double>;
const double PI = acos(-1);
void change(vector<cd> &y) {
	vector<int> rev(y.size());
	for (int i = 0; i < y.size(); ++i) {
		rev[i] = rev[i >> 1] >> 1;
		if (i & 1) {
			rev[i] |= y.size() >> 1;
		}
	}
	for (int i = 0; i < y.size(); ++i) {
		if (i < rev[i]) {
			swap(y[i], y[rev[i]]);
		}
	}
} 
void fft(vector<cd> &y, bool inv) {
	change(y);
	for (int h = 2; h <= y.size(); h <<= 1) {
		cd wn(cos(2 * PI / h), sin(2 * PI / h));
		for (int j = 0; j < y.size(); j += h) {
			cd w(1, 0);
			for (int k = j; k < j + h / 2; ++k) {
				cd u = y[k];
				cd t = w * y[k + h / 2];
				y[k] = u + t;
				y[k + h / 2] = u - t;
				w = w * wn;
			}
		}
	}
	if (inv) {
		reverse(begin(y) + 1, end(y));
		for (int i = 0; i < y.size(); ++i) {
			y[i] /= y.size();
		}
	}
}
void solve() {
	int n;
	int m = 1 << (__lg(n) + 1); //power of 2
	vector<cd> a(m), b(m);
	//...
	fft(a, 0);
	fft(b, 0);
	vector<cd> c(m);
	for (int i = 0; i < m; ++i) {
		c[i] = a[i] * b[i];
	}
	fft(c, 1);
	for (auto p: c) {
		int ans = int(p.real() + 0.25);
	}
}