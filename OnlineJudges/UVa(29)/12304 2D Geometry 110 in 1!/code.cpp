/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const double eps=1e-10;
const double Pi=3.1415926535;
typedef struct Poi Vec;
int dcmp(const double &);
struct Poi
{
	double x,y;
	Poi(const double &a=0,const double &b=0):x(a),y(b){}
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &P)const { return Poi(x*P,y*P); }
	Poi operator/(const double &P)const { return Poi(x/P,y/P); }
	bool operator<(const Poi &P)const
	{
		int k=dcmp(x-P.x);
		return !k?dcmp(y-P.y)<=0:k<=0;
	}
};
struct Circle
{
	Poi Pc;
	double r;
	Circle(const Poi &P=Poi(),const double &R=0):Pc(P),r(R){}
	Poi loc(const double &P=0)const { return Poi(Pc.x+cos(P)*r,Pc.y+sin(P)*r); }
};
int dcmp(const double &x) { if(fabs(x)<eps) return 0; return x<0?-1:1; }
double dOt(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y; }
double cRoss(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
double aRea(const Vec &V1,const Vec &V2) { return fabs(cRoss(V1,V2)); }
double lEnth(const Vec &V) { return sqrt(dOt(V,V)); }
double aNgle(const Vec &V1,const Vec &V2) { return acos(dOt(V1,V2)/lEnth(V1)/lEnth(V2)); }
Vec rOtate(const Vec &V,const double &P)
{
	double cOs=cos(P),sIn=sin(P);
	return Vec(V.x*cOs-V.y*sIn,V.y*cOs+V.x*sIn);
}
Poi iNtersect(const Poi &P1,const Vec &V1,const Poi &P2,const Vec &V2)
{ return P1+V1*cRoss(V2,P1-P2)/cRoss(V1,V2); }
Poi pRoject(const Poi &Ps,const Vec &Vs,const Poi &P)
{ return Ps+Vs*dOt(P-Ps,Vs)/dOt(Vs,Vs); }
Vec nOrmal(const Vec &V) { return Vec(-1*V.y,V.x); }
void CCI(const Circle &C1,const Circle &C2,vector<Poi> &ans)
{
	double d=lEnth(C2.Pc-C1.Pc);
	int k=dcmp(d-C1.r-C2.r);
	if(k>0) return;
	double ori=atan2(C2.Pc.y-C1.Pc.y,C2.Pc.x-C1.Pc.x);
	if(!k)
	{
		ans.push_back(C1.loc(ori));
		return;
	}
	double offset=acos((C1.r*C1.r+d*d-C2.r*C2.r)/2./C1.r/d);
	ans.push_back(C1.loc(ori+offset));
	ans.push_back(C1.loc(ori-offset));
	return;
}
void LCI(const Circle &C,const Poi &Ps,const Vec &Vs,vector<Poi> &ans)
{//get intersections of a line and a circle
	double d=aRea(Vs,C.Pc-Ps)/lEnth(Vs);
	int k=dcmp(d-C.r);
	if(k>0) return;
	Poi Pt=pRoject(Ps,Vs,C.Pc);
	if(!k) ans.push_back(Pt);
	else
	{
		double offset=sqrt(C.r*C.r-d*d);
		ans.push_back(Pt-Vs*offset/lEnth(Vs));
		ans.push_back(Pt+Vs*offset/lEnth(Vs));
	}
	return;
}
void CC(const Poi &P1,const Poi &P2,const Poi &P3)
{// get circumscribed circle
	double R;
	Poi P4=(P1+P2)/2,P5=(P1+P3)/2,P;
	P=iNtersect(P4,nOrmal(P1-P2),P5,nOrmal(P1-P3));
	R=lEnth(P1-P);
	printf("(%.6f,%.6f,%.6f)\n",P.x,P.y,R);
	return;
}
void IC(const Poi &P1,const Poi &P2,const Poi &P3)
{// get inscribed circle
	double a=lEnth(P2-P3),b=lEnth(P1-P3),c=lEnth(P1-P2),d;
	Poi O=(P1*a+P2*b+P3*c)/(a+b+c);
	d=aRea(P3-P2,O-P2)/lEnth(P3-P2);
	printf("(%.6f,%.6f,%.6f)\n",O.x,O.y,d);
	return;
}
void TLTP(const Circle &C,const Poi &P)
{// get tangent line through point
	Vec U=P-C.Pc;
	double R=lEnth(U);
	int k=dcmp(R-C.r);
	putchar('[');
	if(k>0)
	{
		double ang=asin(C.r/R),A1,A2;
		Vec Vt=rOtate(U,ang);
		A1=atan2(Vt.y,Vt.x)*180./Pi;
		while(A1<0.) A1+=180.;
		while(A1>=180.) A1-=180.;
		Vt=rOtate(U,-ang);
		A2=atan2(Vt.y,Vt.x)*180./Pi;
		while(A2<0.) A2+=180.;
		while(A2>=180.) A2-=180.;
		if(A1>A2) swap(A1,A2);
		printf("%.6f,%.6f",A1,A2);
	}
	else if(!k)
	{
		Vec Pk=nOrmal(P-C.Pc);
		double K1=atan2(Pk.y,Pk.x)*180./Pi;
		while(K1>=180.) K1-=180.;
		while(K1<0.) K1+=180.;
		printf("%.6f",K1);
	}
	puts("]");
	return;
}
void CTAPATTALWR(const Circle &C,const Poi &Ps,const Vec &Vs)
{// circle through a point and tangent to a line with radius
	double offset=C.r*lEnth(Vs)/Vs.x;
	vector<Poi>ans;
	//for(int i=-1;i<=1;i++) if(i)
	LCI(C,Poi(Ps.x,Ps.y-offset),Vs,ans);
	LCI(C,Poi(Ps.x,Ps.y+offset),Vs,ans);
	sort(ans.begin(),ans.end());
	putchar('[');
	if(ans.size())
	{
		printf("(%.6f,%.6f)",ans[0].x,ans[0].y);
		for(unsigned i=1;i<ans.size();i++)
			printf(",(%.6f,%.6f)",ans[i].x,ans[i].y);
	}
	puts("]");
	return;
}
void CTTTLWR(const Poi &P1,const Vec &V1,const Poi &P2,const Vec &V2,const double &r)
{
	double offset1=r*lEnth(V1)/V1.x,offset2=r*lEnth(V2)/V2.x;
	vector<Poi> ans;
	for(int i=-1;i<=1;i++) if(i)
		for(int j=-1;j<=1;j++) if(j)
			ans.push_back(
					iNtersect(Poi(P1.x,P1.y+offset1*i),V1,Poi(P2.x,P2.y+offset2*j),V2)
					);
	sort(ans.begin(),ans.end());
	putchar('[');
	printf("(%.6f,%.6f)",ans[0].x,ans[0].y);
	for(unsigned i=1;i<ans.size();i++)
		printf(",(%.6f,%.6f)",ans[i].x,ans[i].y);
	puts("]");
	return;
}
void CTTTDCWR(const Circle &C1,const Circle &C2,const double &P)
{
	vector<Poi>ans;
	CCI(Circle(C1.Pc,C1.r+P),Circle(C2.Pc,C2.r+P),ans);
	sort(ans.begin(),ans.end());
	putchar('[');
	if(ans.size()) printf("(%.6f,%.6f)",ans[0].x,ans[0].y);
	for(unsigned i=1;i<ans.size();i++) printf(",(%.6f,%.6f)",ans[i].x,ans[i].y);
	puts("]");
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,c,d,e,f,g,h,i;
	char tex[110];
	while(scanf("%s",tex)!=-1)
	{
		int k=strlen(tex);
		switch(k)
		{
			case 19:
				scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
				CC(Poi(a,b),Poi(c,d),Poi(e,f));
				break;
			case 15:
				scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
				IC(Poi(a,b),Poi(c,d),Poi(e,f));
				break;
			case 23:
				scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
				TLTP(Circle(Poi(a,b),c),Poi(d,e));
				break;
			case 46:
				scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
			 	CTAPATTALWR(Circle(Poi(a,b),g),Poi(c,d),Vec(e-c,f-d));
				break;
			case 33:
				scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i);
				CTTTLWR(Poi(a,b),Vec(c-a,d-b),Poi(e,f),Vec(g-e,h-f),i);
				break;
			case 43:
				scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
				CTTTDCWR(Circle(Poi(a,b),c),Circle(Poi(d,e),f),g);
				break;
			default: break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

