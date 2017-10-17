#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=10007;
void exgcd(long long a,long long b,long long &x,long long &y)
{
	if(!b)x=1,y=0;
	else exgcd(b,a%b,y,x),y-=a/b*x;
	return;
}
long long comb(long long n,long long m)
{
	if(m>n)
		return 0;
	long long ans=1,x,y;
	for(long long i=1;i<=n;i++)
	{
		ans=(ans*i)%mod;
		if(i<=m)
		{
			exgcd(i,mod,x,y);
			x%=mod;
			if(x<0)x+=mod;
			ans=ans*x%mod;
		}
		if(i<=n-m)
		{
			exgcd(i,mod,x,y);
			x%=mod;
			if(x<0)x+=mod;
			ans=ans*x%mod;
		}
	}
	return ans;
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

