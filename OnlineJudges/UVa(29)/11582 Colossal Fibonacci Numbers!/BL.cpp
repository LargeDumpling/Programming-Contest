/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int m,T,A,B;
int solve()
{
	if(!A||m==1)return 0;
	unsigned long long n=pow(A,B);
	int a=0,b=1;
	for(int i=1;i<=n;i++)
	{
		b=(a+b)%m;
		a=(b-a+m)%m;
	}
	return b;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%d",&A,&B,&m);
		printf("%d\n",solve());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

