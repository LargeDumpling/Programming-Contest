/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=205;
const long long INF=1LL<<61;
int T_T,n,a[MAXN],b[MAXN];
long long f[MAXN][MAXN];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=i<=j?INF:0;
		for(int len=1;len<=n;len++)
			for(int l=1,r;l+len-1<=n;l++)
			{
				r=l+len-1;
				for(int i=l;i<=r;i++)
					f[l][r]=min(f[l][r],f[l][i-1]+f[i+1][r]+a[i]+b[l-1]+b[r+1]);
			}
		printf("Case #%d: %lld\n",cAse,f[1][n]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

