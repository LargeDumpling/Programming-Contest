/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-12-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,x,a,b;
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&x);
		a=-2*x; b=x;
		while(a<0)
		{
			a+=7;
			b-=3;
		}
		if(0<=b) puts("YES");
		else puts("NO");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

