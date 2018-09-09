/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-31	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int f[MAXN],n,m,ans;
long long d[MAXN];
int T_T;
int find(int x)
{
	if(f[x]!=f[f[x]])
	{
		find(f[x]);
		d[x]^=d[f[x]];
		f[x]=f[f[x]];
	}
	return f[x];
}
bool merge(int u,int v,long long w)
{
	int uf=find(u),vf=find(v);
	w^=d[u]^d[v];
	if(uf==vf) return w==0;
	f[vf]=uf;
	d[vf]=w;
	return true;
}
int main()
{
	int u,v;
	long long w;
	scanf("%d",&T_T);
	assert(1<=T_T&&T_T<=30);
	for(int i=0;i<MAXN;i++)
	{
		f[i]=i;
		d[i]=0;
	}
	while(T_T--)
	{
		scanf("%d%d",&n,&m);
		assert(1<=n&&n<=100000);
		for(int i=1;i<n;i++) scanf("%*d%*d");
		ans=m;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%lld",&u,&v,&w);
			if(ans==m&&!merge(u,v,w))
				ans=i-1;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		{
			f[i]=i;
			d[i]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

