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
const int MAXN=5050;
const int MAXM=40050;
const int INF=1<<30;
int fir[MAXN],cur[MAXN],lev[MAXN],end[MAXM],next[MAXM],f[MAXM],mono[MAXM],ed,S,T;
int n,k;
void init(int SS,int TT)
{
	memset(fir,0,sizeof(fir));
	ed=1; S=SS; T=TT;
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
bool SPFA()
{
	int u;
	queue<int> q;
	bool exist[MAXN];
	for(int i=0;i<MAXN;i++) lev[i]=INF;
	memset(exist,false,sizeof(exist));
	q.push(S);
	lev[S]=0;
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
bool vis[MAXN];
int DFS(int u,int maxf)
{
	if(u==T||!maxf) return maxf;
	vis[u]=true;
	int cnt=0;
	for(int &i=cur[u],tem;i;i=next[i]) if(f[i]&&lev[u]+mono[i]==lev[end[i]])
	{
		if(vis[end[i]]) continue;
		tem=DFS(end[i],min(f[i],maxf));
		maxf-=tem;
		f[i]-=tem;
		f[i^1]+=tem;
		cnt+=tem;
		if(!maxf) break;
	}
	if(!cnt) lev[u]=0;
	vis[u]=false;
	return cnt;
}
int MCMF()
{
	int ans=0;
	memset(vis,false,sizeof(vis));
	while(SPFA())
		ans+=DFS(S,INF)*lev[T];
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int in[55][55],out[55][55],x,an=0;
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	scanf("%d%d",&n,&k);
	init(n*n*2+1,n*n*2+2);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&x); x=-x;
			in[i][j]=++an; out[i][j]=++an;
			addedge(in[i][j],out[i][j],1,x);
			addedge(in[i][j],out[i][j],INF,0);
		}
	addedge(S,in[1][1],k,0);
	addedge(out[n][n],T,INF,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i<n) addedge(out[i][j],in[i+1][j],INF,0);
			if(j<n) addedge(out[i][j],in[i][j+1],INF,0);
		}
	printf("%d",MCMF()*-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

