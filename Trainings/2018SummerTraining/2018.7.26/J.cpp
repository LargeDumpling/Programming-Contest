/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-6;
const double Pi=acos(-1.);
const int MAXN=205;
typedef struct Poi Vec;
int dcmp(double x) { if(fabs(x)<eps) return 0; return x<0?-1:1; }
struct Poi
{
	double x,y;
	Poi(const double &X=0,const double &Y=0):x(X),y(Y) { }
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &P)const { return Poi(x*P,y*P); }
	Poi operator/(const double &P)const { return Poi(x/P,y/P); }
}P[MAXN],M[MAXN],inter[2];
int n,m;
double num[MAXN],den[MAXN];
double dot(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y; }
double cross(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
double area(const Vec &V1,const Vec &V2) { return fabs(V1.x*V2.y-V1.y*V2.x); }
Poi rotate(const Vec &V,const double &theta)
{ return Vec(V.x*cos(theta)-V.y*sin(theta),V.x*sin(theta)+V.y*cos(theta)); }
double lenth(const Vec &V) { return sqrt(dot(V,V)); }
Poi intersect(const Poi &P1,const Vec &V1,const Poi &P2,const Vec &V2)
{ return P1+V1*(cross(V2,P1-P2)/cross(V1,V2)); }
bool onseg(const Poi &P,const Poi &A,const Poi &B)
{
	Vec PA=A-P,PB=B-P;
	if(!dcmp(cross(PA,PB))&&dcmp(dot(PA,PB))<=0) return true;
	return false;
}
/*int calc_i(Poi P,Poi A,Poi B,double r)
{
	int itn=0;
	Vec PA=A-P,PB=B-P,Vn=rotate(B-A,Pi/2.),Vt=(A-B)/lenth(A-B);
	Vn=Vn/lenth(Vn);
	if(dcmp(dot(Vn,PA))<0) Vn=Vn*-1.;
	double d=cross(PA,PB)/lenth(A-B),l;
	l=sqrt(r*r-d*d);
	Poi P0=P+Vn*d,P1;
	P1=P0+Vt*l;
	if(onseg(P1,A,B))
		inter[itn++]=P1;
	P1=P0-Vt*l;
	if(onseg(P1,A,B))
		inter[itn++]=P1;
	return itn;
}*/
int intersect_circle_with_segment(const Poi &P,const Poi &A,const Poi &B,const double &r)
{
	int itn,type;
	double d=area(A-P,B-P)/lenth(A-B);
	Vec AB=(B-A)/lenth(B-A),Vn;
	Vn=rotate(AB,Pi/2.);
	if(dcmp(dot(Vn,A-P))<0) Vn=Vn*-1;
	Poi P0=P+Vn*d;
	type=dcmp(r-d);
	if(type==-1) itn=0;
	else
	{
		double offset=sqrt(r*r-d*d);
		itn=0;
		inter[itn++]=P0+AB*offset;
		inter[itn++]=P0-AB*offset;
	}
	return itn;
}
double calc(int x,double r)
{
	double S=0,l1,l2;
	Poi P0=M[x],P1,P2;
	for(int i=0;i<n;i++)
	{
		P1=P[i]; P2=P[(i+1)%n];
		l1=lenth(P1-P0); l2=lenth(P2-P0);
		int itn=intersect_circle_with_segment(P0,P1,P2,r);
		for(int i=itn-1;0<=i;i--)
			if(!onseg(inter[i],P1,P2))
			{
				swap(inter[i],inter[itn-1]);
				itn--;
			}
		if(itn==0)
		{
			if(0<=dcmp(min(l1,l2)-r))
			{
				double alpha=asin(cross(P1-P0,P2-P0)/lenth(P1-P0)/lenth(P2-P0));
				S+=r*r*alpha/2.;
			}
			else if(0<=dcmp(r-max(l1,l2)))
				S+=cross(P1-P0,P2-P0)/2.;
		}
		else if(itn==1)
		{
			if(0<=dcmp(r-l1)&&0<=dcmp(l2-r))
			{
				S+=cross(P1-P0,inter[0]-P0)/2.;
				double alpha=asin(cross(inter[0]-P0,P2-P0)/lenth(inter[0]-P0)/lenth(P2-P0));
				S+=r*r*alpha/2.;
			}
			else if(0<=dcmp(r-l2)&&0<=dcmp(l1-r))
			{
				double alpha=asin(cross(P1-P0,inter[0]-P0)/lenth(inter[0]-P0)/lenth(P1-P0));
				S+=r*r*alpha/2.;
				S+=cross(inter[0]-P0,P2-P0)/2.;
			}
			else if(0<=dcmp(l1-r)&&0<=dcmp(l2-r))
			{
				double alpha=asin(cross(P1-P0,P2-P0)/lenth(P1-P0)/lenth(P2-P0));
				S+=r*r*alpha/2.;
			}
		}
		else if(itn==2)
		{
			if(0<dcmp(lenth(inter[0]-P1)-lenth(inter[1]-P1)))
				swap(inter[0],inter[1]);
			double alpha=asin(cross(P1-P0,inter[0]-P0)/lenth(P1-P0)/lenth(inter[0]-P0));
			S+=r*r*alpha/2.;
			S+=cross(inter[0]-P0,inter[1]-P0)/2.;
			alpha=asin(cross(inter[1]-P0,P2-P0)/lenth(P2-P0)/lenth(inter[1]-P0));
			S+=r*r*alpha/2.;
		}
	}
	return S;
}
int main()
{
	//freopen("J.in","r",stdin);
	double l,mid,r,S,Si;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf%lf",&P[i].x,&P[i].y);
	S=0;
	for(int i=0;i<n;i++)
		S+=cross(P[i],P[(i+1)%n]);
	S/=2.;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lf%lf%lf%lf",&M[i].x,&M[i].y,&num[i],&den[i]);
		l=0; r=1e8;
		while(dcmp(r-l))
		{
			mid=(l+r)/2.;
			Si=calc(i,mid);
			if(dcmp(S*(den[i]-num[i])-Si*den[i])>=0) l=mid;
			else r=mid;
		}
		printf("%.8lf\n",l);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

