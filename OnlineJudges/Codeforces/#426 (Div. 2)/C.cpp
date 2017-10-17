/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-07-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,pos;
long long a,b,num[1000050];
long long gcd(long long n,long long m)
{
	int t;
	while(m)
	{
		t=n%m;
		n=m;
		m=t;
	}
	return n;
}
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	long long c;
	for(int i=1;i<=1000000;i++)
		num[i]=(long long)i*i*i;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%lld%lld",&a,&b);
		c=gcd(a,b);
		pos=lower_bound(num+1,num+1000001,a*b)-num;
		if(num[pos]!=a*b) puts("No");
		else if(c%pos) puts("No");
		else puts("Yes");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

