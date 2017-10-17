/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-16	File created.
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
	bool operator<(const Poi &P)const
	{ return !dcmp(x-P.x)?dcmp(y-P.y)<=0:dcmp(x-P.x)<=0; }
}M[505],C[505],MM[505],CC[505];
double dOt(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y; }
double cRoss(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
int Mn,Cn;
int Andrew(Poi *A,const int &N,Poi *B)
{
	int m=0;
	sort(A,A+N);
	for(int i=0;i<N;B[m++]=A[i++])
		while(m>1&&dcmp(cRoss(B[m-1]-B[m-2],A[i]-B[m-2]))<=0) m--;
	for(int i=N-2,k=m;i>=0;B[m++]=A[i--])
		while(m>k&&dcmp(cRoss(B[m-1]-B[m-2],A[i]-B[m-2]))<=0) m--;
	if(N>1) m--;
	B[m]=B[0];
	return m;
}
bool inPoly(Poi *A,const int &N,const Poi &P)
{
	for(int i=0;i<N;i++)
		if(dcmp(cRoss(A[(i+1)%N]-A[i],P-A[i]))<0) return false;
	return true;
}
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
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int nMn,nCn;
	bool flag;
	while(scanf("%d%d",&Mn,&Cn)!=-1&&Mn&&Cn)
	{
		for(int i=0;i<Mn;i++) scanf("%lf%lf",&M[i].x,&M[i].y);
		for(int i=0;i<Cn;i++) scanf("%lf%lf",&C[i].x,&C[i].y);
		nMn=Andrew(M,Mn,MM);
		nCn=Andrew(C,Cn,CC);
		flag=true;
		for(int i=0;i<nMn&&nCn>2&&flag;i++)
			if(inPoly(CC,nCn,MM[i]))//至少为3才能形成多边形
				flag=false;
		for(int i=0;i<nCn&&nMn>2&&flag;i++)
			if(inPoly(MM,nMn,CC[i]))
				flag=false;
		for(int i=0;i<nMn&&nMn>=2&&nCn>=2&&flag;i++)//至少为2才能形成线段
			for(int j=0;j<nCn&&flag;j++)
				if(segI(MM[i],MM[i+1],CC[j],CC[j+1]))
					flag=false;
		//for(int i=0;i<=Mn;i++) M[i]=MM[i]=Poi();
		//for(int i=0;i<=Cn;i++) C[i]=CC[i]=Poi();
		if(flag) puts("Yes");
		else puts("No");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

