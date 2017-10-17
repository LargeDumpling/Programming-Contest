/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
double t,d[35];
double mAx(double a,double b){return a<b?b:a;}
double solve()
{
	double p1,p0;
	d[n]=(1<<n);
	for(int i=n-1;i>=0;i--)
	{
		p0=mAx((double)(1<<i)/d[i+1],t);
		p1=(p0-t)/(1-t);
		d[i]=d[i+1]*(1+p0)*(1-p1)/2+p1*(1<<i);
	}
	return d[0];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(scanf("%d%lf",&n,&t)!=-1)
	{
		if(n==0&&t==0)break;
		printf("%.3lf\n",solve());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

