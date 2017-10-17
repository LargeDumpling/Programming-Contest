/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n;
long long num[100050];
long long gCd(long long a,long long b)
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
long long solve()
{
	long long aNs=0,tem;
	for(int i=1;i<=n;i++)
	{
		tem=num[i];
		for(int j=i;j;j--)
		{
			tem=gCd(tem,num[j]);
			aNs=max(aNs,(i-j+1)*tem);
		}
	}
	return aNs;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&num[i]);
		printf("%lld\n",solve());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

