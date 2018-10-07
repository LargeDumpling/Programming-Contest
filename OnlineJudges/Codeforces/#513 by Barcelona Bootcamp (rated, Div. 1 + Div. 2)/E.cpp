/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int fir[MAXN],edd[MAXN<<1],nxt[MAXN<<1],ed=0;
long long f[MAXN][2],ans=0;
void addedge(int u,int v)
{
	edd[++ed]=v;
	nxt[ed]=fir[u];
	fir[u]=ed;
	edd[++ed]=u;
	nxt[ed]=fir[v];
	fir[v]=ed;
	return;
}
void DFS(int u,int fa,int ffa)
{
	for(int i=fir[u];i;i=nxt[i]) if(edd[i]!=fa)
		DFS(edd[i],u,fa);
	}
int main()
{
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	DFS(1,-1,-1);
	printf("%I64d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

