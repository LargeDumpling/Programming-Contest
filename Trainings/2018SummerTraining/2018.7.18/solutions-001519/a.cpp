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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXS = 1 << 20;
const int MAXN = 200005;
int P[MAXN], R[MAXN], C[MAXN], sccRoot[MAXN], xn, xs[MAXN * 2];
multiset<int> scc[MAXN];
bool used[MAXN];
vector<int> seg[MAXS];
void update(int sn, int s, int e, int q, int qs, int qe) {
	if (qs <= s && e <= qe) {
		seg[sn].push_back(q);
		return;
	}
	int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
	if (qs <= m) update(lsn, s, m, q, qs, qe);
	if (qe > m) update(rsn, m + 1, e, q, qs, qe);
}
void getIntervals(int sn, int s, int e, int p, vector<int> &ret) {
	ret.insert(ret.end(), seg[sn].begin(), seg[sn].end());
	seg[sn].clear();
	if (s == e) return;
	int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
	if (p <= m) getIntervals(lsn, s, m, p, ret);
	if (p > m) getIntervals(rsn, m + 1, e, p, ret);
}
int discretize(int x) {
	// Returns discrete segment that contains x
	return upper_bound(xs, xs + xn, x) - xs - 1;
}
void backDfs(int v, int root) {
	used[v] = true;
	sccRoot[v] = root;
	scc[root].insert(C[v]);
	vector<int> intervals;
	getIntervals(1, 0, xn - 1, discretize(P[v]), intervals);
	for (int i : intervals) {
		if (used[i]) continue;
		backDfs(i, root);
	}
}
stack<int> S;
set<pair<int, int>> unvisited;
void forwardDfs(int v, bool record = true) {
	unvisited.erase({P[v], v});
	used[v] = true;
	for (;;) {
		auto it = unvisited.lower_bound({P[v] - R[v], 0});
		if (it == unvisited.end() || P[it->second] > P[v] + R[v]) break;
		forwardDfs(it->second, record);
	}
	if (record) S.push(v);
}
int main() {
	int N, Q;
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d%d", &P[i], &R[i], &C[i]);
		unvisited.insert({P[i], i});
		xs[xn++] = P[i] - R[i];
		xs[xn++] = P[i] + R[i] + 1;
	}
	sort(xs, xs + xn);
	xn = unique(xs, xs + xn) - xs;
	for (int i = 1; i <= N; ++i) {
		update(1, 0, xn - 1, i, discretize(P[i] - R[i]), discretize(P[i] + R[i] + 1) - 1);
	}
	for (int i = 1; i <= N; ++i)
		if (!used[i]) forwardDfs(i);
	for (int i = 1; i <= N; ++i) {
		unvisited.insert({P[i], i});
		used[i] = false;
	}
	ll ans = 0;
	while (!S.empty()) {
		int v = S.top();
		S.pop();
		if (used[v]) continue;
		backDfs(v, v);
		forwardDfs(v, false);
		ans += *scc[v].begin();
	}
	while (Q--) {
		int i, c;
		scanf("%d%d", &i, &c);
		if (sccRoot[i]) {
			int r = sccRoot[i];
			ans -= *scc[r].begin();
			scc[r].erase(scc[r].find(C[i]));
			C[i] = c;
			scc[r].insert(c);
			ans += *scc[r].begin();
		}
		printf(INT64 "\n", ans);
	}
}

