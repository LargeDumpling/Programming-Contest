#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

const int MOD = 1e9 + 7;

int n, m;
vector<int> a;
vector<int> ans;
vector<vector<int>> dp;

void add(int &a, int b) {
	a += b;
	while (a >= MOD)
		a -= MOD;
}

void solve(int l, int r, vector<pair<pair<int, int>, int>> q) {
	if (q.empty())
		return;
	
	if (l + 1 == r) {
		for (auto it : q)
			ans[it.y] = (a[l] == 0) + 1;
		return;
	}
	
	int mid = (l + r) >> 1;
	
	for (int i = l; i < r; ++i)
		for (int j = 0; j < m; ++j)
			dp[i][j] = 0;
	
	dp[mid - 1][0]++;
	dp[mid - 1][a[mid - 1]]++;
	
	dp[mid][0]++;
	dp[mid][a[mid]]++;

	for (int i = mid - 1; i > l; --i) {
		for (int j = 0; j < m; ++j) {
			add(dp[i - 1][j], dp[i][j]);
			add(dp[i - 1][(j + a[i - 1]) % m], dp[i][j]);
		}
	}
	for (int i = mid; i < r - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			add(dp[i + 1][j], dp[i][j]);
			add(dp[i + 1][(j + a[i + 1]) % m], dp[i][j]);
		}
	}
	
	vector<pair<pair<int, int>, int>> ql, qr;
	for (auto it : q) {
		if (it.x.x < mid && it.x.y < mid) {
			ql.push_back(it);
		} else if (it.x.x >= mid && it.x.y >= mid) {
			qr.push_back(it);
		} else {
			for (int j = 0; j < m; ++j)
				add(ans[it.y], dp[it.x.x][j] * 1ll * dp[it.x.y][(m - j) % m] % MOD);
		}
	}
	
	q.clear();
	q.shrink_to_fit();
	
	solve(l, mid, ql);
	solve(mid, r, qr);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	scanf("%d %d", &n, &m);
	a = vector<int>(n);
	dp = vector<vector<int>>(n, vector<int>(m));
	
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		a[i] %= m;	
	}
	
	int qq;
	scanf("%d", &qq);
	ans = vector<int>(qq);
	vector<pair<pair<int, int>, int>> q(qq);
	
	for (int i = 0; i < qq; ++i) {
		scanf("%d %d", &q[i].x.x, &q[i].x.y);
		--q[i].x.x, --q[i].x.y;
		q[i].y = i;
	}
	
	solve(0, n, q);
	
	for (int i = 0; i < qq; ++i)
		printf("%d\n", ans[i]);
	
	return 0;
}