/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=998244353;
const int MAXN=1000050;
int T_T;
long long fac[MAXN],ifac[MAXN],sfac[MAXN],n,m;
template<typename Ty>
void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
long long pOw(long long x,long long N)
{
	long long ans;
	for(ans=1LL;N;N>>=1,x=x*x%mod)
		if(N&1)
			ans=ans*x%mod;
	return ans;
}
void precalc()
{
	fac[0]=ifac[0]=1;
	for(int i=1;i<MAXN;i++)
		fac[i]=fac[i-1]*(long long)i%mod;
	ifac[MAXN-1]=pOw(fac[MAXN-1],mod-2);
	for(int i=MAXN-2;i;i--)
		ifac[i]=ifac[i+1]*(long long)(i+1)%mod;
	return;
}
int main()
{
	long long ans,tem;
	read1n(T_T);
	precalc();
	for(int T=1;T<=T_T;T++)
	{
		read1n(n); read1n(m);
		ans=0;
		if(n<=m)
		{
			sfac[0]=1;
			for(int i=1;i<=n;i++)
				sfac[i]=sfac[i-1]*((m-i+1)%mod)%mod;
			for(int i=1;i<=n;i++)
			{
				tem=sfac[i]*fac[n-1]%mod*ifac[i-1]%mod*ifac[n-i]%mod;
				ans=(ans+tem)%mod;
			}
		}
		else if(m<=n)
		{
			sfac[0]=1;
			for(int i=1;i<=m;i++)
				sfac[i]=sfac[i-1]*((n-i)%mod)%mod;
			for(int i=1;i<=m;i++)
			{
				tem=fac[m]*ifac[m-i]%mod*sfac[i-1]%mod*ifac[i-1]%mod;
				ans=(ans+tem)%mod;
			}
		}
		printf("Case #%d: %lld\n",T,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

