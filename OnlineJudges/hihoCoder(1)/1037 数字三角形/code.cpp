#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,num[105][105],f[105][105];
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			scanf("%d",&num[i][j]);
	for(i=1;i<=n;i++)
		f[n][i]=num[n][i];
	for(i=n-1;i;i--)
		for(j=1;j<=i;j++)
			f[i][j]=max(f[i+1][j],f[i+1][j+1])+num[i][j];
	printf("%d",f[1][1]);
	return 0;
}

