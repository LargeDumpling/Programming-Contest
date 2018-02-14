/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,num[MAXN];
int gcd(int a,int b)
{
	int t;
	while(b)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main()
{
	int tem;
	for(int T=1;scanf("%d",&n)!=-1;T++)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			if(i==1) tem=num[i];
			else tem=gcd(tem,num[i]);
		}
		printf("Case %d:",T);
		if(tem!=1) puts(" -1");
		else
		{
			printf(" %d\n",2*(n-1));
			for(int i=2;i<=n;i++)
				printf("1 %d\n",i);
			for(int i=2;i<=n;i++)
				printf("1 %d\n",i);
		}
		puts("");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

