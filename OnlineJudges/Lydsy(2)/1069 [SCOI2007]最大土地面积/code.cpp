#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=2050;
const double eps=1e-10;
int dcmp(const double &x=0) { if(fabs(x)<=eps) return 0; return x<0?-1:1; }
typedef struct Poi Vec;
struct Poi
{
	double x,y;
	Poi(const double &X=0,const double &Y=0):x(X),y(Y){}
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &p)const { return Poi(x*p,y*p); }
	bool operator!=(const Poi &P)const { return x!=P.x||y!=P.y; }
	bool operator<(const Poi &P)const { return x==P.x?y<P.y:x<P.x; }
}v[MAXN],vv[MAXN<<1];
double Cross(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
int n;
int Convex_hull(Poi *P,const int &num,Poi *PP)
{
	int m=0;
	sort(P,P+num);
	for(int i=0;i<num;i++)
	{
		if(1<m&&dcmp(Cross(P[i]-PP[m-1],PP[m-2]-PP[m-1]))<=0) m--;
		PP[m++]=P[i];
	}
	for(int i=num-1,low=m-1;i>=0;i--)
	{
		if(low<m&&dcmp(Cross(P[i]-PP[m-1],PP[m-2]-PP[m-1]))<=0) m--;
		PP[m++]=P[i];
	}
	return m;
}
double Rotating_Clip(Poi *P)
{
	int l,r,m;
	double ans=0,cnt1,cnt2,cnt3,cnt4;
	m=Convex_hull(v,n,vv);
	for(int i=0;i<=m;i++)
		vv[n+i]=vv[i];
	l=r=0;
	while(l<m)
	{
		while(r<(m<<1)&&0<=dcmp(Cross(vv[l+1]-vv[l],vv[r+1]-vv[r]))) r++;
		cnt1=cnt2=cnt3=cnt4=-1000000000000.;
		for(int i=0;i<n;i++)
		{
			cnt1=max(cnt1,Cross(vv[r]-v[i],vv[l]-v[i])/2.);
			cnt3=max(cnt3,Cross(vv[l]-v[i],vv[r]-v[i])/2.);
		}
		for(int i=n-1;i>=0;i--)
		{
			cnt2=max(cnt2,Cross(vv[l]-v[i],vv[r]-v[i])/2.);
			cnt4=max(cnt4,Cross(vv[r]-v[i],vv[l]-v[i])/2.);
		}
		ans=max(ans,max(cnt1+cnt2,cnt3+cnt4));
		l++;
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf%lf",&v[i].x,&v[i].y);
	printf("%.3f",Rotating_Clip(v));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
