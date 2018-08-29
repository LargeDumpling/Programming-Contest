/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,fir[MAXN],eNd[MAXN],nxt[MAXN],v[MAXN],ed=0;
int ans[MAXN],last[MAXN],dep[MAXN],dfn[2][MAXN],dfs_clock=0;
int lis[MAXN<<1],st[MAXN<<1][18],Log[MAXN<<1];
void addedge(int u,int v)
{
	eNd[++ed]=v;
	nxt[ed]=fir[u];
	fir[u]=ed;
	return;
}
void DFS1(int u)
{
	dfn[0][u]=dfn[1][u]=++dfs_clock;
	lis[dfs_clock]=u;
	ans[u]=-1;
	for(int i=fir[u];i;i=nxt[i])
	{
		dep[eNd[i]]=dep[u]+1;
		DFS1(eNd[i]);
		dfn[1][u]=++dfs_clock;
		lis[dfs_clock]=u;
	}
	return;
}
int cmp(int a,int b) { return dep[a]<dep[b]?a:b; }
int LCA(int u,int v)
{
	int l;
	if(dfn[1][v]<dfn[0][u]) swap(u,v);
	u=dfn[1][u];
	v=dfn[0][v];
	l=v-u+1;
	return cmp(st[u][Log[l]],st[v-(1<<Log[l])+1][Log[l]]);
}
void DFS2(int u)
{
	int lca;
	for(int i=1;i*i<=v[u];i++) if((v[u]%i)==0)
	{
		if(last[i])
		{
			lca=LCA(last[i],u);
			ans[lca]=max(ans[lca],i);
		}
		last[i]=u;
		if(i*i!=v[u]&&last[v[u]/i])
		{
			lca=LCA(last[v[u]/i],u);
			ans[lca]=max(ans[lca],v[u]/i);
			last[v[u]/i]=u;
		}
		last[v[u]/i]=u;
	}
	for(int i=fir[u];i;i=nxt[i])
		DFS2(eNd[i]);
	return;
}
int main()
{
	int fa;
	Log[0]=-1;
	for(int i=1;i<(MAXN<<1);i++)
		Log[i]=Log[i>>1]+1;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&fa);
		addedge(fa,i);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	dep[1]=0;
	DFS1(1);
	for(int i=dfs_clock;i;i--)
	{
		st[i][0]=i;
		for(int j=1;j<18&&i+(1<<j)-1<=dfs_clock;j++)
			st[i][j]=cmp(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	DFS2(1);
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

