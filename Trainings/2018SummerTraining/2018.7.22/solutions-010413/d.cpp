#include <bits/stdc++.h>

#define fore(i, l, r) for(int (i) = int(l); (i) < int(r); (i)++)
#define forn(i, n) fore(i, 0, n)

#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a) * (a))
#define sz(a) int((a).size())
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

const int N = 200 * 1000 + 555;

int n;
pt a[N];

inline bool read() {
    if(scanf("%d", &n) != 1)
        return false;

    forn(i, n)
        assert(scanf("%d%d", &a[i].x, &a[i].y) == 2);
    return true;
}

inline void push(li Tset[N], int v) {
    Tset[2 * v + 1] = min(Tset[2 * v + 1], Tset[v]);
    Tset[2 * v + 2] = min(Tset[2 * v + 2], Tset[v]);
    Tset[v] = INF64;
}

void build(li Tset[N], int v, int l, int r) {
    Tset[v] = INF64;

    if(l + 1 == r)
        return;

    int mid = (l + r) >> 1;
    build(Tset, 2 * v + 1, l, mid);
    build(Tset, 2 * v + 2, mid, r);
}

li getMin(li Tset[N], int v, int l, int r, int pos) {
    if(l >= r)
        return INF64;

    if(l + 1 == r) {
        assert(l == pos);
        return Tset[v];
    }

    push(Tset, v);
    int mid = (l + r) >> 1;

    if(pos < mid)
        return getMin(Tset, 2 * v + 1, l, mid, pos);
    else
        return getMin(Tset, 2 * v + 2, mid, r, pos);
}

void setMin(li Tset[N], int v, int l, int r, int lf, int rg, li val) {
    if(l >= r || lf >= rg)
        return;

    if(l == lf && r == rg) {
        Tset[v] = min(Tset[v], val);
        return;
    }

    push(Tset, v);
    int mid = (l + r) >> 1;

    if(lf < mid)
        setMin(Tset, 2 * v + 1, l, mid, lf, min(mid, rg), val);
    if(rg > mid)
        setMin(Tset, 2 * v + 2, mid, r, max(lf, mid), rg, val);
}


li T1[4 * N], T2[4 * N];

vector<li> ts;
li d[N];

inline void solve() {
    stack<pt> st;
    forn(i, n) {
        while(!st.empty() && st.top().y <= a[i].y)
            st.pop();
        st.push(a[i]);
    }
    n = 0;
    while(!st.empty()) {
        a[n++] = st.top();
        st.pop();
    }
    reverse(a, a + n);

    ts.clear();
    forn(i, n)
        ts.pb(a[i].x);

    forn(i, n + 5)
        d[i] = INF64;
    build(T1, 0, 0, n);
    build(T2, 0, 0, n);
    setMin(T2, 0, 0, n, 0, n, 2 * a[0].y);

    forn(i, n) {
        d[i] = min(getMin(T1, 0, 0, n, i), a[i].x + getMin(T2, 0, 0, n, i));
        int pos = int(lower_bound(all(ts), d[i]) - ts.begin());

        if(pos > i + 1)
            setMin(T1, 0, 0, n, i + 1, pos, d[i] + 2 * a[i + 1].y);

        if(pos < n)
            setMin(T2, 0, 0, n, pos, n, 2 * a[i + 1].y);
    }

    printf("%lld\n", d[n - 1]);
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
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