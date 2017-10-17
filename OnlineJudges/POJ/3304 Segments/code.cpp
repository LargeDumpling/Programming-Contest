#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct Poi
{
	double x,y;
	Poi(const double &X=0,const double &Y=0):x(X),y(Y){}
	Poi operator+(const Poi &P){return Poi(x+P.x,y+P.y);}
	Poi operator-(const Poi &P){return Poi(x-P.x,y-P.y);}
	Poi operator*(const double &num){return Poi(x*num,y*num);}
	Poi operator/(const double &num){return Poi(x/num,y/num);}
}seg[210];
const double eps=1e-8;
int dcmp(const double &x){return x<0?(-x<eps?0:-1):(x<eps?0:1);}
double dOt(const Poi &A,const Poi &B){return (A.x*B.x+A.y*B.y);}
double lEnth(const Poi &X){return sqrt(dOt(X,X));}
double aNgle(const Poi &A,const Poi &B){return acos(dOt(A,B)/lEnth(A)/lEnth(B));}
double cRoss(const Poi &A,const Poi &B){return (A.x*B.y-A.y*B.x);}
int n,T;
bool check(const int &P1,const int &P2)
{
	if(!dcmp(seg[P1].x-seg[P2].x)&&!dcmp(seg[P1].y-seg[P2].y))
		return false;
	int t1,t2;
	for(int i=1;i<=n;i++)
	{
		t1=dcmp(cRoss(seg[(i<<1)-1]-seg[P2],seg[P1]-seg[P2]));
		t2=dcmp(cRoss(seg[i<<1]-seg[P2],seg[P1]-seg[P2]));		
		if((t1|t2)&&t1==t2)
			return false;
	}
	return true;
}
bool solve()
{
	for(int i=(n<<1);i;i--)
		for(int j=i-1;j;j--)
			if(check(i,j))
				return true;
	return false;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lf%lf%lf%lf",&seg[(i<<1)-1].x,&seg[(i<<1)-1].y,&seg[i<<1].x,&seg[i<<1].y);
		if(solve())
			printf("Yes!\n");
		else
			printf("No!\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

