/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-05-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,a,b,c,d;
int main()
{
	scanf("%d%d%d%d%d%d",&n,&k,&a,&b,&c,&d);
	if(n==4||k<n+1) printf("-1");
	else
	{
		printf("%d %d",a,c);
		for(int i=1;i<=n;i++)
		{
			if(i==a||i==b||i==c||i==d) continue;
			printf(" %d",i);
		}
		printf(" %d %d\n",d,b);
		printf("%d %d",c,a);
		for(int i=1;i<=n;i++)
		{
			if(i==a||i==b||i==c||i==d) continue;
			printf(" %d",i);
		}
		printf(" %d %d",b,d);
	}
	return 0;
}

