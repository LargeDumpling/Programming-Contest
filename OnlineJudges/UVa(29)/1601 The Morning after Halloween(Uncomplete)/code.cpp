#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,k;
int st[3][2],ed[3][2],fir[300],end[140000],next[140000],ed=0;
int move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char tex[20][20];
void init()
{
	memset(st,0,sizeof(st));
	memset(ed,0,sizeof(ed));
	memset(fir,0,sizeof(fir));
	memset(end,0,sizeof(end));
	memset(next,0,sizeof(next));
	ed=0;
	return;
}
int idx(int x,int y)
{
	return x*17+y;
}
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
bool input()
{
	int x,y;
	scanf("%d%d%d",&n,&m,&k);
	if(!n&&!m&&!k)
		return false;
	for(int i=1;i<=m;i++)
		scanf("%s",tex[i]+1);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if('A'<=tex[i][j]&&tex[i][j]<='Z')
				st[tex[i][j]-'A'][0]=i,st[tex[i][j]-'A'][1]=j;
			if('a'<=tex[i][j]&&tex[i][j]<='z')
				ed[tex[i][j]-'a'][0]=i,ed[tex[i][j]-'a'][1]=j;
		}
	if(n==1)
	{
		if(!st[0][0])
			swap(st[0][0],st[2][0]),swap(ed[0][0],ed[2][0]),swap(st[0][1],st[2][1]),swap(ed[0][1],ed[2][1]);
		if(!st[0][0])
			swap(st[0][0],st[1][0]),swap(ed[0][0],ed[1][0]),swap(st[0][1],st[1][1]),swap(ed[0][1],ed[1][1]);
	}
	else if(n==2)
	{
		if(!st[0][0])
			swap(st[0][0],st[2][0]),swap(ed[0][0],ed[2][0]),swap(st[0][1],st[2][1]),swap(ed[0][1],ed[2][1]);
		if(!st[1][0])
			swap(st[1][0],st[2][0]),swap(ed[1][0],ed[2][0]),swap(st[1][1],st[2][1]),swap(ed[1][1],ed[2][1]);
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<4;k++)
			{
				x=i+move[k][0];
				y=j+move[k][1];
				if(x<1||m<x||y<1||n<y||map[x][y]=='#')
					continue;
				addedge(idx(i,j),idx(x,y));
			}
	return true;
}
struct jp
{
	int A,B,C,dis;
	jp(int a=0,int b=0,int c=0,int d=0):A(a),B(b),C(c),dis(d){}
};
queue<jp>q;
void BFS()
{
	int xa,ya,xb,yb,xc,yc,xA,yA,xB,yB,xC,yC;
	jp u;
	q.push(st[0][0]*1000+st[0][1],st[1][0]*1000+st[1][1],st[2][0]*1000+st[2][1],0);
	while(q.size())
	{
		u=q.front();
		q.pop();
		xa=u.a;
		ya=xa%1000;xa/=1000;
		xb=u.b;
		yb=xb%1000;xb/=1000;
		xc=u.c;
		yc=xc%1000;xc/=1000;
		for(int i=
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(input())
	{
		printf("%d\n",BFS());
		init();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

