/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-11	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=262144;
const long long mod=998244353;
long long pOw(long long a,long long n)
{
	long long ans;
	for(ans=1;n;n>>=1,a=a*a%mod)
		if(n&1)
			ans=ans*a%mod;
	return ans;
}
long long a[MAXN];
int main()
{
	int n;
	a[0]=1;
	a[1]=2;
	for(int i=2;i<MAXN;i++)
		a[i]=((6LL*i-3LL)*a[i-1]%mod-(i-2LL)*a[i-2]%mod+mod)%mod*pOw(i+1,mod-2)%mod;
	scanf("%d",&n);
	printf("%lld",a[n-1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

