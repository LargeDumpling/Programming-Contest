#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef pair<char,char> cc;
typedef vector<ii> vii;
typedef long long ll;
typedef pair<ll, ll> l4;
typedef long double ld;
typedef pair<ld,ld> ldd;
const ld pi = acosl(-1);
const int maxn = 110;
const ll mod = 1e9+7;
const ll inf = 1e18;
const ld eps = 1e-12;

ld A[maxn][maxn], X[maxn];
int dcmp(ld x) {
    if (x > eps) return 1;
    if (x < -eps) return -1;
    return 0;
}
int gauss(int N, int M)
{
    for (int i = 0, r = 0; i < M; ++i)
	{
        int j = r;
        while (j < N && !dcmp(A[j][i]))
			++j;
        if (j >= N)
			continue;
        if (j > r)
		{
            for (int k = 0; k <= M; ++k)
				swap(A[r][k], A[j][k]);
        }
        for (j = 0; j < N; ++j)
		{
            if (j != r && dcmp(A[j][i]))
			{
                ld temp = A[j][i] / A[r][i];
                for (int k = 0; k <= M; ++k)
					A[j][k] -= temp * A[r][k];
            }
        }
        ++r;
    }
    for (int i = 0; i < N; ++i)
	{
        if (!dcmp(A[i][M])) continue;
        int j = 0;
        while (j < M && !dcmp(A[i][j])) ++j;
        if (j == M) return 0;
        X[j] = A[i][M] / A[i][j];
    }
    return 1;
}

string s,t;
map<string, int> mm;
int vis[2*maxn];

pair<string, int> find_prefix(string ss) {
    pair<string, int> ret = {"",0};
    int l = 0, mark = 0;
    for (auto cur : mm) {
        int ls = ss.length(), lt = cur.first.length();
        if (ls >= lt && ss.substr(ls-lt) == cur.first) {
            if (cur.first == t) return cur;
            if (cur.first == s) mark = 1;
            if (lt > l) ret = cur, l = lt;
        }
    }
    if (mark) return {s,0};
    return ret;
}

ld solve(string s, string t) {
    memset(A, 0, sizeof(A));
    memset(vis, 0, sizeof(vis));
    memset(X, 0, sizeof(X));
    mm.clear();
    ld p = 0.5;
    string tmp;
    int tot = 0;
    mm[""] = 0;
    mm[s], mm[t];
    for (int i = 0; i < s.length()-1; i++) {
        tmp += s[i];
        mm[tmp] = ++tot;
    }
    tmp = "";
    for (int i = 0; i < t.length()-1; i++) {
        tmp += t[i];
        if (!mm.count(tmp)) mm[tmp] = ++tot;
    }
    queue<string> Q;
    Q.push("");
    vis[0] = 1;
    while (!Q.empty()) {
        string ft = Q.front();
        Q.pop();
        A[mm[ft]][mm[ft]] = 1;
        auto a = find_prefix(ft+"H");
        auto b = find_prefix(ft+"T");
        if (a.fi == s) A[mm[ft]][tot+1] = p;
        if (b.fi == s) A[mm[ft]][tot+1] = p;
        if (a.fi != s && a.fi != t) A[mm[ft]][a.se] -= p;
        if (b.fi != s && b.fi != t) A[mm[ft]][b.se] -= p;
        if (!vis[a.se]) Q.push(a.fi), vis[a.se] = 1;
        if (!vis[b.se]) Q.push(b.fi), vis[b.se] = 1;
    }
    gauss(tot+1, tot+1);
    return X[0];
}

int main() {
    cin >> s >> t;
    if (s == t) {
        printf("0\n0\n1\n");
        return 0;
    }
    ld ans1 = solve(s, t);
    swap(t, s);
    ld ans2 = solve(s, t);
    cout << fixed << setprecision(12) << ans1 << endl << ans2 << endl << abs(1-ans1-ans2) << endl;
//    printf("%.10Lf\n%.10Lf\n%.10Lf\n",ans1,ans2,abs(1-ans1-ans2));
}


