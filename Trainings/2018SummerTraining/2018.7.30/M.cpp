/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,m;
int dis[14][55][55],dp[55][55][10050];
int main()
{
	int u,v,w;
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(dis,-1,sizeof(dis));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			if(dis[0][u][v]==-1) dis[0][u][v]=w;
			else dis[0][u][v]=min(dis[0][u][v],w);
		}
		for(int l=1;l<14;l++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					for(int k=1;k<=n;k++) if(dis[l-1][i][k]!=-1&&dis[l-1][k][j]!=-1)
					{
						if(dis[l][i][j]==-1) dis[l][i][j]=dis[l-1][i][k]+dis[l-1][k][j];
						else dis[l][i][j]=min(dis[l][i][j],dis[l-1][i][k]+dis[l-1][k][j]);
					}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=13;k;k--) if(dis[k][i][j]!=-1)
				{
					if(dis[k-1][i][j]==-1) dis[k-1][i][j]=dis[k][i][j];
					else dis[k-1][i][j]=min(dis[k-1][i][j],dis[k][i][j]);
				}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

