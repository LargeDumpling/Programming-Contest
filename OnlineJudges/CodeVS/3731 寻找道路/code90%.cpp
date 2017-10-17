#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int fir[10050],end[400050],next[400050],dis[10050],ed=1,s,t,n,m;
bool via[10050],acc[10050];
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
void pre_()
{
	int u;
	queue<int>q;
	memset(via,false,sizeof(via));
	via[t]=true;
	q.push(t);
	while(q.size())
	{
		u=q.front();
		q.pop();
		for(int i=fir[u];i;i=next[i])
		{
			if(!(i&1)||via[end[i]])
				continue;
			via[end[i]]=true;
			q.push(end[i]);
		}
	}
	return;
}
int Hijkstra()
{
	int u;
	bool exist[10050];
	memset(dis,127,sizeof(dis));
	priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >q;
	dis[s]=0;
	q.push(make_pair(0,s));
	while(q.size())
	{
		u=q.top().second;
		q.pop();
		if(exist[u])
			continue;
		exist[u]=true;
		for(int i=fir[u];i;i=next[i])
		{
			if(i&1||!acc[end[i]]||dis[end[i]]<=dis[u]+1||exist[end[i]])
				continue;
			dis[end[i]]=dis[u]+1;
			q.push(make_pair(dis[end[i]],end[i]));
		}
	}
	return dis[t]>10050?-1:dis[t];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	scanf("%d%d",&s,&t);
	pre_();
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		flag=false;
		acc[i]=true;
		for(int j=fir[i];j;j=next[j])
		{
			if(j&1)
				continue;
			acc[i]=acc[i]&via[end[j]];
			flag=true;
		}
		if(!flag)
			acc[i]=false;
	}
	acc[t]=true;
	printf("%d",Hijkstra());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

