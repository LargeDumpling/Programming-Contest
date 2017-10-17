/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-10;
int dcmp(double x) { if(fabs(x)<eps) return 0; return x<0?-1:1; }
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
	//{ return !dcmp(x-P.x)?dcmp(y-P.y)<=0:dcmp(x-P.x)<=0; }
	{ return x==P.x?y<P.y:x<P.x; }
}SP[400050],sp[400050];
double dOt(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y; }
double cRoss(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
double sQr(const Vec &V) { return dOt(V,V); }
int n,Pn,nPn;
int Andrew(Poi *A,int N,Poi *B)
{
	int m=0;
	sort(A,A+N);
	for(int i=0;i<N;B[m++]=A[i++])
		while(m>1&&cRoss(B[m-1]-B[m-2],A[i]-B[m-2])<=0)m--;
	for(int i=N-2,k=m;i>=0;B[m++]=A[i--])
		while(m>k&&cRoss(B[m-1]-B[m-2],A[i]-B[m-2])<=0)m--;
	if(N>1) m--;
	B[m]=B[0];
	return m;
}
int ShamoS(int N,Poi *P)
{
	int r=1,ans=0,d;
	if(N==1) return 0;
	else if(N==2) return sQr(P[0]-P[1]);
	for(int l=0;l<N;r=(r+1)%N)
	{
		d=dcmp(cRoss(P[l+1]-P[l],P[r+1]-P[r]));
		if(d>0) continue;
		ans=max(ans,(int)sQr(P[r--]-P[l++]));
		if(!d) ans=max(ans,(int)sQr(P[r+1]-P[l]));
	}
	return ans;
}
int SHAMOS(int N,Poi *P)
{
	int ans=0;
	if(N==1) return 0;
	else if(N==2) return sQr(P[0]-P[1]);
	for(int u=0,v=1;u<N;u++) while(true)
	{
		int d=cRoss(P[u+1]-P[u],P[v+1]-P[v]);
		if(d<=0)
		{
			ans=max(ans,(int)sQr(P[u]-P[v]));
			if(d==0) ans=max(ans,(int)sQr(P[u]-P[v+1]));
			break;
		}
		v=(v+1)%N;
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T;
	double a,b,c;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		Pn=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf",&a,&b,&c);
			SP[Pn++]=Poi(a,b);
			SP[Pn++]=Poi(a+c,b);
			SP[Pn++]=Poi(a,b+c);
			SP[Pn++]=Poi(a+c,b+c);
		}
		nPn=Andrew(SP,Pn,sp);
		printf("%d\n",ShamoS(nPn,sp));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

