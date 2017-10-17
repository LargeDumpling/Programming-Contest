/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=60050;
const int MAXM=320000;
const int INF=1<<30;
int n,m;
int fir[MAXN],cur[MAXN],lev[MAXN],end[MAXM],next[MAXM],f[MAXM],ed,S,T;
void addedge(int u,int v,int cap)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	f[ed]=cap;
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
		for(int i=fir[u];i;i=next[i]) if(f[i]&&lev[end[i]]==-1)
		{
			lev[end[i]]=lev[u]+1;
			q.push(end[i]);
		}
	}
	memcpy(cur,fir,sizeof fir);
	return lev[T]!=-1;
}
int DFS(int u,int maxf)
{
	if(u==T||!maxf) return maxf;
	int cnt=0;
	for(int &i=cur[u],tem;i;i=next[i]) if(f[i]&&lev[end[i]]==lev[u]+1)
	{
		tem=DFS(end[i],min(maxf,f[i]));
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
	freopen("profit.in","r",stdin);
	freopen("profit.out","w",stdout);
	int a,b,c,tot=0;
	scanf("%d%d",&n,&m);
	init(n+m+1,n+m+2);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		addedge(i+m,T,a),addedge(T,i+m,0);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		tot+=c;
		addedge(S,i,c),addedge(i,S,0);
		addedge(i,a+m,INF),addedge(a+m,i,0);
		addedge(i,b+m,INF),addedge(b+m,i,0);
	}
	printf("%d",tot-Dinic());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

