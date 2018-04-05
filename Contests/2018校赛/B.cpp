/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const long long mod=1e9+7;
int T_T,len;
long long p[MAXN],ip[MAXN],s[MAXN],fs[MAXN],du[MAXN];
long long pOw(long long a,int n)
{
	long long ans;
	for(ans=1;n;n>>=1,a=a*a%mod)
		if(n&1)
			ans=ans*a%mod;
	return ans;
}
char str[MAXN];
void pre_calc()
{
	du[0]=p[0]=ip[0]=1;
	ip[1]=pOw(p[1]=10,mod-2);
	du[1]=2LL;
	for(int i=2;i<MAXN;i++)
	{
		du[i]=du[i-1]*du[1]%mod;
		p[i]=p[i-1]*p[1]%mod;
		ip[i]=ip[i-1]*ip[1]%mod;
	}
	return;
}
int main()
{
	long long f,fs,cnt,cs;
	pre_calc();
	scanf("%d",&T_T);
	while(T_T--)
	{
		f=fs=cnt=cs=0;
		scanf("%s",str);
		len=strlen(str);
		for(int i=0;i<len;i++)
		{
			cnt=(cnt*10LL%mod+str[i]-'0')%mod;
			f=(fs+((long long)du[i]*cnt%mod-p[i]*cs%mod+mod)%mod)%mod;
			cs=(cs+du[i]*cnt%mod*ip[i]%mod)%mod;
			fs=(fs+f)%mod;
		}
		printf("%lld\n",f);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

