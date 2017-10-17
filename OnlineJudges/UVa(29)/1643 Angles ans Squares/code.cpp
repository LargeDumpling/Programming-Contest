/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double e=1e-7;
struct Poi
{
	double x,y;
	Poi(double A=0,double B=0):x(A),y(B){}
	Poi operator+(Poi X)const{return Poi(x+X.x,y+X.y);}
	Poi operator-(Poi X)const{return Poi(x-X.x,y-X.y);}
	Poi operator*(double P)const{return Poi(x*P,y*P);}
	double operator*(Poi X)const{return x*X.y-y*X.x;}
	bool operator==(Poi X)const{return abs(x-X.x)<=e&&abs(y-X.y)<=e;}
}A,B,st,ed,tA,tB;
double dOt(Poi A,Poi B){return A.x*B.x+A.y*B.y;}
double lEnth(Poi A){return sqrt(dOt(A,A));}
int n;
double len[15],Bb,alen,ans;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(scanf("%d",&n)!=-1&&n)
	{
		alen=ans=0;
		scanf("%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&len[i]);
			alen+=len[i]*1.4142135623730951;
		}
		if(A.y/A.x<B.y/B.x)swap(A,B);
		tA=Poi(A.x/(A.x+A.y),A.y/(A.x+A.y));
		tB=Poi(B.x/(B.x+B.y),B.y/(B.x+B.y));
		Bb=alen/lEnth(tA-tB);
		A=tA*Bb;
		B=tB*Bb;
		Poi it=A;
		for(int i=1;i<=n;i++)
		{
			ans+=it*Poi(it.x,it.y-len[i]);
			it.y-=len[i];
			ans+=it*Poi(it.x+len[i],it.y);
			it.x+=len[i];
		}
		printf("%.3lf\n",ans/-2.);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
