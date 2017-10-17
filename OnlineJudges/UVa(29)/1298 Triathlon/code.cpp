/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-18	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-10;
int dcmp(const double &x) { if(fabs(x)<eps) return 0; return x<0?-1:1; }
typedef struct Poi Vec;
struct Poi
{
	double x,y;
	Poi(const double &a=0,const double &b=0):x(a),y(b){}
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &P)const { return Poi(x*P,y*P); }
	Poi operator/(const double &P)const { return Poi(x/P,y/P); }
}pol[105];
struct Line
{
	Poi Ps,Dir;
	double ang;
	Line(const Poi ps=Poi(),const Vec dir=Vec(1,0)):Ps(ps),Dir(dir)
	{ ang=atan2(dir.y,dir.x); }
	bool operator<(const Line &L)const { return ang<L.ang; }
}lines[105];
double dOt(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y; }
double cRoss(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
Poi iNtersect(const Poi &P1,const Vec &V1,const Poi &P2,const Vec &V2)
{ return P1+V1*cRoss(P1-P2,V2)/cRoss(V2,V1); }
Poi iNtersect(const Line &L1,const Line &L2)
{ return iNtersect(L1.Ps,L1.Dir,L2.Ps,L2.Dir); }
int HPI(Line *L,int N,Poi *Pol)
{
	int l,r;
	Poi IP[N+50]; Line q[N+50];
	sort(L,L+N);
	q[l=r=0]=L[0];
	for(int i=1;i<N;i++)
	{
		while(l<r&&dcmp(cRoss(L[i].Dir,IP[r-1]-L[i].Ps))<=0) r--;
		while(l<r&&dcmp(cRoss(L[i].Dir,IP[l]-L[i].Ps))<=0) l++;
		q[++r]=L[i];
		if(!dcmp(cRoss(q[r].Dir,q[r-1].Dir)))
		{
			r--;
			if(dcmp(cRoss(q[r+1].Dir,q[r].Ps-q[r+1].Ps))<0) q[r]=q[r+1];
		}
		if(l<r) IP[r-1]=iNtersect(q[r-1],q[r]);
	}
	while(l<r&&dcmp(cRoss(q[l].Dir,IP[r-1]-q[l].Ps))<=0) r--;
	if(r-l<2) return 0;
	IP[r]=iNtersect(q[l],q[r]);
	int m=0;
	for(int i=l;i<=r;i++) Pol[m++]=IP[i];
	return m;
}
double sv[105],bv[105],rv[105],A,B,C;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,PN;
	bool flag;
	const double K=10000.;
	while(scanf("%d",&n)!=-1&&n)
	{
		for(int i=0;i<n;i++) scanf("%lf%lf%lf",&sv[i],&bv[i],&rv[i]);
		for(int i=0;i<n;i++)
		{
			flag=true; PN=0;
			for(int j=0;j<n;j++) if(i!=j)
			{
				if(sv[i]<=sv[j]&&bv[i]<=bv[j]&&rv[i]<=rv[j]) { flag=false; break; }
				else if(sv[i]>sv[j]&&bv[i]>bv[j]&&rv[i]>rv[j]) continue;
				C=10000./rv[j]-10000/rv[i];
				A=(10000./sv[j]-10000/sv[i])-C;
				B=(10000./bv[j]-10000/bv[i])-C;
				//A=(K/bv[j]-K/rv[j])-(K/bv[i]-K/rv[i]);
				//B=(K/sv[j]-K/rv[j])-(K/sv[i]-K/rv[i]);
				//C=K/rv[j]-K/rv[i];
				Poi D=Vec(B,-A),E;
				if(fabs(A)>fabs(B)) E=Poi(-C/A,0);
				else E=Poi(0,-C/B);
				lines[PN++]=Line(E,D);
			}
			if(flag)
			{
				lines[PN++]=Line(Poi(0.,0.),Vec(0.,-1.));
				lines[PN++]=Line(Poi(0.,0.),Vec(1.,0.));
				lines[PN++]=Line(Poi(0.,1.),Vec(-1.,1.));
				if(!HPI(lines,PN,pol)) flag=false;
			}
			if(flag) puts("Yes"); else puts("No");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

