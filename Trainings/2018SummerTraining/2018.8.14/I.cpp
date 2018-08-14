/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10000050;
long long q,n,pri[MAXN],res[MAXN];
int an=0;
bool exist[MAXN];
void pre_calc()
{
	memset(exist,true,sizeof(exist));
	pri[0]=0;
	for(int i=2;i<MAXN;i++)
	{
		if(exist[i]) pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&pri[j]*i<MAXN;j++)
		{
			exist[pri[j]*i]=false;
			if(i%pri[j]==0) break;
		}
	}
	return;
}
long long pOw(long long a,long long x,long long mod)
{
	long long ans;
	for(ans=1;x;x>>=1,a=a*a%mod)
		if(x&1)
			ans=ans*a%mod;
	return ans;
}
long long gcd(long long a,long long b)
{
	long long t;
	while(b)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	bool flag;
	pre_calc();
	scanf("%lld%lld",&q,&n);
	for(int i=1;i<=pri[0];i++) if(pOw(q,n,pri[i])==1&&((pri[i]-1)%n==0))
	{
		if(pri[i]%q==0) continue;
		if((q-1)%pri[i]==0&&n!=1) continue;
		flag=true;
		for(int j=2;j*j<=n;j++)
		{
			if(n%j==0&&(pOw(q,j,pri[i])==1||pOw(q,n/j,pri[i])==1))
			{
				flag=false;
				break;
			}
		}
		if(flag) res[an++]=pri[i];
	}
	printf("%d\n",an);
	for(int i=0;i<an;i++)
		printf("%lld ",res[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

