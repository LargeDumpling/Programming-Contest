#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define inf 1000000000
#define ll long long 
#define N 400005
#define M 200005
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
bool type;
int n,m,Q,lastans,top,tot,sz;
int s[N],st[M],root[M];
int c[N][2],fa[N],val[N],mn[N];
int sum[4000005],ls[4000005],rs[4000005];
bool rev[N];
struct edge{int u,v;}e[M];
bool isroot(int x)
{
	return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
}
void update(int x)
{
	int l=c[x][0],r=c[x][1];
	mn[x]=x;
	if(val[mn[l]]<val[mn[x]])mn[x]=mn[l];
	if(val[mn[r]]<val[mn[x]])mn[x]=mn[r];	
}
void pushdown(int x)
{
	int l=c[x][0],r=c[x][1];
	if(rev[x])
	{
		rev[x]^=1;rev[l]^=1;rev[r]^=1;
		swap(c[x][0],c[x][1]);
	}
}
void rotate(int x)
{
	int y=fa[x],z=fa[y],l,r;
	if(c[y][0]==x)l=0;else l=1;r=l^1;
	if(!isroot(y))
	{
		if(c[z][0]==y)c[z][0]=x;else c[z][1]=x;
	}
	fa[y]=x;fa[x]=z;fa[c[x][r]]=y;
	c[y][l]=c[x][r];c[x][r]=y;
	update(y);update(x);
}
void splay(int x)
{
	top=0;s[++top]=x;
	for(int i=x;!isroot(i);i=fa[i])
		s[++top]=fa[i];
	for(int i=top;i;i--)
		pushdown(s[i]);
	while(!isroot(x))
	{
		int y=fa[x],z=fa[y];
		if(!isroot(y))
		{
			if(c[y][0]==x^c[z][0]==y)rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
}
void access(int x)
{
	for(int t=0;x;t=x,x=fa[x])
	{
		splay(x);c[x][1]=t;update(x);
	}
}
void makeroot(int x)
{
	access(x);splay(x);rev[x]^=1;
}
void link(int x,int y)
{
	makeroot(x);fa[x]=y;
}
void cut(int x,int y)
{
	makeroot(x);access(y);splay(y);
	c[y][0]=fa[x]=0;
}
int find(int x)
{
	access(x);splay(x);
	while(c[x][0])x=c[x][0];
	return x;
}
int query(int x,int y)
{
	makeroot(x);access(y);splay(y);
	return mn[y];
}
void insert(int l,int r,int x,int &y,int val)
{
	y=++sz;
	sum[y]=sum[x]+1;
	if(l==r)return;
	ls[y]=ls[x];rs[y]=rs[x];
	int mid=(l+r)>>1;
	if(val<=mid)insert(l,mid,ls[x],ls[y],val);
	else insert(mid+1,r,rs[x],rs[y],val);
}
int query(int l,int r,int x,int y,int val)
{
	if(r==val)return sum[y]-sum[x];
	int mid=(l+r)>>1;
	if(val<=mid)return query(l,mid,ls[x],ls[y],val);
	else return sum[ls[y]]-sum[ls[x]]+query(mid+1,r,rs[x],rs[y],val);
}
void pre()
{
	tot=n;
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v;
		if(u==v)
		{
			st[i]=i;continue;
		}
		if(find(u)==find(v))
		{
			int t=query(u,v),x=val[t];
			st[i]=x;
			cut(e[x].u,t);cut(e[x].v,t);
		}
		tot++;
		mn[tot]=tot;val[tot]=i;
		link(u,tot);link(v,tot);
	}
	for(int i=1;i<=m;i++)
		insert(0,m,root[i-1],root[i],st[i]);
}
void solve()
{
	for(int i=1;i<=Q;i++)
	{
		int l=read(),r=read();
		if(type)l^=lastans,r^=lastans;
		lastans=n-query(0,m,root[l-1],root[r],l-1);
		printf("%d\n",lastans);
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	
	n=read();m=read();Q=read();type=read();
	val[0]=inf;
	for(int i=1;i<=n;i++)mn[i]=i,val[i]=inf;
	for(int i=1;i<=m;i++)
		e[i].u=read(),e[i].v=read();
	pre();
	solve();
	return 0;
}
