/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-31	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int T_T,n,m;
int fir[MAXN],end[MAXN<<1],next[MAXN<<1],ed=0;
int dep[MAXN],fa[MAXN][17];
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
void DFS1(int u)
{
	for(int i=1;i<17;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=fir[u];i;i=next[i]) if(end[i]!=fa[u][0])
	{
		fa[end[i]][0]=u;
		dep[end[i]]=dep[u]+1;
		DFS1(end[i]);
	}
	return;
}
int LCA(int u,int v)
{
	int t=abs(dep[u]-dep[v]);
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=16;0<=i;i--) if((t>>i)&1)
		u=fa[u][i];
	if(u==v) return u;
	for(int i=16;0<=i;i--) if(fa[u][i]!=fa[v][i])
	{
		u=fa[u][i];
		v=fa[v][i];
	}
	return fa[u][0];
}
int main()
{
	int u,v,t;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}
		fa[1][0]=1;
		dep[1]=0;
		DFS1(1);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			t=LCA(u,v);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

