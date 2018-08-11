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
const long long mod=1000000007;
long long n,ans=0;
long long pOw(long long a,long long m)
{
	long long sum;
	for(sum=1;m;m>>=1,a=a*a%mod)
		if(m&1)
			sum=sum*a%mod;
	return sum;
}
long long S(long long x)
{
	long long sum1=(x-2LL)*(x-3LL)%mod*(x-2LL)%mod*pOw(2,mod-2)%mod;
	long long sum2=(x-3LL)*(x-2LL)%mod*(2LL*x-5LL)%mod*pOw(6,mod-2)%mod;
	return (sum1-sum2+mod)%mod;
}
int main()
{
	long long F,E,P;
	scanf("%lld",&n);
	P=(S(n)*n%mod*pOw(4,mod-2)%mod+n)%mod;
	E=((S(n)+n-3)%mod*n%mod*pOw(2,mod-2)%mod+n)%mod;
	F=(1LL+E-P+mod)%mod;
	cout<<F;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

