#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
int m,n,num[55][55],f[105][55][55];
int main()
{
	freopen("code.in","r",stdin);
	int i,j,k,x1,x2,y1,y2,ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&num[i][j]);
	for(k=2;k<n+m;k++)
	{
		for(i=1;i<k;i++)
		{
			for(j=1;j<i;j++)
			{
				x1=i;y1=k-i;
				x2=j;y2=k-j;
				if(x1==x2)
					f[k][x1][x2]=max(f[k][x1][x2],max(f[k-1][x1][x2-1],f[k-1][x1-1][x2-1])+num[x1][y1]+num[x2][y2]);
				else if(x1==x2+1)
					f[k][x1][x2]=max(f[k-1][x1][x2-1],max(f[k-1][x1][x2],f[k-1][x1-1][x2-1]))+num[x1][y1]+num[x2][y2];
				else
					f[k][x1][x2]=max(max(f[k-1][x1][x2],f[k-1][x1][x2-1]),max(f[k-1][x1-1][x2],f[k-1][x1-1][x2-1]))+num[x1][y1]+num[x2][y2];
			}
		}
	}
	ans=f[n+m-1][n][n-1]+num[n][m];
	printf("%d",ans);
	fclose(stdin);
	return 0;
}

