/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=2050;
const int MAXM=2000050;
int T_T,n;
int x[MAXN],y[MAXN],r[MAXN],c[MAXN],fir[MAXN],eNd[MAXM],nExt[MAXM],ed;
int dfn[MAXN],low[MAXN],st[MAXN],dfs_clock;
int kol[MAXN],cn;
int in[MAXN],ans;
bool vis[MAXN];
void addedge(int u,int v)
{
	eNd[++ed]=v;
	nExt[ed]=fir[u];
	fir[u]=ed;
	return;
}
long long sqr(long long x) { return x*x; }
long long calc_dis(int i,int j) { return sqr(x[i]-x[j])+sqr(y[i]-y[j]); }
void DFS(int u,int fa)
{
	vis[u]=true;
	low[u]=dfn[u]=++dfs_clock;
	st[++st[0]]=u;
	for(int i=fir[u];i;i=nExt[i])
	{
		if(!dfn[eNd[i]])
		{
			DFS(eNd[i],u);
			low[u]=min(low[u],low[eNd[i]]);
		}
		else if(vis[eNd[i]])
			low[u]=min(low[u],low[eNd[i]]);
	}
	if(dfn[u]==low[u])
	{
		kol[u]=++cn;
		c[cn]=c[u];
		vis[u]=false;
		while(st[st[0]]!=u)
		{
			kol[st[st[0]]]=cn;
			vis[st[st[0]--]]=false;
		}
		st[0]--;
	}
	return;
}
void init()
{
	memset(fir,ed=0,sizeof(fir));
	memset(vis,false,sizeof(vis));
	memset(in,0,sizeof(in));
	dfs_clock=st[0]=ans=cn=0;
	cn=n;
	return;
}
int main()
{
	//freopen("code.in","r",stdin);
	long long dis;
	scanf("%d",&T_T);
	for(int T=1;T<=T_T;T++)
	{
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d%d",&x[i],&y[i],&r[i],&c[i]);
			for(int j=1;j<i;j++)
			{
				dis=calc_dis(j,i);
				if(dis<=(long long)r[i]*r[i]) addedge(i,j);
				if(dis<=(long long)r[j]*r[j]) addedge(j,i);
			}
		}
		for(int i=1;i<=n;i++) if(!dfn[i])
			DFS(i,i);
		for(int u=1;u<=n;u++)
		{
			for(int i=fir[u];i;i=nExt[i]) if(kol[u]!=kol[eNd[i]])
			{
				addedge(kol[u],kol[eNd[i]]);
				in[kol[eNd[i]]]++;
			}
			c[kol[u]]=min(c[kol[u]],c[u]);
		}
		for(int i=n+1;i<=cn;i++) if(!in[i])
			ans+=c[i];
		printf("Case #%d: %d\n",T,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

