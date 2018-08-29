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
const int MAXN=205;
const int INF=0x7f7f7f7f;
int fir[MAXN<<2],cur[MAXN<<2],lev[MAXN<<2],eNd[200000],nxt[200000],f[200000],mono[200000],pre[200000],ed,S,T;
int T_T,n,m,K,W,SS[MAXN],TT[MAXN],w[MAXN],op[MAXN];
bool exist[MAXN<<2];
void init()
{
	memset(fir,0,sizeof(fir));
	ed=1; S=798; T=799;
	return;
}
void addedge(int u,int v,int cap,int val)
{
	eNd[++ed]=v;
	nxt[ed]=fir[u];
	fir[u]=ed;
	f[ed]=cap;
	mono[ed]=val;
	eNd[++ed]=u;
	nxt[ed]=fir[v];
	fir[v]=ed;
	f[ed]=0;
	mono[ed]=-val;
	return;
}
bool BFS()
{
	int u;
	queue<int>q;
	memset(exist,false,sizeof(exist));
	memset(lev,-1,sizeof(lev));
	lev[S]=pre[S]=0;
	q.push(S);
	while(q.size())
	{
		u=q.front(); q.pop();
		exist[u]=false;
		for(int i=fir[u];i;i=nxt[i]) if(f[i]&&lev[eNd[i]]<lev[u]+mono[i])
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
	return lev[T]!=-1;
}
int DFS(int u,int maxf)
{
	if(u==T||!maxf) return maxf;
	exist[u]=true;
	int cnt=0;
	for(int &i=cur[u],tem;i;i=nxt[i]) if(f[i]&&lev[u]+mono[i]==lev[eNd[i]])
	{
		if(exist[eNd[i]]) continue;
		tem=DFS(eNd[i],min(f[i],maxf));
		maxf-=tem;
		f[i]-=tem;
		f[i^1]+=tem;
		cnt+=tem;
		if(!maxf) break;
	}
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
	return ans;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		init();
		scanf("%d%d%d%d",&n,&m,&K,&W);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&SS[i],&TT[i],&w[i],&op[i]);
			addedge(i,i+m,1,0);
		}
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++) if(i!=j&&TT[i]<=SS[j])
			{
				if(op[i]!=op[j]) addedge(i+m,j,1,w[j]);
				else addedge(i+m,j,1,w[j]-W);
			}
		for(int i=1;i<=K;i++)
			for(int j=1;j<=m;j++)
				addedge(i+2*m,j,1,w[j]);
		for(int i=1;i<=K;i++)
			addedge(S,i+2*m,1,0);
		for(int i=1;i<=m;i++)
			addedge(i+m,T,1,0);
		printf("%d\n",MCMF());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
