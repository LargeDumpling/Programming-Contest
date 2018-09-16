/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF f[14][2049]
using namespace std;
const int MAXV=2050;
const int MAXN=15;
int v,n;
int cnt[MAXN],f[MAXN][MAXV],pre[MAXN][MAXV],fv[MAXN];
void count(int lev,int x)
{
	if(lev==n+1||!v) return;
	if(pre[lev][x]!=x)
	{
		cnt[lev]+=(f[lev][x]-f[lev][pre[lev][x]]);
		count(lev,pre[lev][x]);
	}
	else count(lev-1,x);
	return;
}
int main()
{
	while(scanf("%d",&v)!=-1)
	{
		memset(cnt,0,sizeof(cnt));
		memset(f,127,sizeof(f));
		memset(pre,-1,sizeof(pre));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&fv[i]);
		f[n+1][0]=0;
		for(int i=n;i;i--)
		{
			for(int j=0;j<=v;j++)
			{
				f[i][j]=f[i+1][j];
				pre[i][j]=j;
			}
			for(int k=0;k<=11;k++)
			{
				int cost=(1<<k)*fv[i];
				for(int j=cost;j<=v;j++) if(f[i][j-cost]!=INF&&(f[i][j-cost]+(1<<k))<f[i][j])
				{
					f[i][j]=f[i][j-cost]+(1<<k);
					pre[i][j]=j-cost;
				}
			}
		}
		if(f[1][v]==INF) puts("-1");
		else
		{
			int left=v;
			for(int i=1,k;i<=n;i++)
			{
				k=0;
				while(fv[i]*(k+1)<=left&&f[i+1][left-fv[i]*(k+1)]+(k+1)==f[i][left]) k++;
				cnt[i]=k;
			}
			for(int i=1;i<=n;i++)
				printf("%d%c",cnt[i],i==n?'\n':' ');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

