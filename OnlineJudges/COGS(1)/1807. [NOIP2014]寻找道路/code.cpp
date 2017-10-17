#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=10050;
const int MAXM=200050;
const int INF=2139062143;
int fir[MAXN],end[MAXM],next[MAXM],ed=1;
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
int n,m,s,t,dis[MAXN],out[MAXN],acc[MAXN];
bool exist[MAXN];
void DFS(int u)
{
	exist[u]=true;
	for(int i=fir[u];i;i=next[i]) if((i&1)&&!exist[end[i]])
		DFS(end[i]);
	return;
}
int SPFA()
{
	int u;
	queue<int>q;
	memset(dis,127,sizeof(dis));
	memset(exist,false,sizeof(exist));
	dis[s]=0;
	q.push(s);
	while(q.size())
	{
		exist[u=q.front()]=false; q.pop();
		if(acc[u]!=out[u]||!out[u]) continue;
		for(int i=fir[u];i;i=next[i])
			if(!(i&1)&&acc[end[i]]==out[end[i]]&&out[end[i]]&&dis[u]+1<dis[end[i]])
			{
				dis[end[i]]=dis[u]+1;
				if(!exist[end[i]])
				{
					q.push(end[i]);
					exist[end[i]]=true;
				}
			}
	}
	if(dis[t]==INF) return -1;
	return dis[t];
}
int main()
{
	freopen("roadb.in","r",stdin);
	freopen("roadb.out","w",stdout);
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		out[u]++;
	}
	scanf("%d%d",&s,&t);
	memset(exist,false,sizeof(exist));
	DFS(t);
	for(int u=1;u<=n;u++)
		for(int i=fir[u];i;i=next[i])
			if(!(i&1)&&exist[end[i]])
				acc[u]++;
	acc[t]=out[t]=1;
	printf("%d",SPFA());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

