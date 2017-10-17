/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-02	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int fir[1050],cur[1050],lev[1050],end[20050],next[20050],f[20050],len[20050];
int ed,S,T,n,m,k,A[5050],B[5050],C[5050],D[5050];
void addedge1(int u,int v,int cap)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	f[ed]=cap;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	f[ed]=0;
	return;
}
void addedge2(int u,int v,int cap,int mono)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	f[ed]=cap;
	len[ed]=mono;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	f[ed]=0;
	len[ed]=-1*mono;
	return;
}
bool BFS()
{
	int u;
	queue<int> q;
	memset(lev,-1,sizeof(lev));
	lev[S]=0;
	q.push(S);
	while(q.size())
	{
		u=q.front(); q.pop();
		for(int i=fir[u];i;i=next[i]) if(f[i]&&lev[end[i]]==-1)
		{
			lev[end[i]]=lev[u]+1;
			q.push(end[i]);
		}
	}
	memcpy(cur,fir,sizeof(fir));
	return lev[T]!=-1;
}
int DFS(int u,int maxf)
{
	if(u==T||!maxf) return maxf;
	int cnt=0;
	for(int &i=cur[u],tem;i;i=next[i]) if(f[i]&&lev[end[i]]==lev[u]+1)
	{
		tem=DFS(end[i],min(f[i],maxf));
		maxf-=tem;
		f[i]-=tem;
		f[i^1]+=tem;
		cnt+=tem;
	}
	if(!cnt) lev[u]=-1;
	return cnt;
}
int Dinic()
{
	int ans=0;
	while(BFS()) ans+=DFS(S,2146483647);
	return ans;
}
bool SPFA()
{
	int u;
	bool exist[1050];
	memset(exist,false,sizeof(exist));
	queue<int> q;
	for(int i=1;i<=n+5;i++) lev[i]=2147483647;
	lev[S]=0;
	q.push(S);
	while(q.size())
	{
		u=q.front(); q.pop();
		exist[u]=false;
		for(int i=fir[u];i;i=next[i]) if(f[i]&&lev[end[i]]>lev[u]+len[i])
		{
			lev[end[i]]=lev[u]+len[i];
			if(!exist[end[i]])
			{
				exist[end[i]]=true;
				q.push(end[i]);
			}
		}
	}
	memcpy(cur,fir,sizeof(fir));
	return lev[T]!=2147483647;
}
bool vis[1050];
int nDFS(int u,int maxf)
{
	if(u==T||!maxf) return maxf;
	if(lev[u]==-2147483647) return 0;
	vis[u]=true;
	int cnt=0;
	for(int &i=cur[u],tem;i;i=next[i])
		if(f[i]&&lev[end[i]]==lev[u]+len[i]&&!vis[end[i]])
		{
			tem=nDFS(end[i],min(f[i],maxf));
			maxf-=tem;
			f[i]-=tem;
			f[i^1]+=tem;
			cnt+=tem;
		}
	if(!cnt) lev[u]=-2147483647;
	vis[u]=false;
	return cnt;
}
int MCMF()
{
	int ans=0;
	memset(vis,false,sizeof(vis));
	while(SPFA())
		ans+=lev[T]*nDFS(S,2147483647);
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	ed=1; S=1; T=n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
		addedge1(A[i],B[i],C[i]);
	}
	printf("%d ",Dinic());
	S=n+1;
	addedge2(S,1,k,0);
	for(int i=1;i<=m;i++)
		addedge2(A[i],B[i],2147483647,D[i]);
	printf("%d",MCMF());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

