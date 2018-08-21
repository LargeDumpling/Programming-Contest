#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=3050;
const int MAXM=4000050;
const int INF=1000000050;
int fir[MAXN],cur[MAXN],lev[MAXN],eNd[MAXM],nxt[MAXM],f[MAXM],ed,S,T;
void addedge(int u,int v,int cap)
{
	eNd[++ed]=v;
	nxt[ed]=fir[u];
	fir[u]=ed;
	f[ed]=cap;
	eNd[++ed]=u;
	nxt[ed]=fir[v];
	fir[v]=ed;
	f[ed]=0;
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
		for(int i=fir[u];i;i=nxt[i]) if(f[i]&&lev[eNd[i]]==-1)
		{
			lev[eNd[i]]=lev[u]+1;
			q.push(eNd[i]);
		}
	}
	memcpy(cur,fir,sizeof fir);
	return lev[T]!=-1;
}
int DFS(int u,int maxf)
{
	if(u==T||!maxf) return maxf;
	int cnt=0;
	for(int &i=cur[u],tem;i;i=nxt[i]) if(f[i]&&lev[eNd[i]]==lev[u]+1)
	{
		tem=DFS(eNd[i],min(maxf,f[i]));
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
	int u,v,c,n,m;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		init(1,m);
		while(n--)
		{
			scanf("%d%d%d",&u,&v,&c);
			addedge(u,v,c);
		}
		printf("%d\n",Dinic());
	}
	return 0;
}
