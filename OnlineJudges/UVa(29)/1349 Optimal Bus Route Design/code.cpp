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
int n,fir[2005],next[400050],end[400050],c[400050],f[400050],lenth[400050],ed;
int sta,tar,q[10000050],dis[2005],cur[2005],pre[2005],ans,flow;
bool exist[2005];
void addedge(int u,int v,int cost)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	c[ed]=1;
	f[ed]=0;
	lenth[ed]=cost;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	f[ed]=c[ed]=1;
	lenth[ed]=-cost;
	return;
}
#define head q[0]
#define tail q[10000049]
int inc(int &x){return ++x>10000048?x-10000048:x;}
bool SPFA()
{
	int u;
	memset(dis,127,sizeof(dis));
	memset(exist,false,sizeof(exist));
	dis[sta]=head=tail=0;
	q[inc(tail)]=sta;
	while(head!=tail)
	{
		u=q[inc(head)];
		exist[u]=false;
		for(int i=fir[u];i;i=next[i])if(dis[u]+lenth[i]<dis[end[i]]&&c[i]>f[i])
		{
			dis[end[i]]=dis[u]+lenth[i];
			pre[end[i]]=i;
			if(!exist[end[i]])
			{
				exist[end[i]]=true;
				q[inc(tail)]=end[i];
			}
		}
	}
	for(int i=(n+1)<<1;i;i--)cur[i]=fir[i];
	return dis[tar]!=dis[204];
}
#undef head
#undef tail
int DFS(int u,int maxf)
{
	if(u==tar)return maxf;
	exist[u]=true;
	int totf=0,temf;
	for(int &i=cur[u];i;i=next[i])if(dis[u]+lenth[i]==dis[end[i]]&&c[i]>f[i]&&!exist[end[i]])
	{
		totf+=(temf=DFS(end[i],min(maxf,c[i]-f[i])));
		maxf-=temf;
		f[i]+=temf;
		f[i^1]-=temf;
	}
	if(!totf)dis[u]=-1;
	exist[u]=false;
	return totf;
}
void Dinic()
{
	int temp;
	ans=flow=0;
	while(SPFA())
	{
		memset(exist,false,sizeof(exist));
		temp=DFS(sta,2147483647);
		ans+=dis[tar]*temp;
		flow+=temp;
		if(!temp)break;
	}
	if(flow==n)printf("%d\n",ans);
	else puts("N");
	return;
}
void MCMF()
{
	int temp=2147483647;
	ans=flow=0;
	while(SPFA())
	{
		for(int u=tar;u!=sta;u=end[pre[u]^1])temp=min(temp,f[pre[u]^1]);
		for(int u=tar;u!=sta;u=end[pre[u]^1])f[pre[u]]+=temp,f[pre[u]^1]-=temp;
		flow+=temp;
		ans+=dis[tar]*temp;
	}
	if(flow==n)printf("%d\n",ans);
	else puts("N");
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	while(scanf("%d",&n)&&n)
	{
		sta=n<<1|1;
		tar=sta+1;
		ed=1;
		memset(fir,0,sizeof(fir));
		for(int i=1;i<=n;i++)
		{
			addedge(sta,i,0);
			//addedge(i,i+n,0);
			addedge(i+n,tar,0);
		}
		for(int i=1;i<=n;i++)
			while(scanf("%d",&a)!=-1&&a)
			{
				scanf("%d",&b);
				addedge(i,a+n,b);
			}
		Dinic();
		//MCMF();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

