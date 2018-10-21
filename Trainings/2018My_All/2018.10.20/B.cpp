/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define sqr(x) ((x)*(x))
using namespace std;
const int MAXN=1050;
const double eps=1e-6;
typedef struct Poi Vec;
int dcmp(const double &x)
{
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
struct Poi
{
	double x,y;
	Poi(const double &X=0,const double &Y=0):x(X),y(Y) { }
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &p)const { return Poi(x*p,y*p); }
	Poi operator/(const double &p)const { return Poi(x/p,y/p); }
}C[MAXN],I[MAXN*MAXN];
int T_T,n,m,In,ans;
double R[MAXN],S[MAXN];
double dot(const Vec &A,const Vec &B) { return A.x*B.x+A.y*B.y; }
double lenth(const Vec &V) { return sqrt(dot(V,V)); }
Vec Rotate(const Vec &V,const double &the)
{
	double Cos=cos(the),Sin=sin(the);
	return Vec(Cos*V.x-Sin*V.y,Sin*V.x+Cos*V.y);
}
void inters(int a,int b)
{
	Vec AB=C[b]-C[a],E;
	double l=lenth(AB),the;
	E=AB/l;
	if(dcmp(R[a]+R[b]-l)<0||dcmp(R[a]+l-R[b])<0||dcmp(R[b]+l-R[a])<0) return;
	if(!dcmp(R[a]+R[b]-l))
	{
		I[++In]=C[a]+E*R[a];
		return;
	}
	the=acos((sqr(R[a])+sqr(l)-sqr(R[b]))/(2.*R[a]*l));
	I[++In]=C[a]+Rotate(E,the)*R[a];
	I[++In]=C[a]+Rotate(E,-the)*R[a];
	return;
}
int calc(const Poi &P)
{
	int sum=0,cnt=0;
	for(int i=1;i<=n&&cnt<m;i++) if(dcmp(lenth(P-C[i])-R[i])<=0)
	{
		sum+=S[i];
		cnt++;
	}
	return sum;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		In=ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%lf%lf%lf%lf",&C[i].x,&C[i].y,&R[i],&S[i]);
		for(int j=1;j<=n;j++)
			for(int i=1;i<n;i++) if(S[i]<S[i+1])
			{
				swap(C[i],C[i+1]);
				swap(R[i],R[i+1]);
				swap(S[i],S[i+1]);
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				inters(i,j);
		for(int i=1;i<=In;i++)
			ans=max(ans,calc(I[i]));
		for(int i=1;i<=n;i++)
			ans=max(ans,calc(C[i]));
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

