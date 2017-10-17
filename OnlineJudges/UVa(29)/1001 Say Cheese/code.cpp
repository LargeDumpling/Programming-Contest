/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,x[105],y[105],z[105],r[105];
double f[105][105];
double dist(int A,int B)
{
	return sqrt((x[A]-x[B])*(x[A]-x[B])
			+(y[A]-y[B])*(y[A]-y[B])
			+(z[A]-z[B])*(z[A]-z[B]));
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	for(int cAse=1;;cAse++)
	{
		scanf("%d",&n);
		if(n==-1)break;
		for(int i=1;i<=n+2;i++)r[i]=0;
		for(int i=1;i<=n+2;i++)
			for(int j=1;j<=n+2;j++)if(i!=j)
				f[i][j]=2147483647;
		for(int i=1;i<=n;i++)scanf("%d%d%d%d",&x[i],&y[i],&z[i],&r[i]);
		scanf("%d%d%d%d%d%d",&x[n+1],&y[n+1],&z[n+1],&x[n+2],&y[n+2],&z[n+2]);
		for(int i=1;i<=n+2;i++)
			for(int j=1;j<=n+2;j++)
				if(i!=j)
				{
					f[i][j]=dist(i,j)-r[i]-r[j];
					if(f[i][j]<1e-7)f[i][j]=0;
				}
				else f[i][j]=0;
		for(int k=1;k<=n+2;k++)
			for(int i=1;i<=n+2;i++)
				for(int j=1;j<=n+2;j++)
					if(f[i][j]>f[i][k]+f[k][j])
						f[i][j]=f[i][k]+f[k][j];
		printf("Cheese %d: Travel time = %lld sec\n",cAse,(long long)(f[n+1][n+2]*10.+0.5));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

