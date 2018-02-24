/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-8;
const double PI=acos(-1.);
double R,x[3],y[3],vx,vy;
int dcmp(const double &x)
{
	if(fabs(x)<=eps) return 0;
	return x<0?-1:1;
}
int main()
{
	scanf("%lf%lf%lf%lf%lf",&R,&x[0],&y[0],&x[1],&y[1]);
	vx=x[1]-x[0];
	vy=y[1]-y[0];
	if(!dcmp(vx)&&!dcmp(vy))
		printf("%.10lf %.10lf %.10lf",x[0]+R/(2.*sqrt(2)),y[0]+R/(2.*sqrt(2)),R/2.-eps);
	else
	{
		double p=sqrt(vx*vx+vy*vy),len,t=atan2(-vy,-vx);
		vx/=p;
		vy/=p;
		len=(R-min(p,R))/2.;
		printf("%.10lf %.10lf %.10lf",x[0]+len*cos(t),y[0]+len*sin(t),(R+min(R,p))/2.-eps);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

