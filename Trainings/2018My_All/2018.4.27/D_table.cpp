/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int k=5;
long long a[10][10],sum;
long long f(long long x)
{
	for(sum=0;x;x/=10)
		sum+=a[x%10][k];
	return sum;
}
int main()
{
	long long tem;
	for(int i=0;i<10;i++)
	{
		a[i][0]=1l;
		a[i][1]=i;
		for(int j=2;j<10;j++)
			a[i][j]=a[i][j-1]*a[i][1];
	}
	for(long long i=1;;i++) if((tem=f(i)-i)>0)
		printf("%lld %lld\n",i,tem);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

