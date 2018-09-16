/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int fir[MAXN],nxt[MAXN],fa[MAXN];
int n,m,L[MAXN<<2],R[MAXN<<2];
unsigned long long data[MAXN<<2],tag[MAXN<<2][2];
int dep[MAXN],size[MAXN],hson[MAXN],top[MAXN],dfn[MAXN],dfs_clock;
inline void addedge(int u,int v)
{
	nxt[v]=fir[u];
	fir[u]=v;
	return;
}
template<typename Ty>
inline bool read1n(Ty &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch==-1) return false;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return true;
}
inline void DFS1(int u)
{
	if(!u) return;
	size[u]=1;
	hson[u]=0;
	for(int v=fir[u];v;v=nxt[v])
	{
		dep[v]=dep[u]+1;
		DFS1(v);
		size[u]+=size[v];
		if(size[hson[u]]<size[v])
			hson[u]=v;
	}
	return;
}
inline void DFS2(int u,int Top)
{
	if(!u) return;
	top[u]=Top;
	dfn[u]=++dfs_clock;
	DFS2(hson[u],Top);
	for(int v=fir[u];v;v=nxt[v]) if(v!=hson[u])
		DFS2(v,v);
	return;
}
#define lch (root<<1)
#define rch (root<<1|1)
inline void down(int root)
{
	if(tag[root][0]==1&&!tag[root][1]) return;
	if(L[root]==R[root])
	{
		tag[root][0]=1;
		tag[root][1]=0;
		return;
	}
	data[lch]=data[lch]*tag[root][0]+tag[root][1]*(R[lch]-L[lch]+1);
	tag[lch][0]=tag[lch][0]*tag[root][0];
	tag[lch][1]=tag[lch][1]*tag[root][0]+tag[root][1];

	data[rch]=data[rch]*tag[root][0]+tag[root][1]*(R[rch]-L[rch]+1);
	tag[rch][0]=tag[rch][0]*tag[root][0];
	tag[rch][1]=tag[rch][1]*tag[root][0]+tag[root][1];

	tag[root][0]=1;
	tag[root][1]=0;
	return;
}
inline void build(int root,int l,int r)
{
	data[root]=tag[root][1]=0;
	tag[root][0]=1;
	L[root]=l; R[root]=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(lch,l,mid);
	build(rch,mid+1,r);
	return;
}
inline void add(int root,int l,int r,unsigned long long x)
{
	if(l<=L[root]&&R[root]<=r)
	{
		data[root]+=x*(R[root]-L[root]+1);
		tag[root][1]+=x;
		return;
	}
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(l<=mid) add(lch,l,r,x);
	if(mid<r) add(rch,l,r,x);
	data[root]=data[lch]+data[rch];
	return;
}
inline void add(int u,int v,unsigned long long x)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		add(1,dfn[top[u]],dfn[u],x);
		u=fa[top[u]];
	}
	if(dfn[v]<dfn[u]) swap(u,v);
	add(1,dfn[u],dfn[v],x);
	return;
}
inline void mul(int root,int l,int r,unsigned long long x)
{
	if(l<=L[root]&&R[root]<=r)
	{
		data[root]*=x;
		tag[root][0]*=x;
		tag[root][1]*=x;
		return;
	}
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(l<=mid) mul(lch,l,r,x);
	if(mid<r) mul(rch,l,r,x);
	data[root]=data[lch]+data[rch];
	return;
}
inline void mul(int u,int v,unsigned long long x)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		mul(1,dfn[top[u]],dfn[u],x);
		u=fa[top[u]];
	}
	if(dfn[v]<dfn[u]) swap(u,v);
	mul(1,dfn[u],dfn[v],x);
	return;
}
inline unsigned long long query(int root,int l,int r)
{
	if(l<=L[root]&&R[root]<=r) return data[root];
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(r<=mid) return query(lch,l,r);
	if(mid<l) return query(rch,l,r);
	return query(lch,l,r)+query(rch,l,r);
}
inline unsigned long long query(int u,int v)
{
	unsigned long long ans=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		ans+=query(1,dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	if(dfn[v]<dfn[u]) swap(u,v);
	ans+=query(1,dfn[u],dfn[v]);
	return ans;
}
#undef lch
#undef rch
void clear()
{
	dfs_clock=0;
	for(int i=1;i<=n;i++)
		fir[i]=0;
	return;
}
int main()
{
	int opt,u,v;
	unsigned long long x;
	while(read1n(n))
	{
		for(int i=2;i<=n;i++)
		{
			read1n(fa[i]);
			addedge(fa[i],i);
		}
		fa[1]=1;
		dep[1]=1;
		DFS1(1);
		DFS2(1,1);
		build(1,1,n);
		read1n(m);
		while(m--)
		{
			read1n(opt);
			switch(opt)
			{
				case 1:
					read1n(u);
					read1n(v);
					//cout<<"( "<<query(u,v)<<endl;
					read1n(x);
					mul(u,v,x);
					//cout<<" "<<query(u,v)<<" )"<<endl;
					break;
				case 2:
					read1n(u);
					read1n(v);
					//cout<<"( "<<query(u,v)<<endl;
					read1n(x);
					add(u,v,x);
					//cout<<" "<<query(u,v)<<" )"<<endl;
					break;
				case 3:
					read1n(u);
					read1n(v);
					//cout<<"( "<<query(u,v)<<endl;
					mul(u,v,-1);
					add(u,v,-1);
					//cout<<" "<<query(u,v)<<" )"<<endl;
					break;
				case 4:
					read1n(u);
					read1n(v);
					//cout<<query(u,v)<<endl;
					printf("%llu\n",query(u,v));
					break;
				default:
					break;
			}
		}
		clear();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

