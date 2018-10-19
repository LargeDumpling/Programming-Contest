/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,Q;
int fir[MAXN],edd[MAXN<<1],nxt[MAXN<<1],ed=0;
int size[MAXN],fa[MAXN],dep[MAXN],top[MAXN],hson[MAXN],w[MAXN],dfs_clock=0;
int d[MAXN<<2],tag[MAXN<<2],L[MAXN<<2],R[MAXN<<2];
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
	for(int i=fir[u];i;i=nxt[i]) if(edd[i]!=fa[u])
	{
		fa[edd[i]]=u;
		dep[edd[i]]=dep[u]+1;
		DFS(edd[i]);
		size[u]+=size[edd[i]];
		if(size[hson[u]]<size[edd[i]])
			hson[u]=edd[i];
	}
	return;
}
void Asntop(int u,int T)
{
	top[u]=T;
	w[u]=++dfs_clock;
	if(hson[u]) Asntop(hson[u],T);
	for(int i=fir[u];i;i=nxt[i]) if(edd[i]!=fa[u]&&edd[i]!=hson[u])
		Asntop(edd[i],edd[i]);
	return;
}

#define lch ((root)<<1)
#define rch ((root)<<1|1)
void build(int root,int l,int r)
{
	L[root]=l; R[root]=r;
	d[root]=0;
	tag[root]=-1;
	if(l==r) return;
	int mid=(L[root]+R[root])>>1;
	build(lch,l,mid); build(rch,mid+1,r);
	return;
}
void down(int root)
{
	if(tag[root]==-1) return;
	if(L[root]==R[root])
	{
		tag[root]=-1;
		return;
	}
	d[lch]=tag[root]*(R[lch]-L[lch]+1);
	d[rch]=tag[root]*(R[rch]-L[rch]+1);
	tag[lch]=tag[root];
	tag[rch]=tag[root];
	tag[root]=-1;
	return;
}
void change(int root,int l,int r,int x)
{
	if(l<=L[root]&&R[root]<=r)
	{
		d[root]=x*(R[root]-L[root]+1);
		tag[root]=x;
		return;
	}
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(l<=mid) change(lch,l,r,x);
	if(mid<r) change(rch,l,r,x);
	d[root]=d[lch]+d[rch];
	return;
}
#undef lch
#undef rch
int cnt(int u,int v)
{
	int ans=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		ans+=(w[u]-w[top[u]]+1);
		u=fa[top[u]];
	}
	ans+=abs(w[u]-w[v])+1;
	return ans;
}
void change(int u,int v,int x)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		change(1,w[top[u]],w[u],x);
		u=fa[top[u]];
	}
	change(1,min(w[u],w[v]),max(w[u],w[v]),x);
	return;
}
int calc(int A,int B,int C,int D)
{
	int ans=cnt(A,B)+cnt(C,D);
	change(A,B,1); change(C,D,1);
	ans-=d[1];
	change(A,B,0); change(C,D,0);
	return ans;
}
int main()
{
	int u,v,A,B,C,D;
	read1n(n); read1n(Q);
	build(1,1,n);
	for(int i=1;i<n;i++)
	{
		read1n(u);
		read1n(v);
		addedge(u,v);
	}
	build(1,1,n);
	dep[1]=fa[1]=0;
	DFS(1);
	Asntop(1,1);
	while(Q--)
	{
		read1n(A); read1n(B);
		read1n(C); read1n(D);
		printf("%d\n",calc(A,B,C,D));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

