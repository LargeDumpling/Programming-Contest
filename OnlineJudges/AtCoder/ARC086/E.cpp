/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-12-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=2050;
const int mod=1000000007;
int n,fir[MAXN],next[MAXN],F[MAXN][MAXN];
int dep[MAXN],cnt[MAXN],depest=0;
int C[MAXN][MAXN];
void addedge(int u,int v)
{
	next[v]=fir[u];
	fir[u]=v;
	return;
}
void DFS(int u)
{
	cnt[dep[u]]++;
	depest=max(depest,dep[u]);
	for(int v=fir[u];v;v=next[v])
	{
		dep[v]=dep[u]+1;
		DFS(v);
	}
	return;
}
void pre_calc()
{
	C[0][0]=1;
	for(int i=1;i<MAXN;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	return;
}
int main()
{
	int x;
	pre_calc();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		addedge(x,i);
	}
	dep[0]=1;
	DFS(0);
	F[1][1]=1;
	for(int i=2;i<=depest;i++)
		for(int j=0;j<=cnt[i];j++)
			for(int k=0;k+j<=n+1;k++) if(F[i-1][k])
				F[i][k+j]=(F[i-1][k]+(bool)j*C[cnt[i]][j])%mod;
	x=0;
	for(int i=0;i<=n+1;i++)
		x=(x+F[depest][i])%mod;
	printf("%d",x);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

