/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=300050;
int n;
long long g[3][MAXN],f[2][MAXN],ans=0,cnt=0;
int main()
{
	long long sum=0;
	scanf("%d",&n);
	for(int i=0;i<2;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%I64d",&g[i][j]);
			cnt+=g[i][j];
		}
	for(int i=n-1;0<=i;i--)
	{
		g[2][i]=g[2][i+1]+g[0][i]+g[1][i];
		f[0][i]=f[0][i+1]+g[2][i+1]+g[1][i]*(2LL*(n-i)-1LL);
		f[1][i]=f[1][i+1]+g[2][i+1]+g[0][i]*(2LL*(n-i)-1LL);
	}
	for(int i=0;i<n;i++)
	{
		ans=max(ans,sum+f[i&1][i]);
		cnt-=g[i&1][i];
		sum+=cnt;
		cnt-=g[(i&1)^1][i];
		sum+=cnt;
	}
	printf("%I64d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

