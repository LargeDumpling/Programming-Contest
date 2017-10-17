/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=50050;
const int MOD=201314;
int fir[MAXN],next[MAXN],n,q;
int fa[MAXN],deep[MAXN],size[MAXN],hson[MAXN],top[MAXN];
void DFS1(int u)
{
	size[u]=1;
	for(int v=fir[u];v;v=next[v])
	{
		deep[v]=deep[u]+1;
		DFS1(v);
		size[u]+=size[v];
		if(size[v]>size[hson[u]]) hson[u]=v;
	}
	return;
}
void DFS2(int u,int tOp)
{
	top[u]=tOp;
	if(hson[u]) DFS2(hson[u],tOp);
	for(int v=fir[u];v;v=next[v]) if(hson[u]!=v)
		DFS2(v,v);
	return;
}
int LCA(int x,int y)
{
	for(;top[x]!=top[y];x=fa[top[x]])
		if(deep[top[x]]<deep[top[y]])
			swap(x,y);
	return min(deep[x],deep[y]);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int a,b,c;
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&c); c++;
		fa[i]=c;
		next[i]=fir[c];
		fir[c]=i;
	}
	fa[1]=1;
	deep[1]=1;
	DFS1(1);
	DFS2(1,1);
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		scanf("%d%d%d",&a,&b,&c); a++; b++; c++;
		for(int j=a;j<=b;j++)
		{
			ans+=LCA(j,c);
			ans%=MOD;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

