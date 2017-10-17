#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct Point
{
	double x,y;
	Point(double X=0,double Y=0):x(X),y(Y){}
	Point operator+(Point P){return Point(x+P.x,y+P.y);}
	Point operator-(Point P){return Point(x-P.x,y-P.y);}
	Point operator*(double num){return Point(x*num,y*num);}
	Point operator/(double num){return Point(x/num,y/num);}
}seg[2][5050],T,O;
const double eps=1e-6;
double dOt(Point A,Point B){return (A.x*B.x+A.y*B.y);}
double lEnth(Point X){return sqrt(dOt(X,X));}
double aNgle(Point A,Point B){return acos(dOt(A,B)/lEnth(A)/lEnth(B));}
double cRoss(Point A,Point B){return (A.x*B.y-A.y*B.x);}
int dcmp(double x){return fabs(x)<=eps?0:(x<0?-1:1);}
int n,m,num[5050];
double X1,X2,Y1,Y2;
bool cnmp(Point A,Point B){return A.x<B.x;}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int i,j;
	bool flag;
	while(true)
	{
		scanf("%d",&n);
		if(!n)
			break;
		memset(num,0,sizeof(num));
		scanf("%d%lf%lf%lf%lf",&m,&X1,&Y1,&X2,&Y2);
		Y1+=Y2;
		Y2=Y1-Y2;
		Y1-=Y2;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&seg[1][i].x,&seg[0][i].x);
			seg[0][i].y=Y1;
			seg[1][i].y=Y2;
		}
		sort(seg[0]+1,seg[0]+n+1,cnmp);
		sort(seg[1]+1,seg[1]+n+1,cnmp);
		for(i=1;i<=m;i++)
		{
			scanf("%lf%lf",&T.x,&T.y);
			flag=false;
			for(j=1;j<=n;j++)
				if(dcmp(cRoss(seg[1][j]-seg[0][j],T-seg[0][j]))>0)
				{
					flag=true;
					num[j-1]++;
					break;
				}
			if(!flag)
				num[n]++;
		}
		for(i=0;i<=n;i++)
			printf("%d: %d\n",i,num[i]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

