#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 100 * 1000 + 13;
const int LOGN = 17;

int n, m;
vector<int> g[N];
pt q[N];
vector<int> ql[N];
int up[N][LOGN];
int tin[N], tout[N];
int T;
int f[N];
bool used[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		g[x].pb(y);
		g[y].pb(x);
	}
	scanf("%d", &m);
	forn(i, m) {
		scanf("%d%d", &q[i].x, &q[i].y);
		--q[i].x; --q[i].y;
	}
	return true;
}

void dfs(int v, int p) {
	tin[v] = T++;
	
	up[v][0] = p;
	for(int i = 1; i < LOGN; i++) 
		up[v][i] = up[up[v][i - 1]][i - 1];
	
	for (auto u : g[v])
		if (u != p) dfs(u, v);
	
	tout[v] = T++;
}

bool isAnc(int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
	if (isAnc(a, b))
		return a;
	if (isAnc(b, a))
		return b;
	for (int i = LOGN - 1; i >= 0; i--) {
		if (!isAnc(up[a][i], b))
			a = up[a][i];
	}
	return up[a][0];
}

void dfs2(int v, int p) {
	tin[v] = T++;
	for (auto u : g[v])
		if (u != p) dfs2(u, v);
	tout[v] = T;
}

void upd(int pos, int val) {
	for (; pos < n; pos = (pos | (pos + 1)))
		f[pos] += val;
}

int get(int pos) {
	int res = 0;
	for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += f[pos];
	return res;
}

vector<int> bfs() {
	vector<int> res;

	queue<int> q;
	q.push(0);
	used[0] = true;
	
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		res.pb(v);
		for (auto u : g[v]) if (!used[u]) {
			used[u] = true;
			q.push(u);
		}
	}
	
	return res;
}

void solve() {
	dfs(0, 0);
	
	forn(i, m) ql[lca(q[i].x, q[i].y)].pb(i);
	
	T = 0;
	dfs2(0, 0);
	
	vector<int> ord = bfs();
	reverse(all(ord));
	
	vector<int> ans;
	
	for (auto v : ord) {
		bool ok = false;
		
		for (auto it : ql[v]) {
			int a = q[it].x, b = q[it].y;
			if (get(tin[a]) == 0 && get(tin[b]) == 0)
				ok = true;
		}
		
		if (ok) {
			ans.pb(v);
			upd(tin[v], +1);
			upd(tout[v], -1);
		}
	}
	
	printf("%d\n", sz(ans));
	for (auto it : ans)
		printf("%d ", it + 1);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	        
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}