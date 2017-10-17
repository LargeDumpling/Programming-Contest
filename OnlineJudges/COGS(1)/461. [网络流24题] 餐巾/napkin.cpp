/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int INF=0x7f7f7f7f;
int need[205],day,p,kd,kf,md,mf;
int fir[500],cur[500],lev[500],end[2550],next[2550],f[2550],mono[2550],ed,S,T;
int x[205],y[205],pre[500];
bool exist[500];
void init()
{
	memset(fir,0,sizeof(fir));
	ed=1; S=498; T=499;
	return;
}
void addedge(int u,int v,int cap,int val)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	f[ed]=cap;
	mono[ed]=val;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	f[ed]=0;
	mono[ed]=-1*val;
	return;
}
bool BFS()
{
	int u;
	queue<int>q;
	memset(exist,false,sizeof(exist));
	memset(lev,127,sizeof(lev));
	lev[S]=pre[S]=0;
	q.push(S);
	while(q.size())
	{
		u=q.front(); q.pop();
		exist[u]=false;
		for(int i=fir[u];i;i=next[i]) if(f[i]&&lev[u]+mono[i]<lev[end[i]])
		{
			lev[end[i]]=lev[u]+mono[i];
			pre[end[i]]=i;
			if(!exist[end[i]])
			{
				exist[end[i]]=true;
				q.push(end[i]);
			}
		}
	}
	memcpy(cur,fir,sizeof(fir));
	return lev[T]!=INF;
}
int DFS(int u,int maxf)
{
	if(u==T||!maxf) return maxf;
	exist[u]=true;
	int cnt=0;
	for(int &i=cur[u],tem;i;i=next[i]) if(f[i]&&lev[u]+mono[i]==lev[end[i]])
	{
		if(exist[end[i]]) continue;
		tem=DFS(end[i],min(f[i],maxf));
		maxf-=tem;
		f[i]-=tem;
		f[i^1]+=tem;
		cnt+=tem;
		if(!maxf) break;
	}
	if(!cnt) lev[u]=-1*INF;
	exist[u]=false;
	return cnt;
}
int Augment()
{
	int delta=INF;
	for(int i=pre[T];i;i=pre[end[i^1]])
		if(f[i]<delta)
			delta=f[i];
	for(int i=pre[T];i;i=pre[end[i^1]])
	{
		f[i]-=delta;
		f[i^1]+=delta;
	}
	return delta*lev[T];
}
int MCMF()
{
	int ans=0;
	memset(exist,false,sizeof(exist));
	while(BFS())
		//ans+=DFS(S,INF)*lev[T];
		ans+=Augment();
	return ans;
}
int main()
{
	freopen("napkin.in","r",stdin);
	freopen("napkin.out","w",stdout);
	init();
	scanf("%d",&day);
	for(int i=1;i<=day;i++)
	{
		scanf("%d",&need[i]);
		x[i]=i;
		y[i]=i+day;
	}
	scanf("%d%d%d%d%d",&p,&kd,&kf,&md,&mf);
	for(int i=1;i<=day;i++)
	{
		if(i+1<=day) addedge(x[i],x[i+1],INF,0);
		if(i+kd<=day) addedge(x[i],y[i+kd],INF,kf);
		if(i+md<=day) addedge(x[i],y[i+md],INF,mf);
		addedge(S,x[i],need[i],0);
		addedge(S,y[i],INF,p);
		addedge(y[i],T,need[i],0);
	}
	printf("%d",MCMF());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

