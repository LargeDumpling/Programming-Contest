/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int f(int x)
{ return x==1?1:(f(x/2)+1); }
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	while(scanf("%d",&n)!=-1)
		printf("%d\n",f(n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

