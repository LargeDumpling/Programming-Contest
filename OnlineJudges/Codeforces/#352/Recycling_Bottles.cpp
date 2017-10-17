/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-05-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const double INF=1e60;
int n;
double xa,xb,xt,ya,yb,yt,d[MAXN],x[MAXN],y[MAXN],ans,tot=0;
double da[MAXN],db[MAXN],p[MAXN],s[MAXN];
double dis(double xx,double yy) { return sqrt(xx*xx+yy*yy); }
int main()
{
	scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xt,&yt);
	xa-=xt; ya-=yt;
	xb-=xt; yb-=yt;
	scanf("%d",&n);
	p[0]=s[0]=p[n+1]=s[n+1]=INF;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
		x[i]-=xt; y[i]-=yt;
		d[i]=dis(x[i],y[i]);
		da[i]=dis(x[i]-xa,y[i]-ya);
		db[i]=dis(x[i]-xb,y[i]-yb);
		s[i]=p[i]=db[i]-d[i];
		tot+=d[i]*2.;
	}
	for(int i=1;i<=n;i++) p[i]=min(p[i-1],p[i]);
	for(int i=n;i;i--) s[i]=min(s[i+1],s[i]);
	ans=tot+s[1];
	for(int i=1;i<=n;i++)
		ans=min(ans,tot+da[i]-d[i]+min(0.0,min(p[i-1],s[i+1])));
	printf("%.12lf",ans);
	return 0;
}

