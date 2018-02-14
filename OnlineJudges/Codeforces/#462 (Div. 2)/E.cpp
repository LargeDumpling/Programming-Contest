/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-6;
int cmp(double x)
{
	if(fabs(x)<=eps) return 0;
	return x<0?-1:1;
}
struct Poi
{
	double x,y;
	Poi(const double &X=0,const double &Y=0):x(X),y(Y) { }
	bool operator<(const Poi &P)const
	{
		return cmp(x-P.x)==0?cmp(y-P.y)<0:cmp(x-P.x)<0;
	}
	bool operator==(const Poi &P)const
	{
		return cmp(x-P.x)==0&&cmp(y-P.y)==0;
	}
}P[1050];
struct Arc
{
	Poi x,y,C;
	Arc(const Poi &X=Poi(),const Poi &Y=Poi(),const Poi &CC=Poi()):x(X),y(Y),C(CC) { }
	bool operator<(const Arc &A)const
	{
		if(x==A.x) return y==A.y?C<A.C:y<A.y;
		return x<A.x;
	}
	bool operator==(const Arc &A)const
	{
		return x==A.x&&y==A.y&&C==A.C;
	}
}A[1050];
struct Cir
{
	Poi Cen;
	double r;
	bool operator<(const Cir &CC)const
	{
		return Cen==CC.Cen?cmp(r-CC.r)<0:Cen<CC.Cen;
	}
	bool operator==(const Cir &CC)const
	{
		return Cen==CC.Cen&&cmp(r-CC.r)==0;
	}
	Poi get(double k) { return Poi(Cen.x+r*cos(k),Cen.y+r*cos(k)); }
}C[3];
int Pn=0,An=0,n;
double sqr(double x) { return x*x; }
double calc_dis(Poi &P1,Poi &P2)
{
	return sqrt(sqr(P1.x-P2.x)+sqr(P1.y-P2.y));
}
void Intersect(int j,int i)
{
	double dis=calc_dis(C[i].Cen,C[j].Cen);
	if()
}
int calc()
{
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&C[i].Cen.x,&C[i].Cen.y,&C[i].r);
		for(int j=1;j<i;j++)
			Intersect(j,i);
	}
	printf("%d",calc());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

