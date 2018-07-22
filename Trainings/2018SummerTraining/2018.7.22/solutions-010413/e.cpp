#include <bits/stdc++.h>

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back

#define x first
#define y second

using namespace std;

template<class A, class B> ostream& operator << (ostream &out, const pair<A, B> &p) {
	return out << "(" << p.first << ", " << p.second << ")";
}

template<class A> ostream& operator << (ostream &out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i > 0)
			out << " ";
		out << v[i];
	}
	return out << "]";
}

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

inline int gett() {
	return clock() * 1000 / CLOCKS_PER_SEC;
}

const ld EPS = 1e-9;
const int INF = int(1e9);
const li INF64 = li(INF) * INF;
const ld PI = 3.1415926535897932384626433832795;

const int N = 1000 * 1000 + 555;

int n, m, st, fn, t[N];
vector<pt> g[N];
int d[N];

inline bool read() {
	if(scanf("%d%d%d%d", &n, &m, &st, &fn) != 4)
		return false;
		
	st--, fn--;
		
	forn(i, m)
		d[i] = 0;
	forn(i, 2 * n)
		g[i].clear();
	
	forn(i, m) {
		int u, v;
		assert(scanf("%d%d", &u, &v) == 2);
		u--, v--;
		
		g[u].pb(mp(n + v, i));
		g[n + v].pb(mp(u, i));
		
		t[i] = -1;
		d[u]++, d[n + v]++;
	}
	return true;
}

int used[N], T;

void dfs1(int v, int cl) {
	if(d[v] != 1)
		return;
		
	used[v] = T;
	for(pt p : g[v]) {
		int to = p.x;
		int id = p.y;
		
		if(used[to] == T)
			continue;
			
		d[v]--;
		d[to]--;
		t[id] = cl;
		dfs1(to, cl ^ 1);
	}
}

void dfs2(int v, int f, int cl) {
	if(used[v] == T)
		return;
		
	used[v] = T;
//	cerr << "v = " << v << " " << f << " " << cl << endl;
	
	for(pt p : g[v]) {
		int to = p.x;
		int id = p.y;

		if(id == f || d[to] == 0)
			continue;
		
		d[v]--;
		d[to]--;
		t[id] = cl;
		dfs2(to, id, cl ^ 1);
	}
}

vector<int> ans1, ans2;

void dfs31(int v) {
	used[v] = T;
	
	for(pt p : g[v]) {
		int to = p.x;
		int id = p.y;
		
		if(used[to - n] == T || id >= m || t[id] != 1)
			continue;
		
		ans1.pb(id);	
		dfs31(to - n);
	}
}

void dfs32(int v) {
	used[v] = T;
	
	for(pt p : g[v]) {
		int to = p.x;
		int id = p.y;
		
		if(used[to + n] == T || id >= m || t[id] != 0)
			continue;
		
		ans2.pb(id);	
		dfs32(to + n);
	}
}

inline void solve() {
//	cerr << mp(st, fn) << endl;
	g[fn].pb(mp(n + st, m));
	g[n + st].pb(mp(fn, m));
	d[n + st]++;
	d[fn]++;
	
//	forn(i, 2 * n)
//		cerr << d[i] << " : " << g[i] << endl;
	
	T++;
	forn(i, 2 * n) {
		if(d[i] == 1)
			dfs1(i, i >= n);
	}
	
//	cerr << vector<int>(t, t + m) << endl;
//	cerr << vector<int>(d, d + 2 * n) << endl;
	
	forn(i, 2 * n) {
		int oldd = d[i];
		if(d[i] > 1 && used[i] != T) {
			dfs2(i, -1, 0);
			if(oldd - d[i] < 2) {
				used[i] = T - 1;
				dfs2(i, -1, 1);
			}
		}
	}
	
//	cerr << vector<int>(t, t + m) << endl;
	
	T++;
	ans1.clear();
	dfs31(st);
	
	T++;
	ans2.clear();
	dfs32(fn + n);
	
	if(sz(ans1) != n - 1 || sz(ans2) != n - 1) {
		puts("NO");
		return;
	}
	
	puts("YES");
	forn(i, sz(ans1))
		printf("%d ", ans1[i] + 1);
	puts("");
	
	forn(i, sz(ans2))
		printf("%d ", ans2[i] + 1);
	puts("");
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t = gett();
#endif

	srand(time(NULL));
	cout << fixed << setprecision(10);

//	int tc; assert(scanf("%d", &tc) == 1);
	while(read()) {
//		assert(read());
		solve();	
		
#ifdef _DEBUG
		cerr << "TIME = " << gett() - t << endl;
		t = gett();
#endif
	}
	return 0;
}
