/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n;
long long a[10],b[10];
void calc(int x)
{
	if(x==n) return;
	calc(x+1);
	b[x]*=a[x+1];
	a[x]*=a[x+1];
	a[x]+=b[x+1];
	return;
}
long long gcd(long long A,long long B)
{
	long long t;
	while(B)
	{
		t=A%B;
		A=B;
		B=t;
	}
	return A;
}
int main()
{
	scanf("%d",&T_T);
	for(int T=1;T<=T_T;T++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%lld",&b[i]);
		calc(1);
		long long t=gcd(a[1],b[1]);
		a[1]/=t;
		b[1]/=t;
		printf("Case #%d: %lld %lld\n",T,b[1],a[1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

