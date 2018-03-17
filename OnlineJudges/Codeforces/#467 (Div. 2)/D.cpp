/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int INF=1147483647;
int n,m;
struct jz
{
	int u,dis;
	jz(const int &U=0,const int &D=0):u(U),dis(D) { }
	bool operator<(const jz &P)const { return P.dis<dis; }
};
int fir[MAXN],eNd[MAXN<<2],nExt[MAXN<<2],ed=0;
int dep[MAXN],low[MAXN],dfs_clock=0;
int sig[MAXN],siz[MAXN],ccn=0;
int st[MAXN],pre[MAXN][2];
bool exist[MAXN],vis[MAXN],avail[MAXN],dis[MAXN][2];
stack<int> ss[MAXN];
void addedge(int u,int v)
{
	eNd[++ed]=v;
	nExt[ed]=fir[u];
	fir[u]=ed;
	return;
}
void DFS(int u)
{
	dep[u]=low[u]=++dfs_clock;
	st[++st[0]]=u;
	for(int i=fir[u];i;i=nExt[i])
	{
		if(dep[eNd[i]]) low[u]=min(low[u],dep[eNd[i]]);
		else
		{
			DFS(eNd[i]);
			low[u]=min(low[u],low[eNd[i]]);
		}
	}
	if(dep[u]==low[u])
	{
		ss[u].push(u);
		sig[u]=++ccn;
		siz[ccn]=1;
		while(st[st[0]]!=u)
		{
			sig[st[st[0]]]=ccn;
			siz[ccn]++;
			ss[u].push(st[st[0]--]);
		}
		st[0]--;
	}
}
bool SPFA(int S)
{
	int u;
	bool flag=false;
	memset(vis,false,sizeof(vis));
	memset(exist,false,sizeof(exist));
	memset(dis,false,sizeof(dis));
	dis[S][1]=true;
	queue<int> q;
	q.push(S);
	while(q.size())
	{
		u=q.front(); q.pop();
		exist[u]=false;
		vis[u]=true;
		if(dep[u]==low[u]&&1<siz[sig[u]]&&siz[sig[u]]%2==1)
		{
			if(dis[u][0]==false)
			{
				dis[u][1]=true;
				pre[u][1]=u;
			}
			else if(dis[u][1]==false)
			{
				dis[u][0]=true;
				pre[u][0]=u;
			}
		}
		for(int i=fir[u];i;i=nExt[i])
		{
			if(vis[eNd[i]]) flag=true;
			else
			{
				if(dis[eNd[i]][0]==false&&dis[u][1]==true)
				{
					dis[eNd[i]][0]|=dis[u][1];
					pre[eNd[i]][0]=u;
				}
				if(dis[eNd[i]][1]==false&&dis[u][0]==true)
				{
					dis[eNd[i]][1]|=dis[u][0];
					pre[eNd[i]][1]=u;
				}
				if(!exist[eNd[i]])
				{
					q.push(eNd[i]);
					exist[eNd[i]]=true;
				}
			}
		}
	}
	return flag;
}
void print(int x)
{
	puts("Win");
	int y=st[0]=0;
	while(x)
	{
		st[++st[0]]=x;
		x=pre[x][y];
		y^=1;
	}
	y=-1;
	while(st[st[0]])
	{
		printf("%d ",st[st[0]]);
		y=st[st[0]--];
		x=st[st[0]];
		if(x==y)
		{
			while(ss[y].size())
			{
				printf("%d ",ss[y].top());
				ss[y].pop();
			}
		}
	}
	return;
}
int main()
{
	memset(dep,0,sizeof(dep));
	int c,x,sta,ans=-1;
	bool flag;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c);
		while(c--)
		{
			scanf("%d",&x);
			addedge(i,x);
		}
	}
	scanf("%d",&sta);
	DFS(sta);
	flag=SPFA(sta);
	for(int i=1;i<=n;i++) if(fir[i]==0&&dis[i][0]==true&&i!=sta)
	{
		ans=i;
		break;
	}
	if(ans==-1)
	{
		for(int i=1;i<=n;i++) if((dis[i][0]|dis[i][0])&&1<siz[sig[i]])
		{
			ans=0;
			break;
		}
		if(ans==0) puts("Draw");
		else puts("Lose");
	}
	else print(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

