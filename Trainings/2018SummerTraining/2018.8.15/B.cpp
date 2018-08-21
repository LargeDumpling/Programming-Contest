/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-15	File created.
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
const double INF=50000000.;
int T_T;
inline int dcmp(const double &x)
{
	if(fabs(x)<=eps) return 0;
	return x<0?-1:1;
}
typedef struct Poi Vec;
struct Poi
{
	double x,y;
	Poi(const double &X=0.,const double &Y=0.):x(X),y(Y) { }
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
}P[3],P0,P1,P2;
double dot(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y; }
double lenth(const Vec &V) { return sqrt(dot(V,V)); }
double norm(const double &X)
{
	double x=min(fabs(X),1.);
	return X<0?-x:x;
}
Vec rotate(const Vec &V,const double &p)
{
	double co=cos(p),si=sin(p);
	return Vec(V.x*co-V.y*si,V.x*si+V.y*co);
}
double w,ans,fl,ce,le,ri;
int main()
{
	//freopen("in.txt","r",stdin);
	int limit;
	double l1,l2,t[5],the;
	scanf("%d",&T_T);
	while(T_T--)
	{
		ans=INF;
		for(int i=0;i<3;i++)
			scanf("%lf%lf",&P[i].x,&P[i].y);
		scanf("%lf",&w);
		for(int i=0;i<3;i++)
		{
			P0=P[i];
			P1=P[(i+1)%3];
			P2=P[(i+2)%3];
			l1=lenth(P1-P0);
			l2=lenth(P2-P0);
			the=acos(norm(dot(P1-P0,P2-P0)/l1/l2));
			t[0]=0;
			if(dcmp(l1-w)<=0) limit=1;
			else
			{
				limit=5;
				t[1]=acos(norm(w/l1));
				t[2]=Pi-t[1];
				t[3]=t[1]+Pi;
				t[4]=t[2]+Pi;
			}
			for(int j=0;j<limit;j++)
			{
				fl=ce=P0.y;
				le=ri=P0.x;
				P1=P0+rotate(Vec(l1,0),t[j]);
				P2=P0+rotate(Vec(l2,0),t[j]+the);
				fl=min(fl,P1.y);
				fl=min(fl,P2.y);
				ce=max(ce,P1.y);
				ce=max(ce,P2.y);
				le=min(le,P1.x);
				le=min(le,P2.x);
				ri=max(ri,P1.x);
				ri=max(ri,P2.x);
				if(dcmp(ri-le-w)<=0)
				{
					ans=min(ans,ce-fl);
					//printf("%d\n%d\n%lf %lf\n%lf %lf\n%lf %lf\n%lf\n",i,j,P0.x,P0.y,P1.x,P1.y,P2.x,P2.y,ans);
				}
			}
		}
		if(!dcmp(ans-INF)) puts("impossible");
		else printf("%.9lf\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

