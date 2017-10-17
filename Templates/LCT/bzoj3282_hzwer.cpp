#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define N 300005
using namespace std;
int n,m,top;
int c[N][2],fa[N],v[N],s[N],q[N];
bool rev[N];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void update(int x)
{
	int l=c[x][0],r=c[x][1];
	s[x]=s[l]^s[r]^v[x];
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
bool isroot(int x)
{
	return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
}
void rotate(int x)
{
	int y=fa[x],z=fa[y],l,r;
	if(c[y][0]==x)l=0;else l=1;r=l^1;
	if(!isroot(y))
	{
		if(c[z][0]==y)c[z][0]=x;else c[z][1]=x;
	}
	fa[x]=z;fa[y]=x;fa[c[x][r]]=y;
	c[y][l]=c[x][r];c[x][r]=y;
	update(y);update(x);
}
void splay(int x)
{
	top=0;q[++top]=x;
	for(int i=x;!isroot(i);i=fa[i])
		q[++top]=fa[i];
	for(int i=top;i;i--)
		pushdown(q[i]);
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
		splay(x),c[x][1]=t,update(x);
}
void makeroot(int x)
{
	access(x);splay(x);rev[x]^=1;
}
int find(int x)
{
	access(x);splay(x);
	while(c[x][0])x=c[x][0];
	return x;
}
void cut(int y,int x)
{
	makeroot(x);access(y);splay(y);
	if(c[y][0]==x)c[y][0]=fa[x]=0;
}
void link(int x,int y)
{
	makeroot(x);fa[x]=y;
}
int main()
{
	freopen("in.txt","r",stdin);
	
	n=read();m=read();
	for(int i=1;i<=n;i++)v[i]=read(),s[i]=v[i];
	int opt,x,y;
	for(int i=1;i<=m;i++)
	{
		opt=read();x=read();y=read();
		switch(opt)
		{
		case 0:makeroot(y);
		access(x);
		splay(x);
		printf("%d\n",s[x]);
		break;
		case 1:if(find(x)!=find(y))link(x,y);break;
		case 2:if(find(x)==find(y))cut(x,y);break;
		case 3:access(x);splay(x);v[x]=y;update(x);break;
		}
	}
	return 0;
}
