/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=55;
struct jz
{
	int u,dis;
	jz(const int &U=0,const int &D=0):u(U),dis(D) { }
	bool operator<(const jz &X)const { return dis>X.dis; }
};
int m,S,T;
int fir[MAXN],edd[MAXN*MAXN],nex[MAXN*MAXN],len[MAXN*MAXN],ed=0;
int dis[MAXN];
int map[MAXN][MAXN];
bool vis[MAXN];
void addedge(int u,int v,int w)
{
	edd[++ed]=v;
	nex[ed]=fir[u];
	fir[u]=ed;
	len[ed]=w;
	return;
}
int Hijkstra()
{
	for(int i=1;i<=m;i++)
	{
		dis[i]=2147483647;
		vis[i]=false;
	}
	int u,v;
	dis[S]=0;
	priority_queue<jz> q;
	q.push(jz(S,0));
	while(q.size())
	{
		while(q.size()&&(vis[q.top().u]||dis[q.top().u]!=q.top().dis)) q.pop();
		if(!q.size()) break;
		u=q.top().u; q.pop();
		vis[u]=true;
		for(int i=fir[u];i;i=nex[i])
		{
			v=edd[i];
			if(dis[u]+len[i]<dis[v])
			{
				dis[v]=dis[u]+len[i];
				q.push(jz(v,dis[v]));
			}
		}
	}
	return dis[T];
}
int main()
{
	int u,v,w;
	while(scanf("%d",&m)!=-1)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
				map[i][j]=2147483647;
			fir[i]=0;
		}
		ed=0;
		scanf("%d%d",&S,&T);
		while(true)
		{
			scanf("%d",&u);
			if(u==0) break;
			scanf("%d%d",&v,&w);
			if(w<map[u][v]) map[u][v]=map[v][u]=w;
		}
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++) if(i!=j&&map[i][j]!=2147483647)
				addedge(i,j,map[i][j]);
		printf("%d\n",Hijkstra());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

