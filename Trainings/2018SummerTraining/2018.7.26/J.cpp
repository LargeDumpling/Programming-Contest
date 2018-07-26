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
const double eps=1e-10;
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
double dot(Vec V1,Vec V2) { return V1.x*V2.x+V1.y*V2.y; }
double cross(Vec V1,Vec V2) { return V1.x*V2.y-V1.y*V2.x; }
Poi rotate(Vec V,double theta) { return Vec(V.x*cos(theta)-V.y*sin(theta),V.x*sin(theta)+V.y*cos(theta)); }
double lenth(Vec V) { return sqrt(dot(V,V)); }
bool onseg(const Poi &P,const Poi &A,const Poi &B)
{
	Vec PA=A-P,PB=B-P;
	if(!dcmp(cross(PA,PB))&&dcmp(dot(PA,PB))<=0) return true;
	return false;
}
int calc_i(Poi P,Poi A,Poi B,double r)
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
}
double calc(int x,double r)
{
	double S=0,l1,l2,l3;
	Poi P0=M[x],P1,P2;
	for(int i=0;i<n;i++)
	{
		P1=P[i]; P2=P[(i+1)%n];
		l1=lenth(P1-P0); l2=lenth(P2-P0),l3=lenth(P1-P2);
		int itn=calc_i(P0,P1,P2,r);
		if(itn==0)
		{
			if(0<=dcmp(min(l1,l2)-r))
			{
				double alpha=acos((l1*l1+l2*l2-l3*l3)/2./l1/l2);
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
				double l4=lenth(inter[0]-P0);
				double l5=lenth(inter[0]-P2);
				double alpha=acos((l4*l4+l2*l2-l5*l5)/2./l4/l2);
				S+=r*r*alpha/2.;
			}
			else if(0<=dcmp(r-l2)&&0<=dcmp(l1-r))
			{
				S+=cross(P2-P0,inter[0]-P0)/2.;
				double l4=lenth(inter[0]-P0);
				double l5=lenth(inter[0]-P1);
				double alpha=acos((l4*l4+l1*l1-l5*l5)/2./l4/l1);
				S+=r*r*alpha/2.;
			}
		}
		else if(itn==2)
		{
			if(0<dcmp(lenth(inter[0]-P1)-lenth(inter[1]-P1)))
				swap(inter[0],inter[1]);
			double l4=lenth(inter[0]-P0);
			double l5=lenth(inter[1]-P0);
			double l6=lenth(inter[0]-P1);
			//double l7=lenth(inter[0]-inter[1]);
			double l8=lenth(inter[1]-P2);
			S+=cross(inter[0]-P0,inter[1]-P0)/2.;
			double alpha=acos((l1*l1+l4*l4-l6*l6)/2./l1/l4);
			S+=r*r*alpha/2.;
			alpha=acos((l5*l5+l2*l2-l8*l8)/2./l5/l2);
			S+=r*r*alpha/2.;
		}
	}
	return S;
}
int main()
{
	freopen("J.in","r",stdin);
	//Poi P99=rotate(Poi(cos(Pi/4),sin(Pi/4)),Pi/2);
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

