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
	{ return !dcmp(x-P.x)?dcmp(y-P.y)<=0:x<P.x; }
}H[10050],HH[10050];
double dOt(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y; }
double cRoss(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
double lEnth(const Vec &V) { return sqrt(dOt(V,V)); }
int n;
double ax,ay;
void calc(const Poi &P,const Vec &V,double &A,double &B,double &C)
{ A=V.y; B=-V.x; C=cRoss(V,P); }
int Andrew(Poi *A,int N,Poi *B)
{
	int m=0;
	sort(A,A+N);
	for(int i=0;i<N;B[m++]=A[i++])
		while(m>1&&dcmp(cRoss(B[m-1]-B[m-2],A[i]-B[m-2]))<=0) m--;
	for(int i=n-2,k=m;i>=0;B[m++]=A[i--])
		while(m>k&&dcmp(cRoss(B[m-1]-B[m-2],A[i]-B[m-2]))<=0) m--;
	return N>1?m-1:m;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T,An;
	double A,B,C,ans;
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		scanf("%d",&n);
		ax=ay=0;
		ans=1e10;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&H[i].x,&H[i].y);
			ax+=H[i].x; ay+=H[i].y;
		}
		An=Andrew(H,n,HH);
		if(An<=2) ans=0;
		else for(int i=0;i<An;i++)
		{
			calc(HH[i],HH[(i+1)%An]-HH[i],A,B,C);
			ans=min(ans,fabs(A*ax+B*ay+C*n)/sqrt(A*A+B*B));
		}
		printf("Case #%d: %.3f\n",cAse,ans/n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

