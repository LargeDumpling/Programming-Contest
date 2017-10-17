/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(n&1)printf("0");
	else
	{
		n>>=1;
		printf("%d",(n-1)>>1);
	}
	return 0;
}

