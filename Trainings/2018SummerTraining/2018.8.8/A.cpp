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
const double Pi=acos(-1.);
void print(double x)
{
	int t=(int)x;
	printf("%d",t);
	x-=t;
	putchar('.');
	for(int i=1;i<=6;i++)
	{
		x*=10.;
		t=(int)x;
		x-=t;
		putchar('0'+t);
	}
	putchar('\n');
	return;
}
int main()
{
	int T_T;
	double a,b;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%lf%lf",&a,&b);
		print(a*Pi+2.*b);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

