#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
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

const int N = 100 * 1000 + 555;
const int NN = 300 * 1000 + 555;

int n, m;
string s;
string t[NN];

inline bool read() {
	if(!(cin >> n >> m))
		return false;
		
	char buf[N];
	assert(scanf("%s", buf) == 1);
	s = buf;
	
	forn(i, m) {
		assert(scanf("%s", buf) == 1);
		t[i] = buf;
	}
	return true;
}

int c[N], id[N];

inline void calcSA() {
	s += '$';
	
	for(int st = 0; (1 << st) < 2 * sz(s); st++) {
		vector< pair<pt, int> > d;
		forn(i, sz(s))
			d.pb(mp(st == 0 ? mp((int)s[i], 0) : mp(c[i], c[(i + (1 << (st - 1))) % sz(s)]), i));
		stable_sort(all(d));
		
		c[d[0].y] = 0;
		fore(i, 1, sz(d))
			c[d[i].y] = c[d[i - 1].y] + (d[i].x != d[i - 1].x);
		if(c[d[sz(d) - 1].y] == sz(s) - 1)
		    break;
	}
	
	s.pop_back();
	forn(i, sz(s))
		c[i]--;
		
	forn(i, sz(s))
		id[c[i]] = i;
}

inline int fnd(const pt &bd, char c, int sh) {
	if(bd.x >= bd.y)
		return bd.x;
		
	int l = bd.x - 1, r = bd.y;
	while(r - l > 1) {
		int mid = (l + r) >> 1;
		int cid = id[mid];
		
		if(cid + sh >= sz(s) || s[cid + sh] < c)
			l = mid;
		else
			r = mid;
	}
	
	return l + 1;
}

inline pt findSegment(const string &t) {
	pt ans(0, sz(s));
	forn(i, sz(t))
		ans = mp(fnd(ans, t[i], i), fnd(ans, char(t[i] + 1), i));
	
	return ans;
}

const int M = 25 * N;
struct node {
	int mn;
	node *l, *r;
} nodes[M + 5];

int szn = 0;

inline node* getNode() {
	assert(szn < M);
	return &nodes[szn++];
}

node* build(node *v, int l, int r) {
	if(v == NULL)
		v = getNode();
	v->mn = INF;
	
	if(l + 1 >= r)
		return v;
		
	int mid = (l + r) >> 1;
	v->l = build(v->l, l, mid);
	v->r = build(v->r, mid, r);
	
	return v;
}

inline void upd(node *v) {
	v->mn = min(v->l->mn, v->r->mn);
}

node* setVal(node *v, int l, int r, int pos, int val) {
	node* nv = getNode();
	
	if(l + 1 == r) {
		assert(l == pos);
		nv->mn = val;
		return nv;
	}
	
	int mid = (l + r) >> 1;
	if(pos < mid) {
		nv->l = setVal(v->l, l, mid, pos, val);
		nv->r = v->r;
	} else {
		nv->l = v->l;
		nv->r = setVal(v->r, mid, r, pos, val);
	}
	
	upd(nv);
	return nv;
}

int getMin(node *v, int l, int r, int lf, int rg) {
	if(l == lf && r == rg)
		return v->mn;
		
	int mid = (l + r) >> 1;
	
	int mn = INF;
	if(lf < mid)
		mn = min(mn, getMin(v->l, l, mid, lf, min(rg, mid)));
	if(rg > mid)
		mn = min(mn, getMin(v->r, mid, r, max(lf, mid), rg));
	return mn;
}

node* st[N];

inline int getGE(int lf, int rg, int val) {
	if(val >= sz(s))
		return INF;
		
	return getMin(st[val], 0, sz(s), lf, rg);
}

const int B = 250;
int d1[B][N];
map<int, int> d2[N];

int bl, br;
int calc(int id, int len) {
	int &res = (len < B ? d1[len][id] : d2[len][id]);
	if(res != 0)
		return res;
	
	res = 1;
	int nxt = getGE(bl, br, id + len);
	
	if(nxt < INF / 2)
		res += calc(nxt, len);
		
	return res;
}

inline void solve() {
	calcSA();
	st[sz(s)] = build(NULL, 0, sz(s));
	
	for(int i = sz(s) - 1; i >= 0; i--)
		st[i] = setVal(st[i + 1], 0, sz(s), c[i], i);
	
	memset(d1, 0, sizeof d1);
	forn(i, N)
		d2[i].clear();
		
	forn(i, m) {
		pt bd = findSegment(t[i]);
		bl = bd.x;
		br = bd.y;
		
		if(bl >= br) {
			printf("0\n");
			continue;
		}
		
		int id = getGE(bl, br, 0);
		int ans = calc(id, sz(t[i]));
		
        printf("%d\n", ans);
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

	if(read()) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << gett() - t << endl;
		t = gett();
#endif
	}
	return 0;
}