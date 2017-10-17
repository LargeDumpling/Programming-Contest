#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct Point
{
	double x,y;
	Point(double A,double B):x(A),y(B){}
	Point operator+(const Point P){return Point(x+P.x,y+P.y);}
	Point operator-(const Point P){return Point(x-P.x,y-P.y);}
	Point operator*(const double p){return Point(x*p,y*p);}
	Point operator/(const double p){return Point(x/p,y/p);}
	Point operator<(const Point P){return x==p.x?y<p.x:x<p.x;}
}p[160050],sq[450];
const double
int n,pn=0;
double cross(double x1,double y1,double x2,double y2){return (x1*y2-x2*y1);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf%lf",&sq[i*4-4].x,&sq[i*4-4].y,&sq[i*4-1].x,&sq[i*4-1].y);
		sq[i*4-3].x=sq[i*4-4].x;
		sq[i*4-3].y=sq[i*4-1].y;
		sq[i*4-2].x=sq[i*4-1].x;
		sq[i*4-2].y=sq[i*4-4].y;
		p[++pn]=sq[i*4-4];
		p[++pn]=sq[i*4-3];
		p[++pn]=sq[i*4-2];
		p[++pn]=sq[i*4-1];
	}
}

