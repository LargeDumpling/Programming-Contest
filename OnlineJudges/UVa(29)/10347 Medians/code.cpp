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
const double eps=1e-6;
double a,b,c,ans;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(scanf("%lf%lf%lf",&a,&b,&c)!=-1)
	{
		if(a<=0||b<=0||c<=0||(a+b-c)<=0||(a+c-b)<=0||(b+c-a)<=0) ans=-1.;
		else ans=sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a)/3./3.);
		if(ans<eps) ans=-1.;
		printf("%.3f\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

