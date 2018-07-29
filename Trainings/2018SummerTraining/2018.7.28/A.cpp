/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1e9+7;
const int MAXL=100050;
int T_T,n;
char str[MAXL];
long long pOw(long long x,long long n,long long m)
{
	long long ans;
	for(ans=1;n;n>>=1,x=x*x%m)
		if(n&1)
			ans=ans*x%m;
	return ans;
}
int main()
{
	long long t0,t1;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%s",str);
		n=strlen(str);
		t0=t1=0;
		for(int i=0;i<n;i++)
		{
			switch(str[i])
			{
				case '0':
					t0=(t0+1LL)%(mod-1);
					t1=(t1+1LL)%mod;
					break;
				case '1':
					t0=(t0+t0+2LL)%(mod-1);
					t1=(t1+t1+2LL)%mod;
					break;
				case '2':
					t1=(6LL*pOw(2LL,t0,mod)%mod-3LL+mod)%mod;
					t0=(6LL*pOw(2LL,t0,mod-1)%(mod-1)-3LL+(mod-1))%(mod-1);
					break;
				default:
					break;
			}
		}
		printf("%lld\n",t1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

