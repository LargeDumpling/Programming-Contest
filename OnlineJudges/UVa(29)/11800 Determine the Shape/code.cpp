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
	Poi operator+(const Poi& P)const { return Poi(P.x+x,P.y+y); }
	Poi operator-(const Poi& P)const { return Poi(P.x-x,P.y-y); }
	Poi operator*(const double& P)const { return Poi(x*P,y*P); }
	Poi operator/(const double& P)const { return Poi(x/P,y/P); }
	friend istream& operator>>(istream& in,Poi& P) { in>>P.x>>P.y; return in;}
}A,B,C,D,AB,BC,CD,DA;
const double eps=1e-10;
int dcmp(const double& x) { if(fabs(x)<eps) return 0; else return x<0?-1:1; }
//bool cnmp(Poi A,Poi B)
//{ int k=dcmp(A.y-B.y); return !k?dcmp(A.x-B.x)==-1:k==-1; }
double DOT(Vec V1,Vec V2){ return V1.x*V2.x+V1.y*V2.y; }
double CROSS(Vec V1,Vec V2){ return V1.x*V2.y-V1.y*V2.x; }
double LENTH(Vec V) { return sqrt(DOT(V,V)); }
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T,equal_edge,vertical_edge,paral;
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		equal_edge=vertical_edge=paral=0;
		printf("Case %d: ",cAse);
		cin>>A>>B>>C>>D;
		if((dcmp(CROSS(B-A,C-A))^dcmp(CROSS(B-A,D-A)))==-2) swap(B,C);
		if((dcmp(CROSS(D-A,B-A))^dcmp(CROSS(D-A,C-A)))==-2) swap(D,C);
		AB=B-A; BC=C-B; CD=D-C; DA=A-D;
		if(!dcmp(CROSS(AB,CD))) paral++;
		if(!dcmp(CROSS(BC,DA))) paral++;
		if(!dcmp(DOT(AB,BC))) vertical_edge++;
		if(!dcmp(DOT(BC,CD))) vertical_edge++;
		if(!dcmp(DOT(CD,DA))) vertical_edge++;
		if(!dcmp(DOT(DA,AB))) vertical_edge++;
		if(!dcmp(LENTH(AB)-LENTH(BC))) equal_edge++;
		if(!dcmp(LENTH(BC)-LENTH(CD))) equal_edge++;
		if(!dcmp(LENTH(CD)-LENTH(DA))) equal_edge++;
		if(!dcmp(LENTH(DA)-LENTH(AB))) equal_edge++;
		if(!dcmp(LENTH(AB)-LENTH(CD))) equal_edge++;
		if(!dcmp(LENTH(BC)-LENTH(DA))) equal_edge++;
		if(paral==2&&vertical_edge==4&&equal_edge==6) puts("Square");
		else if(paral==2&&vertical_edge==4&&equal_edge==2) puts("Rectangle");
		else if(paral==2&&vertical_edge==0&&equal_edge==6) puts("Rhombus");
		else if(paral==2&&vertical_edge==0&&equal_edge==2) puts("Parallelogram");
		else if(paral==1) puts("Trapezium");
		else puts("Ordinary Quadrilateral");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

