/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-03-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=2050;
long long n,mod,a,b,c,f[MAXN][MAXN],fac[MAXN],ifac[MAXN];
int tim[MAXN][MAXN],T=0;
long long pOw(long long x,long long m)
{
	long long ans;
	for(ans=1LL;m;m>>=1,x=x*x%mod)
		if(m&1)
			ans=ans*x%mod;
	return ans;
}
void pre_calc()
{
	fac[0]=1;
	for(int i=1;i<MAXN;i++)
		fac[i]=fac[i-1]*(long long)i%mod;
	ifac[MAXN-1]=pOw(fac[MAXN-1],mod-2);
	for(int i=MAXN-2;0<=i;i--)
		ifac[i]=ifac[i+1]*(long long)(i+1)%mod;
	return;
}
long long calc(int l,int r)
{
	if(tim[l][r]==T) return f[l][r];
	tim[l][r]=T;
	f[l][r]=0;
	if(l==r)
	{
		if(l==1||r==n) f[l][r]=b;
		else f[l][r]=c;
	}
	else
	{
		for(int i=l;i<=r;i++)
		{
			if(i==l)
			{
				if(l==1) f[l][r]=(f[l][r]+a*calc(i+1,r)%mod*ifac[r-l]%mod)%mod;
				else f[l][r]=(f[l][r]+b*calc(i+1,r)%mod*ifac[r-l]%mod)%mod;
			}
			else if(i==r)
			{
				if(r==n) f[l][r]=(f[l][r]+a*calc(l,i-1)%mod*ifac[r-l]%mod)%mod;
				else f[l][r]=(f[l][r]+b*calc(l,i-1)%mod*ifac[r-l]%mod)%mod;
			}
			else f[l][r]=(f[l][r]+a*calc(l,i-1)%mod*calc(i+1,r)%mod*ifac[i-l]%mod*ifac[r-i]%mod)%mod;
		}
		f[l][r]=f[l][r]*fac[r-l]%mod;
	}
	return f[l][r];
}
int main()
{
	memset(tim,0,sizeof(tim));
	bool first=true;
	while(scanf("%lld%lld%lld%lld%lld",&n,&mod,&a,&b,&c)!=-1)
	{
		T++;
		a%=mod; b%=mod; c%=mod;
		pre_calc();
		printf("%lld",n==1?a:calc(1,n));
		if(first) first=false;
		else putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

