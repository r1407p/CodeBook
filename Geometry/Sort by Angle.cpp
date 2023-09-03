bool cmp(pii a, pii b) {
#define is_neg(k) (k.y < 0 || (k.y == 0 && k.x < 0));
	int A = is_neg(a), B = is_neg(b);
	if (A != B)
		return A < B;
	if (cross(a, b) == 0)
		return (a.x*a.x + a.y*a.y) < (b.x*b.x + b.y*b.y);
	return cross(a, b) > 0;
}