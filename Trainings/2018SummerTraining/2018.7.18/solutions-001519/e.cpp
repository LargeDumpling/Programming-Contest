#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define UNS64 "%I64u"
#else
#define UNS64 "%llu"
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<pair<int, int>, __gnu_pbds::null_type,
	less<pair<int, int>>,
	__gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update> oset;
const int MAXN = 50005;
vector<int> E[MAXN];
int siz[MAXN];
void getSizes(int x, int p = -1) {
	siz[x] = 1;
	for (int y : E[x]) {
		if (y == p) continue;
		getSizes(y, x);
		siz[x] += siz[y];
	}
}
int findCentroid(int x, int n, int p = -1) {
	for (int y : E[x]) {
		if (y == p) continue;
		if (siz[y] > n / 2)
			return findCentroid(y, n, x);
	}
	return x;
}
int vn;
pair<pair<int, int>, pair<int, int>> vals[MAXN];
void go(int x, int p, int sub, int mn, int mx, int h = 1) {
	mn = min(mn, x);
	mx = max(mx, x);
	vals[vn++] = {{mx, mn}, {h, sub}};
	for (int y : E[x]) {
		if (y == p) continue;
		go(y, x, sub, mn, mx, h + 1);
	}
}
ll ans;
map<int, oset> flen[MAXN], flenmn[MAXN * 2];
void decompose(int x) {
	getSizes(x);
	int c = findCentroid(x, siz[x]);
	vn = 0;
	for (int y : E[c]) {
		// deal with child subtree y
		go(y, c, y, c, c);
	}
	sort(vals, vals + vn);
	++ans; // For centroid-only path
	for (int i = 0; i < vn; ++i) {
		int mx = vals[i].first.first, mn = vals[i].first.second;
		int len = vals[i].second.first, sub = vals[i].second.second;
		if (mx - mn == len) ++ans;
		// For those whose min > mn, we need length = mx - mn - len
		int reqlen = mx - mn - len;
		ans += flen[reqlen][0].size() - flen[reqlen][0].order_of_key({mn, INT_MAX});
		// Remove those from same subtree
		ans -= flen[reqlen][sub].size() - flen[reqlen][sub].order_of_key({mn, INT_MAX});
		// For those whose min <= mn, we need mx - len = min + length
		int reqlenmn = mx - len;
		ans += flenmn[reqlenmn][0].order_of_key({mn, INT_MAX});
		ans -= flenmn[reqlenmn][sub].order_of_key({mn, INT_MAX});
		flen[len][0].insert({mn, i});
		flen[len][sub].insert({mn, i});
		flenmn[mn + len][0].insert({mn, i});
		flenmn[mn + len][sub].insert({mn, i});
	}
	for (int i = 0; i < vn; ++i) {
		int mn = vals[i].first.second;
		int len = vals[i].second.first, sub = vals[i].second.second;
		flen[len][0].clear();
		flen[len][sub].clear();
		flenmn[mn + len][0].clear();
		flenmn[mn + len][sub].clear();
	}
	for (int y : E[c]) {
		for (auto it = E[y].begin();; ++it)
			if (*it == c) {
				E[y].erase(it);
				break;
			}
		decompose(y);
	}
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i < N; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	decompose(1);
	printf(INT64 "\n", ans);
}
