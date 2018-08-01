/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-31	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int M=131072;
int fir[MAXN],eNd[MAXN<<1],nExt[MAXN<<1],ed=0;
int fa[MAXN],hson[MAXN],dep[MAXN],size[MAXN],w[MAXN],dfs_clock=0;
int top[MAXN];
long long d[M<<1][2];
int n,fn;
struct Que
{
	int u,v,len;
	bool operator<(const Que &Q)const
	{ return len<Q.len; }
}Q[MAXN];
void addedge(int u,int v)
{
	eNd[++ed]=v;
	nExt[ed]=fir[u];
	fir[u]=ed;
	eNd[++ed]=u;
	nExt[ed]=fir[v];
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
void change(int p,long long x1,long long x2)
{
	for(p+=M;p;p>>=1)
	{
		d[p][0]+=x1;
		d[p][1]+=x2;
	}
	return;
}
long long query(int L,int R,int t)
{
	long long sum=0;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) sum+=d[L^1][t];
		if(R&1) sum+=d[R^1][t];
	}
	return sum;
}
void DFS1(int u)
{
	size[u]=1;
	for(int i=fir[u];i;i=nExt[i]) if(eNd[i]!=fa[u])
	{
		dep[eNd[i]]=dep[u]+1;
		fa[eNd[i]]=u;
		DFS1(eNd[i]);
		size[u]+=size[eNd[i]];
		if(size[hson[u]]<size[eNd[i]])
			hson[u]=eNd[i];
	}
	return;
}
void DFS2(int u,int tOp)
{
	w[u]=++dfs_clock;
	top[u]=tOp;
	if(hson[u]) DFS2(hson[u],tOp);
	for(int i=fir[u];i;i=nExt[i]) if(eNd[i]!=fa[u]&&eNd[i]!=hson[u])
		DFS2(eNd[i],eNd[i]);
	return;
}
long long big_rand()
{
	return ((((long long)rand())<<15)+rand())*rand();
}
int LCA(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
void Query(int u,int v,long long &sum1,long long &sum2)
{
	sum1=sum2=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		sum1+=query(w[top[u]],w[u],0);
		sum2+=query(w[top[u]],w[u],1);
		u=fa[top[u]];
	}
	if(dep[v]<dep[u]) swap(u,v);
	sum1+=query(w[u],w[v],0);
	sum2+=query(w[u],w[v],1);
	return;
}
int main()
{
	int u,v,lca;
	long long x1,x2;
	bool flag=true;
	srand(772002);
	read1n(n);
	read1n(fn);
	for(int i=1;i<n;i++)
	{
		read1n(u); read1n(v);
		addedge(u,v);
	}
	dep[1]=0;
	fa[1]=0;
	DFS1(1);
	DFS2(1,1);
	for(int i=1;i<=fn;i++)
	{
		read1n(Q[i].u);
		read1n(Q[i].v);
		lca=LCA(Q[i].u,Q[i].v);
		Q[i].len=dep[Q[i].u]+dep[Q[i].v]-2*dep[lca]+1;
	}
	sort(Q+1,Q+fn+1);
	for(int i=1;i<=fn;i++)
	{
		u=Q[i].u; v=Q[i].v;
		Query(u,v,x1,x2);
		if(x1||x2)
		{
			flag=false;
			break;
		}
		x1=big_rand();
		x2=big_rand();
		change(w[u],x1,x2);
		change(w[v],-x1,-x2);
	}
	if(flag) puts("Yes");
	else puts("No");
	return 0;
}

