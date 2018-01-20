/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-12-12	File created.
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
int pri[MAXN],u[MAXN];
bool exist[MAXN];
void pre_calc()
{
	memset(exist,true,sizeof(exist));
	pri[0]=0;
	u[1]=1;
	for(int i=2;i<MAXN;i++)
	{
		if(exist[i]) pri[++pri[0]]=i,u[i]=-1;
		for(int j=1;j<=pri[0]&&i*pri[j]<MAXN;j++)
		{
			exist[i*pri[j]]=false;
			if(!(i%pri[j])) u[i*pri[j]]=0;
			else u[i*pri[j]]=-u[i];
		}
	}
	return;
}
long long pOw(long long a,long long n)
{
	long long ans;
	for(ans=1;n;n>>=1,a=a*a%mod)
		if(n&1) ans=ans*a%mod;
	return ans;
}
int calc_u(long long x)
{
	int cnt=0;
	for(int i=1;i<=pri[0]&&pri[i]<=x;i++)
	{
		if(!(x%pri[i]))
			x/=pri[i],cnt++;
		if(!(x%pri[i]))
			return 0;
	}
	if(1<x) cnt++;
	if(cnt&1) return -1;
	return 1;
}
long long f(long long x) { return pOw(2LL,x-1); }
long long calc(long long x)
{
	long long ans=0;
	for(int i=1;i*i<=x;i++) if(!(x%i))
	{
		ans=(ans+u[i]*f(x/i)%mod+mod)%mod;
		if(i*i!=x) ans=(ans+calc_u(x/i)*f(i)%mod+mod)%mod;
	}
	return ans;
}
int main()
{
	pre_calc();
	long long x,y;
	scanf("%I64d%I64d",&x,&y);
	if(y%x) printf("0");
	else printf("%I64d",calc(y/x));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

