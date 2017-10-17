#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define head q[0]
#define tail q[10049]
#define top s[0]
using namespace std;
int n,m,k;
int fir[50050],end[200050],next[200050],ed=0;
unsigned long long len[200050];
int belong[50050],dfn[50050],low[50050],s[50050],dfs_clock=0,SCCn=0;
int q[50050];
unsigned long long dis[50050];
bool exist[50050];
void addedge(int u,int v,unsigned long long l)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	len[ed]=l;
	return;
}
void DFS(int u)
{
	dfn[u]=low[u]=++dfs_clock;
	s[++top]=u;
	for(int i=fir[u];i;i=next[i])
	{
		if(!dfn[end[i]])
			DFS(end[i]);
		low[u]=min(low[u],low[end[i]]);
	}
	if(dfn[u]==low[u])
	{
		SCCn++;
		while(s[top]!=u)
			belong[s[top--]]=SCCn;
		belong[s[top--]]=SCCn;
	}
	return;
}
int inc(int &x){return (++x)>10048?x-10048:x;}
void SPFA()
{
	int u;
	memset(dis,127,sizeof(dis));
	dis[1]=0;
	q[inc(tail)]=1;
	while(head!=tail)
	{
		u=q[inc(head)];
		exist[u]=true;
		for(int i=fir[u];i;i=next[i])
		{
			if(belong[end[i]]==belong[u])
				len[i]=0;
			if(dis[u]+len[i]<dis[end[i]])
			{
				dis[end[i]]=dis[u]+len[i];
				if(!exist[end[i]])
				{
					q[inc(tail)]=end[i];
					exist[end[i]]=true;
				}
			}
		}
	}
	return;
}
int main()
{
	int a,b;
	unsigned long long c;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		cin>>c;
		addedge(a,b,c);
	}
	DFS(1);
	SPFA();
	cout<<dis[k];
    return 0;
}

