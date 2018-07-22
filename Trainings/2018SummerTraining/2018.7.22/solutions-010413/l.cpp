#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef pair<int, int> pt;
typedef long long li;

const int N = 200 * 1000 + 13;
const int LOGN = 19;
const li INF64 = li(1e18);

int n, m, c;
vector<pt> g[N];
vector<int> h[N], th[N], nt[N], t[N];
vector<li> dist, tmp;
vector<pair<pt, pt>> e;

int hgt[N];
int siz[N];
bool fl[N];
int up[LOGN][N];

void Dijkstra(vector<li> &dist){
	dist = vector<li>(n, INF64);
	dist[c] = 0;
	set<pair<li, int>> q;
	q.insert(mp(dist[c], c));
	
	while (!q.empty()){
		int v = q.begin()->y;
		q.erase(q.begin());
		
		for (auto it : g[v]){
			int u = it.x;
			int w = it.y;
			
			if (dist[u] > dist[v] + w){
				q.erase(mp(dist[u], u));
				dist[u] = dist[v] + w;
				q.insert(mp(dist[u], u));
			}
		}
	}
}

bool used[N];
vector<int> ord;

void dfs(int v){
	used[v] = true;
	
	for (auto u : h[v]){
		if (!used[u]){
			t[v].push_back(u);
			dfs(u);
		}
	}
	
	ord.push_back(v);
}

void add(int v, int p){
	nt[p].push_back(v);
	up[0][v] = p;
	for (int i = 1; i < LOGN; ++i)
		up[i][v] = up[i - 1][up[i - 1][v]];
	hgt[v] = hgt[p] + 1;
}

int lca(int v, int u){
	if (hgt[v] > hgt[u])
		swap(v, u);
	
	for (int i = LOGN - 1; i >= 0; --i)
		if (hgt[up[i][u]] >= hgt[v])
			u = up[i][u];
	
	for (int i = LOGN - 1; i >= 0; --i){
		if (up[i][v] != up[i][u]){
			v = up[i][v];
			u = up[i][u];
		}
	}
	
	if (v == u)
		return v;
	
	return up[0][v]; 
}

void calc(int v, int p){
	siz[v] = 1;
	for (auto u : nt[v]){
		if (u == p) continue;
		calc(u, v);
		siz[v] += siz[u];
	}
}

int ans[N];

int main() {
	scanf("%d%d", &n, &m);
	c = 0;
	
	forn(i, m){
		int f, t, w;
		scanf("%d%d%d", &f, &t, &w);
		--f, --t;
		g[f].push_back(mp(t, w));
		g[t].push_back(mp(f, w));
		e.push_back(mp(mp(f, t), mp(w, i)));
		e.push_back(mp(mp(t, f), mp(w, i)));
	}
	
	sort(e.begin(), e.end());
	
	Dijkstra(dist);
	
	forn(v, n){
		for (auto it : g[v]){
			int u = it.x;
			int w = it.y;
			
			if (dist[v] + w == dist[u]){
				h[v].push_back(u);
				th[u].push_back(v);
			}
		}
	}
	
	dfs(c);
	
	reverse(ord.begin(), ord.end());
	
	hgt[c] = 0;
	forn(i, LOGN)
		up[i][c] = c;
	
	for (int i = 1; i < int(ord.size()); ++i){
		int v = ord[i];
		
		int l = th[v][0];
		for (int j = 1; j < int(th[v].size()); ++j)
			l = lca(l, th[v][j]);
		
		fl[v] = (int(th[v].size()) == 1);
		
		add(v, l);
	}
	
	calc(c, -1);
	
	forn(v, n){
		for (auto u : t[v]){
			int i = lower_bound(e.begin(), e.end(), mp(mp(v, u), mp(-1, -1)))->y.y;
			ans[i] = siz[u] * fl[u];
		}
	}
	
	forn(i, m)
		printf("%d\n", ans[i]);
}