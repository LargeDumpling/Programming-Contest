/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10050;
int T_T,n;
int fir[MAXN],eNd[MAXN<<1],nExt[MAXN<<1],len[MAXN<<1],ed=0;
int fa[MAXN][14],S[MAXN],dep[MAXN];
void addedge(int u,int v,int w)
{
	eNd[++ed]=v;
	nExt[ed]=fir[u];
	fir[u]=ed;
	len[ed]=w;
	eNd[++ed]=u;
	nExt[ed]=fir[v];
	fir[v]=ed;
	len[ed]=w;
	return;
}
void DFS(int u)
{
	for(int i=1;i<14;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=fir[u];i;i=nExt[i]) if(eNd[i]!=fa[u][0])
	{
		fa[eNd[i]][0]=u;
		S[eNd[i]]=S[u]+len[i];
		dep[eNd[i]]=dep[u]+1;
		DFS(eNd[i]);
	}
	return;
}
int LCA(int u,int v)
{
	int t;
	if(dep[u]<dep[v]) swap(u,v);
	t=dep[u]-dep[v];
	for(int i=0;i<14;i++)
		if((t>>i)&1)
			u=fa[u][i];
	for(int i=13;0<=i;i--)
		if(fa[u][i]!=fa[v][i])
		{
			u=fa[u][i];
			v=fa[v][i];
		}
	if(u!=v) u=fa[u][0];
	return u;
}
int main()
{
	freopen("B.in","r",stdin);
	int u,v,w,t;
	char comm[10];
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(fir,ed=0,sizeof(fir));
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
		}
		dep[1]=1;
		fa[1][0]=1;
		S[1]=0;
		DFS(1);
		while(true)
		{
			scanf("%s",comm);
			if(comm[1]=='O') break;
			scanf("%d%d",&u,&v);
			t=LCA(u,v);
			if(comm[1]=='I')
				printf("%d\n",S[u]+S[v]-(S[t]<<1));
			else if(comm[1]=='T')
			{
				scanf("%d",&w);
				if(dep[u]-dep[t]<w)
				{
					w=(dep[u]+dep[v]-(dep[t]<<1)+2)-w;
					swap(u,v);
				}
				w--;
				for(int i=0;i<14;i++)
					if((w>>i)&1)
						u=fa[u][i];
				printf("%d\n",u);
			}
		}
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

