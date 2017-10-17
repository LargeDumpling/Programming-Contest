/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int f[31],g[31],ans[31],n;
int cf(int);
int cg(int x)
{
	if(g[x]!=-1)return g[x];
	return g[x]=(1<<x)-cf(x);
}
int cf(int x)
{
	if(f[x]!=-1)return f[x];
	if(x<=2)return f[x]=0;
	f[x]=1<<(x-3);
	for(int i=2;i<=x-2;i++)f[x]+=cg(i-2)*(1<<(x-i-2));
	return f[x];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	memset(f,-1,sizeof(f));
	memset(g,-1,sizeof(g));
	for(int i=30;i>=0;i--)cf(i);
	while(scanf("%d",&n)!=-1&&n)
		printf("%d\n",cf(n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

