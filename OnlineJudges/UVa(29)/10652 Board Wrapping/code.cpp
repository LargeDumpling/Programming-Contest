/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-10;
const double Pi=acos(-1.);
int dcmp(const double &);
typedef struct Poi Vec;
struct Poi
{
	double x,y;
	Poi(const double &a=0,const double &b=0):x(a),y(b){}
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &P)const { return Poi(x*P,y*P); }
	Poi operator/(const double &P)const { return Poi(x/P,y/P); }
	bool operator<(const Poi &P)const { return !dcmp(x-P.x)?dcmp(y-P.y)<=0:x<P.x; }
}Ve[2450],aN[2450];
double dOt(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y; }
double cRoss(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
Vec rOtate(const Vec &V,const double &P)
{ double cOs=cos(P),sIn=sin(P); return Vec(V.x*cOs-V.y*sIn,V.x*sIn+V.y*cOs); }
int dcmp(const double &x) { if(fabs(x)<eps) return 0; return x<0?-1:1; }
int Andrew(Poi *A,int n,Poi *B)
{
	int m=0;
	sort(A,A+n);
	for(int i=0;i<n;B[m++]=A[i++])
		while(m>1&&cRoss(B[m-1]-B[m-2],A[i]-B[m-2])<=0) m--;
	for(int i=n-2,k=m;i>=0;B[m++]=A[i--])
		while(m>k&&cRoss(B[m-1]-B[m-2],A[i]-B[m-2])<=0) m--;
	return n>1?m-1:m;
}
int n,Pn;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T,An;
	double a,b,c,d,e;
	Poi Tem;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		Pn=0;
		a=b=0.;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf%lf%lf",&Tem.x,&Tem.y,&c,&d,&e);
			c/=2.; d/=2.; e=e*Pi/-180.;
			Ve[Pn++]=Tem+rOtate(Vec(c,d),e);
			Ve[Pn++]=Tem+rOtate(Vec(c,-d),e);
			Ve[Pn++]=Tem+rOtate(Vec(-c,d),e);
			Ve[Pn++]=Tem+rOtate(Vec(-c,-d),e);
			a+=c*d*4.;
		}
		An=Andrew(Ve,Pn,aN);
		for(int i=0;i<An;i++) b+=cRoss(aN[i],aN[(i+1)%An]);
		b/=2.;
		c=a*100./b;
		printf("%.1f %%\n",c);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

