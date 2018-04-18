/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const double eps=1e-12;
const double offarg=1e-6;
int dcmp(const double &x)
{
	if(fabs(x)<=eps) return 0;
	return x<0?-1:1;
}
typedef struct Poi Vec;
struct Poi
{
	double x,y;
	Poi(const double &X=0,const double &Y=0):x(X),y(Y) { }
	Poi operator+(const Poi &X)const { return Poi(x+X.x,y+X.y); }
	Poi operator-(const Poi &X)const { return Poi(x-X.x,y-X.y); }
	Poi operator*(const double &P)const { return Poi(P*x,P*y); }
	Poi operator/(const double &P)const { return Poi(P*x,P*y); }
}T[4];
double dot(const Vec &A,const Vec &B) { return A.x*B.x+A.y*B.y; }
double cross(const Vec &A,const Vec &B) { return A.x*B.y-A.y*B.x; }
bool inside(const Poi &P)
{
	int st[3];
	for(int i=0;i<3;i++)
		st[i]=dcmp(cross(T[i+1]-T[i],P-T[i]));
	return (st[0]<0&&st[1]<0&&st[2]<0)||(0<st[0]&&0<st[1]&&0<st[2]);
}
bool intersect(const Poi &P1,const Poi &P2,const Poi &P3,const Poi &P4)
{
	int st1,st2;
	st1=dcmp(cross(P3-P1,P2-P1))*dcmp(cross(P4-P1,P2-P1));
	st2=dcmp(cross(P2-P3,P4-P3))*dcmp(cross(P1-P3,P4-P3));
	return st1==-1&&st2==-1;
}
char map[25][25];
int n,mOve[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
int calc_dist()
{
	int dis[25][25],x,y,xx,yy;
	bool exist[25][25],able[25][25][8];
	memset(able,false,sizeof(able));
	memset(exist,false,sizeof(exist));
	memset(dis,-1,sizeof(dis));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) if(map[i][j]!='#')
			for(int k=0;k<8;k++)
			{
				xx=i+mOve[k][0];
				yy=j+mOve[k][1];
				Poi P1,P2;
				P1=Poi(i,j)+(Poi(xx,yy)-Poi(i,j))*offarg;
				P2=Poi(xx,yy)+(Poi(i,j)-Poi(xx,yy))*offarg;
				if(0<=xx&&xx<n&&0<=yy&&yy<n&&map[xx][yy]!='#'&&!inside(P1)&&(!inside(P2)))
				{
					bool flag=false;
					for(int l=0;l<3&&!flag;l++)
					{
						flag|=intersect(T[l],T[l+1],Poi(i,j),Poi(xx,yy));
						flag|=inside((Poi(i,j)+Poi(xx,yy))/2.);
					}
					if(!flag) able[i][j][k]=true;
				}
			}
	queue<int> q;
	dis[0][0]=0;
	q.push(0);
	while(q.size())
	{
		x=q.front(); q.pop();
		y=x%100; x/=100;
		exist[x][y]=false;
		for(int i=0;i<8;i++) if(able[x][y][i])
		{
			xx=x+mOve[i][0]; yy=y+mOve[i][1];
			if(dis[xx][yy]==-1||dis[x][y]+1<dis[xx][yy])
			{
				dis[xx][yy]=dis[x][y]+1;
				if(!exist[xx][yy])
				{
					exist[xx][yy]=true;
					q.push(xx*100+yy);
				}
			}
		}
	}
	return dis[n-1][n-1];
}
int main()
{
	while(scanf("%d",&n)!=-1)
	{
		scanf("%lf%lf%lf%lf%lf%lf\n",&T[0].x,&T[0].y,&T[1].x,&T[1].y,&T[2].x,&T[2].y);
		T[3]=T[0];
		for(int i=n-1;0<=i;i--)
			gets(map[i]);
		printf("%d\n",calc_dist());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
