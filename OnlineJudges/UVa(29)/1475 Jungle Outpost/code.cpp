/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const double eps=1e-8;
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
}W[50050];
double cRoss(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
Poi iNtersect(const Poi &P1,const Vec &V1,const Poi &P2,const Vec &V2)
{ return P1+V1*(cRoss(V2,P1-P2)/cRoss(V1,V2)); }//建议加括号防炸精度
struct Line
{
	Poi Ps; Vec Dir;
	double ang;
	Line(const Poi &ps=Poi(),const Vec &dir=Vec()):Ps(ps),Dir(dir)
	{ ang=atan2(Dir.y,Dir.x); }
	bool operator<(const Line &L1)const { return ang<L1.ang; }
}lines[50050];
Poi iNtersect(const Line &L1,const Line &L2)
{ return iNtersect(L1.Ps,L1.Dir,L2.Ps,L2.Dir); }
bool HPI(int N)
{
	int l,r;
	Poi *IP= new Poi[N]; Line *q= new Line[N],*L=lines;
	//sort(L,L+N);//因为是按照多边形给的点，所以可以不用排序
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
		if(l<r)
			IP[r-1]=iNtersect(q[r-1],q[r]);
	}
	while(l<r&&dcmp(cRoss(q[l].Dir,IP[r-1]-q[l].Ps))<=0) r--;
	delete IP; delete q;
	return (r-l>1);
}
int n;
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	int l,mid,r;
	while(scanf("%d",&n)!=-1&&n)
	{
		for(int i=0;i<n;i++) scanf("%lf%lf",&W[i].x,&W[i].y);
		l=1;r=n-3;
		while(l<r)
		{
			mid=l+(r-l)/2;
			for(int i=0;i<n;i++) lines[i]=Line(W[i],W[(i-mid-1+n)%n]-W[i]);
			if(HPI(n)) l=mid+1; else r=mid;
		}
		printf("%d\n",l);
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

