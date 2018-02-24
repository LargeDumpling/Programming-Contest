#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
queue<int>q;
int n,m,ed=0,fir[100050],next[200050],end[200050],len[200050],dis[100050];
void addedge(int u,int v,int lenth)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	len[ed]=lenth;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	len[ed]=lenth;
	return;
}
void SPFA()
{
	int u;
	bool exist[100050];
	memset(exist,false,sizeof(exist));
	for(int i=1;i<=n;i++)
		dis[i]=2147483647;
	dis[1]=0;
	exist[1]=true;
	q.push(1);
	while(q.size())
	{
		u=q.front();
		q.pop();
		exist[u]=false;
		for(int i=fir[u];i;i=next[i])
		{
			if(dis[end[i]]==2147483647||dis[end[i]]>dis[u]+len[i])
			{
				dis[end[i]]=dis[u]+len[i];
				if(!exist[end[i]])
				{
					q.push(end[i]);
					exist[end[i]]=true;
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("SPFA.txt","w",stdout);
	int a,b,c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
	}
	SPFA();
	for(int i=1;i<=n;i++)
		printf("%d\n",dis[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

