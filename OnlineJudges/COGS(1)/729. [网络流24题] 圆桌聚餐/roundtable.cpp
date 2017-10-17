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
const int MAXN=500;
const int MAXM=90000;
int n,m,r[500],cap[300];
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
	freopen("roundtable.in","r",stdin);
	freopen("roundtable.out","w",stdout);
	int tot=0;
	scanf("%d%d",&n,&m);
	init(n+m+1,n+m+2);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&r[i]);
		tot+=r[i];
		addedge(S,i,r[i]),addedge(i,S,0);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			addedge(i,j+n,1),addedge(j+n,i,0);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&cap[i]);
		addedge(i+n,T,cap[i]),addedge(T,i+n,0);
	}
	if(tot==Dinic())
	{
		puts("1");
		for(int i=1;i<=n;i++)
		{
			for(int j=fir[i];j;j=next[j]) if(!(j&1)&&!f[j])
				printf("%d ",end[j]-n);
			putchar('\n');
		}
	}
	else puts("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

