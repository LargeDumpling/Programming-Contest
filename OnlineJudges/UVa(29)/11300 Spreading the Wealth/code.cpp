/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
long long num[1000050],C[1000050],sum=0,x;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(scanf("%d",&n)!=-1&&n)
	{
		sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			sum+=num[i];
		}
		sum/=n;
		C[0]=0;
		for(int i=1;i<n;i++)C[i]=C[i-1]+num[i]-sum;
		sort(C,C+n);
		x=C[n>>1];
		sum=0;
		for(int i=0;i<n;i++)sum+=abs(x-C[i]);
		printf("%lld\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

