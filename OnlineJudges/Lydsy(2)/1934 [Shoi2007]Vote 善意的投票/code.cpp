/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=350;
const int MAXM=100050;
const int INF=0x7f7f7f7f;
int fir[MAXN],cur[MAXN],lev[MAXN],end[MAXM],next[MAXM],f[MAXM],sta[MAXN],ed,S,T;
int n,m;
void init()
{
	memset(fir,0,sizeof(fir));
	ed=1; S=MAXN-2; T=MAXN-1;
	return;
}
void addedge(int u,int v,int cap)
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
bool BFS()
{
	int u;
	queue<int>q;
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
		if(!maxf) break;
	}
	if(!cnt) lev[u]=-1;
	return cnt;
}
int Dinic()
{
	int ans=0;
	while(BFS()) ans+=DFS(S,INF);
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sta[i]);
		if(sta[i]==0) addedge(S,i,1);
		else addedge(i,T,1);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		if(!(sta[a]^sta[b]))
			continue;
		if(!sta[b])
			swap(a,b);
		addedge(a,b,1);
	}
	printf("%d",Dinic());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

