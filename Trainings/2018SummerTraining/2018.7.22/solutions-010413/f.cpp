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
typedef pair<li, int> ptl;

inline int gett() {
	return clock() * 1000 / CLOCKS_PER_SEC;
}

const ld EPS = 1e-9;
const int INF = int(1e9);
const li INF64 = li(INF) * INF;
const ld PI = 3.1415926535897932384626433832795;

mt19937 rnd(time(NULL));

li gcd(li a, li b) {
	if(a == 0)
		return b;
	return gcd(b % a, a);
}

const int N = 150 * 1000 + 555;
int n, k;
li a[N];

inline bool read() {
	if(!(cin >> n >> k))
		return false;
	
	forn(i, n)
		assert(scanf(INT64, &a[i]) == 1);
	return true;
}

const int M = 10 * 1000 * 1000 + 3;
bool npr[M];
vector<int> ps;

void sieve() {
	npr[0] = npr[1] = true;
	
	fore(i, 2, M) {
		if(npr[i])
			continue;
		
		ps.pb(i);
		for(li j = i * 1ll * i; j < M; j += i)
			npr[j] = true;
	}
}

vector<ptl> fact(li val) {
	vector<ptl> ans;
	for(int p : ps) {
		if(p * 1ll * p > val)
			break;
			
		int cnt = 0;
		while(val % p == 0)
			cnt++, val /= p;
			
		if(cnt > 0)
			ans.pb(ptl(p, cnt));
	}
	if(val > 1) {
		li curd = -1;
		forn(i, n) {
			li cg = gcd(val, a[i]);
			
			if(1 < cg && cg < val) {
				curd = cg;
				break;
			}
		}
		
		if(curd != -1) {
		    if(curd * curd == val)
		        ans.pb(ptl(curd, 2));
		    else {
			    ans.pb(ptl(min(curd, val / curd), 1));
			    ans.pb(ptl(max(curd, val / curd), 1));
		    }
		} else
			ans.pb(ptl(val, 1));
	}
	
	return ans;
}

const int MAGIC = 30;
const int CNT = 17;

li base;
vector<ptl> f;
int pp[CNT];

map<li, int> id;
li dv[N];


void calcId(int pos, li val, int idx) {
	if(pos >= sz(f)) {
		id[val] = idx;
		dv[idx] = val;
		return;
	}
	
	li cv = 1;
	forn(i, f[pos].y + 1) {
		calcId(pos + 1, val * cv, idx + pp[pos] * i);
		cv *= f[pos].x;
	}
}

int d[CNT][N];

inline void solve() {
	sieve();
	
	li mx = -1;
	forn(kk, MAGIC) {
		id.clear();
		
		base = a[rnd() % n];
		f = fact(base);
		
		pp[0] = 1;
		forn(i, sz(f))
			pp[i + 1] = (f[i].y + 1) * pp[i];
			
		assert(sz(f) < CNT);
		assert(pp[sz(f)] < N);
			
		calcId(0, 1, 0);
		
		forn(cid, sz(f) + 1) forn(i, pp[sz(f)] + 1)
			d[cid][i] = 0;
		
		forn(i, n) {
			li cg = gcd(base, a[i]);
			int idx = id[cg];
			
			d[0][idx]++;
		}
		
		for(int i = pp[sz(f)]; i >= 0; i--) forn(cid, sz(f)) {
			if(d[cid][i] == 0)
				continue;
				
			d[cid + 1][i] += d[cid][i];
			
			if(dv[i] % f[cid].x == 0) {
				int ni = i - pp[cid];
				d[cid][ni] += d[cid][i];
			}
		}
		
		forn(i, pp[sz(f)] + 1) {
			if(d[sz(f)][i] >= n - k)
				mx = max(mx, dv[i]);
		}
	}
	
	cout << mx << endl;
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
