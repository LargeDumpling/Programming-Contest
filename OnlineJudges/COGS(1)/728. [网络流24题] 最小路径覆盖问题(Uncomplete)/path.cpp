/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=3500;
const int MAXM=150000;
int fir[MAXN],cur[MAXN],lev[MAXN],end[MAXM],next[MAXM],f[MAXM],ed,S,T;
void init()
{
	memset(fir,0,sizeof(fir));
	S=MAXN-2; T=MAXN-1; ed=1;
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
	while(BFS()) ans+=DFS(S,2147483647);
	return ans;
}
int main()
{
	freopen("path3.in","r",stdin);
	freopen("path3.out","w",stdout);
	int n,m,a,b,in[2000],out[2000],ans,next[2000];
	bool vis[2000];
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=n;i++)
	{
		in[i]=i,out[i]=i+n;
		addedge(S,in[i],1);
		addedge(out[i],T,1);
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		addedge(in[a],out[b],1);
	}
	ans=Dinic();
	memset(vis,false,sizeof(vis));
	memset(next,0,sizeof(next));
	for(int i=1;i<=n;i++)
		for(int j=fir[i];j;j=next[j])
			if(!f[j]&&n<end[j]&&end[j]<=n+n)
			{
				next[i]=end[j]-n;
				vis[i]=true;
			}
	for(int i=1;i<=n;i++) if(vis[i])
	{
		for(int j=i;j;j=next[j])
		{
			vis[j]=false;
			printf("%d ",j);
		}
		putchar('\n');
	}
	printf("%d\n",n-ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

