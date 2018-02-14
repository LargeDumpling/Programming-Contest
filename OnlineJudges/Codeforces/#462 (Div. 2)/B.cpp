/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int num[10]={1,0,0,0,1,0,1,0,2,1};
int n;
int main()
{
	scanf("%d",&n);
	if(36<n) printf("-1");
	else
	{
		for(;1<n;n-=2)
			putchar('8');
		if(n) putchar('4');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

