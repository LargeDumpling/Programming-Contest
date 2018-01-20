/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1000000007;
const int MAXN=100050;
int T_T,n,q;
long long num[MAXN];
long long pOw(long long a,long long n)
{
	long long ans;
	for(ans=1LL;n;n>>=1,a=a*a%mod)
		if(n&1)
			ans=ans*a%mod;
	return ans;
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C_BL.out","w",stdout);
	int op,l,r;
	long long x;
	scanf("%d",&T_T);
	while(T_T-->0)
	{
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)
			scanf("%lld",&num[i]);
		while(q-->0)
		{
			scanf("%d%d%d",&op,&l,&r);
			switch(op)
			{
				case 1:
					scanf("%lld",&x);
					for(int i=l;i<=r;i++)
						num[i]=num[i]*x%mod;
					break;
				case 2:
					scanf("%lld",&x);
					for(int i=l;i<=r;i++)
						num[i]=pOw(num[i],x);
					break;
				case 3:
					long long ans=1;
					for(int i=l;i<=r;i++)
						ans=ans*num[i]%mod;
					printf("%lld\n",ans);
					break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

