/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-6;
double x,y,c;
int dcmp(double x){ if(fabs(x)<eps) return 0; else return x<0?-1:1; }
double calc(double d)
{
	double a=sqrt(x*x-d*d),b=sqrt(y*y-d*d);
	return a*b/(a+b);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	double l,r,mid,d;
	int k;
	while(scanf("%lf%lf%lf",&x,&y,&c)!=-1)
	{
		l=0; r=min(x,y);
		while(l<r-eps)
		{
			mid=(l+r)/2.;
			d=calc(mid);
			k=dcmp(d-c);
			if(!k) { l=mid; break; }
			else if(k==-1) r=mid;
			else l=mid;
		}
		printf("%.3f\n",l);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

