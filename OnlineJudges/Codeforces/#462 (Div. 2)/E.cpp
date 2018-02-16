/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-12;
inline int cmp(const double &x)
{
	if(fabs(x)<=eps) return 0;
	return x<0?-1:1;
}
double offset()
{
	double x=(double)rand()/RAND_MAX;
	if(rand()%2) x=-x;
	return x;
}
struct Poi
{
	double x,y;
	Poi(const double &X=0,const double &Y=0):x(X),y(Y) { }
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &P)const { return Poi(x*P,y*P); }
	Poi operator/(const double &P)const { return Poi(x/P,y/P); }
	bool operator<(const Poi &P)const { return !cmp(x-P.x)?cmp(y-P.y)<0:cmp(x-P.x)<0; }
	bool operator==(const Poi &P)const { return !cmp(x-P.x)&&!cmp(y-P.y); }
};
struct Cir
{
	Poi P;
	int cnt;
	double r;
	Cir(const Poi &PP=Poi(),const double &R=0):P(PP),r(R) { cnt=0; }
	Poi get(const double &x) { return P+Poi(r*cos(x),r*sin(x)); }
}C[3];
int n,f[3];
int fInd(int x)
{
	if(f[x]!=f[f[x]]) f[x]=fInd(f[x]);
	return f[x];
}
void mErge(int a,int b)
{
	a=fInd(a); b=fInd(b);
	f[b]=a;
	return;
}
void inserct(const Cir &C1,const Cir &C2)
{
}
int main()
{
	int V=0,E=0,Cn=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		scanf("%lf%lf%lf",&C[i].P.x,&C[i].P.y,&C[i].r);
		C[i].P.x+=offset();
		C[i].P.y+=offset();
		C[i].r+=offset();
		for(int j=1;j<i;j++)
			inserct(C[i],C[j]);
	}
	for(int i=1;i<=n;i++)
	{
		if(fInd(i)==i) Cn++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

