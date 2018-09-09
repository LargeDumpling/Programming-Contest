/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=4050;
const int MAXM=300050;
const int INF=2147483647;
int fir[MAXN],cur[MAXN],lev[MAXN],et[MAXM],nxt[MAXM],f[MAXM],ed,S,T;
void addedge(int u,int v,int cap)
{
	et[++ed]=v;
	nxt[ed]=fir[u];
	fir[u]=ed;
	f[ed]=cap;
	et[++ed]=u;
	nxt[ed]=fir[v];
	fir[v]=ed;
	f[ed]=0;
	return;
}
bool BFS()
{
	int u;
	memset(lev,-1,sizeof(lev));
	queue<int>q;
	lev[S]=0;
	q.push(S);
	while(q.size())
	{
		u=q.front(); q.pop();
		for(int i=fir[u];i;i=nxt[i]) if(f[i]&&lev[et[i]]==-1)
		{
			lev[et[i]]=lev[u]+1;
			q.push(et[i]);
		}
	}
	memcpy(cur,fir,sizeof fir);
	return lev[T]!=-1;
}
int DFS(int u,int maxf)
{
	if(u==T||!maxf) return maxf;
	int cnt=0;
	for(int &i=cur[u],tem;i;i=nxt[i]) if(f[i]&&lev[et[i]]==lev[u]+1)
	{
		tem=DFS(et[i],min(maxf,f[i]));
		maxf-=tem;
		f[i]-=tem;
		f[i^1]+=tem;
		cnt+=tem;
		if(!maxf) break;
	}
	if(!cnt) lev[u]=-1;
	return cnt;
}
int Dinic()
{
	int ans=0;
	while(BFS())
		ans+=DFS(S,2147483647);
	return ans;
}
void init(int SS,int TT)
{
	memset(fir,0,sizeof(fir));
	ed=1;
	S=SS; T=TT;
	return;
}
int main()
{
	int n,m,k,l,r,N,uS,uT,cnt;
	for(int Test=1;scanf("%d%d%d",&n,&m,&k)!=-1;Test++)
	{
		N=n+m;
		uS=N+1;
		uT=uS+1;
		init(MAXN-2,MAXN-1);
		scanf("%d%d",&l,&r);
		addedge(uT,uS,INF);
		addedge(uS,T,n*l);
		addedge(S,uT,m*l);
		cnt=m*l;
		for(int i=1;i<=n;i++)
		{
			addedge(uS,i,r-l);
			addedge(S,i,l);
			cnt+=l;
		}
		for(int i=1;i<=m;i++)
		{
			addedge(i+n,uT,r-l);
			addedge(i+n,T,l);
		}
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d",&l,&r);
			addedge(l,r+n,1);
		}
		printf("Case %d: ",Test);
		if(Dinic()==cnt) puts("Yes");
		else puts("No");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

