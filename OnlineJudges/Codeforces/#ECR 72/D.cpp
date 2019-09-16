/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-09-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=5050;
int n,m,fir[MAXN],edd[MAXN],nxt[MAXN],kol[MAXN],ed=0,ans=0;
bool vis[MAXN];
void addedge(int u,int v)
{
	edd[++ed]=v;
	kol[ed]=0;
	nxt[ed]=fir[u];
	fir[u]=ed;
	return;
}
int cnt;
void DFS(int u,int col)
{
	vis[u]=true;
	for(int i=fir[u];i;i=nxt[i]) if(!kol[i]&&!vis[edd[i]])
	{
		cnt++;
		kol[i]=col;
		DFS(edd[i],col);
	}
	return;
}
bool check(int x)
{
	memset(kol,cnt=0,sizeof(kol));
	for(int i=1;i<=x;i++)
	{
		memset(vis,false,sizeof(vis));
		for(int j=1;j<=n;j++) if(!vis[j])
			DFS(j,i);
	}
	return cnt==m;
}
int main()
{
	int u,v,l,r,mid;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	l=0,r=m;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	check(r);
	printf("%d\n",r);
	for(int i=1;i<=m;i++)
		printf("%d ",kol[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

