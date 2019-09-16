/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-09-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,Int,Exp,Str;
int main()
{
	int low;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d%d",&Str,&Int,&Exp);
		low=max(0,Int+Exp+2-Str)>>1;
		printf("%d\n",max(0,Exp-low+1));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

