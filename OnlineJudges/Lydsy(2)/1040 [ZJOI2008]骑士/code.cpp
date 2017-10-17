/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
int n,fir[MAXN],end[MAXN<<1],next[MAXN<<1],ed=1;
int P1,P2,V;
long long f[MAXN][2],force[MAXN],ans=0,tem;
bool exist[MAXN],vis[MAXN];
void addedge(int u,int v)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	return;
}
void DFS(int u,int fa)
{
	exist[u]=vis[u]=true;
	for(int i=fir[u];i;i=next[i]) if(end[i]!=fa)
	{
		if(exist[end[i]]&&!V)
		{
			P1=u;
			P2=end[i];
			V=i;
			continue;
		}
		else if(!exist[end[i]]) DFS(end[i],u);
	}
	return;
}
void F(int u,int fa)
{
	f[u][0]=0;
	f[u][1]=force[u];
	for(int i=fir[u];i;i=next[i]) if(end[i]!=fa&&i!=V&&(i^1)!=V)
	{
		F(end[i],u);
		f[u][0]+=max(f[end[i]][1],f[end[i]][0]);
		f[u][1]+=f[end[i]][0];
	}
	return;
}
void solve()
{
	memset(vis,false,sizeof(vis));
	memset(exist,false,sizeof(exist));
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			V=0;
			DFS(i,i);
			tem=0;
			F(P1,P1);
			tem=max(tem,f[P1][0]);
			F(P2,P2);
			tem=max(tem,f[P2][0]);
			ans+=tem;
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%d",&force[i],&x);
		addedge(i,x);
	}
	solve();
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

