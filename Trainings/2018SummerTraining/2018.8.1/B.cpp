/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const long long mod=1000000007;
const int BLOCK=316;
struct jz
{
	int id;
	long long n,m,ans;
	bool operator<(const jz &X)const { return n/BLOCK==X.n/BLOCK?m<X.m:n<X.n; }
}Q[MAXN];
long long fac[MAXN],ifac[MAXN];
long long pOw(long long a,long long n)
{
	long long ans;
	for(ans=1;n;n>>=1,a=a*a%mod)
		if(n&1)
			ans=ans*a%mod;
	return ans;
}
bool cmp(jz A,jz B) { return A.id<B.id; }
void pre_calc()
{
	ifac[0]=fac[0]=1;
	for(int i=1;i<MAXN;i++)
		fac[i]=fac[i-1]*i%mod;
	ifac[MAXN-1]=pOw(fac[MAXN-1],mod-2);
	for(int i=MAXN-2;i;i--)
		ifac[i]=ifac[i+1]*(i+1)%mod;
	return;
}
long long C(long long n,long long m) { return fac[n]*ifac[m]%mod*ifac[n-m]%mod; }
int main()
{
	int T_T;
	long long curn=1,curm=0,curans=1,idu=pOw(2,mod-2);
	pre_calc();
	scanf("%d",&T_T);
	for(int i=1;i<=T_T;i++)
	{
		scanf("%lld%lld",&Q[i].n,&Q[i].m);
		Q[i].id=i;
	}
	sort(Q+1,Q+T_T+1);
	for(int i=1;i<=T_T;i++)
	{
		while(curn<Q[i].n)
		{
			curans=(curans*2LL-C(curn,curm)+mod)%mod;
			curn++;
		}
		while(Q[i].n<curn)
		{
			curans=(curans+C(curn-1,curm))%mod*idu%mod;
			curn--;
		}
		while(curm<Q[i].m)
		{
			curans=(curans+C(curn,curm+1))%mod;
			curm++;
		}
		while(Q[i].m<curm)
		{
			curans=(curans-C(curn,curm)+mod)%mod;
			curm--;
		}
		Q[i].ans=curans;
	}
	sort(Q+1,Q+T_T+1,cmp);
	for(int i=1;i<=T_T;i++)
		printf("%lld\n",Q[i].ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

