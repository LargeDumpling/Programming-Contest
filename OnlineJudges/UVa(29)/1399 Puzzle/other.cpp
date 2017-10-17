#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
 
const int MAXNODE = 50005;
int n;
 
struct AutoMac {
 
    int ch[MAXNODE][26];
    int val[MAXNODE];
    int next[MAXNODE];
    int sz;
 
    void init() {
    sz = 1; 
    memset(ch[0], 0, sizeof(ch[0]));
    }
 
    int idx(char c) {
    return c - 'A';
    }
 
    void insert(char *str, int v = 1) {
    int n = strlen(str);
    int u = 0;
    for (int i = 0; i < n; i++) {
        int c = idx(str[i]);
        if (!ch[u][c]) {
        memset(ch[sz], 0, sizeof(ch[sz]));
        val[sz] = 0;
        ch[u][c] = sz++;
        }
        u = ch[u][c];
    }
    val[u] = v;
    }
 
    void getnext() {
    queue<int> Q;
    next[0] = 0;    
    for (int c = 0; c < n; c++) {
        int u = ch[0][c];
        if (u) {next[u] = 0; Q.push(u);}
    }
 
    while (!Q.empty()) {
        int r = Q.front(); Q.pop();
        for (int c = 0; c < n; c++) {
        int u = ch[r][c];
        if (!u) {
            ch[r][c] = ch[next[r]][c];
            continue;
        }
        Q.push(u);
        int v = next[r];
        while (v && !ch[v][c]) v = next[v];
        next[u] = ch[v][c];
        val[u] |= val[next[u]];
        }
    }
    }
} gao;
 
int t, m, vis[MAXNODE], dp[MAXNODE], zh[MAXNODE][2], vv[MAXNODE];
char str[55];
 
bool find(int u) {
    vv[u] = 1;
    for (int i = 0; i < n; i++) {
    int v = gao.ch[u][i];
    if (vis[v]) return true;
    if (!vv[v] && !gao.val[v]) {
        vis[v] = 1;
        if (find(v)) return true;
        vis[v] = 0;
    }
    }
    return false;
}
 
int dfs(int u) {
    if (vis[u]) return dp[u];
    vis[u] = 1;
    dp[u] = 0;
    for (int i = n - 1; i >= 0; i--) {
    if (!gao.val[gao.ch[u][i]]) {
        int tmp = dfs(gao.ch[u][i]) + 1;
        if (dp[u] < tmp) {
        dp[u] = tmp;
        zh[u][0] = gao.ch[u][i];
        zh[u][1] = i;
        }
    }
    }
    return dp[u];
}
 
void print(int u) {
    if (zh[u][0] == -1) return;
    printf("%c", zh[u][1] + 'A');
    print(zh[u][0]);
}
 
int main() {
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
    scanf("%d", &t);
    while (t--) {
    gao.init();
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%s", str);
        gao.insert(str);
    }
    gao.getnext();
    memset(vv, 0, sizeof(vv));
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    if (find(0)) printf("No\n");
    else {
        memset(vis, 0, sizeof(vis));
        memset(zh, -1, sizeof(zh));
        if (dfs(0) == 0) printf("No\n");
        else {
        print(0);
        printf("\n");
        }
    }
    }
    return 0;
}
