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
double h;
int main()
{
	scanf("%lf",&h);
	h=(h-100.)*1.8;
	printf("%.1lf",h);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

