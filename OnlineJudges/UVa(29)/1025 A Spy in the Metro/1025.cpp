#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int f[205][55],cost[55],T,n,m,d;
bool h[205][55][2];
int main()
{
	for(int l=1;;l++)
	{
		memset(h,false,sizeof(h));
		scanf("%d",&n);
		if(n==0)
			break;
		scanf("%d",&T);
		for(int i=0;i<=204;i++)
			for(int j=1;j<=54;j++)
				f[i][j]=2147483647;
		cost[0]=1;
		for(int i=1;i<n;i++)
			scanf("%d",&cost[i]);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&d);
			for(int j=1;d<=T&&j<n;d+=cost[j++])
				h[d][j][0]=true;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&d);
			for(int j=n;d<=T&&j>1;d+=cost[--j])
				h[d][j][1]=true;
		}
		f[0][1]=0;
		for(int i=0;i<=T;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i][j]==2147483647)
					continue;
				if(i+1<=T&&f[i][j]+1<f[i+1][j])
					f[i+1][j]=f[i][j]+1;
				if(h[i][j][0]&&j<n&&i+cost[j]<=T
				&&f[i][j]<f[i+cost[j]][j+1])
					f[i+cost[j]][j+1]=f[i][j];
				if(h[i][j][1]&&j>1&&i+cost[j-1]<=T
				&&f[i][j]<f[i+cost[j-1]][j-1])
					f[i+cost[j-1]][j-1]=f[i][j];
			}
		}
		printf("Case Number %d: ",l);
		if(f[T][n]==2147483647)
			printf("impossible\n");
		else
			printf("%d\n",f[T][n]);
	}
	return 0;
}

