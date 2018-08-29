/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-06	File created.
*/
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const long long INF=(1LL<<51)-1LL+(1LL<<51);
const long long Big=1e12;
const int MAXN=6500;
const int MAXM=150000;
const int MAXK=15;
int fir[MAXN],cur[MAXN],eNd[MAXN],nxt[MAXN],f[MAXM],pre[MAXN],vote[MAXN],ed,S,T;
int n,k,w;
long long mono[MAXM],c[MAXN][MAXK],lev[MAXN];
bool exist[MAXN];
void init()
{
	memset(fir,0,sizeof(fir));
	ed=1; S=MAXN-2; T=MAXN-1;
	return;
}
void addedge(int u,int v,int cap,long long val)
{
	eNd[++ed]=v;
	nxt[ed]=fir[u];
	fir[u]=ed;
	f[ed]=cap;
	mono[ed]=val;
	eNd[++ed]=u;
	nxt[ed]=fir[v];
	fir[v]=ed;
	f[ed]=0;
	mono[ed]=-val;
	return;
}
bool BFS()
{
	int u;
	queue<int>q;
	memset(exist,false,sizeof(exist));
	for(int i=1;i<=MAXN;i++)
		lev[i]=INF;
	lev[S]=pre[S]=0;
	q.push(S);
	while(q.size())
	{
		u=q.front(); q.pop();
		exist[u]=false;
		for(int i=fir[u];i;i=nxt[i]) if(f[i]&&lev[u]+mono[i]<lev[eNd[i]])
		{
			lev[eNd[i]]=lev[u]+mono[i];
			pre[eNd[i]]=i;
			if(!exist[eNd[i]])
			{
				exist[eNd[i]]=true;
				q.push(eNd[i]);
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
	for(int &i=cur[u],tem;i;i=nxt[i]) if(f[i]&&lev[u]+mono[i]==lev[eNd[i]])
	{
		if(exist[eNd[i]]) continue;
		tem=DFS(eNd[i],min(f[i],maxf));
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
long long Augment()
{
	int delta=2147483647;
	for(int i=pre[T];i;i=pre[eNd[i^1]])
		if(f[i]<delta)
			delta=f[i];
	for(int i=pre[T];i;i=pre[eNd[i^1]])
	{
		f[i]-=delta;
		f[i^1]+=delta;
	}
	return lev[T]*delta;
}
long long MCMF()
{
	long long ans=0;
	memset(exist,false,sizeof(exist));
	while(BFS())
		//ans+=DFS(S,INF)*lev[T];
		ans+=Augment();
	return ans;
}
int main()
{
	long long ans=(1LL<<62)-1LL+(1LL<<62);
	scanf("%d%d%d",&n,&k,&w);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k+1;j++)
			scanf("%lld",&c[i][j]);
	for(int x=1;x<=n;x++)
	{
		init();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k+1;j++)
				addedge(i,n+j,1,c[i][j]);
		for(int i=1;i<=n;i++)
			addedge(S,i,1,0);
		for(int i=1;i<=k;i++)
		{
			if(i==w)
				addedge(n+i,T,x,-Big);
			else
				addedge(n+i,T,x-1,0);
		}
		addedge(n+k+1,T,2147483647,0);
		long long tem=MCMF()+Big*x;
		for(int l=fir[n+w];l;l=nxt[l])
			if(eNd[l]==T&&!f[l])
			{
				if(tem<ans)
				{
					ans=tem;
					for(int i=1;i<=n;i++)
					{
						for(int j=fir[i];j;j=nxt[j])
							if(n<eNd[j]&&eNd[j]<=n+k+1&&!f[j])
								vote[i]=eNd[j]-n;
					}
				}
			}
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d ",vote[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

