#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>

using namespace std;
template<typename Q> Q &read(Q &x) {
	static char c, f;
	for(f = 0; c = getchar(), !isdigit(c); ) if(c == '-') f = 1;
	for(x = 0; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	if(f) x = -x; return x;
}
template<typename Q> Q read() {
	static Q x; read(x); return x;
}

typedef long long LL;
const int N = 50000 + 10;

struct Point {
	LL x, y;
	Point() {}
	Point(LL x, LL y) : x(x), y(y) {}
	Point operator - (const Point &rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
	LL f(LL k) const {
		return x * k + y;
	}
};

LL Cross(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

Point p[N];
LL k[N], f[N];

LL sqr(const LL &x) {
	return x * x;
}

int main() {
	freopen("code.in", "r", stdin);
	freopen("showsonDrz.out", "w", stdout);
	
	int n, c;
	scanf("%d%d", &n, &c); ++c;
	for(int i = 1; i <= n; i++) {
		scanf("%lld", k + i);
		k[i] += k[i-1] + 1;
	}
	
	int L = 0, R = 0;
	p[R++] = Point(0, 0);
	
	for(int i = 1; i <= n; i++) {
		while(L + 1 < R && p[L].f(k[i]) > p[L + 1].f(k[i])) L++;
		f[i] = p[L].f(k[i]) + sqr(k[i] - c);
		Point np(-2 * k[i], f[i] + k[i] * (k[i] + 2 * c));
		while(L + 1 < R && Cross(np - p[R - 2], np - p[R - 1]) >= 0) R--;
		p[R++] = np;
	}
	
	printf("%lld\n", f[n]);
	
	return 0;
}

