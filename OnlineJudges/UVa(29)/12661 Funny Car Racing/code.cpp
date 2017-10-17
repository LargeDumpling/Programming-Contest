/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct jp
{
	int fir,sec;
	jp(int A=0,int B=0):fir(A),sec(B){}
	bool operator<(const jp& A)const{return fir==A.fir?sec>A.sec:fir>A.fir;}
};
const int MAXN=1e5+100;
int sta,tar,n,m,dis[MAXN],end[MAXN],next[MAXN],fir[MAXN],A[MAXN],B[MAXN],T[MAXN],ed=0;
void addedge(int u,int v,int a,int b,int t)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	A[ed]=a;
	B[ed]=b;
	T[ed]=t;
	return;
}
int cost(int time,int edge)
{
	int ans=time;
	time%=(A[edge]+B[edge]);
	if(time+T[edge]>A[edge])
	{
		ans+=B[edge]+A[edge]-time;
		time=0;
	}
	ans+=T[edge];
	return ans;
}
void Hijkstra()
{
	int u;
	bool exist[305];
	//memset(dis,127,sizeof(dis));
	memset(exist,false,sizeof(exist));
	priority_queue<jp>q;
	for(int i=1;i<=n;i++)dis[i]=1<<29;
	q.push(jp(0,sta));
	dis[sta]=0;
	for(int cnt=1;cnt<=n;cnt++)
	{
		while(q.size()&&exist[q.top().sec])q.pop();
		if(!q.size())break;
		u=q.top().sec;
		q.pop();
		exist[u]=true;
		for(int i=fir[u];i;i=next[i])if(cost(dis[u],i)<dis[end[i]])
		{
			dis[end[i]]=cost(dis[u],i);
			q.push(jp(dis[end[i]],end[i]));
		}
	}
	return;
}
void SPFA()
{
	int u;
	bool exist[305];
	memset(exist,false,sizeof exist);
	queue<int>q;
	for(int i=1;i<=n;i++)dis[i]=1<<29;
	q.push(sta);
	dis[sta]=0;
	while(q.size())
	{
		u=q.front();
		q.pop();
		exist[u]=false;
		for(int i=fir[u];i;i=next[i])if(cost(dis[u],i)<dis[end[i]])
		{
			dis[end[i]]=cost(dis[u],i);
			if(!exist[end[i]])
			{
				q.push(end[i]);
				exist[end[i]]=true;
			}
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int u,v,a,b,t;
	for(int cAse=1;scanf("%d%d%d%d",&n,&m,&sta,&tar)!=-1;cAse++)
	{
		memset(fir,ed=0,sizeof(fir));
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d%d%d",&u,&v,&a,&b,&t);
			if(a>=t) addedge(u,v,a,b,t);
		}
		Hijkstra();
		//SPFA();
		printf("Case %d: %d\n",cAse,dis[tar]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

