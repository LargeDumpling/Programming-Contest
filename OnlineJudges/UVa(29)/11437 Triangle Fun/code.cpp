/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-11	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef struct Poi Vec;
struct Poi
{
	double x,y;
	Poi(double a=0,double b=0):x(a),y(b){}
	Poi operator+(const Poi& P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi& P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double& P)const { return Poi(x*P,y*P); }
	Poi operator/(const double& P)const { return Poi(x/P,y/P); }
	friend istream& operator>>(istream& in,Poi& P) { in>>P.x>>P.y; return in;}
}A,B,C,D,E,F,R,P,Q;
double CROSS(const Vec& V1,const Vec& V2) { return V1.x*V2.y-V1.y*V2.x; }
double AREA(const Vec& V1,const Vec& V2) { return fabs(CROSS(V1,V2)); }
Poi INTERSECT(const Poi& P1,const Vec& V1,const Poi& P2,const Vec& V2)
{ return P1+V1*(AREA(P1-P2,V2)/AREA(V1,V2)); }

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>A>>B>>C;
		D=B+(C-B)/3;
		E=C+(A-C)/3;
		F=A+(B-A)/3;
		R=INTERSECT(A,D-A,C,F-C);
		P=INTERSECT(B,E-B,A,D-A);
		Q=INTERSECT(B,E-B,C,F-C);
		printf("%.0f\n",AREA(Q-P,R-P)/2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

