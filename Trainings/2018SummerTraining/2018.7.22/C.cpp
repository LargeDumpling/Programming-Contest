/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-22	File created.
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
int n,m,fir[MAXN],eNd[MAXN<<1],nExt[MAXN<<1],ed=0;
int fa[MAXN],top[MAXN],dep[MAXN],size[MAXN],hson[MAXN],dfs_clock=0;
int w[MAXN],ans[MAXN];
bool d[M<<1];
struct jz
{
	int u,v,lca;
	bool operator<(const jz &X)const { return dep[lca]<dep[X.lca]; }
}E[MAXN];
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
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void DFS1(int u)
{
	size[u]=1;
	hson[u]=-1;
	for(int i=fir[u];i;i=nExt[i]) if(eNd[i]!=fa[u])
	{
		dep[eNd[i]]=dep[u]+1;
		fa[eNd[i]]=u;
		DFS1(eNd[i]);
		size[u]+=size[eNd[i]];
		if(hson[u]==-1||size[hson[u]]<size[eNd[i]])
			hson[u]=eNd[i];
	}
	return;
}
void DFS2(int u,int pretop)
{
	top[u]=pretop;
	w[u]=++dfs_clock;
	if(hson[u]!=-1) DFS2(hson[u],pretop);
	for(int i=fir[u];i;i=nExt[i]) if(eNd[i]!=fa[u]&&eNd[i]!=hson[u])
		DFS2(eNd[i],eNd[i]);
	return;
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
void change(int p,bool x)
{
	for(p+=M;p;p>>=1)
		d[p]|=x;
	return;
}
bool query(int L,int R)
{
	bool ans=false;
	for(L=L+M-1,R=R+M+1;L<R-1&&(!ans);L>>=1,R>>=1)
	{
		if(!(L&1)) ans|=d[L^1];
		if(R&1) ans|=d[R^1];
	}
	return ans;
}
bool query(int x)
{
	int u=E[x].u,v=E[x].v;
	bool ans=false;
	while(top[u]!=top[v]&&(!ans))
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		ans|=query(w[top[u]],w[u]);
		u=fa[top[u]];
	}
	if(dep[v]<dep[u]) swap(u,v);
	ans|=query(w[u],w[v]);
	return ans;
}
int main()
{
	int u,v;
	read1n(n);
	for(int i=1;i<n;i++)
	{
		read1n(u); read1n(v);
		addedge(u,v);
	}
	dep[1]=0;
	fa[1]=0;
	DFS1(1);
	DFS2(1,1);
	read1n(m);
	for(int i=1;i<=m;i++)
	{
		read1n(E[i].u);
		read1n(E[i].v);
		E[i].lca=LCA(E[i].u,E[i].v);
	}
	sort(E+1,E+m+1);
	ans[0]=0;
	for(int i=m;i;i--)
		if(!query(i))
		{
			ans[++ans[0]]=E[i].lca;
			change(w[E[i].lca],true);
		}
	printf("%d\n",ans[0]);
	for(int i=1;i<=ans[0];i++)
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

