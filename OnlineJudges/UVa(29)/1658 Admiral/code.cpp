/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,fir[2050],end[30050],next[30050],f[30050],c[30050],cost[30050],ed,sta,tar;
int q[1000050],dis[2050],pre[2050];
bool exist[2050];
void addedge(int u,int v,int cap,int lenth)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	c[ed]=cap;
	f[ed]=0;
	cost[ed]=lenth;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	f[ed]=c[ed]=cap;
	cost[ed]=-lenth;
	return;
}
int inc(int &x){return ++x>1000048?x-1000048:x;}
#define head q[0]
#define tail q[1000049]
bool SPFA()
{
	memset(dis,127,sizeof(dis));
	memset(exist,false,sizeof(exist));
	int u;
	head=tail=0;
	dis[sta]=0;
	q[inc(tail)]=sta;
	while(head!=tail)
	{
		u=q[inc(head)];
		exist[u]=false;
		for(int i=fir[u];i;i=next[i])if(dis[u]+cost[i]<dis[end[i]]&&c[i]>f[i])
		{
			dis[end[i]]=dis[u]+cost[i];
			pre[end[i]]=i;
			if(!exist[end[i]])
			{
				exist[end[i]]=true;
				q[inc(tail)]=end[i];
			}
		}
	}
	return dis[tar]!=dis[2049];
}
#undef head
#undef tail
int MCMF()
{
	int u,flow,ans=0;
	sta=1;
	tar=n;
	while(SPFA())
	{
		flow=2147483647;
		for(u=tar;u!=sta;u=end[pre[u]^1])flow=min(flow,c[pre[u]]-f[pre[u]]);
		for(u=tar;u!=sta;u=end[pre[u]^1])f[pre[u]]+=flow,f[pre[u]^1]-=flow;
		ans+=dis[tar]*flow;
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int A,B,C;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		memset(fir,0,sizeof(fir));
		ed=1;
		addedge(1,n+1,2,0);
		for(int i=2;i<n;i++)
			addedge(i,i+n,1,0);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&A,&B,&C);
			addedge(A+n,B,1,C);
		}
		printf("%d\n",MCMF());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

