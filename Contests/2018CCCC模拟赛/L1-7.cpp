/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T;
int main()
{
	double h1,h2;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%lf%lf",&h1,&h2);
		h1=(h1-100.)*1.8;
		if(fabs(h1-h2)<h1*0.1) puts("You are wan mei!");
		else if(h2<h1) puts("You are tai shou le!");
		else if(h1<h2) puts("You are tai pang le!");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

