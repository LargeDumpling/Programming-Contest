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
const int MAXN=250;
const int MAXM=25000;
const int INF=0x7f7f7f7f;
int fir[MAXN],cur[MAXN],lev[MAXN],eNd[MAXM],nExt[MAXM],f[MAXM],mono[MAXM],pre[MAXN],ed,S,T;
int n,x[MAXN][4],y[MAXN][4];
bool exist[MAXN];
void init()
{
	memset(fir,0,sizeof(fir));
	ed=1; S=MAXN-2; T=MAXN-1;
	return;
}
int calc(int a,int b)
{
	int cnt=4;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(x[a][i]==y[b][j])
				cnt--;
	return cnt;
}
void addedge(int u,int v,int cap,int val)
{
	eNd[++ed]=v;
	nExt[ed]=fir[u];
	fir[u]=ed;
	f[ed]=cap;
	mono[ed]=val;
	eNd[++ed]=u;
	nExt[ed]=fir[v];
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
		for(int i=fir[u];i;i=nExt[i]) if(f[i]&&lev[u]+mono[i]<lev[eNd[i]])
		{
			lev[eNd[i]]=lev[u]+mono[i];
			pre[eNd[i]]=i;
			if(!exist[eNd[i]])
			{
				exist[eNd[i]]=true;
				q.push(eNd[i]);
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
	for(int &i=cur[u],tem;i;i=nExt[i]) if(f[i]&&lev[u]+mono[i]==lev[eNd[i]])
	{
		if(exist[eNd[i]]) continue;
		tem=DFS(eNd[i],min(f[i],maxf));
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
	for(int i=pre[T];i;i=pre[eNd[i^1]])
		if(f[i]<delta)
			delta=f[i];
	for(int i=pre[T];i;i=pre[eNd[i^1]])
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
		ans+=Augment();
		//ans+=DFS(S,INF)*lev[T];
	return ans;
}
int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<4;j++)
			scanf("%d",&x[i][j]);
		addedge(S,i,1,0);
		addedge(i+n,T,1,0);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<4;j++)
			scanf("%d",&y[i][j]);
		for(int j=1;j<=n;j++)
			addedge(j,i+n,1,calc(j,i));
	}
	printf("%d",MCMF());
	fclose(stdin);
	fclose(stdout);
	return 0;
}
