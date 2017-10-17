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
const int MAXN=10050;
int n,root;
int fir[MAXN],next[MAXN];
int num[MAXN];
int f[MAXN][2];
void addedge(int u,int v)
{
	next[v]=fir[u];
	fir[u]=v;
	return;
}
void dp(int u)
{
	f[u][1]=num[u];
	f[u][0]=0;
	for(int v=fir[u];v;v=next[v])
	{
		dp(v);
		f[u][1]+=f[v][0];
		f[u][0]+=max(f[v][1],f[v][0]);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	bool exist[MAXN];
	int a,b;
	memset(exist,true,sizeof(exist));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(b,a);
		exist[a]=false;
	}
	for(int i=1;i<=n;i++)
		if(exist[i])
			root=i;
	dp(root);
	printf("%d",max(f[root][0],f[root][1]));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

