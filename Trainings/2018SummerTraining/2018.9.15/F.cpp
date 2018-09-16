/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int INF=0x7f7f7f7f;
const int MAXN=550;
int fir[MAXN],cur[MAXN],lev[MAXN],edd[MAXN<<2],nxt[MAXN<<2],f[MAXN<<2],mono[MAXN<<2],ed,S,T;
int pre[MAXN],l[MAXN],r[MAXN],w[MAXN];
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
	mono[ed]=val;
	edd[++ed]=u;
	nxt[ed]=fir[v];
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
	memset(lev,-1,sizeof(lev));
	lev[S]=pre[S]=0;
	q.push(S);
	while(q.size())
	{
		u=q.front(); q.pop();
		exist[u]=false;
		for(int i=fir[u];i;i=nxt[i]) if(f[i]&&lev[edd[i]]<lev[u]+mono[i])
		{
			lev[edd[i]]=lev[u]+mono[i];
			pre[edd[i]]=i;
			if(!exist[edd[i]])
			{
				exist[edd[i]]=true;
				q.push(edd[i]);
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
	for(int &i=cur[u],tem;i;i=nxt[i]) if(f[i]&&lev[u]+mono[i]==lev[edd[i]])
	{
		if(exist[edd[i]]) continue;
		tem=DFS(edd[i],min(f[i],maxf));
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
	int T_T,n,k,m,h[MAXN];
	scanf("%d",&T_T);
	while(T_T--)
	{
		init();
		h[0]=0;
		scanf("%d%d%d",&n,&k,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&l[i],&r[i],&w[i]);
			h[++h[0]]=l[i];
			h[++h[0]]=r[i];
		}
		sort(h+1,h+h[0]+1);
		h[0]=unique(h+1,h+h[0]+1)-h-1;
		for(int i=1;i<=m;i++)
		{
			l[i]=lower_bound(h+1,h+h[0]+1,l[i])-h;
			r[i]=lower_bound(h+1,h+h[0]+1,r[i])-h;
			addedge(l[i],r[i]+1,1,w[i]);
		}
		addedge(S,1,k,0);
		for(int i=1;i<=h[0];i++)
			addedge(i,i+1,k,0);
		addedge(h[0]+1,T,k,0);
		printf("%d\n",MCMF());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
