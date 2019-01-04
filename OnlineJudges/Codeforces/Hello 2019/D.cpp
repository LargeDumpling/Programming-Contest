/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-01-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=40000000;
const long long mod=1000000007;
int k,pri[MAXN];
bool exist[MAXN];
long long n,inv[200],f[10050][200];
long long pOw(long long a,long long m)
{
	long long pro;
	for(pro=1LL;m;m>>=1,a=a*a%mod)
		if(m&1)
			pro=pro*a%mod;
	return pro;
}
void pre_calc()
{
	memset(exist,true,sizeof(exist));
	pri[0]=0;
	for(int i=2;i<MAXN;i++)
	{
		if(exist[i]) pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&(long long)i*pri[j]<MAXN;j++)
		{
			exist[i*pri[j]]=false;
			if(i%pri[j]==0)
				break;
		}
	}
	inv[0]=1;
	for(int i=1;i<200;i++)
		inv[i]=pOw(i,mod-2);
	return;
}
long long calc(long long p,int num)
{
	f[0][0]=1LL;
	for(int i=1;i<=num;i++)
		f[0][i]=f[0][i-1]*p%mod;
	for(int t=1;t<=k;t++)
	{
		f[t][0]=f[t-1][0];
		for(int i=1;i<=num;i++)
			f[t][i]=(f[t][i-1]+f[t-1][i])%mod;
		for(int i=1;i<=num;i++)
			f[t][i]=f[t][i]*inv[i+1]%mod;
	}
	return f[k][num];
}
int main()
{
	int num;
	pre_calc();
	cin>>n>>k;
	long long ans=1LL;
	for(int i=1;i<=pri[0]&&(long long)pri[i]*pri[i]<=n;i++) if(n%pri[i]==0)
	{
		for(num=0;n%pri[i]==0;n/=pri[i],num++);
		ans=ans*calc(pri[i],num)%mod;
	}
	if(n!=1) ans=ans*calc(n,1)%mod;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

