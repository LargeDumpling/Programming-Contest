/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,q;
int v[15],cnt[4096],cost[4096],limit;
int ans[4096][105];
char str[15];
int main()
{
	int x,k;
	scanf("%d%d%d",&n,&m,&q);
	limit=1<<n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
		v[n]+=v[i];
	}
	for(int S=0;S<limit;S++)
	{
		cost[S]=0;
		for(int i=0;i<n;i++)
			if(!((S>>i)&1))
				cost[S]+=v[i];
	}
	for(int i=1;i<=m;i++)
	{
		x=0;
		scanf("%s",str);
		for(int j=n-1;0<=j;j--)
			x=(x<<1)|(str[j]=='1');
		cnt[x]++;
	}
	for(int S=0;S<limit;S++)
	{
		for(int nS=0;nS<limit;nS++)
			ans[S][cost[nS^S]]+=cnt[nS];
		for(int i=1;i<=100;i++)
			ans[S][i]+=ans[S][i-1];
	}
	while(q--)
	{
		x=0;
		scanf("%s%d",str,&k);
		for(int j=n-1;0<=j;j--)
			x=(x<<1)|(str[j]=='1');
		printf("%d\n",ans[x][k]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

