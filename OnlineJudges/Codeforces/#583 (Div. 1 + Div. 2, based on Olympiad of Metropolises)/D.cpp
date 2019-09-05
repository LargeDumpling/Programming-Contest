/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-09-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=2000050;
int S=0,T=MAXN-1;
int n,m,fir[MAXN],edd[MAXN<<2],nxt[MAXN<<2],len[MAXN<<2],ed=0;
int dis[MAXN];
bool vis[MAXN];
char str[2][MAXN];
void addedge(int u,int v,int c)
{
	edd[++ed]=v;
	len[ed]=c;
	nxt[ed]=fir[u];
	fir[u]=ed;
	return;
}
int idx(int x,int y) { return (x-1)*m+y; }
int SPFA()
{
	int u,v;
	memset(dis,127,sizeof(dis));
	memset(vis,false,sizeof(vis));
	queue<int> q;
	q.push(S);
	vis[S]=true;
	dis[S]=0;
	while(q.size())
	{
		u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=fir[u];i;i=nxt[i])
		{
			v=edd[i];
			if(dis[u]+len[i]<dis[v])
			{
				dis[v]=dis[u]+len[i];
				if(!vis[v])
				{
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
	if(2<dis[T]) while(true);
	return dis[T];
}
int main()
{
	int d=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str[d]+1);
		if(i==1) for(int j=2;j<=m;j++)
			if(n!=1||j!=m)
				addedge(idx(i,j),T,0);
		for(int j=1;j<=m;j++)
		{
			if(1<i&&(i!=2||j!=1)&&(i!=n||j!=m))
				addedge(idx(i,j),idx(i-1,j),(int)(str[d^1][j]=='.'));
			if(j<m&&1<i)
				addedge(idx(i,j),idx(i-1,j+1),(int)(str[d^1][j+1]=='.'));
			if(j<m&&(i!=1||j!=1)&&(i!=n||j!=m-1))
				addedge(idx(i,j),idx(i,j+1),(int)(str[d][j+1]=='.'));

			if(j==1&&i!=1) addedge(S,idx(i,j),(int)(str[d][j]=='.'));
			if(j==m&&i!=n) addedge(idx(i,j),T,0);
		}
		if(i==n) for(int j=1;j<m;j++)
			if(n!=1||j!=1)
				addedge(S,idx(i,j),(int)(str[d][j]=='.'));
		d^=1;
	}
	printf("%d",SPFA());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

