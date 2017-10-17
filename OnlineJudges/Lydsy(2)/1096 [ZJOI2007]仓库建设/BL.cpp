/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
int n;
long long X[MAXN],P[MAXN],C[MAXN],f[MAXN];
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&X[i],&P[i],&C[i]);
		f[i]=(1LL<<62)-1LL+(1LL<<62);
		long long cnt=0;
		for(int j=i-1;j>=0;j--)
		{
			f[i]=min(f[i],f[j]+cnt+C[i]);
			cnt+=P[j]*(X[i]-X[j]);
		}
	}
	long long ans=(1LL<<62)-1LL+(1LL<<62);
	for(int i=n;i;i--)
	{
		long long cnt=0;
		for(int j=i+1;j<=n;j++)
			cnt+=P[j]*(X[j]-X[i]);
		ans=min(ans,f[i]+cnt);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

