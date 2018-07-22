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

inline int gett() {
	return clock() * 1000 / CLOCKS_PER_SEC;
}

const ld EPS = 1e-9;
const int INF = int(1e9);
const li INF64 = li(INF) * INF;
const ld PI = 3.1415926535897932384626433832795;

int d, n[3];
vector<int> a[3];

inline bool read() {
	if(scanf("%d", &d) != 1)
		return false;
	
	forn(i, 3) {
		assert(scanf("%d", &n[i]) == 1);
		a[i].assign(n[i], 0);
	}
	
		
	forn(k, 3) {
		forn(i, n[k])
			assert(scanf("%d", &a[k][i]) == 1);
	}
	
	return true;
}

li countEqual() {
	li ans = 0;
	
	int l[3] = {0, 0, 0};
	int r[3] = {0, 0, 0};
	
	forn(i, sz(a[0])) {
		fore(k, 1, 3) {
			while(l[k] < sz(a[k]) && a[k][l[k]] < a[0][i])
				l[k]++;
			while(r[k] < sz(a[k]) && a[k][r[k]] <= a[0][i])
				r[k]++;
		}
		
		ans += (r[1] - l[1]) * 1ll * (r[2] - l[2]);
	}
	
	return ans;
}

li count1(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
	li ans = 0;
	
	int l[3] = {0, 0, 0};
	int r[3] = {0, 0, 0};
	while(l[0] < sz(a)) {
		while(r[0] < sz(a) && a[l[0]] == a[r[0]])
			r[0]++;
		
		while(l[1] < sz(b) && b[l[1]] < a[l[0]])
			l[1]++;
		while(r[1] < sz(b) && b[r[1]] <= a[l[0]])
			r[1]++;
				
		while(l[2] < sz(c) && c[l[2]] <= a[l[0]])
			l[2]++;
		while(r[2] < sz(c) && c[r[2]] <= a[l[0]] + d)
			r[2]++;
			
		ans += (r[0] - l[0]) * 1ll * (r[1] - l[1]) * (r[2] - l[2]);
		
		l[0] = r[0];
	}
	
	return ans;
}

li count2(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
	li ans = 0;
	
	int l[3] = {0, 0, 0};
	int r[3] = {0, 0, 0};
	while(l[0] < sz(a)) {
		while(r[0] < sz(a) && a[r[0]] == a[l[0]])
			r[0]++;
			
		while(l[1] < sz(b) && b[l[1]] <= a[l[0]])
			l[1]++;
		while(r[1] < sz(b) && b[r[1]] <= a[l[0]] + d)
			r[1]++;
			
		while(l[2] < sz(c) && c[l[2]] <= a[l[0]])
			l[2]++;
		while(r[2] < sz(c) && c[r[2]] <= a[l[0]] + d)
			r[2]++;
			
		ans += (r[0] - l[0]) * 1ll * (r[1] - l[1]) * (r[2] - l[2]);
		
		l[0] = r[0];
	}
	
	return ans;
}


inline void solve() {
	li ans = countEqual();
	
	ans += count1(a[0], a[1], a[2]);
	ans += count1(a[0], a[2], a[1]);
	ans += count1(a[1], a[2], a[0]);
	
	ans += count2(a[0], a[1], a[2]);
	ans += count2(a[1], a[0], a[2]);
	ans += count2(a[2], a[0], a[1]);
	
	printf(INT64 "\n", ans);
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
