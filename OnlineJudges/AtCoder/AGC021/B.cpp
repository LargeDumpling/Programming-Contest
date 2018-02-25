/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-24	File created.
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
int N;
double R=1e30;
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
}P[105],AP[105],BJ[4],Q[10],QQ[10];
int Qn,QQn;
struct Line
{
	Poi Ps; Vec Dir;
	double ang;
	Line(const Poi &ps=Poi(),const Vec &dir=Vec()):Ps(ps),Dir(dir)
	{ ang=atan2(Dir.y,Dir.x); }
	bool operator<(const Line &L1)const { return ang<L1.ang; }
};
double dOt(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y; }
double cRoss(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
double lEnth(const Vec V) { return sqrt(dOt(V,V)); }
Vec rOtate(const Vec &V,const double &P)
{ double cOs=cos(P),sIn=sin(P); return Vec(V.x*cOs-V.y*sIn,V.x*sIn+V.y*cOs); }
double aNgle(const Vec &V1,const Vec &V2) { return acos(dOt(V1,V2)/lEnth(V1)/lEnth(V2)); }
Poi iNtersect(const Poi &P1,const Vec &V1,const Poi &P2,const Vec &V2)
{ return P1+V1*(cRoss(V2,P1-P2)/cRoss(V1,V2)); }
Poi iNtersect(const Line &L1,const Line &L2)
{ return iNtersect(L1.Ps,L1.Dir,L2.Ps,L2.Dir); }
bool onseg(const Poi &A,const Poi &B,const Poi &P)
{
	Vec PA=A-P,PB=B-P;
	if(!dcmp(cRoss(PA,PB))&&dcmp(dOt(PA,PB))<=0) return true;
	return false;
}
bool segI(const Poi &A,const Poi &B,const Poi &C,const Poi &D)
{
	if(onseg(A,B,C) ||onseg(A,B,D) ||onseg(C,D,A) ||onseg(C,D,B)) return true;
	if((dcmp(cRoss(B-C,D-C))^dcmp(cRoss(A-C,D-C)))==-2
			&&(dcmp(cRoss(D-B,A-B))^dcmp(cRoss(C-B,A-B)))==-2) return true;
	return false;
}
int Andrew(Poi *A,int N,Poi *B)
{
	int m=0;
	sort(A,A+N);
	for(int i=0;i<N;B[m++]=A[i++])
		while(m>1&&cRoss(B[m-1]-B[m-2],A[i]-B[m-2])<=0) m--;
	for(int i=N-2,k=m;i>=0;B[m++]=A[i--])
		while(m>k&&cRoss(B[m-1]-B[m-2],A[i]-B[m-2])<=0) m--;
	if(N>1) m--;
	B[m]=B[0];
	return m;
}
double ans[105];
int main()
{
	int n;
	bool exist[4],flag;
	BJ[0].x=R; BJ[0].y=R;
	BJ[1].x=R; BJ[1].y=-R;
	BJ[2].x=-R; BJ[2].y=R;
	BJ[3].x=-R; BJ[3].y=-R;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%lf%lf",&P[i].x,&P[i].y);
	n=Andrew(P,N,AP);
	for(int i=0;i<n;i++)
	{
		memset(exist,true,sizeof(exist));
		Qn=0;
		Poi P1=P[i]+(P[(i-1+n)%n]-P[i])/2;
		Poi P2=P[i]+(P[(i+1)%n]-P[i])/2;
		Line L1=Line(P1,rOtate(P[(i-1+n)%n]-P[i],Pi/2.));
		Line L2=Line(P2,rOtate(P[(i+1)%n]-P[i],Pi/2.));
		Q[Qn++]=iNtersect(L1,L2);
		for(int j=0;j<4;j++)
		{
			flag=true;
			Poi P3=L1.Ps+L1.Dir*1e100;
			Poi P4=L1.Ps-L1.Dir*1e100;
			if(segI(P[i],BJ[j],P3,P4))
				flag=false;
			if(segI(BJ[j],BJ[(j+1)%4],P3,P4))
			{
				Q[Qn++]=iNtersect(L1,Line(BJ[j],BJ[(j+1)%4]-BJ[j]));
				if(segI(P[i],Q[Qn-1],P1+(P2-P1)*1e100,P1-(P2-P1)*1e100))
					Qn--;
			}
			P3=L2.Ps+L2.Dir*1e100;
			P4=L2.Ps-L2.Dir*1e100;
			if(segI(P[i],BJ[j],P3,P4))
				flag=false;
			if(segI(BJ[j],BJ[(j+1)%4],P3,P4))
			{
				Q[Qn++]=iNtersect(L2,Line(BJ[j],BJ[(j+1)%4]-BJ[j]));
				if(segI(P[i],Q[Qn-1],P1+(P2-P1)*1e100,P1-(P2-P1)*1e100))
					Qn--;
			}
			if(flag) Q[Qn++]=BJ[j];
		}
		QQn=Andrew(Q,Qn,QQ);
		for(int i=0;i<QQn;i++)
			ans[i]+=cRoss(QQ[i],QQ[(i+1)%QQn]);
	}
	for(int i=0,j;i<N;i++)
	{
		for(j=0;j<N;j++)
			if(P[i]==AP[j])
				break;
	}
}

