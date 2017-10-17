#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define N 200
#define M 100000

using namespace std;

int head[N],next[M],to[M],len[M];
int can[N][N],pt[M],st[M],ed[M];
int dis[N],q[M],dp[N];
bool vis[N],bh[N];
int n,m,K,e,d,cnt;

inline void add(int u,int v,int w)
{
    to[cnt]=v; len[cnt]=w; next[cnt]=head[u]; head[u]=cnt++;
}

inline void read()
{
    memset(head,-1,sizeof head); cnt=0;
    scanf("%d%d%d%d",&n,&m,&K,&e);
    for(int i=1,a,b,c;i<=e;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c); add(b,a,c);
    }
    scanf("%d",&d);
    for(int i=1;i<=d;i++) scanf("%d%d%d",&pt[i],&st[i],&ed[i]);
}

inline void build(int l,int r)
{
    memset(bh,true,sizeof bh);
    for(int i=1;i<=d;i++)
    {
        if(st[i]>r||ed[i]<l) continue;
        bh[pt[i]]=false;
    }
}

inline int spfa()
{
    memset(dis,0x3f,sizeof dis);
    int h=1,t=2,sta;
    q[1]=1; vis[1]=true; dis[1]=0;
    while(h<t)
    {
        sta=q[h++]; vis[sta]=false;
        for(int i=head[sta];~i;i=next[i])
            if(bh[to[i]]&&dis[to[i]]>dis[sta]+len[i])
            {
                dis[to[i]]=dis[sta]+len[i];
                if(!vis[to[i]]) vis[to[i]]=true,q[t++]=to[i];
            }
    }
    return dis[m];
}

inline void go()
{
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            build(i,j);
            can[i][j]=spfa();
        }
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        {
            if(can[j][i]>=0x3f3f3f3f||dp[j-1]>=0x3f3f3f3f) continue;
            dp[i]=min(dp[i],dp[j-1]+can[j][i]*(i-j+1)+K);
        }
    printf("%d\n",dp[n]-K);
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
    read();
    go();
    return 0;
}
