/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-10;
int dcmp(const double &x) { if(fabs(x)<eps) return 0; return x<0?-1:1; }
typedef struct Poi Vec;
struct Poi
{
	double x,y;
	Poi(const double &a=0,const double &b=0):x(a),y(b){}
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &P)const { return Poi(x*P,y*P); }
	Poi operator/(const double &P)const { return Poi(x/P,y/P); }
}Ve[105],NVe[105],IP[105],NPoly[105];
double dOt(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y; }
double cRoss(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
double lEnth(const Vec &V) { return sqrt(dOt(V,V)); }
Vec Normal(const Vec &V) { return Vec(-V.y,V.x); }
Poi iNtersect(const Poi &P1,const Vec &V1,const Poi &P2,const Vec &V2)
{ return P1+V1*cRoss(P1-P2,V2)/cRoss(V2,V1); }
struct Line
{
	Poi Ps;
	Vec Dir;
	double ang;
	Line(const Poi &P=Poi(),const Vec &V=Vec(1.,0.))
	{ Ps=P; Dir=V; ang=atan2(V.y,V.x); }
	bool operator<(const Line &L)const { return ang<L.ang; }
}lines[105],q[105];
Poi iNtersect(const Line &L1,const Line &L2)
{ return iNtersect(L1.Ps,L1.Dir,L2.Ps,L2.Dir); }
int n;
int HPI(Line* L,int n,Poi *Poly)
{
	sort(L,L+n);//按极角排序
	int l,r,m;	
	q[l=r=0]=L[0];
	for(int i=1;i<n;i++)
	{
		while(l<r&&dcmp(cRoss(L[i].Dir,IP[r-1]-L[i].Ps))<=0) r--;
		//新加入的直线可能使尾部的一些交点失效
		while(l<r&&dcmp(cRoss(L[i].Dir,IP[l]-L[i].Ps))<=0) l++;
		//首部
		q[++r]=L[i];//加入
		if(!dcmp(cRoss(q[r].Dir,q[r-1].Dir)))
		{//对于平行的直线要取靠左的
			r--;
			if(dcmp(cRoss(q[r+1].Dir,q[r].Ps-q[r+1].Ps))<=0)q[r]=q[r+1];
		}
		if(l<r) IP[r-1]=iNtersect(q[r-1],q[r]);//如果队列中有至少两条线则取交点
	}
	while(l<r&&dcmp(cRoss(q[l].Dir,IP[r-1]-q[l].Ps))<=0) r--;
	//后面的一些交点可能实际上是无用的
	if(r-l<=1) return 0;//如果只有不到两条线，则失败了
	IP[r]=iNtersect(q[l],q[r]);//将最后一条线和第一条线交起来
	m=r-l+1;
	for(int i=0;i<=m;i++) Poly[i]=IP[l+i];
	return m;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	double l,mid,r;
	while(scanf("%d",&n)!=-1&&n)
	{
		for(int i=0;i<n;i++) scanf("%lf%lf",&Ve[i].x,&Ve[i].y);
		Ve[n]=Ve[0];
		for(int i=0;i<n;i++)
		{
			NVe[i]=Normal(Ve[i+1]-Ve[i]);
			NVe[i]=NVe[i]/lEnth(NVe[i]);
		}
		l=0,r=10000*sqrt(2.);
		while(dcmp(r-l))
		{
			mid=(l+r)/2;
			for(int i=0;i<n;i++)lines[i]=Line(Ve[i]+NVe[i]*mid,Ve[i+1]-Ve[i]);
			if(HPI(lines,n,NPoly)) l=mid;
			else r=mid;
		}
		printf("%.6f\n",l);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

