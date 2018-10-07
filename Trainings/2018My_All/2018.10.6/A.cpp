/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=105;
const int MAXM=6050;
const int INF=0x7f7f7f7f;
int fir[MAXN],cur[MAXN],lev[MAXN],edd[MAXM],nxt[MAXM],f[MAXM],len[MAXM],ed,S,T;
int pre[MAXN];
bool exist[MAXN];
void init()
{
	memset(fir,0,sizeof(fir));
	ed=1; S=MAXN-2; T=MAXN-1;
	return;
}
void addedge(int u,int v,int cap,int val)
{
	edd[++ed]=v;
	nxt[ed]=fir[u];
	fir[u]=ed;
	f[ed]=cap;
	len[ed]=val;
	edd[++ed]=u;
	nxt[ed]=fir[v];
	fir[v]=ed;
	f[ed]=0;
	len[ed]=-val;
	return;
}
bool BFS()
{
	int u;
	queue<int> q;
	memset(exist,false,sizeof(exist));
	memset(lev,127,sizeof(lev));
	lev[S]=pre[S]=0;
	q.push(S);
	while(q.size())
	{
		u=q.front(); q.pop();
		exist[u]=false;
		for(int i=fir[u];i;i=nxt[i]) if(f[i]&&lev[u]+len[i]<lev[edd[i]])
		{
			lev[edd[i]]=lev[u]+len[i];
			pre[edd[i]]=i;
			if(!exist[edd[i]])
			{
				exist[edd[i]]=true;
				q.push(edd[i]);
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
	for(int &i=cur[u],tem;i;i=nxt[i]) if(f[i]&&lev[u]+len[i]==lev[edd[i]])
	{
		if(exist[edd[i]]) continue;
		tem=DFS(edd[i],min(f[i],maxf));
		maxf-=tem;
		f[i]-=tem;
		f[i^1]+=tem;
		cnt+=tem;
		if(!maxf) break;
	}
	if(!cnt) lev[u]=-INF;
	exist[u]=false;
	return cnt;
}
int Augment()
{
	int delta=INF;
	for(int i=pre[T];i;i=pre[edd[i^1]])
		if(f[i]<delta)
			delta=f[i];
	for(int i=pre[T];i;i=pre[edd[i^1]])
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
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=n;i++)
		addedge(S,i,1,0);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			addedge(i+n,T,1,2*j-1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(i,a+n,1,0);
		addedge(i,b+n,1,0);
	}
	printf("%d",MCMF());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

