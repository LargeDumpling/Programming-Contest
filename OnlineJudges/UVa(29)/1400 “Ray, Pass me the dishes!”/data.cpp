/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	int T=rand()%10+1;
	for(int cAse=1;cAse<=T;cAse++)
	{
		long long n=rand()*rand()%500000+1,m=rand()*rand()%500000+1,tem;
		printf("%lld %lld\n",n,m);
		for(int i=1;i<=n;i++)
		{
			tem=rand()*rand()%1000000000;
			if(rand()%2)tem=-tem;
			printf("%lld ",tem);
		}
		putchar('\n');
		long long a,b;
		for(int i=1;i<=m;i++)
		{
			a=rand()*rand()%n;
			b=rand()*rand()%n;
			if(a>b)swap(a,b);
			printf("%lld %lld\n",a,b);
		}
	}
	fclose(stdout);
	return 0;
}

