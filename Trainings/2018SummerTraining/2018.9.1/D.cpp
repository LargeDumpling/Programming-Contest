/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
const double eps=1e-10;
int dcmp(const double &x) { if(fabs(x)<eps) return 0; return x<0?-1:1; }
typedef struct Poi Vec;
struct Poi
{
	double x,y;
	Poi(const double &a=0,const double &b=0):x(a),y(b) { }
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &P)const { return Poi(x*P,y*P); }
	Poi operator/(const double &P)const { return Poi(x/P,y/P); }
	bool operator<(const Poi &P)const { return !dcmp(x-P.x)?dcmp(y-P.y)<=0:dcmp(x-P.x)<=0; }
}PP[MAXN],NP[MAXN<<1],IP[MAXN];
struct Line
{
	Poi Ps; Vec Dir;
	double ang;
	Line(const Poi &ps=Poi(),const Vec &dir=Vec()):Ps(ps),Dir(dir) { ang=atan2(Dir.y,Dir.x); }
	bool operator<(const Line &L1)const { return ang<L1.ang; }
}lines[MAXN],q[MAXN];
double dOt(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y; }
double cRoss(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
double lEnth(const Vec V) { return sqrt(dOt(V,V)); }
Vec Normal(const Vec &V) { return Vec(-V.y,V.x); }
Poi iNtersect(const Poi &P1,const Vec &V1,const Poi &P2,const Vec &V2)
{ return P1+V1*(cRoss(V2,P1-P2)/cRoss(V1,V2)); }
Poi iNtersect(const Line &L1,const Line &L2)
{ return iNtersect(L1.Ps,L1.Dir,L2.Ps,L2.Dir); }
int HPI(Line *L,int N,Poi *Pol)
{
	int l,r,m=0;
	sort(L,L+N);//按极角排序
	q[l=r=0]=L[0];
	for(int i=1;i<N;i++)
	{
		while(l<r&&dcmp(cRoss(L[i].Dir,IP[r-1]-L[i].Ps))<=0) r--; //新加入的直线可能是尾部的一些交点失效
		while(l<r&&dcmp(cRoss(L[i].Dir,IP[l]-L[i].Ps))<=0) l++; //首部
		q[++r]=L[i]; //加入
		if(!dcmp(cRoss(q[r].Dir,q[r-1].Dir)))
		{ //对于平行直线要取靠左的
			r--;
			if(dcmp(cRoss(q[r+1].Dir,q[r].Ps-q[r+1].Ps))<0) q[r]=q[r+1];
		}
		if(l<r) IP[r-1]=iNtersect(q[r-1],q[r]); //如果队列中有至少两条线，则取交点
	}
	while(l<r&&dcmp(cRoss(q[l].Dir,IP[r-1]-q[l].Ps))<=0) r--; //后面一些交点可能实际上是无用的
	if(r-l<2) return 0; //如果只有不到两条线，则失败了
	IP[r]=iNtersect(q[l],q[r]); //将最后一条线和第一条线交起来
	for(int i=l;i<=r;i++) Pol[m++]=IP[i];
	Pol[m]=Pol[0];
	return m;
}
double area(const Poi &P1,const Poi &P2,const Poi &P3)
{
	return fabs(cRoss(P3-P1,P2-P1));
}
double calc(int n,Poi *P)
{
	int l,r,mid1,mid2,tem;
	double ans=0;
	for(int i=0;i<=n;i++)
		P[i+n]=P[i];
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			l=i; r=j;
			while(l<r-1)
			{
				tem=(r-l+1)/3;
				mid1=l+tem;
				mid2=r-tem;
				if(area(P[i],P[j],P[mid1])<area(P[i],P[j],P[mid2])) l=mid1;
				else r=mid2;
			}
			ans=max(ans,max(area(P[i],P[j],P[l]),area(P[i],P[j],P[r])));
			l=j; r=i+n;
			while(l<r-1)
			{
				tem=(r-l+1)/3;
				mid1=l+tem;
				mid2=r-tem;
				if(area(P[i],P[j],P[mid1])<area(P[i],P[j],P[mid2])) l=mid1;
				else r=mid2;
			}
			ans=max(ans,max(area(P[j],P[i+n],P[l]),area(P[j],P[i+n],P[r])));
		}
	return ans;
}
int main()
{
	int T_T,n,m;
	double r;
	Vec Nv;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%lf",&n,&r);
		for(int i=0;i<n;i++) scanf("%lf%lf",&PP[n-i-1].x,&PP[n-i-1].y);
		PP[n]=PP[0];
		for(int i=0;i<n;i++)
		{
			Nv=Normal(PP[i+1]-PP[i]);
			Nv=Nv/lEnth(Nv);
			lines[i]=Line(PP[i]+Nv*r,PP[i+1]-PP[i]);
		}
		m=HPI(lines,n,NP);
		printf("%lf\n",calc(m,NP));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

