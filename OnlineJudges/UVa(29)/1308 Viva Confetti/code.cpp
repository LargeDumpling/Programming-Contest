/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const double eps=1.*(1e-13);
const double Pi=acos(-1.);
typedef struct Poi Vec;
struct Poi
{
	double x,y;
	Poi(const double &a=0,const double &b=0):x(a),y(b){}
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &P)const { return Poi(x*P,y*P); }
	Poi operator/(const double &P)const { return Poi(x/P,y/P); }
};
double dOt(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y;}
double cRoss(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x;}
double lEnth(const Vec V) { return sqrt(dOt(V,V)); }
int dcmp(const double &x) { if(fabs(x)<eps) return 0; return x<0?-1:1; }
struct Circle
{
	Poi Pc;
	double r;
	Circle(const Poi &P=Poi(),const double &R=0):Pc(P),r(R){}
	Poi loc(double ang,double offset)
	{ return Poi(Pc.x+cos(ang)*(r+offset),Pc.y+sin(ang)*(r+offset)); }
}C[105];
int n;
int topmost(Poi P)
{ for(int i=n;i;i--) if(lEnth(P-C[i].Pc)<C[i].r) return i; return -1; }
double Normalize(double rad)
{ return rad-2*Pi*floor(rad/(2.*Pi)); }
void CCI(Circle C1,Circle C2,vector<double> &ans)
{
	Vec V=C2.Pc-C1.Pc;
	double d1=lEnth(V);
	if(!dcmp(d1)) return;
	if(dcmp(d1-fabs(C1.r-C2.r))==-1) return;//ƒ⁄∫¨
	else if(dcmp(d1-C1.r-C2.r)==1) return;//Õ‚¿Î
	double ori=atan2(V.y,V.x),ang,tem;
	ang=acos((C1.r*C1.r+d1*d1-C2.r*C2.r)/(2.*C1.r*d1));
	tem=ori+ang;
	ans.push_back(Normalize(tem));
	if(!dcmp(ang)) return;
	tem=ori-ang+2.*Pi;
	ans.push_back(Normalize(tem));
	return;
}
void CCII(Circle C1,Circle C2,vector<double> &ans)
{
	Vec V=C2.Pc-C1.Pc;
	double d=lEnth(V);
	if(!dcmp(d)) return;
	if(dcmp(d-C1.r-C2.r)==1) return;
	if(dcmp(d-fabs(C1.r-C2.r))==-1) return;

	double ori=atan2(V.y,V.x),ang=acos((C1.r*C1.r+d*d-C2.r*C2.r)/(2.*C1.r*d));
	ans.push_back(Normalize(ori+ang));
	ans.push_back(Normalize(ori-ang));
}
bool visi[105];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	double mid;
	int k;//,cnt=0;
	while(scanf("%d",&n)!=-1&&n)
	{
		//printf("%d\n",++cnt);
		memset(visi,false,sizeof(visi));
		for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&C[i].Pc.x,&C[i].Pc.y,&C[i].r);
		for(int i=1;i<=n;i++)
		{
			vector<double>rad;
			rad.push_back(0.);
			rad.push_back(Pi*2.);
			for(int j=1;j<=n;j++)
				CCI(C[i],C[j],rad);
			sort(rad.begin(),rad.end());
			//for(unsigned j=0;j<rad.size();j++) printf("%.6f ",rad[j]);
			//putchar('\n');
			for(unsigned j=0;j<rad.size();j++)
			{
				mid=(rad[j]+rad[j+1])/2.;
				k=topmost(C[i].loc(mid,eps));
				if(k>=0) visi[k]=true;
				k=topmost(C[i].loc(mid,-1*eps));
				if(k>=0) visi[k]=true;
			}
		}
		k=0;
		for(int i=1;i<=n;i++) if(visi[i]) k++;
		printf("%d\n",k);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

