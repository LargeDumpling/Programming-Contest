/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-05-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
const int MAXM=200050;
struct jz
{
	int u,v;
}E[MAXM];
int n,m,du[MAXN],f[MAXN],Es[MAXN],Ps[MAXN];
bool vis[MAXN];
int fInd(int x)
{
	if(f[x]!=f[f[x]]) f[x]=fInd(f[x]);
	return f[x];
}
void mErge(int u,int v)
{
	u=fInd(u); v=fInd(v);
	Es[u]++;
	if(u==v) return;
	f[v]=u;
	Es[u]+=Es[v];
	Ps[u]+=Ps[v];
	return;
}
int main()
{
	memset(vis,true,sizeof(vis));
	int ans=0;
	for(int i=0;i<MAXN;i++)
		f[i]=i,Es[i]=0,Ps[i]=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&E[i].u,&E[i].v);
		mErge(E[i].u,E[i].v);
		du[E[i].u]++;
		du[E[i].v]++;
	}
	for(int i=1;i<=n;i++)
	{
		int u=fInd(i);
		if(du[i]!=2)
			vis[u]=false;
	}
	for(int i=1;i<=n;i++)
	{
		int u=fInd(i);
		if(vis[u])
		{
			vis[u]=false;
			if(Ps[u]==Es[u])
				ans++;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

