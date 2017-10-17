#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
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
void Dijkstra()
{
	int u;
	bool exist[105];
	memset(exist,false,sizeof(exist));
	for(int i=0;i<=n;i++)
		dis[i]=2147483647;
	dis[1]=0;
	for(int i=fir[1];i;i=next[i])
		if(end[i]!=1&&dis[end[i]]>len[i])
			dis[end[i]]=len[i];
	exist[1]=true;
	for(int cnt=1;cnt<n;cnt++)
	{
		u=0;
		for(int i=1;i<=n;i++)
			if(!exist[i]&&(dis[i]<dis[u]||(dis[i]==dis[u]&&i>u)))
				u=i;
		exist[u]=true;
		if(dis[u]!=2147483647)
			for(int i=fir[u];i;i=next[i])
				if(dis[end[i]]>dis[u]+len[i])
					dis[end[i]]=dis[u]+len[i];
	}
	return;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("Dijkstra.txt","w",stdout);
	int a,b,c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
	}
	Dijkstra();
	for(int i=1;i<=n;i++)
		printf("%d\n",dis[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

