#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,k,e;
long long INF;
int map[25][25];
bool useable[105][25],avail[25];
long long f[105],cost[105][105],dis[25];
long long SPFA(int s, int t, int l, int r)
{
	queue<int>q;
	bool inq[25];
	memset(inq,false,sizeof(inq));
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= m; i++)
	{
		avail[i] = 1;
		for(int j = l; j <= r; j++) if(!useable[i][j])
		{
			avail[i] = 0;
			break;
		}
	}
	dis[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = 0;
		for(int i = 1; i <=m; i++)
		{
			if(!avail[i]||map[u][i]==-1||dis[u]+map[u][i]>=dis[i])continue;
			dis[i]=dis[u]+map[u][i];
			if(!inq[i])
			{
				q.push(i);
				inq[i]=true;
			}
		}
	}
	return dis[t];
}
/*int Sijkstra(int l,int h)
{
	int u;
	memset(exist,false,sizeof(exist));
	dis[1]=0;
	exist[1]=true;
	for(int i=2;i<=m;i++)
		dis[i]=(map[1][i]==-1?INF:map[1][i]);
	for(int i=1;i<=m;i++)
	{
		avail[i]=true;
		for(int j=l;j<=h;j++)
			if(!useable[i][j])
			{
				avail[i]=false;
				break;
			}
	}
	for(int i=1;i<m;i++)
	{
		u=-1;
		for(int j=2;j<=m;j++)
		{
			if(exist[j]||!avail[j])
				continue;
			if(u==-1||(u!=-1&&dis[j]<dis[u]))
				u=j;
		}
		if(u==-1)
			break;
		exist[u]=true;
		for(int j=1;j<=m;j++)
		{
			if(map[u][j]==-1||u==j||exist[j]||!avail[j])
				continue;
			if(dis[u]+map[u][j]<dis[j])
				dis[j]=dis[u]+map[u][j];
		}
	}
	return dis[m];
}*/
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,c,d;
	memset(map,-1,sizeof(map));
	memset(useable,true,sizeof(useable));
	memset(&INF, 0x3f, sizeof INF);
	scanf("%d%d%d%d",&n,&m,&k,&e);
	for(int i=1;i<=e;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		map[a][b]=map[b][a]=(c<map[a][b]?c:(map[a][b]==-1?c:map[a][b]));
	}
	scanf("%d",&d);
	for(int i=1;i<=d;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		for(int j=b;j<=c;j++)
			useable[a][j]=false;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			cost[i][j]=/*Sijkstra(i,j)*/SPFA(1,m,i,j);
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1,j;i<=n;i++)
		for(j=i-1;j>=0;j--)
		{
			if(cost[j+1][i]==INF||f[j]==f[104])
				continue;
			f[i]=min(f[i],f[j]+cost[j+1][i]*(i-j)+k);
		}
	printf("%lld\n",f[n]-k);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


