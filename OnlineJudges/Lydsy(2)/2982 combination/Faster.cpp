#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=10007;
long long pow(long long a,long long n)
{
	long long ans=1;
	for(;n;n>>=1)
	{
		if(n&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
long long comb(long long n,long long m)
{
	if(m>n)return 0;
	if(m>n-m)m=n-m;
	long long ans1=1,ans2=1;
	for(long long i=0;i<m;i++)
	{
		ans1=ans1*(n-i)%mod;
		ans2=ans2*(i+1)%mod;
	}
	return ans1*pow(ans2,mod-2)%mod;
}
long long Lucas(long long n,long long m)
{
	return m?comb(n%mod,m%mod)*Lucas(n/mod,m/mod)%mod:1;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T;
	long long a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",Lucas(a,b));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

