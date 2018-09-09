/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=250050;
struct jz
{
	int u,v;
	long long w;
	jz(const int &U=0,const int &V=0,const long long &W=0):u(U),v(V),w(W) { }
	bool operator<(const jz &X)const { return w>X.w; }
}E[MAXN<<1];
int n,m,en=0;
int fir[MAXN],edd[MAXN<<2],nxt[MAXN<<2],f[MAXN],ed=0;
int dep[MAXN],fa[MAXN][18];
long long len[MAXN<<2];
void addedge(int u,int v,long long w)
{
	edd[++ed]=v;
	nxt[ed]=fir[u];
	fir[u]=ed;
	len[ed]=w;
	edd[++ed]=u;
	nxt[ed]=fir[v];
	fir[v]=ed;
	len[ed]=w;
	return;
}
int ind(int x,int y) { return (x-1)*m+y; }
int find(int x)
{
	if(f[x]!=f[f[x]]) f[x]=find(f[x]);
	return f[x];
}
void merge(int a,int b)
{
	a=find(a); b=find(b);
	f[b]=a;
	return;
}
template<typename ty>
void read1n(ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void DFS(int u)
{
	for(int i=1;i<18;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=fir[u];i;i=nxt[i]) if(edd[i]!=fa[u][0])
	{
		dep[edd[i]]=dep[u]+1;
		fa[edd[i]][0]=u;
		DFS(edd[i]);
	}
	return;
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	int t=dep[u]-dep[v];
	for(int i=0;i<18;i++) if((t>>i)&1)
		u=fa[u][i];
	for(int i=17;0<=i;i--) if(fa[u][i]!=fa[v][i])
	{
		u=fa[u][i];
		v=fa[v][i];
	}
	return u==v?u:fa[u][0];
}
int query(int u,int v)
{
	int t=LCA(u,v);
	return dep[u]+dep[v]-dep[t]*2;
}
int main()
{
	int u,v,Q,x1,x2,y1,y2;
	long long w;
	//scanf("%d%d",&n,&m);
	read1n(n); read1n(m);
	for(int i=n*m;i;i--) f[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//scanf("%lld",&w);
			read1n(w);
			if(i!=n) E[++en]=jz(ind(i,j),ind(i+1,j),w);
			//scanf("%lld",&w);
			read1n(w);
			if(j!=m) E[++en]=jz(ind(i,j),ind(i,j+1),w);
		}
	}
	sort(E+1,E+en+1);
	for(int i=1;i<=en;i++)
	{
		u=E[i].u;
		v=E[i].v;
		w=E[i].w;
		if(find(u)!=find(v))
		{
			merge(u,v);
			addedge(u,v,w);
		}
	}
	dep[1]=0;
	fa[1][0]=1;
	DFS(1);
	read1n(Q);
	/*cerr<<"***"<<eddl;
	for(int i=1;i<=n*m;i++)
		printf("%d\n",dep[i]);
	cerr<<"***"<<eddl;*/
	while(Q--)
	{
		read1n(x1); read1n(y1);
		read1n(x2); read1n(y2);
		printf("%d\n",query(ind(x1,y1),ind(x2,y2)));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

