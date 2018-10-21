/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long K,N,P;
int T_T;
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%lld%lld%lld",&K,&P,&N);
		if(K<=P) puts("0");
		else printf("%lld\n",(K-P)*N);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

