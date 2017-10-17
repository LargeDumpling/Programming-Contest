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
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &P)const { return Poi(x*P,y*P); }
	Poi operator/(const double &P)const { return Poi(x/P,y/P); }
	friend istream& operator>>(istream& in,Poi& P) { in>>P.x>>P.y; return in; }
}A,B,C,P1,P2,V1,V2,P;
const double PI=3.141592653589793;
double DOT(Vec V1,Vec V2) { return V1.x*V2.x+V1.y*V2.y; }
double CROSS(Vec V1,Vec V2) { return V1.x*V2.y-V1.y*V2.x; }
double LENTH(Vec V) { return sqrt(DOT(V,V)); }
double AREA(Vec V1,Vec V2) { return fabs(CROSS(V1,V2)); }
Poi INTERSECT(Poi P1,Vec V1,Poi P2, Vec V2)
{ return P1+V1*AREA(P1-P2,V2)/AREA(V1,V2); }
Poi NORMAL(Vec V) { return Vec(-1.*V.y,V.x); }
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	double R;
	while(cin>>A>>B>>C)
	{
		P1=(A+B)/2; P2=(B+C)/2;
		V1=NORMAL(B-A); V2=NORMAL(C-B);
		P=INTERSECT(P1,V1,P2,V2);
		R=LENTH(B-P);
		printf("%.2f\n",2*R*PI);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

