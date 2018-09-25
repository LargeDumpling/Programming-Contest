/*Huyyt*/
#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MAXN = 1e5 + 5, MAXM = 1e5 + 5;
int to[MAXM << 1], nxt[MAXM << 1], Head[MAXN], ed = 1;
inline void addedge(int u, int v)
{
        to[++ed] = v;
        nxt[ed] = Head[u];
        Head[u] = ed;
}
inline void read(int &v)
{
        v = 0;
        char c = 0;
        int p = 1;
        while (c < '0' || c > '9')
        {
                if (c == '-')
                {
                        p = -1;
                }
                c = getchar();
        }
        while (c >= '0' && c <= '9')
        {
                v = (v << 3) + (v << 1) + c - '0';
                c = getchar();
        }
        v *= p;
}
bool circle[MAXN];
int vis[MAXN], cnt;
int nnxt[MAXN], nxtcircle[MAXN];
void dfs(int x, int pre)
{
        vis[x] = 1;
        for (int v, i = Head[x]; i; i = nxt[i])
        {
                v = to[i];
                if (pre != -1 && i == (pre ^ 1))
                {
                        continue;
                }
                if (vis[v] == 1)
                {
                        circle[x] = true;
                        nxtcircle[x] = nnxt[x] = i;
                        int cur;
                        cur = to[nxtcircle[x]];
                        while (cur != x)
                        {
                                circle[cur] = true;
                                nxtcircle[cur] = nnxt[cur];
                                cur = to[nxtcircle[cur]];
                        }
                }
                else if (vis[v] == 2)
                {
                        continue;
                }
                else
                {
                        nnxt[x] = i;
                        dfs(v, i);
                }
        }
        vis[x] = 2;
}
int S, T;
int anser = INT_MAX;
int lin[MAXN][3], disminn[MAXN][2];
int dissum[MAXN];
void getdistence(int x, int pre, int root, int d)
{
        for (int v, i = Head[x]; i; i = nxt[i])
        {
                v = to[i];
                if (circle[v] || v == pre)
                {
                        continue;
                }
                dissum[root]++;
                if (d + 1 > disminn[root][0])
                {
                        disminn[root][0] = d + 1;
                        disminn[root][1] = v;
                }
                else if (d == disminn[root][0])
                {
                        if (v < disminn[root][1])
                        {
                                disminn[root][1] = v;
                        }
                }
                getdistence(v, x, root, d + 1);
        }
}
void linju(int x, int pre, int root)
{
        dissum[x] = 0;
        disminn[x][0] = 0;
        disminn[x][1] = x;
        getdistence(x, -1, x, 0);
        if (x == root)
        {
                lin[x][1] = pre;
                return ;
        }
        lin[x][1] = pre;
        int v = to[nxtcircle[x]];
        lin[x][2] = v;
        linju(v, x, root);
}
int main()
{
        int T;
        read(T);
        for (int cas = 1; cas <= T; cas++)
        {
                anser = -1;
                int n;
                int u, v;
                read(n);
                ed = 1;
                for (int i = 0; i <= n; i++)
                {
                        lin[i][1] = lin[i][2] = vis[i] = circle[i] = Head[i] = 0;
                }
                for (int i = 1; i <= n; i++)
                {
                        read(u), read(v);
                        addedge(u, v);
                        addedge(v, u);
                }
                dfs(1, -1);
                for (int i = 1; i <= n; i++)
                {
                        if (circle[i])
                        {
                                int cur = to[nxtcircle[i]];
                                lin[i][2] = cur;
                                linju(cur, i, i);
                                break;
                        }
                }
                //                for(int i=1;i<=n;i++)
                //                {
                //                        cout<<i<<" "<<lin[i][1]<<" "<<lin[i][2]<<" "<<disminn[i][0]<<" "<<disminn[i][1]<<endl;
                //                }
                int ans1 = -1, ans2 = -1, ans1aim, ans2aim;
                int Snow, Tnow;
                int reducemaxn = 0;
                S = T = INT_MAX;
                for (int i = 1; i <= n; i++)
                {
                        if (circle[i])
                        {
                                anser++;
                                anser += dissum[i] * 2;
                                int reduce = disminn[i][0];
                                Snow = disminn[i][1];
                                if (disminn[lin[i][1]][0] > disminn[lin[i][2]][0])
                                {
                                        Tnow = disminn[lin[i][1]][1];
                                        reduce += disminn[lin[i][1]][0];
                                }
                                else if (disminn[lin[i][1]][0] == disminn[lin[i][2]][0])
                                {
                                        Tnow = min(disminn[lin[i][1]][1], disminn[lin[i][2]][1]);
                                        reduce += disminn[lin[i][1]][0];
                                }
                                else
                                {
                                        Tnow = disminn[lin[i][2]][1];
                                        reduce += disminn[lin[i][2]][0];
                                }
                                if (Snow > Tnow)
                                {
                                        swap(Snow, Tnow);
                                }
                                //cout<<"!!! "<<Snow<<" "<<Tnow<<" ";
                                if (reduce > reducemaxn)
                                {
                                        reducemaxn = reduce;
                                        S = Snow, T = Tnow;
                                }
                                else if (reduce == reducemaxn)
                                {
                                        if (Snow < S)
                                        {
                                                S = Snow, T = Tnow;
                                        }
                                        else if (Snow == S)
                                        {
                                                if (Tnow < T)
                                                {
                                                        T = Tnow;
                                                }
                                        }
                                }
                                //cout<<i<<" "<<reducemaxn<<" "<<S<<" "<<T<<endl;
                        }
                }
                if (S > T)
                {
                        swap(S, T);
                }
                printf("Case #%d: %d %d %d\n", cas, anser - reducemaxn, S, T);
        }
        return 0;
}
