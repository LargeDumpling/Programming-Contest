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
int fir[150],cur[150],lev[150],end[1050],next[1050],f[1050],mono[1050],ed,S,T;
bool exist[150];
void init()
{
	memset(fir,0,sizeof(fir));
	ed=1; S=148; T=149;
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
	lev[S]=0;
	q.push(S);
	while(q.size())
	{
		u=q.front(); q.pop();
		exist[u]=false;
		for(int i=fir[u];i;i=next[i]) if(f[i]&&lev[u]+mono[i]<lev[end[i]])
		{
			lev[end[i]]=lev[u]+mono[i];
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
int MCMF()
{
	int ans=0;
	memset(exist,false,sizeof(exist));
	while(BFS())
		ans+=DFS(S,INF)*lev[T];
	return ans;
}
int main()
{
	freopen("overload.in","r",stdin);
	freopen("overload.out","w",stdout);
	int n,num[105],ave=0;
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		addedge(S,i,num[i],0);
		if(i==1) addedge(i,n,INF,1);
		else addedge(i,i-1,INF,1);
		if(i==n) addedge(n,1,INF,1);
		else addedge(i,i+1,INF,1);
		ave+=num[i];
	}
	ave/=n;
	for(int i=1;i<=n;i++) addedge(i,T,ave,0);
	printf("%d",MCMF());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

