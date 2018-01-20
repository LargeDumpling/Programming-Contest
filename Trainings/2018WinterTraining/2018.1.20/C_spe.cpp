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
long long lg[1050];
const long long mod=1000000007;
long long pOw(long long a,long long n)
{
	long long ans;
	for(ans=1;n;n>>=1,a=a*a%mod)
		if(n&1)
			ans=ans*a%mod;
	return ans;
}
int main()
{
	/*long long a=1LL;
	freopen("C_bitch.txt","w",stdout);
	for(int i=1;i<=1000000006;i++)
	{
		a=a*500000003%1000000007;
		if(a<=1000)
			lg[a]=i;
	}
	for(int i=1;i<=1000;i++)
		printf(",%lld",lg[i]);*/
	while(true)
	{
		long long a,b;
		scanf("%lld",&a);
		printf("%lld\n",pOw(500000003,a));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

