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
const double eps=1e-10;
int dcmp(double);
typedef struct Poi Vec;
struct Poi
{
	double x,y;
	Poi(const double &a=0,const double &b=0):x(a),y(b){}
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &P)const { return Poi(x*P,y*P); }
	Poi operator/(const double &P)const { return Poi(x/P,y/P); }
	bool operator<(const Poi &P)const
	{ return !dcmp(x-P.x)?dcmp(y-P.y)<=0:dcmp(x-P.x)<=0; }
	bool operator==(const Poi &P)const { return !dcmp(x-P.x)&&!dcmp(y-P.y); }
	friend istream& operator>>(istream &in,Poi &P) { in>>P.x>>P.y; return in; }
}V[90050],P[350];
int dcmp(double x) { if(fabs(x)<eps) return 0; else return x<0?-1:1; }
double dOt(Vec V1,Vec V2) { return V1.x*V2.x+V1.y*V2.y; }
double cRoss(Vec V1,Vec V2) { return V1.x*V2.y-V1.y*V2.x; }
double lEnth(Vec V) { return sqrt(dOt(V,V)); }
Poi iNtersect(Poi P1,Vec V1,Poi P2,Vec V2)
{ return P1+V1*cRoss(P1-P2,V2)/cRoss(V2,V1); }
bool cHeck(Poi P1,Poi P2,Poi P3,Poi P4)
{
	Vec P12=P2-P1,P34=P4-P3;
	int k1=(dcmp(cRoss(P3-P1,P12))^dcmp(cRoss(P4-P1,P12)));
	int k2=(dcmp(cRoss(P2-P3,P34))^dcmp(cRoss(P1-P3,P34)));
	return k1==-2&&k2==-2;
}
bool onSegment(Poi P,Poi A,Poi B)
{ return !dcmp(cRoss(A-P,B-P))&&dcmp(dOt(A-P,B-P))<0; }
int n,e,v;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int q;
	for(int T_T=1;scanf("%d",&n)!=-1&&n;T_T++)
	{
		for(int i=0;i<n;i++) { cin>>P[i]; V[i]=P[i]; }
		e=v=--n;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(cHeck(P[i],P[i+1],P[j],P[j+1]))
				V[v++]=iNtersect(P[i],P[i+1]-P[i],P[j],P[j+1]-P[j]);
		sort(V,V+v);
		v=unique(V,V+v)-V;
		for(int i=0;i<v;i++)
			for(int j=0;j<n;j++)
				if(onSegment(V[i],P[j],P[j+1]))
					e++;
		printf("Case %d: There are %d pieces.\n",T_T,2+e-v);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

