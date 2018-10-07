/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define sqr(x) ((x)*(x))
using namespace std;
const int MAXN=100050;
int n;
long double x[MAXN],y[MAXN],minx,maxx;
long double calc(const long double &cx,const long double &cy)
{
	long double ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,sqrt(sqr(cx-x[i])+sqr(cy-y[i])));
	return ans;
}
bool check(const long double &R)
{
	long double l=minx,mid[2],r=maxx,maxdis[2];
	while(l<r)
	{
		mid[0]=(r-l)/3.;
		mid[1]=r-mid[0];
		mid[0]+=l;
		maxdis[0]=calc(mid[0],R);
		maxdis[1]=calc(mid[1],R);
		if(maxdis[0]<=maxdis[1])
		{
			if(r==mid[1]) break;
			r=mid[1];
		}
		else
		{
			if(l==mid[0]) break;
			l=mid[0];
		}
	}
	maxdis[0]=calc(l,R);
	return maxdis[0]<=R;
}
int main()
{
	double u,v;
	scanf("%d",&n);
	bool pos=false,neg=false;
	minx=1e14; maxx=-1e14;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&u,&v);
		x[i]=u;
		y[i]=v;
		maxx=max(maxx,x[i]);
		minx=min(minx,x[i]);
		if(0<y[i]) pos=true;
		else if(y[i]<0) neg=true;
	}
	if(pos&&neg) puts("-1");
	else
	{
		if(neg) for(int i=1;i<=n;i++) y[i]=-y[i];
		double l=0,mid,r=1e16;
		while(l<r)
		{
			mid=(l+r)/2.;
			if(check(mid))
			{
				if(r==mid) break;
				r=mid;
			}
			else
			{
				if(l==mid) break;
				l=mid;
			}
		}
		printf("%.7lf\n",(double)r);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
