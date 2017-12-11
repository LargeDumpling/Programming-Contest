#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=2147483647;
const int MAXN=1050;
int n;
int fir[MAXN],next[MAXN],x[MAXN],f[MAXN];
int g[2][MAXN];
bool DFS(int u)
{
	int now=0;
	for(int v=fir[u];v;v=next[v])
		if(!DFS(v))
			return false;
	for(int i=1;i<=x[u];i++)
		g[now][i]=INF;
	g[now][0]=0;
	for(int v=fir[u];v;v=next[v])
	{
		now^=1;
		for(int i=1;i<=x[u];i++)
			g[now][i]=INF;
		for(int j=x[u];j;j--)
		{
			if(x[v]<=j&&g[now^1][j-x[v]]!=INF)
				g[now][j]=min(g[now][j],g[now^1][j-x[v]]+f[v]);
			if(f[v]<=j&&g[now^1][j-f[v]]!=INF)
				g[now][j]=min(g[now][j],g[now^1][j-f[v]]+f[v]);
		}
	}
	f[u]=INF;
	for(int i=0;i<=x[u];i++)
		f[u]=min(f[u],g[now][i]);
	return f[u]!=INF;
}
int main()
{
	int p;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&p);
		next[p]=fir[i];
		fir[i]=p;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	if(DFS(1)) puts("POSSIBLE");
	else puts("IMPOSSIBLE");
    return 0;
}
