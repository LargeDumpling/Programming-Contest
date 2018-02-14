/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long a,b,t;
long long gcd(int m,int n)
{
	long long tem;
	while(n)
	{
		tem=m%n;
		m=n;
		n=tem;
	}
	return m;
}
int main()
{
	scanf("%I64d%I64d",&a,&b);
	t=gcd(a,b);
	if(t!=1) puts("infinity infinity");
	else printf("%I64d %I64d",(a*b-a-b+1LL)/2,a*b-a-b);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

