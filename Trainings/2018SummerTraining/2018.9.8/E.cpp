/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const double eps=1e-5;
const double Pi=acos(-1.);
const int MAXN=305;
typedef struct Poi Vec;
struct Poi
{
	double x,y;
	Poi(const double &a=0,const double &b=0):x(a),y(b){}
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &P)const { return Poi(x*P,y*P); }
	Poi operator/(const double &P)const { return Poi(x/P,y/P); }
};
inline double dOt(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y;}
inline double cRoss(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x;}
inline double lEnth(const Vec &V) { return sqrt(dOt(V,V)); }
inline int dcmp(const double &x) { if(fabs(x)<eps) return 0; return x<0?-1:1; }
struct Circle
{
	Poi Pc;
	double r;
	Circle(const Poi &P=Poi(),const double &R=0):Pc(P),r(R){}
	Poi loc(double ang)
	{ return Poi(Pc.x+cos(ang)*r,Pc.y+sin(ang)*r); }
}C[MAXN];
int n,s;
inline bool covers(const Poi &P,const double &R)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(dcmp(lEnth(C[i].Pc-P)-R)<=0) cnt++;
	return s<=cnt;
}
inline double Normalize(const double &rad)
{ return rad-2*Pi*floor(rad/(2.*Pi)); }
inline void CCI(const Circle &C1,const Circle &C2,vector<double> &ans)
{
	Vec V=C2.Pc-C1.Pc;
	double d1=lEnth(V);
	if(!dcmp(d1)) return;
	if(dcmp(d1-fabs(C1.r-C2.r))==-1) return;//ƒ⁄∫¨
	else if(dcmp(d1-C1.r-C2.r)==1) return;//Õ‚¿Î
	double ori=atan2(V.y,V.x),ang,tem;
	ang=acos((C1.r*C1.r+d1*d1-C2.r*C2.r)/(2.*C1.r*d1));
	tem=ori+ang;
	ans.push_back(Normalize(tem));
	if(!dcmp(ang)) return;
	tem=ori-ang+2.*Pi;
	ans.push_back(Normalize(tem));
	return;
}
bool check(double R)
{
	if(dcmp(R)<0) return false;
	for(int i=1;i<=n;i++) C[i].r=R;
	for(int i=1;i<=n;i++)
	{
		vector<double> rad;
		rad.push_back(0.);
		rad.push_back(Pi*2.);
		for(int j=1;j<=n;j++)
			CCI(C[i],C[j],rad);
		sort(rad.begin(),rad.end());
		for(unsigned j=0;j<rad.size()-1;j++)
		{
			double mid=(rad[j]+rad[j+1])/2.;
			if(covers(C[i].loc(mid),R))
				return true;
		}
	}
	return false;
}
int main()
{
	int T_T;
	double l,mid,r,R0;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&n,&s);
		for(int i=1;i<=n;i++)
			scanf("%lf%lf",&C[i].Pc.x,&C[i].Pc.y);
		scanf("%lf",&R0);
		l=0; r=2e4;
		while(true)
		{
			if(dcmp(r-l)<=0) break;
			mid=(l+r)/2.;
			if(check(mid-R0)) r=mid;
			else l=mid;
		}
		if(check(r)) printf("%.5lf\n",r);
		else puts("The cake is a lie.");
	}
}

