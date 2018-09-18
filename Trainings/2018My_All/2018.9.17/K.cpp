#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
const int dir[8][2] = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}, {1, 1}, {1, -1}, { -1, -1}, { -1, 1}};
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 105, MAXM = 10005;
vector<int> G[105];
int to[MAXM << 1], nxt[MAXM << 1], Head[MAXN], ed = 1;
int cost[MAXM << 1];
inline void addedge(int u, int v, int c)
{
        to[++ed] = v;
        cost[ed] = c;
        nxt[ed] = Head[u];
        Head[u] = ed;
}
int n;
char s[105][105];
int vis[105];
int mindis[105];
int du[105], du2[105];
long long anser = 1;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >que;
queue<int> quee;
int main()
{
        int T = 0;
        while (scanf("%d", &n) == 1)
        {
                anser = 1;
                ed = 1;
                mem(Head, 0);
                mem(du, 0);
                T++;
                for (int i = 0; i < n; i++)
                {
                        G[i].clear();
                        scanf("%s", s[i]);
                }
                for (int i = 0; i < n; i++)
                {
                        for (int j = i + 1; j < n; j++)
                        {
                                int now = s[i][j] - '0';
                                if (now != 0)
                                {
                                        addedge(i, j, now), addedge(j, i, now);
                                        //cout<<"add "<<i<<" "<<j<<" "<<now<<endl;
                                }
                        }
                }
                pair<int, int> cnt;
                cnt.first = cnt.second = 0;
                vis[0] = T;
                que.push(cnt);
                while (!que.empty())
                {
                        cnt = que.top();
                        que.pop();
                        int x = cnt.second;
                        mindis[x] = cnt.first;
                        for (int v, i = Head[x]; i; i = nxt[i])
                        {
                                v = to[i];
                                if (vis[v] == T)
                                {
                                        continue;
                                }
                                vis[v] = T;
                                que.push(make_pair(cnt.first + cost[i], v));
                        }
                }
                for (int x = 0; x < n; x++)
                {
                        int u, v;
                        u = x;
                        for (int i = Head[x]; i; i = nxt[i])
                        {
                                v = to[i];
                                if (mindis[v] == mindis[u] + cost[i])
                                {
                                        G[u].push_back(v);
                                        //cout<<"G "<<u<<" "<<v<<endl;
                                        du[v]++;
                                }
                        }
                }
                for (int i = 0; i < n; i++)
                {
                        du2[i] = du[i];
                }
                du2[0] = 1;
                quee.push(0);
                while (!quee.empty())
                {
                        int x = quee.front(),v;
                        quee.pop();
                        anser = (anser * du2[x]) % mod;
                        for (unsigned i=0;i<G[x].size();i++)
                        {
								v=G[x][i];
                                du[v]--;
                                if (du[v] == 0)
                                {
                                        quee.push(v);
                                }
                        }
                }
                printf("%lld\n", anser);
        }
        return 0;
}

