/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int INF=2147483647;
int n,m,k,fir[MAXN],edd[MAXN<<1],nxt[MAXN<<1],ed=0;
int dep[MAXN],fa[MAXN],size[MAXN],hson[MAXN],top[MAXN],cnt[MAXN];
int dfn[MAXN],idfn[MAXN],dfs_clock=0;
int L[MAXN<<2],R[MAXN<<2],d[MAXN<<2],tag[MAXN<<2];
int ans[MAXN];
struct jz
{
	int u,v,c;
	jz(const int &U=0,const int &V=0,const int &C=0):u(U),v(V),c(C) { }
}kol[MAXN];
void addedge(int u,int v)
{
	edd[++ed]=v;
	nxt[ed]=fir[u];
	fir[u]=ed;
	edd[++ed]=u;
	nxt[ed]=fir[v];
	fir[v]=ed;
	return;
}
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void DFS(int u)
{
	size[u]=1;
	hson[u]=0;
	for(int i=fir[u];i;i=nxt[i]) if(edd[i]!=fa[u])
	{
		dep[edd[i]]=dep[u]+1;
		fa[edd[i]]=u;
		DFS(edd[i]);
		size[u]+=size[edd[i]];
		if(size[hson[u]]<size[edd[i]])
			hson[u]=edd[i];
	}
	return;
}
void calctop(int u,int Top)
{
	dfn[u]=++dfs_clock;
	idfn[dfs_clock]=u;
	top[u]=Top;
	if(hson[u]) calctop(hson[u],Top);
	for(int i=fir[u];i;i=nxt[i]) if(edd[i]!=fa[u]&&edd[i]!=hson[u])
		calctop(edd[i],edd[i]);
	return;
}
void pre_add(int l,int r)
{
	cnt[l]++;
	cnt[r+1]--;
	return;
}
void pre_calc(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		pre_add(dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	if(dep[v]<dep[u]) swap(u,v);
	pre_add(dfn[u],dfn[v]);
	return;
}
#define lch ((root)<<1)
#define rch ((root)<<1|1)
void build(int root,int l,int r)
{
	L[root]=l; R[root]=r;
	tag[root]=0;
	if(l==r)
	{
		if(k<=cnt[l]) d[root]=-(cnt[l]-k+1);
		else d[root]=-INF;
		tag[root]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	d[root]=max(d[lch],d[rch]);
	return;
}
void down(int root)
{
	if(!tag[root]) return;
	if(L[root]==R[root])
	{
		tag[root]=0;
		return;
	}
	d[lch]+=tag[root];
	tag[lch]+=tag[root];
	d[rch]+=tag[root];
	tag[rch]+=tag[root];
	tag[root]=0;
	return;
}
void deal(int root,int tim)
{
	if(L[root]==R[root])
	{
		if(!d[root])
		{
			ans[idfn[L[root]]]=tim;
			d[root]=-INF;
		}
		return;
	}
	down(root);
	if(!d[lch]) deal(lch,tim);
	if(!d[rch]) deal(rch,tim);
	d[root]=max(d[lch],d[rch]);
	return;
}
void change(int root,int l,int r,int tim)
{
	if(l<=L[root]&&R[root]<=r)
	{
		d[root]++;
		tag[root]++;
		if(!d[root]) deal(root,tim);
		return;
	}
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(l<=mid) change(lch,l,r,tim);
	if(mid<r) change(rch,l,r,tim);
	d[root]=max(d[lch],d[rch]);
	return;
}
void calc(int u,int v,int c)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		change(1,dfn[top[u]],dfn[u],c);
		u=fa[top[u]];
	}
	if(dep[v]<dep[u]) swap(u,v);
	change(1,dfn[u],dfn[v],c);
	return;
}
#undef lch
#undef rch
int main()
{
	int u,v;
	read1n(n); read1n(m);
	read1n(k);
	for(int i=1;i<n;i++)
	{
		read1n(u); read1n(v);
		addedge(u,v);
	}
	for(int i=1;i<=m;i++)
	{
		read1n(kol[i].u);
		read1n(kol[i].v);
		read1n(kol[i].c);
	}
	fa[1]=1;
	dep[1]=0;
	DFS(1);
	calctop(1,1);
	for(int i=1;i<=m;i++)
		pre_calc(kol[i].u,kol[i].v);
	for(int i=1;i<=n;i++)
		cnt[i]+=cnt[i-1];
	build(1,1,n);
	for(int i=1;i<=m;i++)
		calc(kol[i].u,kol[i].v,kol[i].c);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

