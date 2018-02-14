/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=1050;
const long long INF=(1LL<<62)-1LL+(1LL<<62);
struct jp
{
	int u;
	long long dis;
	jp(const int &U=0,const long long &D=0):u(U),dis(D) { }
	bool operator<(const jp &X)const { return dis>X.dis; }
};
int T,S,D;
long long map[MAXN][MAXN],len[MAXN*MAXN],dis[MAXN];
int fir[MAXN],eNd[MAXN*MAXN],nExt[MAXN*MAXN],ed=0;
bool exist[MAXN];
void addedge(int u,int v,int w)
{
	eNd[++ed]=v;
	nExt[ed]=fir[u];
	fir[u]=ed;
	len[ed]=w;
	eNd[++ed]=u;
	nExt[ed]=fir[v];
	fir[v]=ed;
	len[ed]=w;
	return;
}
long long Hijkstra()
{
	int u;
	memset(exist,false,sizeof(exist));
	for(int i=0;i<MAXN;i++)
		dis[i]=INF;
	priority_queue<jp> q;
	dis[0]=0;
	q.push(jp(0,0));
	for(int i=0;i<MAXN;i++)
	{
		while(q.size()&&(exist[q.top().u]||dis[q.top().u]!=q.top().dis)) q.pop();
		if(!q.size()) break;
		u=q.top().u;
		q.pop();
		exist[u]=true;
		for(int i=fir[u];i;i=nExt[i]) if(dis[u]+len[i]<dis[eNd[i]])
		{
			dis[eNd[i]]=dis[u]+len[i];
			q.push(jp(eNd[i],dis[eNd[i]]));
		}
	}
	return dis[1025];
}
int main()
{
	int u,v;
	long long w;
	while(scanf("%d%d%d",&T,&S,&D)!=-1)
	{
		memset(map,127,sizeof(map));
		memset(fir,ed=0,sizeof(fir));
		while(T--)
		{
			scanf("%d%d%lld",&u,&v,&w);
			map[u][v]=map[v][u]=min(w,map[u][v]);
		}
		for(int i=1;i<MAXN;i++)
			for(int j=i+1;j<MAXN;j++) if(map[i][j]!=map[0][0])
				addedge(i,j,map[i][j]);
		while(S--)
		{
			scanf("%d",&u);
			addedge(0,u,0);
		}
		while(D--)
		{
			scanf("%d",&u);
			addedge(u,1025,0);
		}
		printf("%lld\n",Hijkstra());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

