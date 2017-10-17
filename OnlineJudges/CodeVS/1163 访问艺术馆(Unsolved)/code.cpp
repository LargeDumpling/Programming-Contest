/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-07-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=250;
int ddl,fir[MAXN],end[MAXN],next[MAXN],num[MAXN],len[MAXN],ed=0,sz=0;
int cost[MAXN],f[MAXN][605];
void addedge(int u,int v,int lenth)
{
	end[++ed]=v;
	len[ed]=lenth;
	next[ed]=fir[u];
	fir[u]=ed;
	return;
}
void build(int u)
{
	int arg1,arg2;
	scanf("%d%d",&arg1,&arg2);
	addedge(u,++sz,arg1);
	if(!arg2)
	{
		build(++sz);
		build(++sz);
	}
	else num[sz]=arg2;
	return;
}
void DFS(int u)
{
	for(int i=fir[u];i;i=next[i])
	{
		cost[end[i]]=cost[u]+len[i];
		DFS(end[i]);
	}
	return;
}
void dp(int u)
{
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&ddl);
	build(0);
	cost[0]=0;
	DFS(0);
	dp(0);
	printf("%d",f[ddl][0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

