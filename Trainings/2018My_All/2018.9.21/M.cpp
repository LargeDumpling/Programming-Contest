/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
typedef struct Poi Vec;
struct Poi
{
	double x,y;
	Poi(const double &X=0,const double &Y=0):x(X),y(Y) { }
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &p)const { return Poi(x*p,y*p); }
	Poi operator/(const double &p)const { return Poi(x/p,y/p); }
}P[MAXN];
int T_T,n;
double cross(const Poi &P1,const Poi &P2) { return P1.x*P2.x+P1.y*P2.y; }
Poi intersect(const Poi &P1,const Vec &V1,const Poi &P2,const Vec &V2)
{ return P1+V1*(cross(V2,P1-P2)/cross(V1,V2)); }
Vec rotate(const Vec &V,const double &theta)
{ return Vec(V.x*cos(theta)-V.y*sin(theta),V.x*sin(theta)+V.y*cos(theta)); }
unsigned Rand()
{
	unsigned a=rand(),b=rand();
	return (a<<15)+b;
}
int Rand(int a,int b) { return Rand()%(b-a+1)+a; }
int calc(const Poi &P0,const Poi &P1,const Poi &P2)
{
}
int main()
{
	int x,y,z,cnt;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&P[i].x,&P[i].y);
		do
		{
			x=Rand(1,n);
			y=Rand(1,n);
			z=Rand(1,n);
		}while(x==y||x==z||y==z);
		while(true)
		{
			cnt=calc(P[x],P[y],P[z]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

