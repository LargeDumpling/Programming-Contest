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
const double g=9.8;
const double Pi=acos(-1.);
int T_T,cnt;
int main()
{
	double theta,ga,gb,l,h,s,vx,vy,a,b,x,y;
	scanf("%d",&T_T);
	while(T_T--)
	{
		cnt=0;
		scanf("%lf%lf%lf%lf",&a,&b,&x,&y);
		x=-x;
		theta=atan2(b,a);
		ga=g*sin(theta);
		gb=g*cos(theta);
		l=y-x*tan(theta);
		h=l*cos(theta);
		s=x/cos(theta)+l*sin(theta);
		double dt=sqrt(2.*h/gb),ds;
		vy=dt*gb;
		vx=dt*ga;
		ds=ga*dt*dt/2.;
		s-=ds;
		dt=2.*vy/gb;
		while(s>=0)
		{
			cnt++;
			ds=vx*dt+ga*dt*dt/2.;
			vx+=ga*dt;
			s-=ds;
		}
		printf("%d\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

