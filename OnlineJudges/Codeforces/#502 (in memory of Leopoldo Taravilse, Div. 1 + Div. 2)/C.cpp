/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,num[MAXN],bn;
int main()
{
	scanf("%d",&n);
	bn=sqrt(n);
	if(n%bn)
	{
		int k=n%bn;
		for(int i=1;i<=k;i++)
			printf("%d ",n-k+i);
		n-=k;
	}
	while(n)
	{
		for(int i=1;i<=bn;i++)
			printf("%d ",n-bn+i);
		n-=bn;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

