/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-12	File created.
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
	//friend istream& operator>>(istream &in,Poi &P) { in>>P.x>>P.y; return in; }
	//friend ostream& operator<<(ostream &out,Poi &P)
	//{ out<<P.x<<" "<<P.y; return out; }
}A,B,C,D,E,F,AB,BC,CA;
double DOT(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y; }
double CROSS(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
double LENTH(const Vec &V) { return sqrt(DOT(V,V)); }
double AREA(const Vec &V1,const Vec &V2) { return fabs(CROSS(V1,V2)); }
double ANGLE(const Vec &V1,const Vec &V2)
{ return acos(DOT(V1,V2)/LENTH(V1)/LENTH(V2)); }
Vec ROTATE(const Vec &V,const double &P)
{
	double cOs=cos(P),sIn=sin(P);
	return Vec(V.x*cOs-V.y*sIn,V.y*cOs+V.x*sIn);
}
Poi INTERSECT(Poi P1,Vec V1,Poi P2,Vec V2)
{ return P1+V1*CROSS(V2,P1-P2)/CROSS(V1,V2); }
void input(Poi &P) { scanf("%lf%lf",&P.x,&P.y); return; }
void output(const Poi &P) { printf("%.6f %.6f",P.x,P.y); return; }
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T;
	double AA,BB,CC;
	scanf("%d",&T_T);
	while(T_T--)
	{
		//cin>>A>>B>>C;
		input(A); input(B); input(C);
		AB=B-A; BC=C-B; CA=A-C;
		AA=ANGLE(AB,C-A);
		BB=ANGLE(A-B,BC);
		CC=ANGLE(B-C,CA);
		D=INTERSECT(B,ROTATE(BC,BB/3.),C,ROTATE(CA,CC*2./3.));
		E=INTERSECT(C,ROTATE(CA,CC/3.),A,ROTATE(AB,AA*2./3.));
		F=INTERSECT(A,ROTATE(AB,AA/3.),B,ROTATE(BC,BB*2./3.));
		//cout<<D<<" "<<E<<" "<<F<<"\n";
		output(D); putchar(' ');
		output(E); putchar(' ');
		output(F); putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

