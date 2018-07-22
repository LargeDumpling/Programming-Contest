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

const int N = 400 * 1000 + 555;

int n, m;
string s;

int mod[N];
vector<pt> qs[N];

inline bool read() {
	if(!(cin >> n >> m))
		return false;
		
	char buf[N];
	assert(scanf("%s", buf) == 1);
	s = buf;
	
	forn(i, m) {
		int k;
		assert(scanf("%d%d", &k, &mod[i]) == 2);
		forn(j, k) {
			pt sg;
			assert(scanf("%d%d", &sg.x, &sg.y) == 2);
			sg.x--;
			
			qs[i].pb(sg);
		}
	}
	return true;
}

int c[N], p[N], lcp[N];
inline void calcSufArray() {
	s += '$';
	for(int pw = 0; (1 << pw) < 2 * sz(s); pw++) {
		vector< pair<pt, int> > d(sz(s));
		forn(i, sz(s))
			d[i] = mp(pw == 0 ? pt(s[i], 0) : pt(c[i], c[(i + (1 << (pw - 1))) % sz(s)]), i);
		stable_sort(all(d));
		
		c[d[0].y] = 0;
		fore(i, 1, sz(d))
			c[d[i].y] = c[d[i - 1].y] + (d[i - 1].x != d[i].x);
	}
	
	s.pop_back();
	forn(i, sz(s))
		c[i]--;
		
	forn(i, sz(s)) {
		p[c[i]] = i;
		lcp[i] = 0;
	}
		
	int l = 0;
	forn(i, sz(s)) {
		l = max(0, l - 1);
		
		int id = c[i];
		if(id == sz(s) - 1)
			continue;
			
		int j = p[id + 1];
		
		while(i + l < sz(s) && j + l < sz(s) && s[i + l] == s[j + l])
			l++;
			
		lcp[c[i]] = l;
	}
}

const int LOGN = 20;

int lg[N];
int st[LOGN][N];

inline void calcSparse() {
	lg[0] = lg[1] = 0;
	fore(i, 2, N) {
		lg[i] = lg[i - 1];
		if((1 << (lg[i] + 1)) <= i)
			lg[i]++;
	}
	
	forn(pw, LOGN) {
		if(pw == 0) {
			forn(i, n)
				st[pw][i] = lcp[i];
		} else {
			forn(i, n) {
				st[pw][i] = st[pw - 1][i];
				if(i + (1 << (pw - 1)) < n)
					st[pw][i] = min(st[pw][i], st[pw - 1][i + (1 << (pw - 1))]);
			}
		}
	}
}

inline int getMin(int lf, int rg) {
	int l = min(c[lf], c[rg]);
	int r = max(c[lf], c[rg]);
	
	if(l == r)
		return n;
		
	int ln = lg[r - l];
	return min(st[ln][l], st[ln][r - (1 << ln)]);
}

inline bool cmp(const pt &a, const pt &b) {
	int lcp = getMin(a.x, b.x);
	if(lcp >= (a.y - a.x) || lcp >= (b.y - b.x))
		return a.y - a.x < b.y - b.x;
		
	return s[a.x + lcp] < s[b.x + lcp];
}

int pr[N], siz[N], ans[N];

int len[N], curmod;

inline void init(const vector<pt> &q, int cmod) {
	curmod = cmod;
	forn(i, sz(q)) {
		pr[i] = i;
		siz[i] = 1;
		ans[i] = 2 % curmod;
		
		len[i] = q[i].y - q[i].x;
	}
}

int top(int v) {
	if(v == pr[v])
		return v;
	return pr[v] = top(pr[v]);
}

inline void unite(int u, int v, int lcp) {
	u = top(u);
	v = top(v);
	
	if(u == v)
		return;
		
	int res = 0;
	if(siz[u] == 1 && lcp == len[u]) {
		res = (1 + ans[v]) % curmod;
	} else if(siz[v] == 1 && lcp == len[v]) {
		res = (1 + ans[u]) % curmod;
	} else
		res = int((ans[u] * 1ll * ans[v]) % curmod);
		
	if(siz[u] < siz[v])
		swap(u, v);
		
	siz[u] += siz[v];
	pr[v] = u;
	ans[u] = res;
}

inline void solve() {
	calcSufArray();
	calcSparse();
		
	forn(_id, m) {
		auto &q = qs[_id];
		
		sort(all(q), cmp);
		vector<pt> lcp(sz(q) - 1);
		forn(i, sz(q) - 1)
			lcp[i] = pt(min(getMin(q[i].x, q[i + 1].x), min(q[i].y - q[i].x, q[i + 1].y - q[i + 1].x)), i);
		
		sort(all(lcp));
		reverse(all(lcp));
		
		init(q, mod[_id]);
		for(auto p : lcp) {
			int i = p.y;
			unite(i, i + 1, p.x);
		}
		
		int v = top(0);
		printf("%d\n", ans[v]);
	}
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t = gett();
#endif

	srand(time(NULL));
	cout << fixed << setprecision(10);

	while(read()) {
		solve();	
		
#ifdef _DEBUG
		cerr << "TIME = " << gett() - t << endl;
		t = gett();
#endif
	}
	return 0;
}
