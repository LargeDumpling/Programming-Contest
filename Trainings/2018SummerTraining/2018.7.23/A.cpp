/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T;
long long n;
int main()
{
	scanf("%d",&T_T);
	while(T_T-->0)
	{
		scanf("%lld",&n);
		if(!(n%3))
			printf("%lld\n",n*n*n/27LL);
		else if(!(n%4))
			printf("%lld\n",n*n*n/32LL);
		else printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

