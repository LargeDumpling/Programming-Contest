/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T;
long long n,k,cnt,kth;
int main()
{
	int limit;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%lld%lld",&n,&k);
		cnt=(limit=sqrt(n))<<1;
		if(limit==n/limit)
		{
			cnt--;
			if(k<=limit) kth=n/k;
			else kth=limit-(k-limit);
		}
		else
		{
			if(k<=limit) kth=n/k;
			else kth=limit-(k-limit-1);
		}
		printf("%lld %lld\n",cnt,kth);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

