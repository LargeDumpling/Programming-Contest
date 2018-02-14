/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10050;
const int M=16384;
struct jp
{
	int u,v,w;
}E[MAXN];
int T_T,n;
int fir[MAXN],end[MAXN<<1],next[MAXN<<1],dep[MAXN],size[MAXN],fa[MAXN],ed;// Graph
int hson[MAXN],w[MAXN],fw[MAXN],top[MAXN],dfs_clock;// Link
int d[M<<1];
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
void init()
{
	dfs_clock=ed=0;
	memset(fir,0,sizeof(fir));
	memset(hson,0,sizeof(hson));
	memset(top,0,sizeof(top));
	memset(d,0,sizeof(d));
	return;
}
void DFS1(int u)
{
	size[u]=1;
	for(int i=fir[u];i;i=next[i]) if(end[i]!=fa[u])
	{
		dep[end[i]]=dep[u]+1;
		fa[end[i]]=u;
		DFS1(end[i]);
		size[u]+=size[end[i]];
		if(hson[u]==0||size[hson[u]]<size[end[i]])
			hson[u]=end[i];
	}
	return;
}
void Dist(int u,int tOp)
{
	w[u]=++dfs_clock;
	fw[dfs_clock]=u;
	top[u]=tOp;
	if(hson[u]) Dist(hson[u],tOp);
	for(int i=fir[u];i;i=next[i]) if(end[i]!=fa[u]&&end[i]!=hson[u])
		Dist(end[i],end[i]);
	return;
}
int mAx(int L,int R)
{
	int ans=0;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) ans=max(ans,d[L^1]);
		if(R&1) ans=max(ans,d[R^1]);
	}
	return ans;
}
void change(int j,int x)
{
	d[w[E[j].u]+M]=x;
	for(int i=(w[E[j].u]+M)>>1;i;i>>=1)
		d[i]=max(d[i<<1],d[i<<1|1]);
	return;
}
int query(int u,int v)
{
	int ans=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		ans=max(ans,mAx(w[top[u]],w[u]));
		u=fa[top[u]];
	}
	if(u!=v)
	{
		if(dep[u]<dep[v])
			swap(u,v);
		ans=max(ans,mAx(w[v]+1,w[u]));
	}
	return ans;
}
int main()
{
	freopen("A.in","r",stdin);
	char comm[10];
	int u,v;
	scanf("%d",&T_T);
	while(T_T--)
	{
		init();
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
			addedge(E[i].u,E[i].v);
		}
		dep[1]=1;
		fa[1]=1;
		DFS(1);
		Dist(1,1);
		for(int i=1;i<n;i++)
		{
			if(dep[E[i].u]<dep[E[i].v])
				swap(E[i].u,E[i].v);
			d[w[E[i].u]+M]=E[i].w;
		}
		for(int i=M-1;i;i--)
			d[i]=max(d[i<<1],d[i<<1|1]);
		while(true)
		{
			scanf("%s",comm);
			if(comm[0]=='D') break;
			scanf("%d%d",&u,&v);
			if(comm[0]=='Q') printf("%d\n",query(u,v));
			else change(u,v);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

