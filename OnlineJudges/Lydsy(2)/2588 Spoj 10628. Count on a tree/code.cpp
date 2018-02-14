/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-02	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int MAX_SIZE=8000000;
int n,m,num[MAXN],h[MAXN];
int fir[MAXN],end[MAXN<<1],next[MAXN<<1],ed=0;// Graph
int fa[MAXN][17],dep[MAXN];// LCA
int data[MAX_SIZE],son[MAX_SIZE][2],root[MAXN],sz=0;
int lastans=0;
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
void read1n(int &x)
{
	char ch; bool neg=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch=='-')
			neg=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return;
}
void build(int L,int R,int x,int last,int &now)
{
	now=++sz;
	data[now]=data[last]+1;
	if(L==R) return;
	int mid=(L+R)>>1;
	son[now][0]=son[last][0];
	son[now][1]=son[last][1];
	if(x<=mid) build(L,mid,x,son[last][0],son[now][0]);
	else build(mid+1,R,x,son[last][1],son[now][1]);
	return;
}
void DFS(int u)
{
	for(int i=1;i<17;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=fir[u];i;i=next[i]) if(end[i]!=fa[u][0])
	{
		dep[end[i]]=dep[u]+1;
		fa[end[i]][0]=u;
		build(1,n,num[end[i]],root[u],root[end[i]]);
		DFS(end[i]);
	}
	return;
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	int t=dep[u]-dep[v];
	for(int i=0;i<17;i++) if((t>>i)&1) u=fa[u][i];
	for(int i=16;0<=i;i--) if(fa[u][i]!=fa[v][i])
	{
		u=fa[u][i];
		v=fa[v][i];
	}
	if(u!=v) u=fa[u][0];
	return u;
}
int query(int u,int v,int k)
{
	int lca=LCA(u,v),L=1,R=n,t,mid,tem;
	u=root[u]; v=root[v]; t=root[lca];
	while(L<R)
	{
		mid=(L+R)>>1;
		if(num[lca]<=mid) tem=1;
		else tem=0;
		if(k<=data[son[u][0]]+data[son[v][0]]-(data[son[t][0]]<<1)+tem)
		{
			u=son[u][0];
			v=son[v][0];
			t=son[t][0];
			R=mid;
		}
		else
		{
			k-=(data[son[u][0]]+data[son[v][0]]-(data[son[t][0]]<<1)+tem);
			u=son[u][1];
			v=son[v][1];
			t=son[t][1];
			L=mid+1;
		}
	}
	return L;
}
int main()
{
	//freopen("code.in","r",stdin);
	int u,v,k;
	h[0]=0;
	read1n(n);
	read1n(m);
	//scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		read1n(num[i]);
		//scanf("%d",&num[i]);
		h[++h[0]]=num[i];
	}
	sort(h+1,h+h[0]+1);
	h[0]=unique(h+1,h+h[0]+1)-h-1;
	for(int i=1;i<=n;i++)
		num[i]=lower_bound(h+1,h+h[0]+1,num[i])-h;
	for(int i=1;i<n;i++)
	{
		read1n(u);
		read1n(v);
		//scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	fa[1][0]=1;
	build(1,n,num[1],root[0],root[1]);
	DFS(1);
	for(int i=1;i<=m;i++)
	{
		//scanf("%d%d%d",&u,&v,&k);
		read1n(u); u^=lastans;
		read1n(v);
		read1n(k);
		printf("%d",lastans=h[query(u,v,k)]);
		if(i!=m) putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

