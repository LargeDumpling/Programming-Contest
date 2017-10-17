/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,pre[20][20],now[20][20],ans;
void DFS(int x)
{//have calculated 1~x-1
	if(x==n+1)
	{
		for(int i=2;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				now[i][j]=(now[i-1][j-1]+now[i-1][j+1]+now[i-2][j])&1;
				if(!now[i][j]&&pre[i][j])
					return;
			}
		for(int i=1;i<=n;i++)
			if((now[n][i-1]+now[n-1][i]+now[n][i+1])&1)
				return;
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cnt+=(!pre[i][j]&&now[i][j]);
		ans=min(ans,cnt);
		return;
	}
	now[1][x]=pre[1][x];
	DFS(x+1);
	if(!now[1][x])
	{
		now[1][x]=1;
		DFS(x+1);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&pre[i][j]);
		ans=2147483647;
		memset(now,0,sizeof(now));
		DFS(1);
		if(ans==2147483647) ans=-1;
		printf("Case %d: %d\n",cAse,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

