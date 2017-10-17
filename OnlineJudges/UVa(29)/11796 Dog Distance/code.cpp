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
int dcmp(const double&x);
typedef struct Poi Vec;
struct Poi
{
	double x,y;
	Poi(const double &a=0,const double &b=0):x(a),y(b){}
	Poi operator+(const Poi &P) { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P) { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &P) { return Poi(x*P,y*P); }
	Poi operator/(const double &P) { return Poi(x/P,y/P); }
	bool operator==(const Poi &P) { return !dcmp(x-P.x)&&!dcmp(y-P.y); }
	friend istream& operator>>(istream &in,Poi &P) { in>>P.x>>P.y; return in; }
}A[55],B[55],PA,PB;
int dcmp(const double &x) { if(fabs(x)<eps) return 0; return x<0?-1:1; }
double mAx(const double &a=0,const double &b=0) { return a<b?b:a; }
double mIn(const double &a=0,const double &b=0) { return a<b?a:b; }
double dOt(Vec V1,Vec V2) { return V1.x*V2.x+V1.y*V2.y; }
double cRoss(Vec V1,Vec V2) { return V1.x*V2.y-V1.y*V2.x; }
double lEnth(Vec V) { return sqrt(dOt(V,V)); }
double dIsttoseg(Poi P,Poi P1,Poi P2)
{
	if(P1==P2) return lEnth(P-P1);
	Vec V1=P2-P1,V2=P-P1,V3=P-P2;
	if(dcmp(dOt(V1,V2))<=0) return lEnth(V2);
	if(dcmp(dOt(V1,V3))>=0) return lEnth(V3);
	return fabs(cRoss(V1,V2))/lEnth(V1);
}
double maX,miN;
void updata(Poi A,Poi P,Poi B,Poi C)
{
	C=C-P+A;
	miN=mIn(miN,dIsttoseg(A,B,C));
	maX=mAx(maX,lEnth(B-A));
	maX=mAx(maX,lEnth(C-A));
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T,An,Bn,Sa,Sb;
	double La,Lb,LenA,LenB,T;
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		scanf("%d%d",&An,&Bn);
		for(int i=0;i<An;i++) cin>>A[i];
		for(int i=0;i<Bn;i++) cin>>B[i];
		LenA=LenB=0;
		maX=-1e9; miN=1e9;
		for(int i=0;i<An-1;i++) LenA+=lEnth(A[i+1]-A[i]);
		for(int i=0;i<Bn-1;i++) LenB+=lEnth(B[i+1]-B[i]);
		PA=A[Sa=0]; PB=B[Sb=0];
		while(Sa<An-1&&Sb<Bn-1)
		{
			La=lEnth(A[Sa+1]-PA);
			Lb=lEnth(B[Sb+1]-PB);
			T=min(La/LenA,Lb/LenB);
			Vec Va=(A[Sa+1]-PA)/La*T*LenA,Vb=(B[Sb+1]-PB)/Lb*T*LenB;
			updata(PA,PA+Va,PB,PB+Vb);
			PA=PA+Va;
			PB=PB+Vb;
			if(PA==A[Sa+1]) Sa++;
			if(PB==B[Sb+1]) Sb++;
		}
		printf("Case %d: %.0f\n",cAse,maX-miN);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

