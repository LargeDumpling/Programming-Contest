/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,num[505],f[505][505];
int main()
{
	memset(f,127,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		if(i>1)f[i-1][i]=num[i-1]==num[i]?1:2;
		f[i][i]=1;
	}
	for(int j=2;j<n;j++)
		for(int i=1;i+j<=n;i++)
		{
			if(num[i]==num[i+j])f[i][i+j]=min(f[i][i+j],f[i+1][i+j-1]);
			for(int k=i;k<=i+j;k++)
				f[i][i+j]=min(f[i][i+j],f[i][k]+f[k+1][i+j]);
		}
	printf("%d",f[1][n]);
	return 0;
}

