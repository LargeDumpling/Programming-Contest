/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int T_T,n,ans[2];
int fir[2][MAXN<<1],eNd[2][MAXN<<1],nExt[2][MAXN<<1],ed[2],opp[2][MAXN<<1];
int dfn[MAXN<<1],low[MAXN<<1],st[MAXN<<1],cn[MAXN<<1],in[MAXN<<1],dfs_clock=0,cnn=0;
bool vis[MAXN<<1],exist[MAXN<<1],cho[MAXN<<1];
void addedge(int k,int u,int v)
{
	eNd[k][++ed[k]]=v;
	nExt[k][ed[k]]=fir[k][u];
	fir[k][u]=ed[k];
	return;
}
void init()
{
	memset(fir,0,sizeof(fir));
	memset(ed,0,sizeof(ed));

	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(in,0,sizeof(in));
	memset(cn,0,sizeof(cn));
	st[0]=dfs_clock=cnn=0;

	memset(vis,false,sizeof(vis));
	memset(exist,false,sizeof(exist));
	memset(cho,false,sizeof(cho));
	memset(ans,0,sizeof(ans));
	return;
}
void DFS(int u,int tim)
{
	dfn[u]=low[u]=++dfs_clock;
	st[++st[0]]=u;
	for(int i=fir[0][u];i;i=nExt[0][i])
		if(!dfn[eNd[0][i]])
		{
			DFS(eNd[0][i],tim);
			low[u]=min(low[u],low[eNd[0][i]]);
		}
		else if(tim<dfn[eNd[0][i]])
			low[u]=min(low[u],dfn[eNd[0][i]]);
	if(dfn[u]==low[u])
	{
		cnn++;
		cn[u]=cnn;
		while(st[st[0]]!=u)
			cn[st[st[0]--]]=cnn;
		st[0]--;
	}
	return;
}
void DFS2(int u)
{
	vis[u]=exist[u]=true;
	if(exist[opp[1][u]])
		cho[u]=true;
	for(int i=fir[1][u];i;i=nExt[1][i]) if(!vis[eNd[1][i]])
		DFS2(eNd[1][i]);
	exist[u]=false;
	return;
}
void DuSATO()
{
	for(int i=1;i<=2*n;i++) if(!dfn[i])
		DFS(i,dfs_clock);
	for(int u=1;u<=2*n;u++)
	{
		opp[1][cn[u]]=cn[opp[0][u]];
		for(int i=fir[0][u];i;i=nExt[0][i]) if(cn[u]!=cn[eNd[0][i]])
		{
			addedge(1,cn[u],cn[eNd[0][i]]);
			in[cn[eNd[0][i]]]++;
		}
	}
	for(int i=1;i<=cnn;i++)
		if(!vis[i]&&in[i]==0)
			DFS2(i);
	for(int i=1;i<=n;i++)
	{
		if(cho[cn[i]]) ans[0]++;
		if(cho[cn[opp[0][i]]]) ans[1]++;
	}
	return;
}
int main()
{
	int x;
	char str[10];
	scanf("%d",&T_T);
	while(T_T--)
	{
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			opp[0][i]=i+n;
			opp[0][i+n]=i;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d%s",&x,str);
			if(i==x)
			{
				if(str[0]=='w') ans[1]++;
				continue;
			}
			if(str[0]=='v')
			{
				addedge(0,i,x);
				addedge(0,opp[0][x],opp[0][i]);
			}
			else
			{
				addedge(0,i,opp[0][x]);
				addedge(0,x,opp[0][i]);
			}
		}
		DuSATO();
		printf("%d %d\n",ans[0],ans[1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

