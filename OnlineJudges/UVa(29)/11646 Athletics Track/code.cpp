/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-11	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double PI=3.1415926535;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	double a,b,x;
	for(int cAse=1;scanf("%lf : %lf",&a,&b)!=-1;cAse++)
	{
		x=200./(sqrt(a*a+b*b)*atan2(b,a)+a);
		printf("Case %d: %.10f %.10f\n",cAse,a*x,b*x);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

