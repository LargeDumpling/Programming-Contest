/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-04-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,C[MAXN],fir[MAXN],end[MAXN<<1],next[MAXN<<1],len[MAXN<<1],ed=0;
long long size[MAXN],f[MAXN],ans=(1LL<<62)-1LL+(1LL<<62),tot=0;
void addedge(int u,int v,int lenth)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	len[ed]=lenth;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	len[ed]=lenth;
	return;
}
void DFS(int u,int fa)
{
	size[u]=C[u];
	f[u]=0;
	for(int i=fir[u];i;i=next[i]) if(end[i]!=fa)
	{
		DFS(end[i],u);
		f[u]+=f[end[i]]+size[end[i]]*len[i];
		size[u]+=size[end[i]];
	}
	return;
}
void move(int u,int fa)
{
	ans=min(ans,f[u]);
	for(int i=fir[u];i;i=next[i]) if(end[i]!=fa)
	{
		f[end[i]]=f[u]+(tot-(size[end[i]]<<1))*len[i];
		move(end[i],u);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int u,v,l;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&C[i]);
		tot+=C[i];
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&l);
		addedge(u,v,l);
	}
	DFS(1,1);
	move(1,1);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

