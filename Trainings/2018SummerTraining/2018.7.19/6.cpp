/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
const int MAXN=1050;
const long long mod=1000000007;
long long fac[MAXN],rev[MAXN],f[MAXN][MAXN],ff[MAXN][MAXN];
int m;
long long a[MAXN],pa[MAXN];
inline long long pOw(long long a,long long n)
{
	long long ans;
	for(ans=1;n;n>>=1,a=a*a%mod)
		if(n&1)
			ans=ans*a%mod;
	return ans;
}
inline void precalc()
{
	fac[0]=1;
	for(int i=1;i<MAXN;i++)
		fac[i]=fac[i-1]*i%mod;
	rev[MAXN-1]=pOw(fac[MAXN-1],mod-2);
	for(int i=MAXN-2;i;i--)
		rev[i]=rev[i+1]*(i+1)%mod;
	for(int i=1;i<MAXN;i++)
		rev[i]=rev[i]*fac[i-1]%mod;
	for(int k=1;k<=1000;k++)
	{
		for(int i=1;i<=k+1;i++)
			f[i][1]=pOw(i,k);
		for(int j=2;j<=k+1;j++)
			for(int i=j;i<=k+1;i++)
				f[i][j]=(f[i][j-1]-f[i-1][j-1]+mod)%mod;
		for(int i=1;i<=k+1;i++)
			ff[k][i]=f[i][i];
	}
	return;
}
inline long long calc_f(int n,int k)
{
	if(n<=0) return 0;
	if(k==0) return n;
	long long C=n,ans=0;
	for(int i=1;i<=k+1;i++)
	{
		ans=(ans+C*ff[k][i]%mod)%mod;
		C=C*(n-i)%mod*rev[i+1]%mod;
	}
	return ans;
}
template<typename Ty>
inline bool read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch)
	{
		if(ch==-1) return false;
		ch=getchar();
	}
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return true;
}
int main()
{
	long long ans;
	precalc();
	pa[0]=1;
	while(scanf("%d",&m)!=-1)
	//while(read1n(m))
	{
		for(int i=1;i<=m;i++)
		{
			scanf("%lld",&a[i]);
			//read1n(a[i]);
		}
		sort(a+1,a+m+1);
		for(int i=1;i<=m;i++)
			pa[i]=pa[i-1]*a[i]%mod;
		a[0]=ans=0;
		for(int i=1;i<=m;i++)
		{
			long long a1=(a[i]*pOw(a[i],m-i+1)%mod-calc_f(a[i]-1,m-i+1)+mod)%mod;
			long long a2=(a[i-1]*pOw(a[i-1],m-i+1)%mod-calc_f(a[i-1]-1,m-i+1)+mod)%mod;
			ans=(ans+pa[i-1]*(a1-a2+mod)%mod)%mod;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

