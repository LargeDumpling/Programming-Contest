/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int M=131072;
const long long mod=1000000007;
int n,m;
int fir[MAXN],next[MAXN],num[MAXN];
int size[MAXN],dfn[MAXN],dfs_clock=0;
int d[M<<1][6];
int fac[6]={2,3,5,7,11,13};
	//0 for 2
	//1 for 3
	//2 for 5
	//3 for 7
	//4 for 11
	//5 for 13
void DFS(int u)
{
	size[u]=1;
	dfn[u]=++dfs_clock;
	for(int v=fir[u];v;v=next[v])
	{
		DFS(v);
		size[u]+=size[v];
	}
	return;
}
void maintain(int root)
{
	for(int i=0;i<6;i++)
		d[root][i]=d[root<<1][i]+d[root<<1|1][i];
	return;
}
void add(int u,int x)
{
	int p=M+u;
	for(int i=0;i<6;i++)
		for(;!(x%fac[i]);x/=fac[i],d[p][i]++);
	for(p>>=1;p;p>>=1)
		maintain(p);
	return;
}
long long pOw(long long a,int n)
{
	long long ans;
	for(ans=1;n;n>>=1,a=a*a%mod)
		if(n&1)
			ans=ans*a%mod;
	return ans;
}
void query(int L,int R)
{
	int ans[6]={0,0,0,0,0,0};
	if(R<L) swap(L,R);
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) for(int i=0;i<6;i++) ans[i]+=d[L^1][i];
		if(R&1) for(int i=0;i<6;i++) ans[i]+=d[R^1][i];
	}
	long long mul=1,num=1;
	for(int i=0;i<6;i++)
	{
		mul=mul*pOw(fac[i],ans[i])%mod;
		num=num*(ans[i]+1LL)%mod;
	}
	printf("%lld %lld\n",mul,num);
	return;
}
int main()
{
	char comm[5];
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		u++; v++;
		next[v]=fir[u];
		fir[u]=v;
	}
	DFS(1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		for(int j=0;j<6;j++)
			for(d[dfn[i]+M][j]=0;!(num[i]%fac[j]);num[i]/=fac[j],d[dfn[i]+M][j]++);
	}
	for(int i=M-1;i;i--)
		maintain(i);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s%d",comm,&u);
		u++;
		switch(comm[0])
		{
			case 'R':
				query(dfn[u],dfn[u]+size[u]-1);
				break;
			case 'S':
				scanf("%d",&v);
				add(dfn[u],v);
				break;
			default:
				break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

