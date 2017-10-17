/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=1050;
const int MAXM=50050;
const int INF=0x7f7f7f7f;
int fir[MAXN],cur[MAXN],lev[MAXN],end[MAXM],next[MAXM],f[MAXM],mono[MAXM],ed,S,T;
bool exist[MAXN];
void init()
{
	memset(fir,0,sizeof(fir));
	ed=1; S=MAXN-2; T=MAXN-1;
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
	memset(exist,false,sizeof(exist));
	memset(lev,127,sizeof(lev));
	lev[S]=0;
	q.push(S);
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
int DFS(int u,int maxf)
{
	if(u==T||!maxf) return maxf;
	exist[u]=true;
	int cnt=0;
	for(int &i=cur[u],tem;i;i=next[i]) if(f[i]&&lev[u]+mono[i]==lev[end[i]])
	{
		if(exist[end[i]]) continue;
		tem=DFS(end[i],min(f[i],maxf));
		maxf-=tem;
		f[i]-=tem;
		f[i^1]+=tem;
		cnt+=tem;
	}
	if(!cnt) lev[u]=-1*INF;
	exist[u]=false;
	return cnt;
}
int MCMF()
{
	int ans=0;
	memset(exist,false,sizeof(exist));
	while(SPFA())
		ans+=DFS(S,INF)*lev[T];
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,m,demond[MAXN],a,b,c;
	init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&demond[i]);
	demond[0]=0;
	for(int i=n+1;i;i--) demond[i]-=demond[i-1];
	for(int i=1;i<=n+1;i++)
	{
		if(demond[i]>0) addedge(i,T,demond[i],0);
		else if(demond[i]<0) addedge(S,i,-1*demond[i],0);
		addedge(i,i+1,INF,0);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b+1,INF,c);
	}
	printf("%d",MCMF());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

